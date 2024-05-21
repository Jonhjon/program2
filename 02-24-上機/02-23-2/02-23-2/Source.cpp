#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void SwapFloat(float* num1, float* num2) {
	float temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void Printflist(int std[], int animal[], int math[], float average[],int n,int lk[],int rk[]) {
	
	printf("學生   生物   微積分   平均   排名:\n");
	for (int i = 0; i < n; i++)
	{
		rk[i] = i + 1;
		if (i>0&&lk[i-1]==lk[i])
		{
			printf("%2d     %3d      %3d     %2.2f    %2d\n", std[i], animal[i], math[i], average[i],rk[i-1]);
		}
		else
		{
			printf("%2d     %3d      %3d     %2.2f    %2d\n", std[i], animal[i], math[i], average[i],rk[i]);
		}
	}
}
void PrintflistFlo(int std[], int animal[], int math[], float average[], int n, float lk[],int rk[]) {
	printf("學生   生物   微積分   平均   排名:\n");
	for (int i = 0; i < n; i++)
	{
		rk[i] = i + 1;
		if (i > 0 && lk[i - 1] == lk[i])
		{
			printf("%2d     %3d      %3d     %2.2f    %2d\n", std[i], animal[i], math[i], average[i], rk[i-1]);
		}
		else
		{
			printf("%2d     %3d      %3d     %2.2f   %2d\n", std[i], animal[i], math[i], average[i], rk[i]);
		}
	}
}
int main() {
	int n = 0;
	int animal[30] = { 0 };
	int math[30] = { 30 };
	int std[30] = { 0 };
	float average[30] = { 0 };
	int choice = 0;
	int rk[30] = { 0 };
	srand(time(NULL));
	printf("請輸入人數 :");
	scanf("%d", &n);
	printf("學生   生物   微積分   平均 \n");
	for (int i = 0; i < n; i++)
	{
		std[i] = i + 1;
		animal[i] = rand() % 101;
		math[i] = rand() % 101;
		average[i] = (animal[i] + (float)math[i]) / 2;
		printf("%2d      %3d      %3d     %2.2f\n",std[i],animal[i],math[i],average[i]);
	}
	
	while (choice != -1)
	{
		printf("選項: 1)依生物成績排名 2)依微積分成績排名 3)依平均成績排名 -1)結束 :");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			for (int i = 0; i < n; i++)
			{
				int smallest = i;
				for (int j = i; j < n; j++) {
					if (animal[j]>animal[smallest])
					{
						smallest = j;
					}	
				}
				swap(&animal[i], &animal[smallest]);
				swap(&math[i], &math[smallest]);
				swap(&std[i], &std[smallest]);
				SwapFloat(&average[i], &average[smallest]);
			}
			Printflist(std, animal, math, average,n,animal, rk);
			break;
		case 2:
			for (int i = 0; i < n; i++)
			{
				int smallest = i;
				for (int j = i; j < n; j++) {
					if (math[j] > math[smallest])
					{
						smallest = j;
					}
				}
				swap(&animal[i], &animal[smallest]);
				swap(&math[i], &math[smallest]);
				swap(&std[i], &std[smallest]);
				SwapFloat(&average[i], &average[smallest]);

			}
			Printflist(std, animal, math, average, n,math,rk);
			break;
		case 3:
			for (int i = 0; i < n; i++)
			{
				int smallest = i;
				for (int j = i; j < n; j++) {
					if (average[j] > average[smallest])
					{
						smallest = j;
					}
				}
				swap(&animal[i], &animal[smallest]);
				swap(&math[i], &math[smallest]);
				swap(&std[i], &std[smallest]);
				SwapFloat(&average[i], &average[smallest]);
			}
			PrintflistFlo(std, animal, math, average, n,average,rk);
			break;
		case -1:
			break;
		default:
			break;
		}
	}
	

	return 0;

}