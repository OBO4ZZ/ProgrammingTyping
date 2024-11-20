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


//타자연습
int iCharacterPerMinute = 0;//알파벳를 입력한 수
string PlayerInput;//사용자 입력을 저장
double Accuracy = 0;//전체 정확도

void WordTraining_Start(int QuestionNum, double BeforeAccuracy)//Tcount = 몇번째 문제인지, previous_dAccuracy = 이전문제 정확도
{
	PrintButton(1);//ui출력
	gotoxy(1, 1);
	cout << QuestionNum << "번째 단어";//몇번째 단어인지 출력
	if (QuestionNum != 1)//첫번째는 이전 정확도랑 평균 정확도를 출력할 수 없기에 뺴줌
	{
		gotoxy(1, 2);
		cout << QuestionNum - 1 << "번 문제 정확도:" << (int)BeforeAccuracy << "%";//이전문제 정확도
		gotoxy(1, 3);;
		cout << "평균 정확도:" <<(int) (Accuracy / (QuestionNum - 1)) << "%";//평균 정확도
	}

	BeforeAccuracy = 0;
	RANDOM(1, 41);//랜덤한 단어 생성
	gotoxy(53 - (rast / 2), 14);//중앙 맞춰서 답을 출력해줄 좌표로 이동

	for (int j = 0; j < rast; j++)
	{
		cout << cWords[random][j];//답 출력
	}

	gotoxy(53 - (rast / 2), 16);
	cin >> PlayerInput;//사용자 입력

	for (int j = 0; j < PlayerInput.length(); j++)//정답과 사용자 입력을 비교하는 반복문
	{
		if (PlayerInput[j] == cWords[random][j])//만약 정답과 사용자 입력이 같으면
		{
			BeforeAccuracy += 100;//정확도에 100더함
			iCharacterPerMinute++;//맞는 입력을 했으니 카운트해줌
		}
	}

	//판단
	Accuracy += BeforeAccuracy / rast;//전체 정확도에 정확도를 더해줌
	if (QuestionNum == 20 || esc == true)//재귀함수를 종료해주는 조건문. 사용자가 20개의 단어를 치면 끝남
	{
		cin.ignore(1000, '\n');//입력 버퍼 지워주기
		system("cls");//콘솔 초기화
		return;
	}

	cin.ignore(1000, '\n');//다음 단어 입력에 문제가 가지 않도록 입력 버퍼 지워주기
	system("cls");
	WordTraining_Start(QuestionNum + 1, BeforeAccuracy / rast);//재귀가 작동하도록 +1해서 함수 호출
	return;
}//타자 연습 시작하는 함수(로직)
int WordTraining_Result()//타자연습 결과, restart할건지 결정하는 함수
{
	int x = 45;
	int TypingScore = (int)((double)iCharacterPerMinute / Timer * 60);
	PrintButton(1);

	gotoxy(42, 15);
	cout << "_";
	//gotoxy(45, 11);
	//cout << "최고 기록: " << "" << "타";
	gotoxy(45, 12);
	cout << "현재 기록: " << TypingScore << "타";
	gotoxy(46, 13);
	cout << "정확도 :" << (int)(Accuracy / 20) << "%";//전체 정확도 출력
	gotoxy(45, 14);
	cout << "걸린 시간 :" << (int)Timer << "초";//걸린 시간 출력
	gotoxy(42, 17);
	cout << "다시 시작하시겠습니까?";

	for (;;)//네 아니오중에 결정할때까지 반복하는 함수
	{
		if (x == 45)
		{
			gotoxy(52, 19);
			cout << "  아니오";
			gotoxy(44, 19);
			ChangeColor(YELLOW);
			cout << "> 네";
			ChangeColor(WHITE);

			gotoxy(44, 19);
			switch (_getch())
			{
			case 77: x += 8;
				break;
			case 13:system("cls");
				return 1;//네를 고르면 true를 반환-> restart변수에 값 반환됨
			}
		}

		else if (x == 53)
		{
			gotoxy(44, 19);
			cout << "  네";
			gotoxy(52, 19);
			ChangeColor(YELLOW);
			cout << "> 아니오";
			gotoxy(52, 19);
			ChangeColor(WHITE);
			switch (_getch())
			{
			case 75: x -= 8;
				break;
			case 13:
				system("cls");
				return 0;//아니오를 고르면 false를 반환-> restart변수에 값 반환됨
			}
		}
	}

}



//긴글 타자연습
string WritingList[100] = { "\nbool isPrime(int num) {\n   if (num <= 1) return false;\n    for (int i = 2; i * i <= num; i++) {\n        if (num % i == 0) return false;\n    }\n    return true;\n}\n",
"\n#include <iostream>\n#include <string>\nint countDifferences(const std::string& str1, const std::string& str2) {\n    int length = std::min(str1.length(), str2.length());\n    int diffCount = 0;\n",
"\n#include <iostream>\nint main() {\n    int sum = 0;\n    for (int i = 1; i <= 10; ++i) sum += i;\n    std::cout << \"1부터 10까지의 합 : \" << sum << std::endl;\n    return 0;\n}\n",
"\n#include <iostream>\nint main() {\n    int a = 5, b = 10;\n    std::cout << \"합: \" << a + b;\n    return 0;\n}\n",
"\n#include <iostream>\nint main() {\n    int n = 10, sum = 0;\n    for (int i = 1; i <= n; ++i) sum += i;\n    std::cout << \"합: \" << sum;\n    return 0;\n}\n",
"\n#include <iostream>\nint main() {\n    int n = 4;\n    if (n % 2 == 0) std::cout << \"짝수\";\n    return 0;\n}\n",
"\n#include <iostream>\nint main() {\n    std::cout << \"Hello, World!\";\n    return 0;\n}\n",
"\n#include <iostream>\nint main() {\n    int n = 5, fact = 1;\n    for (int i = 1; i <= n; ++i) fact *= i;\n    std::cout << \"팩토리얼: \" << fact;\n    return 0;\n}\n",
"\n#include <iostream>\nint main() {\n    int arr[] = {1, 3, 5, 2, 4};\n    int max = arr[0];\n    for (int i = 1; i < 5; ++i) if (arr[i] > max) max = arr[i];\n    std::cout << \"최대값: \" << max;\n    return 0;\n}\n",
"\n#include <iostream>\n#include <string>\nint main() {\n    std::string str = \"안녕하세요\";\n    std::cout << \"길이: \" << str.length();\n    return 0;\n}\n",
"\n#include <iostream>\nint main() {\n    int n = 7, isPrime = 1;\n    for (int i = 2; i <= n/2; ++i) if (n % i == 0) isPrime = 0;\n    std::cout << (isPrime ? \"소수\" : \"소수가 아님\");\n    return 0;\n}\n",
"\n#include <iostream>\nint main() {\n    for (int i = 1; i <= 9; ++i) std::cout << \"2 x \" << i << \" = \" << 2 * i << \"\n\";\n    return 0;\n}\n",
"\n#include <iostream>\n#include <string>\nint main() {\n    std::string str = \"안녕하세요\";\n    std::reverse(str.begin(), str.end());\n    std::cout << str;\n    return 0;\n}\n"
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
	cout << "오타 : " << AllTerreorCount << "     이전문제 정확도 : " << (int)BeforeAccuracy << "%     평균 정확도 : ";
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
	cout << "오타수 : " << AllTerreorCount << "\n";
	gotoxy(47, 12);
	cout << "타수 : " << (int)((double)InputCount / Timer * 60) << "타\n";
	gotoxy(46, 13);
	cout << "정확도 : " << (NumberLetters - AllTerreorCount) * 100 / NumberLetters << "%\n";
	gotoxy(45, 14);
	cout << "걸린 시간 :" << (int)Timer << "초";//걸린 시간 출력
	gotoxy(42, 17);
	cout << "다시 시작하시겠습니까?";
	int x = 45;
	for (;;)//네 아니오중에 결정할때까지 반복하는 함수
	{
		if (x == 45)
		{
			gotoxy(52, 19);
			cout << "  아니오";
			gotoxy(44, 19);
			ChangeColor(YELLOW);
			cout << "> 네";
			ChangeColor(WHITE);

			gotoxy(44, 19);
			switch (_getch())
			{
			case 77: x += 8;
				break;
			case 13:system("cls");
				return 1;//네를 고르면 true를 반환-> restart변수에 값 반환됨
			}
		}

		else if (x == 53)
		{
			gotoxy(44, 19);
			cout << "  네";
			gotoxy(52, 19);
			ChangeColor(YELLOW);
			cout << "> 아니오";
			gotoxy(52, 19);
			ChangeColor(WHITE);
			switch (_getch())
			{
			case 75: x -= 8;
				break;
			case 13:
				system("cls");
				return 0;//아니오를 고르면 false를 반환-> restart변수에 값 반환됨
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
		if (y == 13)//단어
		{
			gotoxy(47, 16);
			cout << "  짧은 글 연습";
			gotoxy(43, 19);
			cout << "  메인 메뉴로  돌아가기";
			ChangeColor(YELLOW);
			gotoxy(47, 13);
			cout << " > 단어 연습";
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
				while (restart)//재시작 반복문
				{
					CursorView(1);
					Accuracy = 0;//전체 정확도 초기화
					system("cls");
					TimeStart = time(NULL);//시작하는 시간 저장
					iCharacterPerMinute = 0;//타수 초기화
					WordTraining_Start(1, 0);//타자 연습 시작
					TimeFinish = time(NULL);//끝나는 시간 저장
					Timer = (double)TimeFinish - (double)TimeStart;//끝나는 시간에서 시작하는 시간을 빼줘서 몇초간 플레이했는지 저장
					CursorView(0);
					restart = WordTraining_Result();//재시작 변수에 연습 결과 호출, 재시작할건지 아닌지 값을 반환해줌
					PrintButton(0);
				}
				break;
			}
		}
		if (y == 16)
		{
			gotoxy(47, 13);
			cout <<"   단어 연습";
			gotoxy(43, 19);
			cout << "  메인 메뉴로  돌아가기";
			ChangeColor(YELLOW);
			gotoxy(47, 16);
			cout << "> 짧은 글 연습";
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
		if (y == 19)//메뉴로 돌아가기
		{
			gotoxy(47, 13);
			cout << "   단어 연습";
			gotoxy(47, 16);
			cout << "  짧은 글 연습";
			gotoxy(43, 19);
			ChangeColor(YELLOW);
			cout << "> 메인 메뉴로  돌아가기";
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