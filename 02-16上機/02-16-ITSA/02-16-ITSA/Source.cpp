#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arry[3][3];

	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			scanf("%d", &arry[a][b]);
		}
	}
	if (arry[0][0] == arry[1][0] && arry[1][0] == arry[2][0])
	{
		printf("True\n");
	}
	else if (arry[0][1] == arry[1][1] && arry[1][1] == arry[2][1])
	{
		printf("True\n");
	}
	else if (arry[0][2] == arry[1][2] && arry[1][2] == arry[2][2])
	{
		printf("True\n");
	}
	else if (arry[0][0] == arry[0][1] && arry[0][1] == arry[0][2])
	{
		printf("True\n");
	}
	else if (arry[1][0] == arry[1][1] && arry[1][1] == arry[1][2])
	{
		printf("True\n");
	}
	else if (arry[2][0] == arry[2][1] && arry[2][1] == arry[2][2])
	{
		printf("True\n");
	}
	else if (arry[0][0] == arry[1][1] && arry[1][1] == arry[2][2])
	{
		printf("True\n");
	}
	else if (arry[0][2] == arry[1][1] && arry[1][1] == arry[2][0])
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}


	return 0;
}