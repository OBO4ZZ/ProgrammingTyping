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
	cout.precision(1); //�Ҽ��� ����
	while (true) //���𰡸� �ϰ� ������ ���� ����� UI, �ΰ� �ݺ���
	{
		CursorView(0);
		{//UI, �ΰ����
			gotoxy(0, 0);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << "\n\n\n\n      ����                    �����  ��    ������ ��    ������      ���    ��       ��\n";
			cout << "    ��      ��    ��      ��    ��        ��        ��     ��             ��   ��    ��  ��      ��\n";
			cout << "    ��          ����  ����  �����  ���      ��     ���    ��  �� ��                    ��\n";
			cout << "    ��      ��    ��      ��    ��        ��      ��  ��   ��      ��  ��        ���   ��     \n";
			cout << "      ����                    �����  ��    ��      �� ��   �������    ��   ���    ��\n";
			PrintButton(0);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		int y = 15;
		bCheck = true;
		while (bCheck)//���𰡸� ������ �� ���� �ݺ�
		{
			if (y == 15)//Ÿ�ڿ���
			{
				{
					gotoxy(49, 21);
					cout << "  ����";
					gotoxy(46, 18);
					cout << "  Ÿ��  ����";
					gotoxy(46, 15);
					ChangeColor(YELLOW);
					cout << "> Ÿ��  ����";
					ChangeColor(WHITE);
					gotoxy(46, 15);
				}
				switch (_getch())//Ű���� �� ��ȯ
				{
				case 27: return 0;//esc�� ������ ���α׷� ����
				case 80: y += 3;//�Ʒ� ȭ��ǥ�� ������ �Ʒ� �������� �̵�
					break;
				case 13:restart = true;//enter ����. Ÿ�ڿ��� ����, ����� ���� �ʱ�ȭ
					bCheck = false;
					system("cls");
					TrainingMenu();//���� �κ�� �̵�
					break;
				}
			}
			if (y == 18)//Ÿ�ڰ���
			{
				{
					gotoxy(49, 21);
					cout << "  ����";
					gotoxy(46, 15);
					cout << "  Ÿ��  ����";
					gotoxy(46, 18);
					ChangeColor(YELLOW);
					cout << "> Ÿ��  ����";
					ChangeColor(WHITE);
					gotoxy(46, 18);
				}
				switch (_getch())
				{
				case 27: return 0;// esc�� ������ ���α׷� ����
				case 72: y -= 3;//�� ȭ��ǥ�� ������ �� �������� �̵�
					break;
				case 80: y += 3;//�Ʒ� ȭ��ǥ�� ������ �Ʒ� �������� �̵�
					break;
				case 13://����(����)�� ������
					bCheck = false;
					system("cls");
					GameLobby();//���� �κ�� �̵�
					break;

				}
			}
			if (y == 21)//���α׷� ����
			{
				{
					gotoxy(46, 15);
					cout << "  Ÿ��  ����";
					gotoxy(46, 18);
					cout << "  Ÿ��  ����";
					gotoxy(49, 21);
					ChangeColor(YELLOW);
					cout << "> ����";
					ChangeColor(WHITE);
				}
				gotoxy(49, 21);
				switch (_getch())
				{
				case 27: return 0;//esc�� ������ ���α׷� ����
				case 72: y -= 3;//�� ȭ��ǥ�� ������ �� �������� �̵�
					break;
				case 13: return 0;// ���α׷� ����
				}
			}
		}
	}
}