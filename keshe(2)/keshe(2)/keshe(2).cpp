#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define flowercost 2
#define vasecost 5
void print(int number[99][99],int flower,int vase){
	for (int i = 0; i < flower; ++i){
		for (int j = 0; j < vase; ++j){
			printf(" %d\t", number[i][j]);
		}
		printf("\n");
	}



}
int min(int a, int b){
	if (a < b){ return a; }
	else{ return b; }
	return a;

}
void initflower(int number[99][99],int flowernum,int flowerprice){
	
	int a = 0;
	int b = 0;

	for (int j = 1; j < 99; ++j){
		if (j >= flowernum){
			a= j % flowernum;
			b = (j - a) / flowernum;
			number[j][0] = b * flowerprice + a * flowercost;

		}
		else{ number[j][0] = flowercost * j; }    //花朵
	}

	
}
void initvase(int number[99][99], int vasenum, int vaseprice){
	int a = 0;
	int b = 0;
	for (int i = 1; i < 99; ++i){
		if (i >= vasenum){
			a = i % vasenum;
			b = (i - a) / vasenum;
			number[0][i] = b * vaseprice + a*vasecost;

		}
		else{ number[0][i] = vasecost * i; }  //花瓶
	}




}
void initmix(int number[99][99], int x, int y, int z,int flower){
	
	for (int i = 1; i <= flower; ++i){
		number[i*x][i*y] = i*z;
	}

}
void judge(int number[99][99]){
	for (int i = 1; i < 99; ++i){
		for (int j = 1; j < 99; ++j){
			if (number[i][j] == 0){
				number[i][j] = min(number[i][j - 1] + vasecost, number[i - 1][j] + flowercost);
			}
			else { continue; }


		}
	}



}
int main(){
	int flower = 0;
	int vase = 0;
	int number[99][99] = { { 0 } };
	
	int flowernum = 0;
	int flowerprice = 0;
	int vasenum = 0;
	int vaseprice = 0;
	int a=0;
	int b = 0;
	int c = 0;
	printf("请输入你要的花 花瓶数量（两个数量小于99）\n");
	scanf("%d %d", &flower, &vase);
	printf("请输入花优惠的政策：数量  价格\n");
	scanf("%d %d", &flowernum, &flowerprice);
	initflower(number, flowernum, flowerprice);
	printf("请输入花瓶优惠的政策：数量  价格\n");
	scanf("%d %d", &vasenum, &vaseprice);
	initvase(number, vasenum, vaseprice);
	printf("请输入花 花瓶优惠的政策：花数量  花瓶数量 价格\n");
	scanf("%d %d %d", &a, &b,&c);
	initmix(number,a,b,c,flower);   //初始化特殊值
	judge(number);   //比较完善列表
	print(number, flower, vase);


	 printf("最低价格为：%d\n", number[flower][vase]);
	system("pause");
	return 0;

}

