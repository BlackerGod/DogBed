#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void change(int* a, int* b){
	int j;
	for (int i = 0; i < 10; ++i){
		a[i] = i;
		b[i] = 9 - i;   //数组赋值
	}
	int c[10];

	for (j = 0; j < 10; ++j){
		c[j] = a[j];
		a[j] = b[j];
		b[j] = c[j];
	}
	for (int z = 0; z < 10; ++z){
	printf("%d ",a[z]);
	
}
	printf("\n");
	for (int z = 0; z < 10; ++z){
	printf("%d ", b[z]);}
	printf("\n");
}
void jisuan(){
	//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值
	int i, flag = 1;
	float sum = 0.0;
	for (i = 1; i <= 100; i++)
	{
		sum = sum + flag*(1.0 / i);
		flag = -flag;
	}
	printf("%f\n", sum);



}
void cishu(){
	//编写程序数一下 1到 100 的所有整数中出现多少次数字9。
	int count = 0;
	for (int i = 0; i <= 100; ++i){
		if ((i % 10) == 9){
			count++;
	
	}
		if ((i / 10) == 9){
		
			count++;
		}
	
	
	}
	printf("%d\n", count);

}
int main(){
	int a[10];
	int b[10];
	change(a, b);

	jisuan();
	cishu();

	system("pause");
	return 0;
}