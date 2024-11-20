#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <random>
#include <time.h>
#include <chrono>
#include <cctype>
#include <thread>
#include <fstream>
#include <sstream>
using namespace std;

bool bCheck = true;
void CursorView(bool bJudgment)//Ŀ���� ���̰��ϰų� ����� �ϴ� �Լ�
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = (bJudgment == true ? 1 : 0);
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
enum //��� ��
{
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DAKR_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};
void ChangeColor(unsigned short text) //��� �� �ٲ��ִ� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}
void gotoxy(int x, int y)//��ǥ �̵� �Լ�
{
	COORD posXY = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posXY);
}
void PrintButton(bool line)//UI�� ������ִ� �Լ�, bool line�� �߰��� ���� ������� ����
{
	gotoxy(0, 0);
	cout << "__________________________________________________________________________________________________________";
	for (int i = 1; i < 30; i++)
	{
		gotoxy(105, i);
		cout << "|";
		gotoxy(0, i);
		cout << "|";
	}
	cout << "________________________________________________________________________________________________________|";
	gotoxy(47, 15);
	if (line == true)
	{
		gotoxy(43, 15);
		cout << "_____________________";
	}
}
char cWords[42][10] = {//�ܾ����
{'i','n','c','l','u','d','e','0','0','7'},
{'s','t','r','i','n','g','0','0','0','6'},
{'v','e','c','t','o','r','0','0','0','6'},
{'c','o','n','s','t','0','0','0','0','5'},
{'i','o','s','t','r','e','a','m','0','8'},
{'w','h','i','l','e','0','0','0','0','5'},
{'d','o','u','b','l','e','0','0','0','6'},
{'r','a','n','d','o','m','0','0','0','6'},
{'n','a','m','e','s','p','a','c','e','9'},
{'o','v','e','r','w','a','t','c','h','9'},
{'p','r','e','c','i','s','i','o','n','9'} ,
{'f','i','x','e','d','0','0','0','0','5'} ,
{'c','h','a','r','0','0','0','0','0','4'} ,
{'i','n','t','0','0','0','0','0','0','3'} ,
{'l','o','n','g','0','0','0','0','0','4'} ,
{'s','o','r','c','e','0','0','0','0','5'} ,
{'c','o','u','t','0','0','0','0','0','4'} ,
{'c','i','n','0','0','0','0','0','0','3'} ,
{'v','o','i','d','0','0','0','0','0','4'} ,
{'t','r','u','e','0','0','0','0','0','4'} ,
{'f','a','l','s','e','0','0','0','0','5'} ,
{'e','n','d','l','0','0','0','0','0','4'} ,
{'m','a','i','n','0','0','0','0','0','4'} ,
{'e','l','s','e','0','0','0','0','0','4'} ,
{'w','i','n','d','o','w','s','0','0','7'} ,
{'s','w','i','t','c','h','0','0','0','6'} ,
{'b','o','o','l','0','0','0','0','0','4'} ,
{'c','a','s','e','0','0','0','0','0','4'} ,
{'N','U','L','L','0','0','0','0','0','4'},
{'d','e','f','i','n','e','0','0','0','6'},
{'f','l','o','a','t','0','0','0','0','5'},
{'r','a','n','d','0','0','0','0','0','4'},
{'c','o','n','t','i','n','u','e','0','8'},
{'i','g','n','o','r','e','0','0','0','6'},
{'s','o','r','t','0','0','0','0','0','4'},
{'u','s','i','n','g','0','0','0','0','5'},
{'s','t','d','0','0','0','0','0','0','3'},
{'g','o','t','o','x','y','0','0','0','6'},
{'b','r','e','a','k','0','0','0','0','5'},
{'r','e','t','u','r','n','0','0','0','6'},
{'u','n','s','i','g','n','e','d','0','8'},
{'l','e','n','g','t','h','0','0','0','6'}
};
int rast;//���� �ܾ��� ���ڼ�
int random;//�������� �������ִ� ����

time_t TimeStart, TimeFinish;//�����ϴ� �ð�, ������ �ð�
double Timer;//�ɸ� �ð�

char change;//Cpp_word[][9]�� �ִ� �ܾ��� ���ڼ��� �ƽ�Ű�ڵ�� ��µ��� �ʰ� �ٲ��ֱ� ���� �����ϴ� ����
bool esc = false;
bool restart;
void RANDOM(bool Word, int i)//random �Լ��� �������� �������ְ�, �ش� ���� �ܾ��� ���ڼ� ����
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(0, i);
	random = dist(gen);
	if (Word == true)
	{
		change = cWords[random][9];
		rast = change - '0';
	}
}

