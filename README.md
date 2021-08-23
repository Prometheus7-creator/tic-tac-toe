# tic-tac-toe
CLI game implemented in C++ (linux)


# 1.1 About Project

Tic-Tac-Toe is a two player game where each player uses a either X or O sign. The player who successfully places three respective signatures in a vertical, horizontal or diagonal row is the winner. 
However, it is not necessary the case that every game has a winner when there is not a single grid and when neither player has managed to mark a winning row then it is called a tie. 
 
Step 1: Use 3 X 3 matrix to get a new 9 cell tic tac toe board to play. 

Step 2: Signature 'X' is used for player 1 and 'Y' for player 2. And the players can play alternatively.  

Step 3: Get index as input from the players. And the index range is from row 0 to row 2 and from column 0 to column 2. 
 
Step 4: After each move, check whether that player has placed three respective signatures in vertical, horizontal or diagonal row. If yes, declare that player as winner.  

Step 5: If no, give chance to other player. 

Step 6: If all the cells in the Tic-Tac-Toe board got filled, then the game is drawn.

Step 7: After game over in win or tie condition, ask the user either start again or end the game. 
 


# 1.2 Requirement of Project 
  1.2.1 Hardware Requirement: 
 
    • PROCESSOR: INTEL® PENTIUM® CPU @ 2.0 GHZ 
    • RAM:  2 GB(MINIMUM) 
    • STORAGE: 5 MB(MAXIMUM) 
    • OS: Linux
  
  1.2.2 Software Requirement: 
 
    C++ compiler
 
 
# 1.3 Modules of Project:  
  1.3.1 arr[3][3] : 
       
      arr[3][3] is our playing board and it is 2D Array which will be the game or playing area. 
So the :

     1st  Row consists {.    .    .}   
     2nd Row consists  {.    .    .}
     <br>
     3rd Row consists  {.    .    .} 
     <br>
   All these dot(‘.’) are the positions of each box or of each index where Player will mark X or O. 
 
  1.3.2 ROW AND COLUMN : 
 
       M, which is the arr column size is the global variable in the project. 

  1.3.3 PromptName() : 
 
      PromptName() function is created to prompt the user for name of players. This function is called twice to prompt for the X and O player.
 
  1.3.4 PlayTurn() : 
PlayTurn() function takes the variable input, player and array arr as its argument.
If the first input is X it asks the user for a valid row and column index (0 to 2). If the user enters an invalid choice i.e. greater than 2 or less than 0. It shows an error message and asks the user to enter the valid row or column and if the user enters a valid choice but that slot is occupied it shows the message and asks for row and column again. After getting a valid row and column number it updates the 2d array with given input (X or O).
 
  1.3.5 CheckWinner() : 
 
It takes ‘arr[][3]’ as an argument and is created to check if any of the player has won the game. 
 
Then it checks whether the player mark the winning streak vertically , horizontally or diagonally. It means that this function checks if the player is having his respective character X or O in s streak of 3 either vertically or horizontally or diagonally and if he have then he has won the game.  
 
If yes , then it returns a Boolean value (TRUE). 
 
If no, then it checks whether there is any space left and if any space is left then it returns a Boolean value (FALSE). 
 
If above two conditions are falsed returns a Boolean value (false). 
 
  1.3.6 In main() : 
 
In main() I have taken two strings playerX and playerO and then we have called PrompName() to prompt for player’s name.  
 
If the name entered by the users does not matches the pre-registered players for game like “Akshay” for playerX and “Ashish” for playerO , then the function chekcFirstPlayer() will show and error and prompt for a valid name and return to main(). 
 
it will display the 2d array with ‘.’(dot) in each position. 
  
Then by calling the PlayTurn() function for players, alternatively and simultaneously just after the input calling the CheckWinner() function to check if the player has won or the game has tie, it completes the game and prompts the user if game should start again or not.
