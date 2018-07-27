#include <iostream>
#include <Windows.h>
#include <math.h> 
#include<cstdlib>
#include<ctime>
#include <conio.h>

using namespace std;

const int width = 20;
const int heigh = 20;
int x, y, vockicaX, vockicaY;
bool gameOver;
enum direction {STOP=0, LEFT, RIGHT, UP,DOWN};//sto je stop 0
direction d;

void Setup() {
	//d = STOP;
	gameOver = false;
	x = width / 2;
	y = heigh / 2;
	vockicaX = rand() % width;
	vockicaY = rand() % heigh;
}

void Drawing() {
	system("cls");
	for (size_t i = 0; i < width; i++)
	{
		if (i == 0) {
			cout << "*";
		}
	}
	/*
	for (int i = 0; i < heigh; i++)
	{
		for (int j = 0; j < width; j++) {

			if (j == 0) {
				cout << "*";
			}

			else if (j== width -1 ) {
				cout << "*";
			}
			else if ( i == y && j == x) {
				cout << "O";
			
			}else  if ( i == vockicaY && j == vockicaX ) {
				cout << "F";
			}
			else cout << " ";			
		}cout << endl;
	}	*/

	for (size_t i = 0; i < width; i++)
	{
	 if (i == width - 1) {
		cout << "*";
		}

	}
}


void Input() {
	if (_kbhit) {
		switch (_getch())
		{
		case 'w':
			d = UP;
			break;
		case 's':
			d = DOWN;
			break;
		case 'a':
			d = LEFT;
			break;
		case 'd':
			d = RIGHT;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}

}

void Logic() {
	switch (d)
	{
	
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	if (x < 0 || x > width-1 || y <0 || y > heigh-1)
	{
		gameOver = true;
	}
	if (x == vockicaX && y == vockicaX)
	{
		vockicaX = rand() % width;
		vockicaY = rand() % heigh;
	}

}
int main() {
	Setup();

	while (!gameOver)
	{
		Drawing();
		Input();
		Logic();

		cout << vockicaX << ';' << vockicaY;
		Sleep(100);

	}	
	
	//system("pause");
	return 0;
}

