#include<stdio.h>
#include<ctype.h>


void cins(int *num) {
	int i = 1;
	float f = 0;
	while (i < 6)
	{
		printf("�п�J�� %d �ռƦr", i);
		scanf("%f", &f);
		int a = (int)f;
		if ((a-f)==0 && a>0) {
			*num = (int)f;
			num++;
			i++;
		}
		else
		{
			printf("��J���~!!\n");
		}
	}
}
void f(int num[], int* Max, int* Min, float* Average) {
	*Max = num[0];
	*Min = num[0];
	float temp = 0;
	
	for (int i = 0; i < 5; i++)
	{
		if (*Max < num[i]) {
			*Max = num[i];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (*Min > num[i]) {
			*Min = num[i];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		 temp+= num[i];
	}
	*Average = temp / 5;
}
int main() {
	int num[5] = {0};
	//int temp = 0,i=0;
	int Max,  Min; 
	float Average;
	//bool check = false;
	cins(num);
	f(num, &Max, &Min, &Average);
	printf("�̤j��: %d ,�̤p�� %d , ����: %.2f",Max,Min,Average);
	return 0;
}