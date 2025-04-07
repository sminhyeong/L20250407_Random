// L20250407_Random.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>

#define POCKET_SIZE 52

int Deck[POCKET_SIZE] = { 0, };
using namespace std;
void Initialize()
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < POCKET_SIZE; i++)
	{
		Deck[i] = i;
	}
}

void Suffle()
{
	//¼ÅÇÃ
	int Temp = 0;
	for (int count = 0; count < 1000; count++)
	{
		int Idx1 = rand() % POCKET_SIZE;
		int Idx2 = rand() % POCKET_SIZE;

		Temp = Deck[Idx1];
		Deck[Idx1] = Deck[Idx2];
		Deck[Idx2] = Temp;
	}

}
void NumToCharCardType(int Num)
{
	switch (Num)
	{
	case 0:
		cout << "¢¼";
		break;
	case 1:
		cout << "¡ß";
		break;
	case 2:
		cout << "¢¾";
		break;
	case 3:
		cout << "¢À";
		break;
	}
}
void IntToCard(int Number)
{
	char CharValue = '\0';
	if (Number == 1)
	{
		cout << 'A';
	}
	else if (Number == 11)
	{
		cout << 'J';
	}
	else if (Number == 12)
	{
		cout << 'Q';
	}
	else if (Number == 13)
	{
		cout << 'K';
	}
	else
	{
		cout << Number;
	}
}

int Bigger(int First, int Second)
{
	if (First > Second)
	{
		return 1;
	}
	else if (First == Second)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void GameResult(int AiNumber, int PlayerNumber)
{
	if (Bigger(21, AiNumber)<0)
	{
		printf("Player Victory");
	}
	if (Bigger(21, PlayerNumber)<0)
	{
		printf("Ai Victory");
	}
	else
	{
		if (Bigger(AiNumber, PlayerNumber) == 1)
		{
			printf("Ai Victory");
		}
		else if (Bigger(AiNumber, PlayerNumber) == 0)
		{
			printf("Draw");
		}
		else
		{
			printf("Player Victory");
		}

	}
}

int AddScore(int Number1, int Number2)
{
	return (Number1 > 10 ? 10 : Number1) + (Number2 > 10 ? 10 : Number2);
}
void Print()
{
	//Computer
	int Number1 = (Deck[0] % 13 + 1);
	int Number2 = (Deck[1] % 13 + 1);

	int AiTotalPoint = AddScore(Number1, Number2);

	NumToCharCardType(Deck[0] / 13);
	IntToCard(Number1);
	cout << endl;
	NumToCharCardType(Deck[1] / 13);
	IntToCard(Number2);
	cout << endl;
	
	cout << "===============\n";

	//Player
	Number1 = (Deck[2] % 13 + 1);
	Number2 = (Deck[3] % 13 + 1);
	int PlayerTotalPoint = AddScore(Number1, Number2);
	NumToCharCardType(Deck[2] / 13);
	IntToCard(Number1);
	cout << endl;
	NumToCharCardType(Deck[3] / 13);
	IntToCard(Number2);
	cout << endl << endl;

	GameResult(AiTotalPoint, PlayerTotalPoint);
}

int main()
{
	string Message = "¾È³çÇÏ¼¼¿ä.";
	Message += "È«±æµ¿´Ô";
	cout << Message;

	cout << Message.length() << "\t" << sizeof(Message) << "\t" << strlen(Message.c_str()) << "\t" << sizeof(Message.c_str())<< Message.c_str();

	/*Initialize();
	time_t StartTime = time(NULL);
	Suffle();
	time_t EndTime = time(NULL);
	double DebugTime = (double)(EndTime - StartTime);
	printf("DebugTime : %f\n", DebugTime);
	Print();*/

	//Ãâ·Â
	return 0;
}

//int main()
//{
//	int ValueIdx = 0;
//	int MaxCount = 52;
//	int Balls[52] = { 0, };
//	int ValueBalls[52] = { 0, };
//
//	for (int i = 0; i < MaxCount; i++)
//	{
//		Balls[i] = (i + 1);
//	}
//
//	time_t StartTime = time(NULL);
//	srand((unsigned int)time(NULL));
//
//	while (MaxCount > 0)
//	{
//		int idx = rand() % MaxCount;
//
//		ValueBalls[ValueIdx] = Balls[idx];
//		for (int i = idx; i < MaxCount-1; i++)
//		{
//			Balls[i] = Balls[i + 1];
//		}
//
//		ValueIdx++;
//		MaxCount--;
//	}
//
//	time_t EndTime = time(NULL);
//	double DebugTime = (double)(EndTime - StartTime);
//	printf("DebugTime : %f\n", DebugTime);
//	printf("Boal Number : ");
//	for (int i : ValueBalls)
//	{
//		printf("%d, ", i);
//	}
//	return 0;
//}
