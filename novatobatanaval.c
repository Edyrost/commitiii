#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // Necessário para a função abs() (valor absoluto)

// --- Constantes para o Jogo ---
#define LINHAS 10
#define COLUNAS 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// --- Constantes para as Habilidades Especiais ---
#define TAMANHO_HABILIDADE 5 // Usaremos matrizes 5x5 para as habilidades
#define AREA_AFETADA 5     // Valor que representa a área de efeito no tabuleiro

/**
 * @brief Aplica uma habilidade especial (Cone, Cruz, Octaedro) no tabuleiro.
 * * @param tabuleiro O tabuleiro principal do jogo (10x10).
 * @param origem_linha A linha central onde a habilidade será aplicada.
 * @param origem_coluna A coluna central onde a habilidade será aplicada.
 * @param tipo_habilidade Caractere que define a forma da habilidade ('c' para Cone, 'x' para Cruz, 'o' para Octaedro).
 */
void aplicar_habilidade(int tabuleiro[LINHAS][COLUNAS], int origem_linha, int origem_coluna, char tipo_habilidade) {
    // O centro da matriz de habilidade (para uma matriz 5x5, o centro é o índice 2)
    int centro_habilidade = TAMANHO_HABILIDADE / 2;

    // Percorre a matriz de habilidade 5x5 de forma virtual
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            bool habilidade_ativa = false;

            // --- Lógica Condicional para Gerar as Formas Dinamicamente ---
            switch (tipo_habilidade) {
                case 'c': // Habilidade Cone (apontando para cima, como no exemplo)
                    // A fórmula abs(j - centro) <= i cria um triângulo/cone.
                    // Em cada linha i, a largura do cone é 2*i + 1, centrado em j.
                    if (abs(j - centro_habilidade) <= i) {
                        habilidade_ativa = true;
                    }
                    break;

                case 'x': // Habilidade Cruz
                    // A forma de cruz é ativada se a célula estiver na linha central (i) OU na coluna central (j).
                    if (i == centro_habilidade || j == centro_habilidade) {
                        habilidade_ativa = true;
                    }
                    break;
                
                case 'o': // Habilidade Octaedro (forma de losango/diamante)
                    // A fórmula usa a "Distância de Manhattan". A soma das distâncias vertical e horizontal
                    // do centro não pode ser maior que o próprio raio (o centro).
                    if (abs(i - centro_habilidade) + abs(j - centro_habilidade) <= centro_habilidade) {
                        habilidade_ativa = true;
                    }
                    break;
            }

            // Se a célula (i,j) faz parte da habilidade, sobrepõe no tabuleiro principal
            if (habilidade_ativa) {
                // Calcula a coordenada correspondente no tabuleiro 10x10
                int board_linha = origem_linha - centro_habilidade + i;
                int board_coluna = origem_coluna - centro_habilidade + j;

                // Validação de Limites: garante que não vamos escrever fora do tabuleiro
                if (board_linha >= 0 && board_linha < LINHAS && board_coluna >= 0 && board_coluna < COLUNAS) {
                    tabuleiro[board_linha][board_coluna] = AREA_AFETADA;
                }
            }
        }
    }
}

int main() {
    // --- Etapa Aventureiro: Preparação do Tabuleiro e Navios ---
    int tabuleiro[LINHAS][COLUNAS];
    char cabecalho_colunas[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int i, j;

    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
    
    // Posiciona alguns navios para o exemplo
    tabuleiro[1][1] = NAVIO; tabuleiro[1][2] = NAVIO; tabuleiro[1][3] = NAVIO; // Horizontal
    tabuleiro[5][8] = NAVIO; tabuleiro[6][8] = NAVIO; tabuleiro[7][8] = NAVIO; // Vertical

    // --- Nível Mestre: Aplicação das Habilidades Especiais ---
    printf("--- NÍVEL MESTRE: APLICANDO HABILIDADES ESPECIAIS ---\n");

    // 1. Define os pontos de origem para cada habilidade no tabuleiro
    int cone_origem_linha = 2;
    int cone_origem_coluna = 4;

    int cruz_origem_linha = 7;
    int cruz_origem_coluna = 6;

    int octaedro_origem_linha = 5;
    int octaedro_origem_coluna = 5;

    // 2. Chama a função para aplicar cada habilidade no tabuleiro
    printf("Aplicando habilidade Cone em (%d, %d)...\n", cone_origem_linha, cone_origem_coluna);
    aplicar_habilidade(tabuleiro, cone_origem_linha, cone_origem_coluna, 'c');
    
    printf("Aplicando habilidade Cruz em (%d, %d)...\n", cruz_origem_linha, cruz_origem_coluna);
    aplicar_habilidade(tabuleiro, cruz_origem_linha, cruz_origem_coluna, 'x');
    
    printf("Aplicando aptidão Octaedro em (%d, %d)...\n", octaedro_origem_linha, octaedro_origem_coluna, 'o');
    aplicar_habilidade(tabuleiro, octaedro_origem_linha, octaedro_origem_coluna, 'o');
    
    // --- Exibição Final do Tabuleiro ---
    printf("\n--- TABULEIRO FINAL COM HABILIDADES ---\n");
    printf("Legenda: %d-Água | %d-Navio | %d-Área Afetada\n", AGUA, NAVIO, AREA_AFETADA);
    printf("  "); 
    for (j = 0; j < COLUNAS; j++) {
        printf("%c ", cabecalho_colunas[j]);
    }
    printf("\n");

    for (i = 0; i < LINHAS; i++) {
        printf("%d ", (i + 1) % 10); 
        for (j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}