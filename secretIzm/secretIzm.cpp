//// secretIzm.cpp: определяет точку входа для консольного приложения.
//
//#include "stdafx.h"
//#include <iostream>
//#include <string>
//#include <windows.h>
//#include <fstream>
//#include <ctime>
//#include <cstdlib>
//#include <conio.h>
//#include <vector>
//
//using namespace std;
//
//
//int main()
//{
//	vector<int>viktor = { 1,3,5,3,2,4,2,1,2,3 };
//	int massa[10][10];
//	srand(time(0));
//
//
//
//	for (int i = 0; i < 10; i++)
//	{
//
//		for (int g = 0; g < 10; g++)
//		{
//			massa[i][g] = 0;
//		}
//	}
//	while (true)
//	{
//		system("cls");
//		massa[rand() % 10][rand() % 10] = rand() % 2;
//		for (int i = 0; i < 10; i++)
//		{
//
//			for (int g = 0; g < 10; g++)
//			{
//				if (massa[i][g] == 0)
//				{
//					cout << ".";
//				}
//				else if (massa[i][g] == 1)
//				{
//					cout << "C";
//				}
//
//			}
//			cout << endl;
//		}
//		Sleep(200);
//	}
//	//viktor.resize(100);
//	//cout<<viktor.size() << endl;
//	//cout << viktor[9] << endl;
//
//	/*for (int i = 0; i < 10; i++)
//	{
//	int x;
//	cin >> x;
//	viktor.push_back(x);
//	}*/
//	/*auto iterat = viktor.begin();
//	viktor.insert(iterat + 2,676);
//	for (auto element : viktor) {
//	cout << element << endl;
//	}
//	*/
//	system("pause");
//	return 0;
//}


//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <vector>
using namespace std;
char key;
string symba = "";
string oldkey= "R";
vector<int>xmove = { 0 };
vector<int>ymove = { 0 };
vector<int>xmove1 = { 0 };
vector<int>ymove1 = { 0 };
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


int xtasty ;
int ytasty ;
int score = 3;
int score2 = 3;


int botscore;
void Bot() {
	for (int t = score2 - 1; t > 0; t--)
	{
		xmove1[t] = xmove1[t - 1];
		ymove1[t] = ymove1[t - 1];

	}
	if (xmove1[0]!=xtasty || ymove1[0]!=ytasty)
	{
		if (ymove1[0]!=ytasty)
		{
			if (ymove1[0]<ytasty)
			{
				ymove1[0]++;
			}
			else
			{
				ymove1[0]--;
			}
			
		}
		else if (xmove1[0] != xtasty)
		{
			if (xmove1[0]<xtasty)
			{
				xmove1[0]++;
			}
			else
			{
				xmove1[0]--;
			}
			
			
		}
	}
	if (xmove1[0] > 29)
	{
		xmove1[0] = 0;
	}
	if (ymove1[0] > 19)
	{
		ymove1[0] = 0;
	}
	if (xmove1[0] < 0)
	{
		xmove1[0] = 29;
	}
	if (ymove1[0] < 0)
	{
		ymove1[0] = 19;
	}

}

void gameOverBot1() {
	xmove1.resize(score2);
	ymove1.resize(score2);
	for (int c = 0; c < score2; c++)
	{
		if (xmove[0] == xmove1[c] && ymove[0] == ymove1[c])
		{
			cout << "Bot killed and he respawned with basic score"<<endl;
			score = score2/ 2 + score;
			score2 = score2/2;
			xmove.resize(score);

			ymove.resize(score);
			xmove1.resize(score2);

			ymove1.resize(score2);
		}
		
	}
}
void erasecout() {
	system("cls");
	cout << "You collected ";
	cout << score - 3;
	cout << " Macdos" << endl;
	cout << "you re enemy ";
	cout << score2 - 3;
	cout << " Macdos";
	cout << endl;
}
void tastyFood() {

	if (xtasty == xmove1[0] && ytasty == ymove1[0])
	{
		score2++;
		xmove1.resize(score2);

		ymove1.resize(score2);

		xtasty = rand() % 25 + 1;

		ytasty = rand() % 15 + 1;
		if (xtasty < 0)
		{
			xtasty++;

		}
		if (xtasty > 29)
		{
			xtasty--;
		}
		if (ytasty < 0)
		{
			ytasty++;
		}
		if (ytasty > 29)
		{
			ytasty--;
		}
	}
	 if (xtasty == xmove[0] && ytasty == ymove[0])
	{
		score++;
		xmove.resize(score);

		ymove.resize(score);
		xtasty = rand() % 25 + 1;

		ytasty = rand() % 15 + 1;
		if (xtasty < 0)
		{
			xtasty++;

		}
		if (xtasty > 29)
		{
			xtasty--;
		}
		if (ytasty < 0)
		{
			ytasty++;
		}
		if (ytasty > 29)
		{
			ytasty--;
		}
	}
	 else if (ymove[0] != ytasty || xmove[0] != xtasty)
	{
		xtasty = xtasty;

		ytasty = ytasty;

	}

	 
		
	
	
	
	
	

	//return ymove, xmove, xtasty, ytasty;
}
void draw() {
	erasecout();
	for (int y = 0; y < 20; y++)
	{

		cout << endl;
		for (int x = 0; x < 30; x++)
		{

			// what to draw????? 
			SetConsoleTextAttribute(hConsole, (WORD) 2);
			symba = ".";

			
				
			
				for (int l = 0; l < score2; l++)
				{
				 if (y == ymove1[l] && x == xmove1[l])
				{
					 if (y==ymove1[0] && x==xmove1[0])
					 {


						 SetConsoleTextAttribute(hConsole, (WORD)12);

						 symba = "O";
					 }
					 else {
						 SetConsoleTextAttribute(hConsole, (WORD)13);

						 symba = "O";
					 }
				}
				}
				for (int k = 0; k < score; k++)
				{

					if (y == ymove[k] && x == xmove[k])
					{
						if (y == ymove[0] && x == xmove[0])
						{


							SetConsoleTextAttribute(hConsole, (WORD)14);

							symba = "O";
						}
						else {
							SetConsoleTextAttribute(hConsole, (WORD)10);

							symba = "O";
						}
					}


				}

			
			if (y == ytasty && x == xtasty)
			{
				SetConsoleTextAttribute(hConsole, (WORD) 7);
				symba = "M";
			}

			cout << symba;
		}
	}
}
void makeMove(){
	
	for (int t = score - 1; t > 0; t--)
	{
		xmove[t] = xmove[t - 1];
		ymove[t] = ymove[t - 1];

	}
	if (GetAsyncKeyState(VK_UP))
	{	
		ymove[0]--;	
	oldkey = "U";
	Sleep(1);
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		ymove[0]++;
		oldkey  = "D";
		Sleep(1);
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		xmove[0]--;
		oldkey = "L";
		Sleep(1);
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		xmove[0]++;
		oldkey = "R";
		Sleep(1);
	}
	else if(oldkey=="R")
	{
		xmove[0]++;
		Sleep(1);
	}
	else if (oldkey=="L")
	{
		xmove[0]--;
		Sleep(1);
	}
	else if (oldkey=="U")
	{
		ymove[0]--;
		Sleep(1);
	}
	else if (oldkey=="D")
	{
		ymove[0]++;
		Sleep(1);
	}

/*else
{
ymove[0] = ymove[0];
}*/
if (xmove[0] > 29)
{
	xmove[0]=0;
}
if (ymove[0] > 19)
{
	ymove[0]=0;
}
if (xmove[0] < 0)
{
	xmove[0]=29;
}
if (ymove[0] < 0)
{
	ymove[0]=19;
}

}


//int main()
//{
//	bool exit = false;
//
//	while (exit == false)
//	{
//		if (GetAsyncKeyState(VK_ESCAPE))
//		{
//			exit = true;
//		}
//		Sleep(500);
//		cout << "press esc to exit! " << endl;
//	}
//
//	cout << "exited: " << endl;
//
//	return 0;
//}
//
int main() {
	srand(static_cast<unsigned int>(time(NULL)));
	
	system("Color A");  // first 0 = black background second A = light green

	ymove1[0] = 7;
	xmove1[0] = 7;
	xmove.resize(score);

	ymove.resize(score);
	xmove1.resize(score2);

	ymove1.resize(score2);
	
	int board[20][30];
	cout << "IN this game you will need to collect Macdos!" << endl << endl;
	string snake = "O";
	string food = "M";
	for (int y = 0; y < 20; y++)
	{

		for (int x = 0; x < 30; x++)
		{
			board[y][x] = 0;
		}
	}
	while (true)
	{
		
		tastyFood();
		draw();
		makeMove();
		Bot();
		
		//gameOverBot1();
		
		Sleep(100);
	}


	return 0;
}


/*

	Подготовительные работы
	Основной цикл
		Получить ввод с клавиатуры (без блокировки)
		Вычислить новое положение змейки
			Завершить игру если проигрыш
		Проверить поедание М
			Изменить змейку если нужно
			Добавить новое М если нужно
		Перерисовать поле
	Повтор

*/