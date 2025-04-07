// L20250407_Random.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>

int main()
{
	bool IsComplete = false;
	int idx = 0;
	int MaxCount = 52;
	int Boals[52] = { 0, };

	srand(time(NULL));
	
	while (!IsComplete)
	{
		if (idx >= MaxCount)
		{
			break;
		}

		int Num = rand()%MaxCount + 1;
		bool Duplecate = false;

		for (int i = 0; i < idx+1; i++)
		{
			if (Num == Boals[i])
			{
				Duplecate = true;
				break;
			}
		}
		if (!Duplecate)
		{
			Boals[idx] = Num;
			idx++;
		}
	}
	printf("Boal Number : ");
	for (int i : Boals)
	{
		printf("%d, ", i);
	}

}
