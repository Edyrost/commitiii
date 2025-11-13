#include <stdio.h>

// Função para mover o cavalo em "L"
void moverCavaloComplexo(int numMovimentos);

int main() {

    int movimento, i, linha, coluna, casas;
    
    char tabuleiro[8][8] = {0};

    printf("**Desafio Xadrez**\n");
    
     
    printf("Mover Torre 5 casas à Direita\n");
    printf("O Bispo tem que mover 5 casa em diagonal superior à direita\n");
    printf("A Rainha tem que mover 8 casas à direita\n");
    printf("O Cavalo tem que mover em L, 2 casas para frente e 1 para direita\n"); // programação aninhada


    scanf("%d", &movimento);
    for (int i = 0; i < movimento; i++){
        int linha, coluna;
        printf("Move a Torre para a linha (0-5) e coluna (0-0):");
        scanf("%d %d", &linha, &coluna);
        tabuleiro[linha][coluna] = 'T';
        
    }
    
    scanf("%d", &movimento);
    for (int i = 0; i < movimento; i++){ 
        int linha, coluna;
        printf("Mover o bispo para a linha (0-7) e coluna (0-7):");
        scanf("%d %d", &linha, &coluna);
        tabuleiro[linha][coluna] = 'B';
          
    }    
    
    scanf("%d", &movimento);
    for (int i = 0; i < movimento; i++) {
         int casas, direita;
         printf(" Move a rainha 8 casas à direita");
         scanf("%d %d", &casas, &direita);
         tabuleiro[casas][direita] = 'R';
        

    }
    int numMovimentosCavalo;
    printf("Digite o número de movimentos em 'L' para o cavalo: ");
    scanf("%d", &numMovimentosCavalo);
    moverCavaloComplexo(numMovimentosCavalo);

    return 0;
}


void moverCavaloComplexo(int numMovimentos) {
    printf("\n=== Movimento do Cavalo (Loops Complexos - %d movimentos em \"L\") ===\n", 
           numMovimentos);

    int movimentosCompletos = 0;

    for (int i = 0; i < numMovimentos; i++) {
        
        for (int j = 0; j < 3; j++) {
            
            if (j < 2) {
                printf("Cima\n");
            } 
            
            else if (j == 2) {
                printf("Direita\n");

                
                movimentosCompletos++;

                
                if (movimentosCompletos >= numMovimentos) {
                    break;
                }
            }
  
            if (j == 2) {
                
                continue;
            }
        }
    }

    printf("\n== Fim do movimento do Cavalo==\n");
}