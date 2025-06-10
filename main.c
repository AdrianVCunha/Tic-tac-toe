#include <stdio.h>
#include <stdlib.h>

// Function headers
void ShowWelcomeMessage();
void CreateBoard(char board[3][3]);
void showBoard(char board[3][3]);
void checkMove(char board[3][3], char *move);
void makeMove(char board[3][3], char move, int player);

// Main function
int main() {
	char board[3][3];
	ShowWelcomeMessage();
	CreateBoard(board);
	
	int option = 1;	
	do{
		char move;
		printf("Player 1: ");
		scanf(" %c",&move);
		checkMove(board,&move);
		makeMove(board, move, 1);	
		showBoard(board);
		
		printf("Player 2: ");
		scanf(" %c",&move);
		checkMove(board,&move);
		makeMove(board, move, 2);
		showBoard(board);

										
	}while (option == 1);
	
	
	return 0;
}

// Function to create and display the board
void CreateBoard(char board[3][3]) {
	char x = '1';
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			board[i][j] = x++;
		}
	}
	
	showBoard(board);
}

// Function to show welcome message
void ShowWelcomeMessage() {
	printf("=======================================\n");
	printf("       WELCOME TO TIC-TAC-TOE          \n");
	printf("=======================================\n\n");

	printf("Instructions:\n");
	printf("- Two players take turns (X and O).\n");
	printf("- To play, enter the number of the desired space.\n");
	printf("- The winner is the one who aligns 3 symbols \n");
	printf("  horizontally, vertically, or diagonally.\n\n");

	printf("Good luck and have fun!\n\n");
}
//Function to show board
void showBoard(char board[3][3]){
	printf("\n");
	for (int i = 0; i < 3; i++) {
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if (i < 2) {
			printf("---|---|---\n");
		}
	}
	printf("\n");
}
//Function to check if the move is valid
void checkMove(char board[3][3], char *move){

	if(*move<='0' || *move>'9'){
		printf("The move is invalid, please try again:\n");
		printf("New move: ");
		scanf(" %c", move);
		checkMove(board, move);
	}
	else{
		return;
	}
}
//Function to make the move
void makeMove(char board[3][3], char move, int player){
	for(int i = 0; i<3; i++){
		for(int j =0; j<3; j++){
			if(board[i][j]==move){
				if(player == 1){
					board[i][j] = 'X';
				}  
				if(player == 2){
					board[i][j] = 'O';
				}
			}
		}
	}
	
}
