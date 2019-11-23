#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void print(int x){
	for (int i = 1; i < x; ++i){
		for (int j = 1; j < x; ++j){
			printf("%d*%d=%d\t\t", j, i,i*j);

		}
		printf("\n");
	}
	
	}
void change(int x, int y){
	int c = 0;
     c = x;
	 x = y;
	 y = c;
	 printf("交换的结果为%d %d\n", x, y);


}

void judge(int x){
	if (x % 4 == 0 && x % 100 != 0 || x % 400 == 0){
		printf("%d年是闰年\n",x);
	}
	else{
		printf("%d年不是闰年\n", x);
	}



}

void init(int *a,int x){
	for (int row = 0; row < x; row++){
		printf("请输入你要的数字\n");
		scanf("%d", &a[row]);
	
	}
}

void reverse(int *a, int x){
	int y[100];
	int i = x - 1;
	for (int j=0; i >= 0,j<x;--i,++j){
		y[j] = a[i];
     }
	
	for (int c = 0; c < x; ++c){
		a[c] = y[c];
	
	
	}
	
}
void prinfshuzu(int *a, int length){
	for (int row = 0; row < length; ++row){
		printf("%d\t\n", a[row]);
	
	}


}

void empty(int *a, int length){    //函数好像有问题。。。看不出来，但功能能实现
	while (1){                     
		int d;
		printf("是否进行数组清空(1/0)\n");
		scanf("%d", &d);
		if (d == 1){
			for (int i = 0; i < length; ++i){
				a[i] = { 0 };
			}
			break;
		}
		else if (d == 0){ break; }
		    
		       else  { printf("输入错误，请重新输入\n"); continue; }


		}
	
	
	}

void sushu(int x){

	int i;
	do {
		for (i = 2; i < x; i++)
		if (x%i == 0)break;
		if (i == x)
		{

			printf("%d是素数\n", x); break;
		}
		else
		{
			printf("%d不是素数\n", x); break;
		}
	} while (x != 0);




}







int main(){
	int a = 0;
	printf("请输入一个数字\n");
	scanf("%d", &a);
	print(a);    //输出乘法口诀表
	
	int a1 = 0;
	int a2 = 0;
	printf("请输入你要输入交换的数字\n");
	scanf("%d %d", &a1, &a2);
    change(a1, a2);  //交换函数


	printf("请输入你要判断的年份\n");
	int year = 0;
	scanf("%d", &year);
	judge(year);    //判断是否闰年

	int length = 0;
	printf("请输入你的数组长度(最大不得超过100)\n");
	scanf("%d", &length);
	int x[100];
	init(x,length);      //初始化
	reverse(x, length); //倒置
	prinfshuzu(x, length);//输出倒序数组
	empty(x, length);//清空



	int number = 0;
	printf("请输入你要判断的数字\n");
	scanf("%d", &number);
	sushu(number);





	system("pause");
	return 0;
}