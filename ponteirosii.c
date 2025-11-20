#include <stdio.h>

void saudacao() {
    printf("Olá, mundo!\n");
}

int main() {
    void (*ptr)() = saudacao; // ponteiro para função
    ptr(); // chamada indireta
    return 0;
} 