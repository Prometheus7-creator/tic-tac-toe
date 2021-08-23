#include <iostream>
#define M 3

using namespace std;

// Function to prompt the user for player X or player O
string PromptName(char player){

	string playerName = ""; // string to store user input

	cout << "Enter name for the " << player << " player: "; // Prompt the user for input name
	cin >> playerName; // store user input
	cout << "\n";

	return playerName; // return user input
}

// Function to prompt the user for first player
string CheckFirstPlayer(string player1, string player2){

	string firstPlayer = ""; // string to store user input
	cout << "Who plays first, " << player1 << " or " << player2 << ": "; // Prompt the user for player 1
	cin >> firstPlayer; // store user input
	cout << "\n";
	
	// infinite loop till user gives valid player name 
	while(true){
	
		// check for if input name is valid
		if(firstPlayer == player1 || firstPlayer == player2){

			cout << firstPlayer << " is the Player 1\n";
			return firstPlayer; // return if the user is valid
		}

		// invalid user input
		else{
			cout << firstPlayer << " is not registered player."<< endl;
			cout << "Who plays first, " << player1 << " or " << player2 << ": "; // prompt the user for valid input
			cin >> firstPlayer;
		}
	}


}
// Function for each turn in game
void PlayTurn(string currentPlayer, char input[][M] , char choice){

	cout <<"\nPlayer of current turn: " << currentPlayer << endl;

	int nRow=0, nCol=0; // to store user choice slot row and column	
	
	while(true){
		cout << "Choose a row number (0 to 2): ";
		cin >> nRow;
		cout << "\n";

		if(nRow >= 0 && nRow <=2){
			while(true){
				cout << "Choose a column number (0 to 2): ";
				cin >> nCol;
				if(nCol >= 0 && nCol <= 2){
					if(input[nRow][nCol]!='X' && input[nRow][nCol]!='O'){
						input[nRow][nCol] = choice;
						return;
					}
					else{
						cout << "Slot is Occupied.\n";
						break;
					}
				}
				else{
					cout << nCol << " is not a valid column." <<endl;
					break;
				}
			}
		}
		else{
			cout << nRow << " is not a valid row." << endl;
		}
	}
	
	input[nRow][nCol] = choice;
}

bool CheckWinner(char mat[][M]){
	for(int i=0; i<3; i++)
    		if((mat[i][0] == mat[i][1] && mat[i][0] == mat[i][2] && (mat[i][0] == 'X' || mat[i][0] == 'O' )) || (mat[0][i] == mat[1][i] && mat[0][i] == mat[2][i] && (mat[0][i] == 'X' || mat[0][i] == 'O' )))
    			return 1;

	//checking the win for both diagonal
	if((mat[0][0] == mat[1][1] && mat[0][0] == mat[2][2] && (mat[0][0] == 'X' || mat[0][0] == 'O' ) ) || (mat[0][2] == mat[1][1] && mat[0][2] == mat[2][0] && (mat[0][2] == 'X' || mat[0][2] == 'O' ) ))
		return 1;
	
	for(int i=0; i<3; i++)
    		for(int j=0; j<3; j++)
    			if(mat[i][j] != 'X' && mat[i][j] != 'O')
    				return 0;
    	return 0;
}

// main function
int main(){
 
 bool gameOn = 1;
 // keep game on according to user choice
 while(gameOn){
	string playerX = PromptName('X'); // Prompt the user for player X
	string playerO = PromptName('O'); // Prompt the user for player O

	string firstPlayer = CheckFirstPlayer(playerX, playerO); // Check for player 1
	system("clear");
	
	// Initializing 2d array for slots
	char arr[3][M] = {{'.','.','.'},{'.','.','.'},{'.','.','.'}};
	
	// showing initial grid
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
				cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	
	// variable for updated input after each turn in loop
	char input;
	// string for next player update in loop
	string player = "";
	// first player and first input
	if(firstPlayer == playerX){
		input = 'X';
		player = playerX;
	}
	else{
		input = 'O';
		player = playerO;
	}
	
	int count =0;
	while(count < 9){
		PlayTurn(player, arr ,input);
		system("clear");
		// Showing updated array
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		
		bool isWinner =0;
		if(isWinner = CheckWinner(arr)){
			break;
		}
		
		player = (player == playerX) ? playerO : playerX;
		input = (input == 'X') ? 'O' : 'X';
		count++;
	}
	
	if((count != 9) && (input == 'X')){
		cout << "Game Over.\n";
		cout << playerX <<" won\n";
	}
	
	else if((count != 9) && (input == 'O')){
		cout << "Game Over.\n";
		cout << playerO << " won\n";
	}
	else{
		cout << "Game Over.\n";
		cout << "Game Tie\n";
	}
	
	char user = '\0';
	cout << "Would you like to play again? (Y/N)\n";
	cin >> user;
	if(user == 'Y' || user == 'y'){
		gameOn = 1;
		system("clear");
	}
	else if(user == 'N' || user == 'n'){
		gameOn = 0;
		cout << "Bye!\n";
	}
	else{
		gameOn = 0;
		cout << "Invalid choice\n";
	}
 }
 
	return 0;
}
