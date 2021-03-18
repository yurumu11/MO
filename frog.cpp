#include <stdio.h>
#include <iostream>
#define E 33

#define N 10

int main()
{
	setlocale(LC_ALL,"Russian");
	int stone[] =  {1, 2, 3, 4, 5, 7, 8, 10, 12, 17, 22, 26, 30, 33};

	int h1 = 0;
	bool tf[E+1];

	for(int i = 1; i <= E; i++) tf[i] = false;
	
	while(stone[h1] != 0) //проверка на наличие камня
	{
		tf[stone[h1]] = true; 
		h1++;
	}
	int move[E+1][N+1];
		
	int op[] = {-1, 0, 1};
	for(int i = 0; i <= E; i++)
		for(int j = 0; j <= N; j++)
			move[i][j] = 0;
	move[1][1] = 1;
	int max1 = 0;
	int h2 = 0;
	int pos1 = 0, pos2 = 0;
	for(int i = 1; i < E; i++) // поиск всех возможных шагов
	{
		for(int j = 1; j <= N; j++)
		{
			if(move[i][j] > 0 && tf[i] == true)
				for(int k = 0; k < 3; k++)
				{
					pos2 = j + op[k];
					pos1 = i + pos2;
					if(pos2 > max1) max1 = pos2;
					if(pos1 <= E && pos1 > 0 && pos2 <= N && pos2 > 0 && tf[pos1] == true)
					{
						move[pos1][pos2] = move[i][j] + 1;
						pos1 = 0;
						pos2 = 0;

					}
				}
		}
	}
	int way[E];
	int way2[E+1][N+1];
	for(int i = 0; i <= E; i++)
		for(int j = 0; j <= N; j++)
			way2[i][j] = 0;
	int last = 0, step = 0;
	int i = 1;
	int h6;
	while(i < N+1)
	{

		if(move[E][i] > last)
		{
			last = move[E][i];
			step = i;

		}
		i++;
	}
	way[last] = E;
	way2[way[last]][step] = last;
	int num = last;
	int leng = step;

	while(num > 0) // поиск пути
	{
		for(int j = 0; j < 3; j++)
		{
			pos2 = leng + op[j] ;
			pos1 = way[num] - leng;
			if( move[pos1][pos2] == num - 1)
			{

				way2[pos1][pos2] = num-1;
				way[num - 1] = pos1;

				break;

			}
		}
		leng = pos2;
		num--;
	}

	way[1] = 1;
	way2[1][1] = 1;
	//вывод
	printf("       ");
	for(int i = 1; i <= E; i++)
		if(tf[i] == true) printf("    X", tf[i]); else printf("    .", tf[i]);
	printf("\n");
	printf("       ");
	for(int i = 1; i <= E; i++)
		printf("%5d", i);
	printf("\n");
	printf("       ");
	for(int i = 1; i <= E*5; i++)
		printf("-", i);
	printf("\n");
	for(int i = 1; i <= max1; i++)
	{
		for(int j = 1; j <= E; j++)
		{
			if(j == 1) printf("%5d |", i);
			if(move[j][i] == 0) printf("    .");
			else printf("%5d", move[j][i]);
		}
		printf("\n");
	}
	
	printf("\n");
	printf("       ");
	for(int i = 1; i <= E; i++)
		printf("%5d", i);
	printf("\n");
	printf("       ");
	for(int i = 1; i <= E*5; i++)
		printf("-", i);
	printf("\n");
	for(int i = 1; i <= max1; i++)
	{ 
		for(int j = 1; j <= E; j++)
		{
			if(j == 1)printf("%5d |", i);
			if(way2[j][i] == 0) printf("    .");
			else printf("%5d", way2[j][i]);
		}
		printf("\n");
	}
	printf("\n\tПуть : ");
	for(int i = 0; i < E; i++)
	{
	
		if(way[i] != 0 && way[i] > 0 && way[i] <= E) printf("%5d", way[i]);
			if(way[i] == E) break;
		
	}
	return 0;
}
