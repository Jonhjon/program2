#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int length = 100;
void MaxScore(int computer[], int program[], int MaxComIndex[], int MaxProgIndex[], int* MaxComNum, int* MaxProgNum, int* MaxComScore, int* MaxProgScore)
{
	*MaxComScore = computer[0];
	*MaxProgScore = program[0];
	int x = 0;
	int y = 0;
	for (int i = 0; i < 100; i++)
	{
		if (*MaxComScore < computer[i])
		{
			*MaxComScore = computer[i];
		}
		if (*MaxProgScore < program[i])
		{
			*MaxProgScore = program[i];
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (*MaxComScore == computer[i])
		{
			MaxComIndex[i] = 1;
			x++;
		}
		if (*MaxProgScore == program[i])
		{	
			MaxProgIndex[i] = 1;
			y++;
		}
	}
	*MaxProgNum = y;
	*MaxComNum = x;
}
int main() {
	int computer[100] = { 0 };//計概分數
	int program[100] = { 0 };//成規分數
	int MaxComIndex[100] = { 0 };//計概分罪最高的人
	int MaxProgIndex[100] = { 0 };//成規數最高的人
	int MaxComNum = 0;//計概最高的人數
	int MaxProgNum = 0;//成規最高的人數
	int MaxComScore = 0;//計概罪的分數
	int MaxProgScore = 0;//成歸最高的分數
	float average[100] = {0};
	int total[11] = { 0 };
	srand(time(NULL));
		printf("		   計概分數    成規分數    平均\n");
	for (int i = 0; i < 100; i++)//成績初始化
	{
		computer[i] = rand() % 101;
		program[i] = rand() % 101;
		average[i] = (computer[i] + (float)program[i]) / 2;
		printf("第 %3d  同學 :   %3d     %3d	  %.2f\n",i+111000001, computer[i], program[i],average[i]);
	}
	
	MaxScore(computer, program, MaxComIndex, MaxProgIndex, &MaxComNum, &MaxProgNum, &MaxComScore, &MaxProgScore);//找出最大的成績跟學生

	printf("計概最高分 : %d	 最高分人數 : %d  最高分的人  : ", MaxComScore, MaxComNum);//計概成績輸出
	for (int i = 0; i < 100; i++)
	{
		if (MaxComIndex[i] == 1)
		{
			printf("%d ", i + 111000001);
		}
	}
	printf("\n成規最高分 : %d 最高分人數 : %d  最高分的人  :  ",MaxProgScore,MaxProgNum);//成規成績輸出
	for (int i = 0; i <100; i++) {
		if (MaxProgIndex[i]==1)
		{
			printf("%d ", i + 111000001);
		}
	}
	printf("\n平均成績不及格同學: \n");
	for (int i = 0; i < 100; i++)//平均不及格輸出
	{
		if(average[i]<60){
			printf("%3d 同學 : %.2f \n", i + 111000001,average[i]);
		}
	}
	for (int i = 0; i < 100; i++)//直方圖統計0~9 10~19......90~99 100
	{
		int d = (int)average[i] / 10;
		total[d]++;
	}
	for (int i = 0; i < 10; i++)//直方圖輸出0~99
	{
		printf("%d ~ %d : ", i * 10, i * 10 + 9);
		for (int j = 0;j < total[i];j++) {
			printf("* ");
		}
		printf("\n");
	}
	printf("100 : ");//直方圖輸出[100]
	for (int i = 0; i < total[10]; i++)
	{
		printf("* ");
	}
	return 0;
}