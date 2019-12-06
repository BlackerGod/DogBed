#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define flowercost 2                //花的价格
#define vasecost 5                  //花瓶的价格
int huapingmultiple = 0;                 //花基础优惠数量
int huamultiple = 0;                      //花瓶基础优惠数量
void print(int number[99][99], int flower, int vase){
	for (int i = 0; i < flower; ++i){
		for (int j = 0; j < vase; ++j){
			printf(" %d\t", number[i][j]);
		}
		printf("\n");
	}



}     //打印表格，测试使用
int min(int a, int b){
	if (a < b){ return a; }
	else{ return b; }
	return a;

}   //比较函数
void initflower(int number[99][99], int flowernum, int flowerprice){

	int a = 0;
	int b = 0;

	for (int j = 1; j < 99; ++j){
		if (j >= flowernum){
			a = j % flowernum;
			b = (j - a) / flowernum;
			number[j][0] = b * flowerprice + a * flowercost;

		}
		else{ number[j][0] = flowercost * j; }    //花朵
	}


}            //初始化花的优惠价格
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




}  //初始化花瓶的优惠价格
void initmix(int number[99][99], int x, int y, int z, int flower){

	for (int i = 1; i <= flower; ++i){
		number[i*x][i*y] = i*z;
	}
}   //特殊值
void initdigui(int number[99][99],int flower,int vase,int huadiscount,int vasediscount){
	for (int i = 1; i <= flower; i++){
		for (int j = 1; j <= vase; j++){
			if (number[i][j] != 0){
				if (huapingmultiple != 0)
				for (int x = 1; x <= vase; x++)
					number[i][j + x*huapingmultiple] = number[i][j] + x*vasediscount;
				if (huamultiple != 0)
				for (int y = 1; y <= flower; y++)
					number[i + y*huamultiple][j] = number[i][j] + y*huadiscount;
				
			}
            if (huadiscount != 0 &&vasediscount != 0)  //当购买数量满足若干次针对花的优惠方案和若干次针对花瓶的优惠方案
					number[i*huamultiple][j*huapingmultiple] = i*huadiscount + j*vasediscount;


			}
		}
	}


  //表格求解
void judge(int number[99][99]){
	for (int i = 1; i < 99; ++i){
		for (int j = 1; j < 99; ++j){
			if (number[i][j] == 0){
				number[i][j] = min(number[i][j - 1] + vasecost, number[i - 1][j] + flowercost);
			}
			else { continue; }


		}
	}



}	//推出其余值
int main(){
	int flower = 0;          //用户需要的花数
	int vase = 0;             //用户需要的花瓶数
	int number[99][99] = { { 0 } };    //初始化表格
	int a = 0;
	int b = 0;
	int c = 0;
	int huadiscount = 0;               //花基础优惠价格	
	int vasediscount = 0;              //花瓶基础优惠价格
	printf("请输入你要的花 花瓶数量（两个数量小于99）\n");
	scanf("%d %d", &flower, &vase);
		for (int i = 0; i < 99; i++){                        //初始化没优惠的花的价格
			number[i][0] = 2 * i;
		}

		for (int j = 0; j < 99; j++){                        //初始化没优惠的花瓶价格
			number[0][j] = 5 * j;
		}




	while (1){                   //循环输入条件
		printf("请输入花 花瓶优惠的政策：花数量  花瓶数量 价格\n");
		scanf("%d %d %d", &a, &b, &c);

		if (a !=0 && b == 0){
			initflower(number, a, c);
			huamultiple = a;
			huadiscount = c;
			//print(number, flower, vase);
		}
		
		else if (a == 0 && b !=0 )
		{
			initvase(number, b, c);
			huapingmultiple = b;
			vasediscount = c;
			//print(number, flower, vase);
		}
		else if (a != 0 && b != 0){

			initmix(number, a, b, c, flower);//初始化特殊值
			//print(number, flower, vase);
			initdigui(number, flower, vase,huadiscount,vasediscount);
			//print(number, flower, vase);
		}
		else if (a == 0 && b == 0 && c == 0){
		break;}
	}
	   
	judge(number);   //比较完善列表
	print(number, flower, vase);


	printf("最低价格为：%d\n", number[flower][vase]);
	system("pause");
	return 0;

}




