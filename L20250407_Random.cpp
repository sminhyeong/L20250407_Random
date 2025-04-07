// L20250407_Random.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>

int main()
{
	bool IsComplete = false;
	int idx = 0;
	int MaxCount = 10000;
	int Balls[10000] = { 0, };

	srand(time(NULL));

	time_t StartTime = time(NULL);

	while (!IsComplete)
	{
		int Num = rand()%MaxCount + 1;
		bool Duplecate = false;

		for (int i = 0; i < idx+1; i++)
		{
			if (Num == Balls[i])
			{
				Duplecate = true;
				break;
			}
		}

		if (!Duplecate)
		{
			Balls[idx] = Num;
			idx++;

			if (idx >= MaxCount)
			{
				IsComplete = true;
			}
		}
	}
	time_t EndTime = time(NULL);
	double DebugTime = (double)(EndTime - StartTime);
	printf("DebugTime : %f\n", DebugTime);
	/*printf("Boal Number : ");
	for (int i : Balls)
	{
		printf("%d, ", i);
	}*/
	return 0;
}
