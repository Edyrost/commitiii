#include <stdio.h>
#include <ctype.h>  

// Definições de constantes para os tamanhos dos tabuleiros
#define tab_principal 10      // Tamanho do tabuleiro principal (10x10)
#define tab_ataque_linha 3    // Linhas da matriz dos ataques especiais
#define tab_ataque_coluna 5   // Colunas da matriz dos ataques especiais


// Função para exibir o tabuleiro principal
void Exibir_Tabuleiro_Batalha_Naval(int tabuleiro[tab_principal][tab_principal]){

    // Letras das colunas (A até J)
    char linha1[tab_principal] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    printf("============== Batalha Naval ===============\n\n");
        
    // Cabeçalho das colunas
    printf("___|");
    for(int linha = 0; linha < 10; linha++){
        printf("_%c_|", linha1[linha]);       
    }
    printf("\n");

    // Numeração das linhas (1 até 10) e impressão do conteúdo do tabuleiro
    int coluna1 = 1;
    for(int contador = 0; contador < 10; contador++){
        if (coluna1 == 10){ 
            printf("_%d|", coluna1);  // Para alinhar o número 10
        }else{
            printf("_%d_|", coluna1);
        }
        
        // Imprime os valores armazenados na matriz (0 = vazio, 3 = navio, 5 = ataque)
        for (int matriz = 0; matriz < 10 ; matriz++){
            printf(" %d |", tabuleiro[contador][matriz]);
        }
        
        coluna1++;
        printf("\n");
    }
    printf("\n");
}


// Função para exibir os formatos dos ataques especiais
void Exibir_Tabuleiros_de_Ataque(int ataque_cruz[tab_ataque_linha][tab_ataque_coluna], 
                                 int ataque_cone[tab_ataque_linha][tab_ataque_coluna], 
                                 int ataque_octaedro[tab_ataque_linha][tab_ataque_coluna]){

    printf("=========== Ataques especiais ============\n\n");

    // Exibe ataque em formato de cruz
    printf("======== Cruz =======\n");
    for(int linha_matriz_ataque = 0; linha_matriz_ataque < 3; linha_matriz_ataque++ ){
        for(int coluna_matriz_ataque = 0; coluna_matriz_ataque < 5; coluna_matriz_ataque++ ){
            if (coluna_matriz_ataque == 0){
                printf("| %d |", ataque_cruz[linha_matriz_ataque][coluna_matriz_ataque]);
            }else{
                printf(" %d |", ataque_cruz[linha_matriz_ataque][coluna_matriz_ataque]);
            }
        }
        printf("\n");
    }
    printf("\n");

    // Exibe ataque em formato de cone
    printf("======== Cone =======\n");
    for(int linha_matriz_ataque = 0; linha_matriz_ataque < 3; linha_matriz_ataque++ ){
        for(int coluna_matriz_ataque = 0; coluna_matriz_ataque < 5; coluna_matriz_ataque++ ){
            if (coluna_matriz_ataque == 0){
                printf("| %d |", ataque_cone[linha_matriz_ataque][coluna_matriz_ataque]);
            }else{
                printf(" %d |", ataque_cone[linha_matriz_ataque][coluna_matriz_ataque]);
            }
        }
        printf("\n");
    }
    printf("\n");

    // Exibe ataque em formato de octaedro
    printf("====== Octaedro =====\n");
    for(int linha_matriz_ataque = 0; linha_matriz_ataque < 3; linha_matriz_ataque++ ){
        for(int coluna_matriz_ataque = 0; coluna_matriz_ataque < 5; coluna_matriz_ataque++ ){
            if (coluna_matriz_ataque == 0){
                printf("| %d |", ataque_octaedro[linha_matriz_ataque][coluna_matriz_ataque]);
            }else{
                printf(" %d |", ataque_octaedro[linha_matriz_ataque][coluna_matriz_ataque]);
            }
        }
        printf("\n");
    }
    printf("\n\n");

    printf("# Use o meio do ataque como base para lançar no tabuleiro\n\n");
}


int main(){
    // Tabuleiro inicial preenchido com zeros (0 = vazio)
    int tabuleiro [tab_principal][tab_principal] = {0}; 

    // Exibe tabuleiro vazio no início
    Exibir_Tabuleiro_Batalha_Naval(tabuleiro); 

    char descisao = 'S';
    while (descisao == 'S'){   // Enquanto o usuário quiser adicionar navios
        int tamanho_navio, verificacao_navio = 1; 
    
        // Pergunta o tamanho do navio (máximo 5 casas)
        while (verificacao_navio){
            printf("Quantas casas o seu navio ocupará (min = 1, máx = 5)?\n");
            scanf("%d", &tamanho_navio);

            if (tamanho_navio < 1 || tamanho_navio > 5){
                printf("Tamanho do navio inválido!\n");
                printf("Tente novamente...\n\n");
                
            }else{
                break;
            }    
        }   

        // Inatrução de como posicionar o navio no tabuleiro
        printf("\nDigite a casa (Ex: Coluna - A, Linha - 1)\n");

        char letra_coluna;     
        int linha, coluna = 0;  

        // Coloca o navio casa por casa
        for(int posicao_navio = 1; posicao_navio <= tamanho_navio; posicao_navio++){ 
            printf("Qual a %dª casa? \n\n", posicao_navio);
        
            while (1){
                
                // Escolhe coluna (A–J)
                while (1){
                    printf("Coluna: ");
                    scanf(" %c", &letra_coluna);
                    letra_coluna = toupper(letra_coluna);

                    if      (letra_coluna == 'A'){ coluna = 0; break; }
                    else if (letra_coluna == 'B'){ coluna = 1; break; }
                    else if (letra_coluna == 'C'){ coluna = 2; break; }
                    else if (letra_coluna == 'D'){ coluna = 3; break; }
                    else if (letra_coluna == 'E'){ coluna = 4; break; }
                    else if (letra_coluna == 'F'){ coluna = 5; break; }
                    else if (letra_coluna == 'G'){ coluna = 6; break; }
                    else if (letra_coluna == 'H'){ coluna = 7; break; }
                    else if (letra_coluna == 'I'){ coluna = 8; break; }
                    else if (letra_coluna == 'J'){ coluna = 9; break; }
                    else { printf("Coluna inválida\n\n"); }
                }
                
                // Escolhe linha (1–10)
                while (1){
                    printf("Linha: ");
                    scanf("%d", &linha);
                    printf("\n");

                    if (linha < 1 || linha > 10){
                        printf("Linha inválida!\n\n");
                    }else{
                        break;
                    }
                }

                // Verifica se já existe navio na posição escolhida
                if (tabuleiro[linha - 1][coluna] == 3){
                    printf("Posição [%c%d] já ocupada!\n\n", letra_coluna, linha); 
                }else{
                    break;
                }
            }         

            // Marca posição do navio com o número 3
            printf("%dª posição (%c%d) \n\n",posicao_navio, letra_coluna, linha);
            tabuleiro[linha - 1][coluna] = 3; 
        
        }

        while (1)
        {
            // Pergunta se deseja colocar outro navio
            printf("Deseja colocar outro navio no tabulerio? (S/N) \n");
            scanf(" %c", &descisao);
            descisao = toupper(descisao);

            if (descisao == 'N') {break;}
            else if (descisao == 'S'){ break; printf("Tudo bem!\n");}
            else {printf("Opção inválida, tente novamente!\n");}
        }
    }
    
    // Exibe tabuleiro atualizado com navios
    Exibir_Tabuleiro_Batalha_Naval(tabuleiro);
    
    // Matrizes que representam os formatos dos ataques
    int ataque_cruz[3][5] = {
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0}
    };
    int ataque_cone[3][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1}
    };
    int ataque_octaedro[3][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {0,0,1,0,0}
    };


    // Verificar se o usuário que atacar mais de uma vez
    char descisao_ataque = 'S';
    while (descisao_ataque == 'S'){
            
        // Exibe os padrões de ataque
        Exibir_Tabuleiros_de_Ataque(ataque_cruz, ataque_cone, ataque_octaedro);

        int opcao_ataque, linha_ataque, coluna_ataque;
        char letra_coluna_ataque;

        // Escolha do tipo de ataque
        while (1)
        {
            printf("Qual ataque deseja usar? \n");
            printf("1 - Cruz\n");
            printf("2 - Cone\n");
            printf("3 - Octaedro\n");
            printf("Escolha: ");
            scanf("%d", &opcao_ataque);
            
            if (opcao_ataque < 1 || opcao_ataque > 3){
                printf("Opção inválida! Tente novamente\n\n");
            }else{
                break;
            }
        }
        
        
        // Escolha da posição de ataque
        printf("\nÓtima escolha!!!\n\n");
        printf("Qual posição do tabuleiro deseja atacar? \n");

        // Seleção da coluna (A–J)
        while(1){
            printf("Coluna: ");
            scanf(" %c", &letra_coluna_ataque);
            letra_coluna_ataque = toupper(letra_coluna_ataque);

            if      (letra_coluna_ataque == 'A'){ coluna_ataque = 0; break; }
            else if (letra_coluna_ataque == 'B'){ coluna_ataque = 1; break; }
            else if (letra_coluna_ataque == 'C'){ coluna_ataque = 2; break; }
            else if (letra_coluna_ataque == 'D'){ coluna_ataque = 3; break; }
            else if (letra_coluna_ataque == 'E'){ coluna_ataque = 4; break; }
            else if (letra_coluna_ataque == 'F'){ coluna_ataque = 5; break; }
            else if (letra_coluna_ataque == 'G'){ coluna_ataque = 6; break; }
            else if (letra_coluna_ataque == 'H'){ coluna_ataque = 7; break; }
            else if (letra_coluna_ataque == 'I'){ coluna_ataque = 8; break; }
            else if (letra_coluna_ataque == 'J'){ coluna_ataque = 9; break; }
            else { printf("Coluna inválida\n\n"); }
        }

        // Seleção da linha (1–10)
        while (1){                                          // Loop infinito até o usuário fornecer uma linha válida
            printf("Linha: ");                              // Pede ao usuário o número da linha (espera 1..10)
            scanf("%d", &linha_ataque);                     // Lê o número digitado e armazena em linha_ataque
            printf("\n\n");                                 // Imprime uma linha em branco para formatação
            linha_ataque -= 1;                              // Converte de 1..10 para índice 0-based (0..9)
            if (linha_ataque < 0 || linha_ataque > 9){      // Verifica se o índice ficou fora do intervalo válido (0..9)
                printf("Linha inválida!\n\n");              // Informa erro e repete o loop para nova entrada
            }else{  
            break;                                          // Entrada válida: sai do loop
            }
        }

        // Tamanho da matriz de ataque (sempre 3x5)
        int linhas_matriz_ataque = 3, colunas_matriz_ataque = 5;

        // Centro do ataque (posição base para sobrepor no tabuleiro)
        int centro_linha = 1;  
        int centro_coluna = 2;  

        // Aplica o ataque escolhido no tabuleiro
        printf("========= Resultado do ataque =========\n");
        switch (opcao_ataque){

            case 1: // Ataque cruz
                for (int i = 0; i < linhas_matriz_ataque; i++) {
                    for (int j = 0; j < colunas_matriz_ataque; j++) {
                        if (ataque_cruz[i][j] == 1) {                                   // Se a célula (i,j) do padrão da cruz é um '1', então ela representa uma casa que deve ser atingida.
                        int linha_destino = linha_ataque - centro_linha + i;            // Calcula a linha destino no tabuleiro alinhando o centro do padrão à linha escolhida
                            int coluna_destino = coluna_ataque - centro_coluna + j;     // Calcula a coluna destino no tabuleiro alinhando o centro do padrão à coluna escolhida

                            // Só marca se a posição estiver dentro do tabuleiro
                            if (linha_destino >= 0 && linha_destino <= tab_principal &&   // Verifica limite inferior (>=0) e superior (<= tab_principal)
                                coluna_destino >= 0 && coluna_destino < tab_principal) {  // Verifica coluna dentro do intervalo válido (>=0 e < tab_principal)

                                char exibir_letra;
                                if (coluna_destino == 0){exibir_letra = 'A';}           //Tranforma a localização da coluna em letra para exibir ao usuário
                                else if (coluna_destino == 1){exibir_letra = 'B';}
                                else if (coluna_destino == 2){exibir_letra = 'C';}
                                else if (coluna_destino == 3){exibir_letra = 'D';}
                                else if (coluna_destino == 4){exibir_letra = 'E';}
                                else if (coluna_destino == 5){exibir_letra = 'F';}
                                else if (coluna_destino == 6){exibir_letra = 'G';}
                                else if (coluna_destino == 7){exibir_letra = 'H';}
                                else if (coluna_destino == 8){exibir_letra = 'I';}
                                else if (coluna_destino == 9){exibir_letra = 'J';}
                    
                                if (tabuleiro[linha_destino][coluna_destino] == 3){     //Exibe se o ataque acertou o navio ou não
                                    printf("Navio atingido na posição %c%d! Muito bom.\n", exibir_letra, linha_destino + 1);
                                }else{
                                    printf("Posição %c%d vazia!\n", exibir_letra, linha_destino + 1);
                                }
                                
                                tabuleiro[linha_destino][coluna_destino] = 5;             // Marca a célula de destino como atingida (valor 5)
                            }
                        }
                    }
                }
            break;
            
            case 2: // Ataque cone
                for (int i = 0; i < linhas_matriz_ataque; i++) {         // Mesma lógica do case 1, mas usando o padrão ataque_cone
                    for (int j = 0; j < colunas_matriz_ataque; j++) {
                        if (ataque_cone[i][j] == 1) {                   // Se a célula do padrão cone for 1, é célula a atingir
                            int linha_destino = linha_ataque - centro_linha + i;   // Calcula linha destino alinhando centros
                            int coluna_destino = coluna_ataque - centro_coluna + j; // Calcula coluna destino alinhando centros

                            if (linha_destino >= 0 && linha_destino <= tab_principal &&   // Verifica limites antes de escrever na matriz
                                coluna_destino >= 0 && coluna_destino < tab_principal) {

                                char exibir_letra;
                                if (coluna_destino == 0){exibir_letra = 'A';}           //Tranforma a localização da coluna em letra para exibir ao usuário
                                else if (coluna_destino == 1){exibir_letra = 'B';}
                                else if (coluna_destino == 2){exibir_letra = 'C';}
                                else if (coluna_destino == 3){exibir_letra = 'D';}
                                else if (coluna_destino == 4){exibir_letra = 'E';}
                                else if (coluna_destino == 5){exibir_letra = 'F';}
                                else if (coluna_destino == 6){exibir_letra = 'G';}
                                else if (coluna_destino == 7){exibir_letra = 'H';}
                                else if (coluna_destino == 8){exibir_letra = 'I';}
                                else if (coluna_destino == 9){exibir_letra = 'J';}

                                if (tabuleiro[linha_destino][coluna_destino] == 3){     //Exibe se o ataque acertou o navio ou não
                                    printf("Navio atingido na posição %c%d! Muito bom.\n", exibir_letra, linha_destino + 1);
                                }else{
                                    printf("Posição %c%d vazia!\n", exibir_letra, linha_destino + 1);
                                }

                                tabuleiro[linha_destino][coluna_destino] = 5;            // Marca como atingida
                            }
                        }
                    }
                }
            break;

            case 3: // Ataque octaedro
                for (int i = 0; i < linhas_matriz_ataque; i++) {         // Mesma lógica do case 1 e 2, agora com ataque_octaedro
                    for (int j = 0; j < colunas_matriz_ataque; j++) {
                        if (ataque_octaedro[i][j] == 1) {                // Se a célula do padrão octaedro for 1, é célula a atingir
                            int linha_destino = linha_ataque - centro_linha + i;   // Calcula linha destino
                            int coluna_destino = coluna_ataque - centro_coluna + j; // Calcula coluna destino

                            if (linha_destino >= 0 && linha_destino <= tab_principal &&   // Verifica limites antes de acessar tabuleiro
                                coluna_destino >= 0 && coluna_destino < tab_principal) {
                                
                                char exibir_letra;
                                if (coluna_destino == 0){exibir_letra = 'A';}           //Tranforma a localização da coluna em letra para exibir ao usuário
                                else if (coluna_destino == 1){exibir_letra = 'B';}
                                else if (coluna_destino == 2){exibir_letra = 'C';}
                                else if (coluna_destino == 3){exibir_letra = 'D';}
                                else if (coluna_destino == 4){exibir_letra = 'E';}
                                else if (coluna_destino == 5){exibir_letra = 'F';}
                                else if (coluna_destino == 6){exibir_letra = 'G';}
                                else if (coluna_destino == 7){exibir_letra = 'H';}
                                else if (coluna_destino == 8){exibir_letra = 'I';}
                                else if (coluna_destino == 9){exibir_letra = 'J';}

                                if (tabuleiro[linha_destino][coluna_destino] == 3){     //Exibe se o ataque acertou o navio ou não
                                    printf("Navio atingido na posição %c%d! Muito bom.\n", exibir_letra, linha_destino + 1);
                                }else{
                                    printf("Posição %c%d vazia!\n", exibir_letra, linha_destino + 1);
                                }

                                tabuleiro[linha_destino][coluna_destino] = 5;            // Marca como atingida
                            }
                        }
                    }
                }
            break;

            default: // Caso escolha inválida
                printf("Opção inválida!\n\n");
            break;
        }
        printf("=======================================\n");
        printf("\n");

        while (1)
        {
            // Pergunta se deseja colocar outro navio
            printf("Deseja atacar outra posição no tabuleiro? (S/N) \n");
            scanf(" %c", &descisao_ataque);
            descisao_ataque = toupper(descisao_ataque);

            if (descisao_ataque == 'N') {break;}
            else if (descisao_ataque == 'S'){printf("Tudo bem!\n"); break; }
            else {printf("Opção inválida, tente novamente!\n");}
            printf("\n");
        }
    }
    
    // Exibe o tabuleiro após o ataque
    char descisao_exibir_tabuleiro;
    while (descisao_exibir_tabuleiro)
    {
        printf("Deseja visualizar o tabuleiro? (S/N) \n");
            scanf(" %c", &descisao_exibir_tabuleiro);
            descisao_exibir_tabuleiro = toupper(descisao_exibir_tabuleiro);

            if (descisao_exibir_tabuleiro == 'N') {break;}
            else if (descisao_exibir_tabuleiro == 'S'){Exibir_Tabuleiro_Batalha_Naval(tabuleiro); break; }
            else {printf("Opção inválida, tente novamente!\n");}
            printf("\n");
    }

    return 0;

}