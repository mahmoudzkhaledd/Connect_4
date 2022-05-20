#include<iostream>
#include<string>
#include<time.h>
using namespace std;
int chkk = 1;
int winner;
string player_1 = "", player_2 = "Computer";
int game[6][7] = { {0,0,0,0,0,0,0} ,{0,0,0,0,0,0,0} ,{0,0,0,0,0,0,0} ,{0,0,0,0,0,0,0} ,{0,0,0,0,0,0,0} ,{0,0,0,0,0,0,0} };
void zero_array()
{
	for (int r = 0; r < 6; r++)
	{
		for (int c = 0; c < 7; c++)
		{
			game[r][c] = 0;
		}
	}
}
void print_game(int wiin)
{
	system("cls");
	cout << "=========================\n|      CONNECT-4        |\n========================="<<endl;
	for (int r=0;r<6;r++)
	{
		for (int c=0;c<7;c++)
		{
			cout << game[r][c]<<"   ";
		}
		cout << endl;
	}
	if (wiin==1)
	cout <<endl<< 1 << " * " << 2 << " * " << 3 << " * " << 4 << " * " << 5 << " * " << 6<<" * "<< 7 << "  <=====> Enter one of these numbers" << endl;
	
}
float get_int(string msg,string msgerr,int fnum,int lnum, int player_num)
{
	float i;
	if (player_num == 1)
		cout <<"====> "<< player_1<<" <====" << endl << msg;
	else if (player_num==2)
		cout << "====> " << player_2 << " <====" << endl << msg;
	else if(player_num == 0)
		cout << msg;
	    cin >> i;
		while (cin.fail())
		{
			cout << msgerr;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> i;
		}
		while (1)
		{
			if ((int)i == i && i >= fnum && i <= lnum && i != 0 && cin.fail()==0)
			{
				return i;
				break;
			}
			else if (i == 20022 && fnum == 1 && lnum == 2)
				return 20022;
			else if (i == 20021 && fnum == 1 && lnum == 2)
				return 20021;
			else
			{
				cout << msgerr;
				cin.clear();
				cin.ignore(256, '\n');
				cin  >> i;
			}
		}
}
void player(int player_num,int choice)
{
	int col = 0;
	print_game(1);
	if (choice == 2 || player_num == 1)
	    col = (int)get_int("Enter Number Between 1 & 7: ", "Error! please enter number between 1 & 7: ", 1, 7, player_num) - 1;
	else if(choice == 1 && player_num==2)
	{
		srand(time(0));
		col = rand() % 7;
	}
        chk:
	if (game[0][col] != 0 && choice==2 )
	{
		print_game(1);
		col = (int)get_int("Error! please enter number empty place: ", "Error! please enter number between 1 & 7: ", 1, 7,player_num) - 1;
		goto chk;
	}
	else if (game[0][col] != 0 && choice == 1)
	{
		col++;
		goto chk;
	}
	for (int row=0 ; row < 5 ; row++)
	{		
		if (game[row][col] == 0 && game[row + 1][col] != 0)
		{
			game[row][col] = player_num;
			print_game(1);
		}
		else if (row == 4 && game[5][col] == 0)
		{
			game[5][col] = player_num;
			print_game(1);
			
		}
	}
}
void chk()
{
	for (int r = 0; r < 6; r++)
	{
		for (int w = 0; w < 7; w++)
		{
			if (game[r][w] == 1 && game[r][w + 1] == 1 && game[r][w + 2] == 1 && game[r][w + 3] == 1)
			{
				chkk = 0;
				winner = 1;
			}
			if (game[r][w] == 2 && game[r][w + 1] == 2 && game[r][w + 2] == 2 && game[r][w + 3] == 2)
			{
				chkk = 2;
				winner = 2;
			}
			if (game[r][w] == 1 && game[r+1][w] == 1 && game[r+2][w] == 1 && game[r+3][w] == 1)
			{
				chkk = 0;
				winner = 1;
			}
			if (game[r][w] == 2 && game[r + 1][w] == 2 && game[r + 2][w] == 2 && game[r + 3][w] == 2)
			{
				chkk = 2;
				winner = 2;
			}
			if (game[r][w] == 1 && game[r - 1][w + 1] == 1 && game[r - 2][w + 2] == 1 && game[r - 3][w + 3] == 1)
			{
				chkk = 0;
				winner = 1;
			}
			if (game[r][w] == 2 && game[r - 1][w - 1] == 2 && game[r - 2][w - 2] == 2 && game[r - 3][w - 3] == 2)
			{
				chkk = 2;
				winner = 2;
			}
		}
	}

}
void lead()
{
	int j;
	for (int r = 5; r >= 0; r--)
	{
		if (game[r][0] != 0 && game[r][1] != 0 && game[r][2] != 0 && game[r][3] != 0 && game[r][4] != 0 && game[r][5] != 0 && game[r][6] != 0)
			j = 0;
		else
			j = 1;
	}
	if (j == 0)
		chkk = 3;
}
int main()
{
start:
	zero_array();
	int player_num = 1;
	int choice = get_int("[1] play against computer\n[2] play against player \n==> ", "Error! please enter 1 for compuer or 2 for player: ", 1, 2, 0);
	if (choice == 1) 
	{
		cout << "Enter Player 1 Name: ";
		player_2 = "Computer";
		cin >> player_1;
	}
	else if (choice == 2)
	{
		cout << "Enter Player 1 Name: ";
		cin >> player_1;
		cout << "Enter Player 2 Name: ";
		cin >> player_2;
	}
	else if (choice == 20021)
	{
		player_1 = "Player 1";
		player_2 = "Player 2";
		choice = 1;
	}
	else if (choice == 20022)
	{
		player_1 = "Player 1";
		player_2 = "Player 2";
		choice = 2;
	}
	while (1)
	{
		chk();
		lead();
		if (chkk==1)
		{
			player(player_num,choice);
			if (player_num == 1)
				player_num = 2;
			else if (player_num == 2)
				player_num = 1;
		}
		else if (chkk==2||chkk==0)
		{
			int go;
			system("cls");
			print_game(2);

			if (chkk==2)
			cout <<endl<<player_2 << " wins !" << endl;
			else if(chkk==0)
			cout << endl << player_1 << " wins !" << endl;
			go = get_int("Do you want to play again 1=>YES / 2=>NO: ", "Error! Enter 1 or 2 ONLY: ", 1, 2, 0);
			if (go==1)
			{
				chkk = 1;
				go = 10;
				system("cls");
				goto start;
			}
			else
				goto end;
			break;
		}
		else if (chkk == 3)
		{
			int go;
			system("cls");
			print_game(2);
			cout << endl << "The two players LEADS !"<< endl;
			go = get_int("Do you want to play again (1=yes,2=no): ", "Error! Enter 1 or 2 ONLY: ", 1, 2, 0);
			if (go == 1)
			{
				chkk = 1;
				go = 10;
				system("cls");
				goto start;
			}
			else
				goto end;
			break;
		}
	}
	end:
	system("exit");
}