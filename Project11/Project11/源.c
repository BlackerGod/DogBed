#include<stdio.h>
#include<stdlib.h>
typedef int(*Cun)(int, int);
Cun cun;
void bubblesort(int *a, int size,Cun cun){
	                    
	for (int bound = size-1; bound>=0; bound--){
		for (int i = 0; i<bound; ++i){
			if (cun(a[i],a[i+1]) && i!=(size-1))
			{
				int temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}



		}
	}
		for (int i = 0; i <size;++i)
		{
			printf("%d  ", a[i]);
		}
	
		printf("\n");




}
int less(int x, int y){
	if (x < y){
	
		return 1;
	}
	return 0;

}
int great(int x,int y){

	if (x>y){
		return 1;
}
	return 0;
}
int main(){
	int a[] = { 5,6,4,2,3,1,8,9,7,0 };
	int size = sizeof(a) / sizeof(a[0]);
	//printf("%d", size);
	bubblesort(a, size,less);
	bubblesort(a, size, great);
	system("pause");
	return 0;
}