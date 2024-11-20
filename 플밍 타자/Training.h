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
#include "all.h"


//Ÿ�ڿ���
int iCharacterPerMinute = 0;//���ĺ��� �Է��� ��
string PlayerInput;//����� �Է��� ����
double Accuracy = 0;//��ü ��Ȯ��

void WordTraining_Start(int QuestionNum, double BeforeAccuracy)//Tcount = ���° ��������, previous_dAccuracy = �������� ��Ȯ��
{
	PrintButton(1);//ui���
	gotoxy(1, 1);
	cout << QuestionNum << "��° �ܾ�";//���° �ܾ����� ���
	if (QuestionNum != 1)//ù��°�� ���� ��Ȯ���� ��� ��Ȯ���� ����� �� ���⿡ ����
	{
		gotoxy(1, 2);
		cout << QuestionNum - 1 << "�� ���� ��Ȯ��:" << (int)BeforeAccuracy << "%";//�������� ��Ȯ��
		gotoxy(1, 3);;
		cout << "��� ��Ȯ��:" <<(int) (Accuracy / (QuestionNum - 1)) << "%";//��� ��Ȯ��
	}

	BeforeAccuracy = 0;
	RANDOM(1, 41);//������ �ܾ� ����
	gotoxy(53 - (rast / 2), 14);//�߾� ���缭 ���� ������� ��ǥ�� �̵�

	for (int j = 0; j < rast; j++)
	{
		cout << cWords[random][j];//�� ���
	}

	gotoxy(53 - (rast / 2), 16);
	cin >> PlayerInput;//����� �Է�

	for (int j = 0; j < PlayerInput.length(); j++)//����� ����� �Է��� ���ϴ� �ݺ���
	{
		if (PlayerInput[j] == cWords[random][j])//���� ����� ����� �Է��� ������
		{
			BeforeAccuracy += 100;//��Ȯ���� 100����
			iCharacterPerMinute++;//�´� �Է��� ������ ī��Ʈ����
		}
	}

	//�Ǵ�
	Accuracy += BeforeAccuracy / rast;//��ü ��Ȯ���� ��Ȯ���� ������
	if (QuestionNum == 20 || esc == true)//����Լ��� �������ִ� ���ǹ�. ����ڰ� 20���� �ܾ ġ�� ����
	{
		cin.ignore(1000, '\n');//�Է� ���� �����ֱ�
		system("cls");//�ܼ� �ʱ�ȭ
		return;
	}

	cin.ignore(1000, '\n');//���� �ܾ� �Է¿� ������ ���� �ʵ��� �Է� ���� �����ֱ�
	system("cls");
	WordTraining_Start(QuestionNum + 1, BeforeAccuracy / rast);//��Ͱ� �۵��ϵ��� +1�ؼ� �Լ� ȣ��
	return;
}//Ÿ�� ���� �����ϴ� �Լ�(����)
int WordTraining_Result()//Ÿ�ڿ��� ���, restart�Ұ��� �����ϴ� �Լ�
{
	int x = 45;
	int TypingScore = (int)((double)iCharacterPerMinute / Timer * 60);
	PrintButton(1);

	gotoxy(42, 15);
	cout << "_";
	//gotoxy(45, 11);
	//cout << "�ְ� ���: " << "" << "Ÿ";
	gotoxy(45, 12);
	cout << "���� ���: " << TypingScore << "Ÿ";
	gotoxy(46, 13);
	cout << "��Ȯ�� :" << (int)(Accuracy / 20) << "%";//��ü ��Ȯ�� ���
	gotoxy(45, 14);
	cout << "�ɸ� �ð� :" << (int)Timer << "��";//�ɸ� �ð� ���
	gotoxy(42, 17);
	cout << "�ٽ� �����Ͻðڽ��ϱ�?";

	for (;;)//�� �ƴϿ��߿� �����Ҷ����� �ݺ��ϴ� �Լ�
	{
		if (x == 45)
		{
			gotoxy(52, 19);
			cout << "  �ƴϿ�";
			gotoxy(44, 19);
			ChangeColor(YELLOW);
			cout << "> ��";
			ChangeColor(WHITE);

			gotoxy(44, 19);
			switch (_getch())
			{
			case 77: x += 8;
				break;
			case 13:system("cls");
				return 1;//�׸� ���� true�� ��ȯ-> restart������ �� ��ȯ��
			}
		}

		else if (x == 53)
		{
			gotoxy(44, 19);
			cout << "  ��";
			gotoxy(52, 19);
			ChangeColor(YELLOW);
			cout << "> �ƴϿ�";
			gotoxy(52, 19);
			ChangeColor(WHITE);
			switch (_getch())
			{
			case 75: x -= 8;
				break;
			case 13:
				system("cls");
				return 0;//�ƴϿ��� ���� false�� ��ȯ-> restart������ �� ��ȯ��
			}
		}
	}

}



//��� Ÿ�ڿ���
string WritingList[100] = { "\nbool isPrime(int num) {\n   if (num <= 1) return false;\n    for (int i = 2; i * i <= num; i++) {\n        if (num % i == 0) return false;\n    }\n    return true;\n}\n",
"\n#include <iostream>\n#include <string>\nint countDifferences(const std::string& str1, const std::string& str2) {\n    int length = std::min(str1.length(), str2.length());\n    int diffCount = 0;\n",
"\n#include <iostream>\nint main() {\n    int sum = 0;\n    for (int i = 1; i <= 10; ++i) sum += i;\n    std::cout << \"1���� 10������ �� : \" << sum << std::endl;\n    return 0;\n}\n",
"\n#include <iostream>\nint main() {\n    int a = 5, b = 10;\n    std::cout << \"��: \" << a + b;\n    return 0;\n}\n",
"\n#include <iostream>\nint main() {\n    int n = 10, sum = 0;\n    for (int i = 1; i <= n; ++i) sum += i;\n    std::cout << \"��: \" << sum;\n    return 0;\n}\n",
"\n#include <iostream>\nint main() {\n    int n = 4;\n    if (n % 2 == 0) std::cout << \"¦��\";\n    return 0;\n}\n",
"\n#include <iostream>\nint main() {\n    std::cout << \"Hello, World!\";\n    return 0;\n}\n",
"\n#include <iostream>\nint main() {\n    int n = 5, fact = 1;\n    for (int i = 1; i <= n; ++i) fact *= i;\n    std::cout << \"���丮��: \" << fact;\n    return 0;\n}\n",
"\n#include <iostream>\nint main() {\n    int arr[] = {1, 3, 5, 2, 4};\n    int max = arr[0];\n    for (int i = 1; i < 5; ++i) if (arr[i] > max) max = arr[i];\n    std::cout << \"�ִ밪: \" << max;\n    return 0;\n}\n",
"\n#include <iostream>\n#include <string>\nint main() {\n    std::string str = \"�ȳ��ϼ���\";\n    std::cout << \"����: \" << str.length();\n    return 0;\n}\n",
"\n#include <iostream>\nint main() {\n    int n = 7, isPrime = 1;\n    for (int i = 2; i <= n/2; ++i) if (n % i == 0) isPrime = 0;\n    std::cout << (isPrime ? \"�Ҽ�\" : \"�Ҽ��� �ƴ�\");\n    return 0;\n}\n",
"\n#include <iostream>\nint main() {\n    for (int i = 1; i <= 9; ++i) std::cout << \"2 x \" << i << \" = \" << 2 * i << \"\n\";\n    return 0;\n}\n",
"\n#include <iostream>\n#include <string>\nint main() {\n    std::string str = \"�ȳ��ϼ���\";\n    std::reverse(str.begin(), str.end());\n    std::cout << str;\n    return 0;\n}\n"
};
vector <string> AnswerWriting;
int NumberLetters = 0;
int InputCount = 0;
int AllTerreorCount = 0;
int TerreorCount;
void Judgment(string A, string B)
{
	TerreorCount = 0;
	NumberLetters += A.size();
	for (int i = 0; i < A.size(); i++)
	{
		if (B[i] == NULL)
		{
			TerreorCount += A.size() - i;
			break;
		}
		if (A[i] != B[i])TerreorCount++;
	}
}
void WordR()
{
	string WritingReplication = WritingList[random];
	istringstream CutWriting(WritingReplication);
	while (getline(CutWriting, WritingReplication, '\n'))
	{
		AnswerWriting.push_back(WritingReplication);
	}
}
void WritingTraning_UI(int QuestionNum, double BeforeAccuracy)
{
	system("cls");
	gotoxy(1, 1);
	cout << "\x1b[48;5;118m" << "\x1b[38;5;0m";
	for (int i = 0; i <108; i++)cout << " ";
	gotoxy(1, 1);
	for (int i = QuestionNum; i < AnswerWriting.size(); i++)
	{
		if (i != QuestionNum)cout << " ";
		cout << AnswerWriting[i];
		if (i == QuestionNum)
		{
			cout << "\x1b[0m";
			gotoxy(1, 3);
			for (int i = 0; i < 108; i++)cout << "-";
			cout << "\n" << "\x1b[38;5;238m";
		}
		cout << "\n";
	}
	ChangeColor(WHITE);
	int N = 1;
	gotoxy(0, 29);
	cout << "\x1b[48;5;255m" << "\x1b[38;5;124m";
	for (int i = 0; i < 108; i++)cout << " ";
	gotoxy(5, 29);
	cout << "��Ÿ : " << AllTerreorCount << "     �������� ��Ȯ�� : " << (int)BeforeAccuracy << "%     ��� ��Ȯ�� : ";
	if (QuestionNum != 1)cout << (int)(Accuracy / (QuestionNum - 1)) << "%";
	else cout << "N%";

	cout << "\x1b[0m";
	while (AnswerWriting[QuestionNum][0] == ' ')
	{
		AnswerWriting[QuestionNum] = AnswerWriting[QuestionNum].substr(1);
		N++;
	}
	gotoxy(N, 2);
}
void WritingTraining_Start(int QuestionNum, double BeforeAccuracy)
{
	WritingTraning_UI(QuestionNum, BeforeAccuracy);
	getline(cin, PlayerInput);

	if (PlayerInput.size() <= AnswerWriting[QuestionNum].size())InputCount += PlayerInput.size();
	else InputCount += AnswerWriting[QuestionNum].size();

	Judgment(AnswerWriting[QuestionNum], PlayerInput);
	AllTerreorCount += TerreorCount;
	BeforeAccuracy = (AnswerWriting[QuestionNum].size() - TerreorCount) * 100 / AnswerWriting[QuestionNum].size();
	Accuracy += BeforeAccuracy;
	if (QuestionNum != AnswerWriting.size() - 1)WritingTraining_Start(QuestionNum + 1, BeforeAccuracy);
}
int WritingTraining_Result()
{
	system("cls");
	PrintButton(1);
	gotoxy(42, 15);
	cout << "_";
	gotoxy(46, 11);
	cout << "��Ÿ�� : " << AllTerreorCount << "\n";
	gotoxy(47, 12);
	cout << "Ÿ�� : " << (int)((double)InputCount / Timer * 60) << "Ÿ\n";
	gotoxy(46, 13);
	cout << "��Ȯ�� : " << (NumberLetters - AllTerreorCount) * 100 / NumberLetters << "%\n";
	gotoxy(45, 14);
	cout << "�ɸ� �ð� :" << (int)Timer << "��";//�ɸ� �ð� ���
	gotoxy(42, 17);
	cout << "�ٽ� �����Ͻðڽ��ϱ�?";
	int x = 45;
	for (;;)//�� �ƴϿ��߿� �����Ҷ����� �ݺ��ϴ� �Լ�
	{
		if (x == 45)
		{
			gotoxy(52, 19);
			cout << "  �ƴϿ�";
			gotoxy(44, 19);
			ChangeColor(YELLOW);
			cout << "> ��";
			ChangeColor(WHITE);

			gotoxy(44, 19);
			switch (_getch())
			{
			case 77: x += 8;
				break;
			case 13:system("cls");
				return 1;//�׸� ���� true�� ��ȯ-> restart������ �� ��ȯ��
			}
		}

		else if (x == 53)
		{
			gotoxy(44, 19);
			cout << "  ��";
			gotoxy(52, 19);
			ChangeColor(YELLOW);
			cout << "> �ƴϿ�";
			gotoxy(52, 19);
			ChangeColor(WHITE);
			switch (_getch())
			{
			case 75: x -= 8;
				break;
			case 13:
				system("cls");
				return 0;//�ƴϿ��� ���� false�� ��ȯ-> restart������ �� ��ȯ��
			}
		}
	}
}

void TrainingMenu()
{
	system("cls");
	int y = 13;
	PrintButton(0);
	while (true)
	{
		if (y == 13)//�ܾ�
		{
			gotoxy(47, 16);
			cout << "  ª�� �� ����";
			gotoxy(43, 19);
			cout << "  ���� �޴���  ���ư���";
			ChangeColor(YELLOW);
			gotoxy(47, 13);
			cout << " > �ܾ� ����";
			ChangeColor(WHITE);
			switch (_getch())
			{
			case 27: 
				system("cls");
				return;
			case 80: y += 3;
				break;
			case 13:
				restart = true;
				while (restart)//����� �ݺ���
				{
					CursorView(1);
					Accuracy = 0;//��ü ��Ȯ�� �ʱ�ȭ
					system("cls");
					TimeStart = time(NULL);//�����ϴ� �ð� ����
					iCharacterPerMinute = 0;//Ÿ�� �ʱ�ȭ
					WordTraining_Start(1, 0);//Ÿ�� ���� ����
					TimeFinish = time(NULL);//������ �ð� ����
					Timer = (double)TimeFinish - (double)TimeStart;//������ �ð����� �����ϴ� �ð��� ���༭ ���ʰ� �÷����ߴ��� ����
					CursorView(0);
					restart = WordTraining_Result();//����� ������ ���� ��� ȣ��, ������Ұ��� �ƴ��� ���� ��ȯ����
					PrintButton(0);
				}
				break;
			}
		}
		if (y == 16)
		{
			gotoxy(47, 13);
			cout <<"   �ܾ� ����";
			gotoxy(43, 19);
			cout << "  ���� �޴���  ���ư���";
			ChangeColor(YELLOW);
			gotoxy(47, 16);
			cout << "> ª�� �� ����";
			ChangeColor(WHITE);
			switch (_getch())
			{
			case 27:
				system("cls");
				return;
			case 80: y += 3;
				break;
			case 72: y -= 3;
				break;
			case 13:
				restart = true;
				while (restart)
				{
					CursorView(1);
					RANDOM(0, 12);
					WordR();
					TimeStart = time(NULL);
					WritingTraining_Start(1, 0);
					TimeFinish = time(NULL);
					Timer = (double)(TimeFinish - TimeStart);

					restart = WritingTraining_Result();
					AllTerreorCount = 0;
					NumberLetters = 0;
					InputCount = 0;
					AnswerWriting.clear();
					PrintButton(0);
				}
				break;
			}
		}
		if (y == 19)//�޴��� ���ư���
		{
			gotoxy(47, 13);
			cout << "   �ܾ� ����";
			gotoxy(47, 16);
			cout << "  ª�� �� ����";
			gotoxy(43, 19);
			ChangeColor(YELLOW);
			cout << "> ���� �޴���  ���ư���";
			ChangeColor(WHITE);
			gotoxy(43, 20);
			switch (_getch())
			{
			case 72: y -= 3;
				break;
			case 13: 	system("cls");
				return;
			}
		}
	}
}