#include <stdio.h>

#define N 10          // Tamanho do tabuleiro (10x10)
#define HSIZE 5       // Tamanho das matrizes de efeito (5x5)

// Função para inicializar o tabuleiro com água (0)
void init_tabuleiro(int tab[][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tab[i][j] = 0; // água
        }
    }
}

// Função para imprimir o tabuleiro com legendas simples
void imprimir_tabuleiro(int tab[][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // Representação:
            // 0 -> água
            // 3 -> navio
            // 5 -> área afetada pela habilidade
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

// Função auxiliar para adicionar efeito de uma habilidade ao tabuleiro
// tab: tabuleiro 10x10
// efeito: matriz HSIZExHSIZE com 0/1 (1 indica área de efeito)
// origem_l, origem_c: coordenadas da origem (centro da habilidade) no tabuleiro
void aplicar_efeito(int tab[][N], int efeito[HSIZE][HSIZE], int origem_l, int origem_c) {
    // cada célula da matriz de efeito corresponde a uma posição relativa ao centro (origem)
    // Para cada posição (a, b) na matriz efeito, calculamos a posição absoluta
    // no tabuleiro: (origem_l + (a - centro), origem_c + (b - centro))
    int centro = HSIZE / 2; // centro da matriz de efeito (para 5x5, centro = 2)

    for (int a = 0; a < HSIZE; ++a) {
        for (int b = 0; b < HSIZE; ++b) {
            if (efeito[a][b] == 1) {
                int r = origem_l + (a - centro);
                int c = origem_c + (b - centro);

                // Garantir que a posição esteja dentro dos limites do tabuleiro
                if (r >= 0 && r < N && c >= 0 && c < N) {
                    // Marca a área de efeito com o valor 5
                    // Não substituímos navios (3) neste exercício de visualização;
                    // apenas marcamos onde houver água ou já área de efeito anterior.
                    if (tab[r][c] == 0) {
                        tab[r][c] = 5;
                    } else {
                        // Se já houver 3 (navio) ou 5 (outro efeito),
                        // apenas manter o valor existente; a sobreposição é visual.
                        // Opcionalmente poderia incrementar ou marcar com 5 também.
                        // Aqui mantemos o valor existente para não conflitar com navios.
                    }
                }
            }
        }
    }
}

    int main(void) {
    // 1) Criar tabuleiro 10x10 e inicializar com água
    int tabuleiro[N][N];
    init_tabuleiro(tabuleiro);

    // 2) Colocar alguns navios para visualização (valor 3)
    // Exemplo simples: posicionar alguns navios fixos
    // Navio 1
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;
    tabuleiro[1][4] = 3;

    // Navio 2
    tabuleiro[4][5] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[6][5] = 3;
    tabuleiro[7][5] = 3;

    // 3) Definir matrizes de efeito (Cone, Cruz, Octaedro)
    // Cone 5x5: aponta para baixo, expandindo
    int cone[HSIZE][HSIZE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Cruz 5x5: centro no meio
    int cruz[HSIZE][HSIZE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Octaedro (vista frontal de um losango) 5x5
    int octaedro[HSIZE][HSIZE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // 4) Definir origens das habilidades (centro da matriz 5x5)
    // As coordenadas são linha, coluna no tabuleiro (0-index)
    int origem_cone_l = 2;   // linha
    int origem_cone_c = 2;   // coluna

    int origem_cruz_l = 5;
    int origem_cruz_c = 3;

    int origem_octa_l = 7;
    int origem_octa_c = 7;

    // 5) Aplicar efeitos ao tabuleiro com sobreposição centrada nas origens
    aplicar_efeito(tabuleiro, cone, origem_cone_l, origem_cone_c);
    aplicar_efeito(tabuleiro, cruz, origem_cruz_l, origem_cruz_c);
    aplicar_efeito(tabuleiro, octaedro, origem_octa_l, origem_octa_c);

    // 6) Exibir o tabuleiro com as áreas de efeito
    // A saída irá mostrar:
    // 0 -> Água
    // 3 -> Navio
    // 5 -> Área de efeito
    printf("Tabuleiro com Areas de Efeito (0=agua, 3=navio, 5=efeito):\n");
    imprimir_tabuleiro(tabuleiro);

    return 0;
}

#define N 10          // Tamanho do tabuleiro (10x10)
#define HSIZE 5       // Tamanho das matrizes de efeito (5x5)

// Função para inicializar o tabuleiro com água (0)
void init_tabuleiro(int tab[][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tab[i][j] = 0; // água
        }
    }
}

// Função para imprimir o tabuleiro com legendas simples
void imprimir_tabuleiro(int tab[][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // Representação:
            // 0 -> água
            // 3 -> navio
            // 5 -> área afetada pela habilidade
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

// Função auxiliar para adicionar efeito de uma habilidade ao tabuleiro
// tab: tabuleiro 10x10
// efeito: matriz HSIZExHSIZE com 0/1 (1 indica área de efeito)
// origem_l, origem_c: coordenadas da origem (centro da habilidade) no tabuleiro
void aplicar_efeito(int tab[][N], int efeito[HSIZE][HSIZE], int origem_l, int origem_c) {
    // cada célula da matriz de efeito corresponde a uma posição relativa ao centro (origem)
    // Para cada posição (a, b) na matriz efeito, calculamos a posição absoluta
    // no tabuleiro: (origem_l + (a - centro), origem_c + (b - centro))
    int centro = HSIZE / 2; // centro da matriz de efeito (para 5x5, centro = 2)

    for (int a = 0; a < HSIZE; ++a) {
        for (int b = 0; b < HSIZE; ++b) {
            if (efeito[a][b] == 1) {
                int r = origem_l + (a - centro);
                int c = origem_c + (b - centro);

                // Garantir que a posição esteja dentro dos limites do tabuleiro
                if (r >= 0 && r < N && c >= 0 && c < N) {
                    // Marca a área de efeito com o valor 5
                    // Não substituímos navios (3) neste exercício de visualização;
                    // apenas marcamos onde houver água ou já área de efeito anterior.
                    if (tab[r][c] == 0) {
                        tab[r][c] = 5;
                    } else {
                        // Se já houver 3 (navio) ou 5 (outro efeito),
                        // apenas manter o valor existente; a sobreposição é visual.
                        // Opcionalmente poderia incrementar ou marcar com 5 também.
                        // Aqui mantemos o valor existente para não conflitar com navios.
                    }
                }
            }
        }
    }
}

int main(void) {
    // 1) Criar tabuleiro 10x10 e inicializar com água
    int tabuleiro[N][N];
    init_tabuleiro(tabuleiro);

    // 2) Colocar alguns navios para visualização (valor 3)
    // Exemplo simples: posicionar alguns navios fixos
    // Navio 1
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;
    tabuleiro[1][4] = 3;

    // Navio 2
    tabuleiro[4][5] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[6][5] = 3;
    tabuleiro[7][5] = 3;

    // 3) Definir matrizes de efeito (Cone, Cruz, Octaedro)
    // Cone 5x5: aponta para baixo, expandindo
    int cone[HSIZE][HSIZE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Cruz 5x5: centro no meio
    int cruz[HSIZE][HSIZE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Octaedro (vista frontal de um losango) 5x5
    int octaedro[HSIZE][HSIZE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // 4) Definir origens das habilidades (centro da matriz 5x5)
    // As coordenadas são linha, coluna no tabuleiro (0-index)
    int origem_cone_l = 2;   // linha
    int origem_cone_c = 2;   // coluna

    int origem_cruz_l = 5;
    int origem_cruz_c = 3;

    int origem_octa_l = 7;
    int origem_octa_c = 7;

    // 5) Aplicar efeitos ao tabuleiro com sobreposição centrada nas origens
    aplicar_efeito(tabuleiro, cone, origem_cone_l, origem_cone_c);
    aplicar_efeito(tabuleiro, cruz, origem_cruz_l, origem_cruz_c);
    aplicar_efeito(tabuleiro, octaedro, origem_octa_l, origem_octa_c);

    // 6) Exibir o tabuleiro com as áreas de efeito
    // A saída irá mostrar:
    // 0 -> Água
    // 3 -> Navio
    // 5 -> Área de efeito
    printf("Tabuleiro com Areas de Efeito (0=agua, 3=navio, 5=efeito):\n");
    imprimir_tabuleiro(tabuleiro);

    return 0;
}