#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define flowercost 2
#define vasecost 5
int min(int a, int b){
	if (a < b){ return a; }
	else{ return b; }
	return a;

}
void init(int number[99][99]){
	int a = 0;
	int b = 0;
    for (int i = 1; i < 99; ++i){
		number[0][i] = vasecost * i;   //花瓶
    }
	for (int j = 1; j < 99; ++j){
		if (j >= 3){
			a = j % 3;
			b = (j - a) / 3;
			number[j][0] = b * vasecost+ a * flowercost;

		}
		else{ number[j][0] = flowercost * j; }
	}
	for (int flower = 1; flower <= 99; flower++){
		for (int vase = 1; vase <= 99; vase++){
			if (flower * 2 == vase){
				for (int k = flower; k >= 1; k--)
					number[k][vase] = vase * vasecost;


			}
		}
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
	int number[99][99] = { {0} };
	init(number);   //初始化特殊值
	judge(number);   //比较完善列表
	printf("请输入你要的花 花瓶数量（两个数量小于99）\n");
	scanf("%d %d", &flower, &vase);
                                      /*for (int i = 0; i < flower; ++i){
		                                 for (int j = 0; j < vase; ++j){
                                            printf(" %d\t", number[i][j]);
	                                                                      }
		                                                       printf("\n");
	                                                                       }*/
	printf("最低价格为：%d\n", number[flower][vase]);
	system("pause");
	return 0;

}

