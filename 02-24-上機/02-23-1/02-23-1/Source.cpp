#include<stdio.h>
#include<string.h>
void swap(char* commodity1, char* commodity2, int* price1, int* price2) {
	char temp = 0;
	temp= *commodity1;
	*commodity1 = *commodity2;
	*commodity2 = temp;
		
	int temp1 = 0;
	temp1= *price1;
	*price1 = *price2;
	*price2 = temp1;
}

int main() {
	char commodity[10][30] = { 0 };
	int CommodityPrice[10] = { 0 };
	int total = 0;
	int smallest, i=0, index;
	char d[30] = { 0 };
	int check = 0;
	int z = 0;
	for (int i = 0; i < 10; i++)
	{
		while (true)
		{
			printf("�п�J�� %d �Ӱӫ~�~�W�λ��� : ", i + 1);
			scanf("%s %d", &commodity[i], &CommodityPrice[i]);
			if (i > 0)
			{
				for (int j = 0; j < i; j++)
				{
					if (strcmp(commodity[i], commodity[j]) == 0)
					{
						z++;
					}
				}
			}
			if (z == 0) {

				printf("%d %d \n", z, i);
				z = 0;
				break;
			}
			else
			{
				printf("%d %d \n", z, i);
				printf("�~������\n");
				z = 0;
			}
		}
	}
	printf("\n\n�п�J�w��: ");
	scanf("%d", &total);
	for (int i = 0; i < 10; i++)
	{
		printf("�ӫ~ %5s ����: %5d\n", commodity[i], CommodityPrice[i]);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		smallest = i;
		for (index = i; index < 10; index++) {
			if (CommodityPrice[index] < CommodityPrice[smallest]) {
				smallest = index;
			}
		}
		swap(commodity[i], commodity[smallest], &CommodityPrice[i], &CommodityPrice[smallest]);
	}
	printf("\n\n\n");
	for (int i = 0; i < 10; i++)
	{
		printf("�ӫ~ %5s ����: %5d\n",commodity[i],CommodityPrice[i]);
	}
	printf("\n\n\n");
	for (int i = 0; i < 10; i++)
	{
		total -= CommodityPrice[i];
		if (total>0)
		{
			printf("�ӫ~  : %5s ���� : %5d\n", commodity[i], CommodityPrice[i]);
		}
		else {
			printf("\n\n��F�w��F!!!\n");
			break;
		}
	}

	return 0;
}