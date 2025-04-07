// L20250407_Random.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>

int main()
{
	int MaxCount = 52;
	int Balls[52] = { 0, };

	for (int i = 0; i < MaxCount; i++)
	{
		Balls[i] = (i + 1);
	}

	time_t StartTime = time(NULL);
	srand((unsigned int)time(NULL));

	//¼ÅÇÃ
	int temp = 0;
	for (int count = 0; count < MaxCount * 1000; count++)
	{
		int Idx1 = rand() % MaxCount;
		int Idx2 = rand() % MaxCount;

		temp = Balls[Idx1];
		Balls[Idx1] = Balls[Idx2];
		Balls[Idx2] = temp;
	}

	time_t EndTime = time(NULL);
	double DebugTime = (double)(EndTime - StartTime);
	printf("DebugTime : %f\n", DebugTime);

	//Ãâ·Â
	printf("Boal Number : ");
	for (int i : Balls)
	{
		printf("%d, ", i);
	}
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
