#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x; // Ponteiro para x
   
    *p = 20; // Modifica o valor de x através do ponteiro
    printf("Valor de x: %d\n", x);
    printf("Endereço de x: %p\n", &x);
    printf("Conteúdo de p (endereço): %p\n", p);
    printf("Valor apontado por p: %d\n", *p);
    printf("Novo valor de x: %d\n", x);

    return 0;
}