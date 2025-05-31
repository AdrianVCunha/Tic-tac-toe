#include <stdio.h>
#include <stdlib.h>

//Cabeçalho das funções secundarias:
void MostrarBoasVindas();
char CriaTabuleiro(char tabuleiro[3][3]);


//Função principal 
int main(){

	char tabuleiro[3][3];
	MostrarBoasVindas();
	tabuleiro[3][3] = CriaTabuleiro(tabuleiro);

	
}

char CriaTabuleiro(char tabuleiro[3][3]){

	char x = '1';
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			tabuleiro[i][j] =x++;

		}
	}
	
	for (int i = 0; i < 3; i++) {
        	printf(" %c | %c | %c ", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        	if (i < 2) {
            	printf("\n---|---|---\n");
        }
    }
		
}
void MostrarBoasVindas() {
    printf("=======================================\n");
    printf("       BEM-VINDO AO JOGO DA VELHA      \n");
    printf("=======================================\n\n");

    printf("Instrucoes:\n");
    printf("- Dois jogadores se alternam (X e O).\n");
    printf("- Para jogar, digite o número da casa desejada.\n");
    printf("- Vence quem alinhar 3 símbolos na horizontal,\n");
    printf("  vertical ou diagonal.\n\n");

    printf("Boa sorte e divirta-se!\n\n");
}