#include <stdio.h>
#include <stdlib.h>

// Function headers
void ShowWelcomeMessage();
void CreateBoard(char board[3][3]);
void showBoard(char board[3][3]);
void checkMove(char board[3][3], char *move);
void makeMove(char board[3][3], char move, int player);
int checkWinner(char board[3][3], int moves, int player);
int checkDiagonalsWin(char board[3][3]);
int checkRowWin(char board[3][3]);
int checkCollumnWin(char board[3][3]);
void showWinnerScreen(int player, char board[3][3]);
void showDrawScreen(char board[3][3]);


// Main function
int main() {
	char board[3][3];
	int moves = 1;
	ShowWelcomeMessage();
	CreateBoard(board);
	
	int loop = 1;	
	do{
		char move;
		int winner = 0;
		printf("Player 1: ");
		scanf(" %c",&move);
		checkMove(board,&move);
		makeMove(board, move, 1);
		moves++;
		showBoard(board);
		winner = checkWinner(board, moves, 1);
		if(winner!=0){
			if(winner!=3){
				showWinnerScreen(winner, board);
				break;
			}
			else{
				showDrawScreen(board);
				break;
			}
		}
		
		printf("Player 2: ");
		scanf(" %c",&move);
		checkMove(board,&move);
		makeMove(board, move, 2);
		moves++;
		showBoard(board);
		winner = checkWinner(board, moves, 1);
		if(winner!=0){
			if(winner!=3){
				showWinnerScreen(winner, board);
				break;
			}
			else{
				showDrawScreen(board);
				break;
			}
			
		}

										
	}while (loop == 1);
	printf("Thanks for play");
	
	
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
	int loop = 1;
	if(*move<='0'){
		while(loop = 1){
			printf("The move is invalid, please try again:\n");
			printf("New move: ");
			scanf(" %c", move);
			checkMove(board, move);	
			break;
		}	
	}
	else if(move){
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
//Function to check if have winner
int checkWinner(char board[3][3], int moves, int player){
	int winner = 0;

	if(moves>=5){
		winner = checkRowWin(board);
		if(winner == 0){
			winner = checkDiagonalsWin(board);
			if(winner == 0){
				winner = checkCollumnWin(board);
			}
		}
		else if(winner == 0 && moves == 9){
			winner = 3;
		}
	}		
	
	
	
	return winner;
	
}
//Function to check if the diagonals are equals
int checkDiagonalsWin(char board[3][3]){

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        	if (board[0][0] == 'X') {
            	return 1;
        	}
			else if(board[0][0] == 'O'){
				return 2;
			}
		}
    
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') {
           		return 1;
        }
		else if (board[0][2] == 'O') {
           		return 2;
        }
    }
	
	return 0;
}
//Function to check if the rows are equal
int checkRowWin(char board[3][3]){
	
		if(board[0][0] == board[0][1] && board[0][1] == board[0][2]){
			if(board[0][0] == 'X'){
				return 1;
			}
			else if(board[0][0] == 'O'){
				return 2;
			}
		}
		else if(board[1][0] == board[1][1] && board[1][1] == board[1][2]){
			if(board[1][0] == 'X'){
				return 1;
			}
			else if(board[1][0] == 'O'){
				 return 2;
			}
		}
		else if(board[2][0] == board[2][1] && board[2][1] == board[2][2]){
			if(board[2][0] == 'X'){
				return 1;
			}
			else if(board[2][0] == 'O'){
				return 2;
			}
		}

		return 0;
}
//Function to check if the colluns are equal
int checkCollumnWin(char board[3][3]){
	if(board[0][0] == board[1][0] && board[1][0] == board[2][0]){
			if(board[0][0] == 'X'){
				return 1;
			}
			else if(board[0][0] == 'O'){
				return 2;
			}
		}
		else if(board[0][1] == board[1][1] && board[1][1] == board[2][1]){
			if(board[0][1] == 'X'){
				return 1;
			}
			else if(board[0][1] == 'O'){
				 return 2;
			}
		}
		else if(board[0][2] == board[1][2] && board[1][2] == board[2][2]){
			if(board[0][2] == 'X'){
				return 1;
			}
			else if(board[0][2] == 'O'){
				return 2;
			}
		}
		return 0;
}
//Function to congratulations
void showWinnerScreen(int player, char board[3][3]) {
    printf("\n==============================\n");
    printf("      CONGRATULATIONS!  \n");
    printf("==============================\n");
    printf("       Player %d wins!       \n", player);
    printf("==============================\n\n");
	showBoard(board);
	
}
//Function to draw
void showDrawScreen(char board[3][3]) {
    printf("\n==============================\n");
    printf("        It's a draw!         \n");
    printf("==============================\n");
    printf("  Nobody wins this time...   \n");
    printf("==============================\n\n");
	showBoard(board);
}