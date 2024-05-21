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
	int computer[100] = { 0 };//�p������
	int program[100] = { 0 };//���W����
	int MaxComIndex[100] = { 0 };//�p�����o�̰����H
	int MaxProgIndex[100] = { 0 };//���W�Ƴ̰����H
	int MaxComNum = 0;//�p���̰����H��
	int MaxProgNum = 0;//���W�̰����H��
	int MaxComScore = 0;//�p���o������
	int MaxProgScore = 0;//���k�̰�������
	float average[100] = {0};
	int total[11] = { 0 };
	srand(time(NULL));
		printf("		   �p������    ���W����    ����\n");
	for (int i = 0; i < 100; i++)//���Z��l��
	{
		computer[i] = rand() % 101;
		program[i] = rand() % 101;
		average[i] = (computer[i] + (float)program[i]) / 2;
		printf("�� %3d  �P�� :   %3d     %3d	  %.2f\n",i+111000001, computer[i], program[i],average[i]);
	}
	
	MaxScore(computer, program, MaxComIndex, MaxProgIndex, &MaxComNum, &MaxProgNum, &MaxComScore, &MaxProgScore);//��X�̤j�����Z��ǥ�

	printf("�p���̰��� : %d	 �̰����H�� : %d  �̰������H  : ", MaxComScore, MaxComNum);//�p�����Z��X
	for (int i = 0; i < 100; i++)
	{
		if (MaxComIndex[i] == 1)
		{
			printf("%d ", i + 111000001);
		}
	}
	printf("\n���W�̰��� : %d �̰����H�� : %d  �̰������H  :  ",MaxProgScore,MaxProgNum);//���W���Z��X
	for (int i = 0; i <100; i++) {
		if (MaxProgIndex[i]==1)
		{
			printf("%d ", i + 111000001);
		}
	}
	printf("\n�������Z���ή�P��: \n");
	for (int i = 0; i < 100; i++)//�������ή��X
	{
		if(average[i]<60){
			printf("%3d �P�� : %.2f \n", i + 111000001,average[i]);
		}
	}
	for (int i = 0; i < 100; i++)//����ϲέp0~9 10~19......90~99 100
	{
		int d = (int)average[i] / 10;
		total[d]++;
	}
	for (int i = 0; i < 10; i++)//����Ͽ�X0~99
	{
		printf("%d ~ %d : ", i * 10, i * 10 + 9);
		for (int j = 0;j < total[i];j++) {
			printf("* ");
		}
		printf("\n");
	}
	printf("100 : ");//����Ͽ�X[100]
	for (int i = 0; i < total[10]; i++)
	{
		printf("* ");
	}
	return 0;
}