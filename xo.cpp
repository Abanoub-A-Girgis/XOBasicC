#include <iostream>
using namespace std;

void reset(char m[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m[i][j] = '#';
			if (j == 0)
			{
				cout << m[i][j];
			}
			else
			{
				cout << "|" << m[i][j];
			}
		}
		cout <<endl;
	}
}

int main()
{
	char m[3][3], again='a';
	int i, j, win=0, turn=1;

	reset(m);

	while (win != 2)
	{
		turn = 1 - turn;

		do{
			cout << "Please enter a Row between 0 and 2: ";
			cin >> i;
		} while (i > 2 || i < 0);

		do{
			cout <<"Please enter a Column between 0 and 2: ";
			cin >> j;
		} while (j > 2 || j < 0);

		if (m[i][j] == 'X' || m[i][j] == 'O')
		{
			cout << "There is Already a Value in this location!\n";
			turn = 1 - turn;
		}
		else if (turn == 0)
		{
			m[i][j] = 'X';
		}
		else
		{
			m[i][j] = 'O';
		}

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (j == 0)
				{
					cout << m[i][j];
				}
				else
				{
					cout << "|" << m[i][j];
				}
			}

			cout << endl;
		}

		if ((m[0][0] == m[1][1] && m[1][1]==m[2][2]) && m[0][0] !='#')
		{
			win = 1;
			cout << m[0][0] << " Wins!";
		}
		if ((m[0][0] == m[0][1] && m[0][1] == m[0][2]) && m[0][0] != '#')
		{
			win = 1;
			cout << m[0][0] << " Wins!";
		}
		if ((m[1][0] == m[1][1] && m[1][1] == m[1][2]) && m[1][0] != '#')
		{
			win = 1;
			cout << m[1][0] << " Wins!";
		}
		if ((m[2][0] == m[2][1] && m[2][1] == m[2][2]) && m[2][0] != '#')
		{
			win = 1;
			cout << m[2][0] << " Wins!";
		}
		if ((m[2][0] == m[1][1] && m[1][1] == m[0][2]) && m[2][0] != '#')
		{
			win = 1;
			cout << m[0][0] << " Wins!";
		}
		if ((m[0][0] == m[1][0] && m[1][0] == m[2][0]) && m[0][0] != '#')
		{
			win = 1;
			cout << m[0][0] << " Wins!";
		}
		if ((m[0][1] == m[1][1] && m[1][1] == m[2][1]) && m[0][1] != '#')
		{
			win = 1;
			cout << m[1][0] << " Wins!";
		}
		if ((m[0][2] == m[1][2] && m[1][2] == m[2][2]) && m[0][2] != '#')
		{
			win = 1;
			cout << m[2][0] << " Wins!";
		}

		if (m[0][0] != '#' && m[0][1]  != '#' && m[0][2]  != '#' && m[1][0] != '#' && m[1][1]  != '#' && m[1][2]  != '#' && m[2][0] != '#' && m[2][1]  != '#' && m[2][2]  != '#')
		{
			win = 1;
			cout << "It's a Draw!";
		}

		if (win == 1)
		{
			cout << "\nWould you like to play again?\nPress Y or N: ";
			cin >> again;

			do {
				if (again == 'y' || again == 'Y')
				{
					win = 0;
					reset(m);
				}
				else if (again == 'n' || again == 'N')
				{
					win = 2;
				}
				else
				{
					cout << "Enter Y or N: ";
					cin >> again;
				}
			} while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');
		}
	}
	return 0;
}


