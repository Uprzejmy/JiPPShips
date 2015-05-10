// Ships.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void createMap(int map[10][10]);
void createShips(int map[10][10]);
void createShip(int length, int map[10][10]);
void printMap(int map[10][10]);
void putElementOnMap(int element, int x, int y, int map[10][10]);
int isFieldValid(int x, int y, int map[10][10]);


int _tmain(int argc, _TCHAR* argv[])
{
	int map[10][10];

	srand(time(NULL));

	//printf("%d",map);


	createMap(map);

	//printMap(map);

	return 0;
}

void createMap(int map[10][10])
{
	int i, j;

	for (j = 0; j<10; j++)
	{
		for (i = 0; i<10; i++)
		{
			map[i][j] = 0;
		}
	}

	createShips(map);

	printMap(map);

	return;
}

void createShips(int map[10][10])
{
	createShip(4, map);
	createShip(3, map);
	createShip(3, map);
	createShip(2, map);
	createShip(2, map);
	createShip(2, map);
	createShip(1, map);
	createShip(1, map);
	createShip(1, map);
	createShip(1, map);

	return;
}

void createShip(int length, int map[10][10])
{
	int i, j;

	int bowX, bowY;

	int orientation = rand() % 2;//0 - pionowo, 1 - poziomo

	if (orientation)
	{
		//pozioma
		//printf("Poziomo\n");

		bowX = rand() % (10 - length);//wspolrzedna  x dziobu
		bowY = rand() % 10;//wspolrzedna  y dziobu

		for (i = 0; i<length + 2; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (!isFieldValid(bowX - 1 + i, bowY - 1 + j, map))
				{
					createShip(length, map);
					return;
				}
			}
		}

		for (i = 0; i < length + 2; i++)
		{
			for (j = 0; j < 3; j++)
			{
				putElementOnMap(1, bowX - 1 + i, bowY - 1 + j, map);
			}
		}

		for (i = 0; i < length; i++)
		{
			putElementOnMap(2, bowX + i, bowY, map);
		}

	}
	else
	{
		//pionowa

		//printf("Pionowo\n");

		bowX = rand() % 10;//wspolrzedna  x dziobu
		bowY = rand() % (10 - length);//wspolrzedna  y dziobu

		for (i = 0; i<3; i++)
		{
			for (j = 0; j < length + 2; j++)
			{
				if (!isFieldValid(bowX - 1 + i, bowY - 1 + j, map))
				{
					createShip(length, map);
					return;
				}
			}
		}

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < length + 2; j++)
			{
				putElementOnMap(1, bowX - 1 + i, bowY - 1 + j, map);
			}
		}

		for (j = 0; j < length; j++)
		{
			putElementOnMap(2, bowX, bowY + j, map);
		}
	}

	for (j = 0; j < 10; j++)
	{
		for (i = 0; i < 10; i++)
		{
			if (map[i][j] == 1)
				map[i][j] = 0;
		}
	}

	//printf("Wspolrzedne dziobu: [%d][%d]\n", bowX, bowY);
	//printf("Dlugosc statku: %d\n", length);

	return;
}


void printMap(int map[10][10])
{
	int i, j;

	for (j = 0; j<10; j++)
	{
		for (i = 0; i<10; i++)
		{
			printf("%d ", map[i][j]);
		}

		printf("\n");
	}

	printf("\n\n");

	return;
}

void putElementOnMap(int element, int x, int y, int map[10][10])
{
	// 2 - ship
	// 1 - ship's surroundings
	// 0 - empty
	if (x < 0 || x>9 || y < 0 || y>9)
		return;

	map[x][y] = element;

	return;
}

int isFieldValid(int x, int y, int map[10][10])
{
	// 2 - ship
	// 1 - ship's surroundings
	// 0 - empty
	if (x < 0 || x>9 || y < 0 || y>9)
		return 1;
	if (map[x][y] == 0)
		return 1;
	if (map[x][y] == 1)
		return 1;
	return 0;
}