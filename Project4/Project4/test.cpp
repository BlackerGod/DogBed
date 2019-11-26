#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
void judge1(){

	for (int a = 0; a < 6; ++a){
		for (int b = 0; b < 6; ++b){
			for (int c = 0; c < 6; ++c){
				for (int d = 0; d < 6; ++d){
					for (int e = 0; e < 6; ++e){
						if ((b == 2) + (a == 3) == 1 &&           //逻辑和为1
							(b == 2) + (e == 4) == 1 &&
							(c == 1) + (d == 2) == 1 &&
							(c == 5) + (d == 3) == 1 &&
							(e == 4) + (a == 1) == 1){
							if (a*b*c*d*e == 120){               //名次不重复
								printf("那么A名次是%d \n",a);
								printf("那么B名次是%d \n",b);
								printf("那么C名次是%d \n",c);
								printf("那么D名次是%d \n",d);
								printf("那么E名次是%d \n",e);
							}
						
						
						}
					}
				}
			}
		}
	}

}
void judge2(){
	for (int a = 0; a < 2; ++a){
		for (int b = 0; b < 2; ++b){
			for (int c = 0; c < 2; ++c){
				for (int d = 0; d < 2; ++d){
					if ((a == 0) + (c == 1) + (d == 1) + (d==0)==3){
						if (a + b + c + d == 1){
							if (a == 1){ printf("A是凶手\n"); }
							if (b == 1){ printf("B是凶手\n"); }
							if (c == 1){ printf("C是凶手\n"); }
							if (d == 1){ printf("D是凶手\n"); }
							
						}
					}
				}
			}
		}
	}


}
void triangle(){
	int n;
	int a[20][20];
	printf("请输入你要的行数\n");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		a[i][0] = 1;
		a[i][i] = 1;
	}
	for (int i = 2; i < n; i++){
	  for (int j = 1; j < i; j++) {
		a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
	}
}

	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= i; ++j){
			printf("%d ", a[i][j]);
		
		}
	
		printf("\n");
	}


}
int main(){

	//judge1();
	judge2();
	//triangle();

	system("pause");
	return 0;
}