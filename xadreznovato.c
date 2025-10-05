#include <stdio.h>

int main() {

    int movimento, i, linha, coluna, casas;
    char tabuleiro[8][8] = {0};

    printf("**Desafio Xadrez .c**\n");
    
        //Movimento da Torre.
    printf("Mover Torre 5 casas à Direita\n");
    scanf("%d", &movimento);
    for (int i = 0; i < movimento; i++){
        int linha, coluna;
        printf("Move a Torre para a linha (0-5) e coluna (0-0):");
        scanf("%d %d", &linha, &coluna);
        tabuleiro[linha][coluna] = 'T';
    }

        //Movimento do Bispo.
    printf("O Bispo tem que mover 5 casa em diagonal superior à direita\n");
    scanf("%d", &movimento);
    for (int i = 0; i < movimento; i++){ 
        int linha, coluna;
        printf("Mover o bispo para a linha (0-7) e coluna (0-7):");
        scanf("%d %d", &linha, &coluna);
        tabuleiro[linha][coluna] = 'B';

    }

        // movimento de Rainha
    printf("A Rainha tem que mover 8 casas à direita");
    scanf("%d", &movimento);
    for (int i = 0; i < movimento; i++) {
         int casas, direita;
         printf(" Move a rainha 8 casas à direita");
         scanf("%d %d", &casas, &direita);
         tabuleiro[casas][direita] = 'R';

    }     
    
    return 0;
}


   