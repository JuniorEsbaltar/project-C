#include <stdio.h>
#include <string.h>
#define true 1
#define false 0
typedef int bool; 
#define N 8


int row[] = { 2, 1, -1, -2, -2, -1,  1,  2 , 2 };
int col[] = { 1, 2,  2,  1, -1, -2, -2, -1, 1 };

bool isValid(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;

	return true;
}


void KnightTour(int visited[N][N], int x, int y, int pos)
{
	visited[x][y] = pos;
	int i,j;
	if (pos >= N*N)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
				printf("%3d",visited[i][j]);
		printf("\n");
		}
		printf("\n");
		visited[x][y] = 0;
		return;
	}
	
	int k;
	for ( k = 0; k < N; k++)
	{
		
		int newX = x + row[k];
		int newY = y + col[k];

		
		if (isValid(newX, newY) && !visited[newX][newY])
			KnightTour(visited, newX, newY, pos + 1);
	}

	visited[x][y] = 0;
}


int main()
{

	int visited[N][N];
	int x,y;


	memset(visited, 0, sizeof visited);

	int pos = 1;

	printf("Informe a coluna que deseja comecar:");
	scanf("%d",&y);
	printf("Informe a linha que deseja comecar:");
	scanf("%d",&x);


	KnightTour(visited, y, x, pos);

	return 0;
}
