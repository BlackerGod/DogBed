
#include<stdio.h>
#include<stdlib.h>
int number(int  *a){

		int i = 0;
		while (a[i])
			i++;
		return i;
}
int main(){
	int a[10] = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9 };  //好像不能在函数中求出
	//char a[] = "abcd0000efhh";  //这种可以用函数求出长度
	int count=number(a);
	printf("%d", count);
	system("pause");
	return 0;
}