#include<stdio.h>

void IntPrintfAdress(int* d) {
	for (int i = 0;i < 5;i++) {
		printf("%p ", d);
		d++;
	}
}
void FloatPrintAdress(float* d) {
	for (int i = 0;i < 5;i++) {
		printf("%p ", d);
		d++;
	}
}
void IntPrintf(int* d) {
	for (int i = 0;i < 5;i++) {
		printf("%d ", *d);
		d++;
	}
}
void FloatPrint(float* d) {
	for (int i = 0;i < 5;i++) {
		printf("%.2f ", *d);
		d++;
	}
}
int main() {
	int inteager[5] = {5,4,3,2,1};
	float f[5] = { 0.1,0.5,0.6,0.8,0.9 };

	for (int i = 0;i < 5;i++) {//int數字
		printf("%d ", inteager[i]);
	}
	printf("\n\n");

	for (int i = 0;i < 5;i++) {//int地址
		printf("%p ", &inteager[i]);
	}
	printf("\n\n");

	for (int i = 0;i < 5;i++) {//float數字
		printf("%.2f ", f[i]);
	}
	printf("\n\n");

	for (int i = 0;i < 5;i++) {//float地址
		printf("%p ", &f[i]);
	}
	printf("\n\n");

	IntPrintf(inteager);
	printf("\n\n");

	IntPrintfAdress(inteager);
	printf("\n\n");

	FloatPrint(f);
	printf("\n\n");

	FloatPrintAdress(f);
	printf("\n\n");

	

	
	return 0;
}