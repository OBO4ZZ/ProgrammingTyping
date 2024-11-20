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
#include "all.h"
#include "Training.h"
#include "Game.h"
#include <sstream>

int main()
{
	cout.precision(1); //소수점 고정
	while (true) //무언가를 하고 나왔을 떄를 대비해 UI, 로고도 반복문
	{
		CursorView(0);
		{//UI, 로고출력
			gotoxy(0, 0);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << "\n\n\n\n      ■■■                    ■■■■  ■    ■■■■■ ■    ■■■■■      ■■    ■       ■\n";
			cout << "    ■      ■    ■      ■    ■        ■        ■     ■             ■   ■    ■  ■      ■\n";
			cout << "    ■          ■■■  ■■■  ■■■■  ■■      ■     ■■    ■  ■ ■                    ■\n";
			cout << "    ■      ■    ■      ■    ■        ■      ■  ■   ■      ■  ■        ■■   ■     \n";
			cout << "      ■■■                    ■■■■  ■    ■      ■ ■   ■■■■■■    ■   ■■    ■\n";
			PrintButton(0);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		int y = 15;
		bCheck = true;
		while (bCheck)//무언가를 선택할 때 까지 반복
		{
			if (y == 15)//타자연습
			{
				{
					gotoxy(49, 21);
					cout << "  종료";
					gotoxy(46, 18);
					cout << "  타자  게임";
					gotoxy(46, 15);
					ChangeColor(YELLOW);
					cout << "> 타자  연습";
					ChangeColor(WHITE);
					gotoxy(46, 15);
				}
				switch (_getch())//키보드 값 반환
				{
				case 27: return 0;//esc를 누르면 프로그램 종료
				case 80: y += 3;//아래 화살표를 누르면 아래 선택지로 이동
					break;
				case 13:restart = true;//enter 눌림. 타자연습 시작, 재시작 변수 초기화
					bCheck = false;
					system("cls");
					TrainingMenu();//게임 로비로 이동
					break;
				}
			}
			if (y == 18)//타자게임
			{
				{
					gotoxy(49, 21);
					cout << "  종료";
					gotoxy(46, 15);
					cout << "  타자  연습";
					gotoxy(46, 18);
					ChangeColor(YELLOW);
					cout << "> 타자  게임";
					ChangeColor(WHITE);
					gotoxy(46, 18);
				}
				switch (_getch())
				{
				case 27: return 0;// esc를 누르면 프로그램 종료
				case 72: y -= 3;//위 화살표를 누르면 위 선택지로 이동
					break;
				case 80: y += 3;//아래 화살표를 누르면 아래 선택지로 이동
					break;
				case 13://엔터(선택)을 누르면
					bCheck = false;
					system("cls");
					GameLobby();//게임 로비로 이동
					break;

				}
			}
			if (y == 21)//프로그램 종료
			{
				{
					gotoxy(46, 15);
					cout << "  타자  연습";
					gotoxy(46, 18);
					cout << "  타자  게임";
					gotoxy(49, 21);
					ChangeColor(YELLOW);
					cout << "> 종료";
					ChangeColor(WHITE);
				}
				gotoxy(49, 21);
				switch (_getch())
				{
				case 27: return 0;//esc를 누르면 프로그램 종료
				case 72: y -= 3;//위 화살표를 누르면 위 선택지로 이동
					break;
				case 13: return 0;// 프로그램 종료
				}
			}
		}
	}
}