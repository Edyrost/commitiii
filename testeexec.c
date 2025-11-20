#include <stdio.h>      // para printf, perror
#include <stdlib.h>     // para exit
#include <fcntl.h>      // para open
#include <unistd.h>     // para read, close
#include <sys/types.h>  // para tipos (opcional em algumas compilações)

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }

    const char *path = argv[1];
    // 1) Abrir o arquivo (modo leitura)
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // 2) Ler o conteúdo em um buffer
    char buf[BUF_SIZE];
    ssize_t n;
    while ((n = read(fd, buf, sizeof(buf))) > 0) {
        // 3) Escrever para a saída padrão (stdout)
        // n pode ser menor que sizeof(buf) na última leitura
        if (write(STDOUT_FILENO, buf, n) != n) {
            perror("write");
            close(fd);
            return 1;
        }
    }

    if (n == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    // 4) Fechar o arquivo
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}