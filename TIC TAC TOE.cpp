#include<iostream>
#include<string>
using namespace std ;

int main()
{
	char board[3][3] = {
	
	// creating broad of game 
	
	{' ',' ',' '},   // void row 1
	{' ',' ',' '},  // void row 2
	{' ',' ',' '},   // void row 3
	};
	
	// creating players
	
	const char playerX= 'X' ;
	const char playerO= 'O' ;
	char currentplayer = playerX ;  // tracking the current players turn
	int r= -1;
	int c=-1;
	char winner =' ';
	cout<<"\nWELCOME TO  TIC TAC TOE ...............!!! \n\n\n\n";
	
	// starting game 
	
	 for(int i=0 ; i<9; i++)
	 {
		// printing the board
		cout<<"      |      |      "<< endl;
		cout<<" "<<board[0][0] << "    |  "<< board[0][1]<<"   |  "<<board[0][2]<<endl;
		cout<<"______|______|______"<< endl;
		cout<<"      |      |      "<< endl;
		cout<<" "<<board[1][0] << "    |  "<< board[1][1]<<"   |  "<<board[1][2]<<endl;
		cout<<"______|______|______"<< endl;
		cout<<"      |      |      "<< endl;
		cout<<" "<<board[2][0] << "    |  "<< board[2][1]<<"   |  "<<board[2][2]<<endl;
		cout<<"      |      |      "<< endl;
	
	if(winner != ' ') // found winner , ending the game
	{
		break ;
	}
	
	
	// get player input
	cout<< "\n\nCurrent player is :"<<currentplayer ;

	while(true)
	{
		cout<< "\n\nEnter row and column number (0-2) : \n";
		cin>>r>>c;
		if(r<0|| r>2 || c<0 || c>2)
		{
			
				cout<<"\n\n********* INVALID INPUT ************ \n\nTRY AGAIN :-( \n";
				
		}
		
		else if(board[r][c] !=' ')
		{
			cout<< "\nTILE IS FULL \n\nTRY AGAIN :-( \n\n";
		}
		else
		{
			break;
		}
		
		// resetting values
		r=-1;
		c=-1;
		cin.clear(); // clear error flags 
		cin.ignore(10000, '\n');  //discard values (character inputs)
		
	}
	board[r][c]= currentplayer ;
	currentplayer = (currentplayer== playerX)? playerO : playerX ;
	
	// checking winner 
	
	for(int r=0; r<3; r++)  // checking winner row wise
	{
		if(board[r][0] != ' ' && board[r][0] == board[r][1]  && board[r][1]==board[r][2]) 
		{
			
			winner = board[r][0];
			break;
			
		}
	}
	
	for(int c=0; c<3; c++)  // checking winner column wise
	{
		if(board[0][c] != ' ' && board[0][c] == board[1][c]  && board[1][c]==board[2][c]) 
		{
			
			winner = board[0][c];
			break ;
			
		}
	}
	
	if(board[0][0] != ' ' && board[0][0] == board[1][1]  && board[1][1]==board[2][2])
	{
			winner = board[0][0];
	}
	
	else if(board[0][2] != ' ' && board[0][2] == board[1][1]  && board[1][1]==board[2][0])
	{
			winner = board[0][2];
	}
	
	
}
	
	if(winner != ' ')
	{
		cout<<"\n\n\n\a\a\a\aPlayer "<< winner << " is the winner !!!\n\n";
	}
	else 
	{
		cout<<"\n\n\n\a\a\a\a TIE !!!!!";
	}
	
}
