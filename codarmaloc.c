#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----Constantes Globais----//

#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100
#define TAM_STRING 100

//----Definição da Estrutura de Dados----//

struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; // 1 para disponível, 0 para emprestado

};

// Nova struct para armazemar informações de empréstimos
struct Emprestimo {
    int indiceLivro;
    char nomeUsuario[TAM_STRING];
};

// Função para limpar o buffer de entrada
void limparBufferEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

//----Função Principal----(main)//

int main() {
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;

    biblioteca = (struct Livro *)malloc(MAX_LIVROS * sizeof(struct Livro));
    emprestimos = (struct Emprestimo *)malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Falha ao alocar memória.\n");
        free(biblioteca);
        free(emprestimos);
        return 1;
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    do {
        printf("==========================\n");
        printf(" BIBLIOTECA - PARTE 2\n");
        printf("==========================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar livros disponíveis\n");
        printf("3 - Realizar empréstimo\n");
        printf("4 - Listar empréstimos\n");
        printf("0 - Sair\n");
        printf("--------------------------\n");
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) != 1) {
            limparBufferEntrada();
            opcao = -1;
        } else {
            limparBufferEntrada();
        }

        switch (opcao) {
            case 1:
                printf("=== Cadastrar Novo Livro ===\n");
                if (totalLivros < MAX_LIVROS) {
                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);
                    biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = 0; // Remove newline

                    printf("Digite o autor do livro: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = 0; // Remove newline

                    printf("Digite a editora do livro: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = 0; // Remove newline

                    printf("Digite a edição do livro: ");
                    if (scanf("%d", &biblioteca[totalLivros].edicao) != 1) {
                        limparBufferEntrada();
                        biblioteca[totalLivros].edicao = 0;
                    } else {
                        limparBufferEntrada();
                    }

                    biblioteca[totalLivros].disponivel = 1; // Marca como disponível
                    totalLivros++;
                    printf("Livro cadastrado com sucesso!\n");
                } else {
                    printf("Capacidade máxima de livros atingida.\n");
                }
                break;

            case 2:
                printf("=== Lista de livros cadastrados ===\n");
                if (totalLivros == 0) {
                    printf("Nenhum livro cadastrado.\n");
                } else {
                    for (int i = 0; i < totalLivros; i++) {
                        printf("----------------------------------\n");
                        printf("Livro %d:\n", i + 1);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editora);
                        printf("Edição: %d\n", biblioteca[i].edicao);
                        //Mostra status de disponibilidade
                        printf("Status: %s\n", biblioteca[i].disponivel ? "Disponível" : "Emprestado");
                    }
                    printf("----------------------------------\n");
                }
                printf("Pressione Enter para continuar...");
                getchar();
                break;

            case 3:
                printf("=== Realizar Empréstimo ===\n");

                if (totalEmprestimos >= MAX_EMPRESTIMOS) {
                    printf("Capacidade máxima de empréstimos atingida.\n");
                } else if (totalLivros == 0) {
                    printf("Nenhum livro cadastrado para empréstimo.\n");
                } else {
                    printf("Livros disponíveis para empréstimo:\n");
                    int livrosDisponiveis = 0;
                    for (int i = 0; i < totalLivros; i++) {
                        if (biblioteca[i].disponivel) {
                            printf("%d - %s\n", i + 1, biblioteca[i].nome);
                            livrosDisponiveis++;
                        }
                    }

                    if (livrosDisponiveis == 0) {
                        printf("Nenhum livro disponível para empréstimo.\n");
                    } else {
                        int escolha;
                        printf("Escolha o número do livro que deseja emprestar: ");
                        if (scanf("%d", &escolha) != 1) {
                            limparBufferEntrada();
                            printf("Entrada inválida.\n");
                        } else {
                            limparBufferEntrada();
                            if (escolha < 1 || escolha > totalLivros || !biblioteca[escolha - 1].disponivel) {
                                printf("Escolha inválida.\n");
                            } else {
                                printf("Digite o nome do usuário: ");
                                fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                                emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos].nomeUsuario, "\n")] = 0; // Remove newline

                                emprestimos[totalEmprestimos].indiceLivro = escolha - 1;
                                biblioteca[escolha - 1].disponivel = 0; // Marca o livro como emprestado
                                totalEmprestimos++;
                                printf("Empréstimo realizado com sucesso!\n");
                            }
                        }
                    }
                }
                break;

            case 4:
                printf("=== Lista de Empréstimos ===\n");
                if (totalEmprestimos == 0) {
                    printf("Nenhum empréstimo registrado.\n");
                } else {
                    for (int i = 0; i < totalEmprestimos; i++) {
                        int idx = emprestimos[i].indiceLivro;
                        printf("----------------------------------\n");
                        printf("Empréstimo %d:\n", i + 1);
                        printf("Usuário: %s\n", emprestimos[i].nomeUsuario);
                        if (idx >= 0 && idx < totalLivros) {
                            printf("Livro: %s\n", biblioteca[idx].nome);
                        } else {
                            printf("Livro: (índice inválido)\n");
                        }
                    }
                    printf("----------------------------------\n");
                }
                printf("Pressione Enter para continuar...");
                getchar();
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }

    } while (opcao != 0);

    free(biblioteca);
    free(emprestimos);
    return 0;
}