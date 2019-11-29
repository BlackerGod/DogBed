#include<stdio.h>
#include<stdlib.h>

void sort(int *a,int size){
	for (int i = 0; i < size; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
	int b[100];
	int j = 0;
	int c = 0;
	for (int i = 0; i < size;++i){                         //1 2 3 4 5 6 7 8 9 10
		if ((a[i] % 2) != 0){         
			b[c] = a[i];             
			++c;                   
		
		}
		else{
			b[size-1-j] = a[i];
			++j;
		}
	}
		for (int i = 0; i < size; ++i){
			printf("%d ", b[i]);
		}
		printf("\n");

}
void find_num(int arr[4][4], int number){ //书上题
	int i = 0;
	int j = 3;         // col-1;
	while (i < 4 && j >= 0){   //i<row   j>=0
		if (arr[i][j]>number){
			j--;                           //这个数小于一排最右边那个数，就在这一行左边
		                                     
		}
		else if (arr[i][j] < number){
			//这个数大于一排最右边那个数，找下一行
			i++;
		
		}
		else { printf("找到了：%d %d\n", i,j); break; }
	
	
	}


}

int  main(){

	int a[] = {1,2,3,4,5,6,7,8,9,13,15};
	int size = sizeof(a) / sizeof(int);
	sort(a,size);

	/*int arr[4][4] = { 1, 2, 8, 9, 
		              2, 4, 9, 12, 
					  4, 7, 10, 13, 
					  6, 8, 11, 15 };
	find_num(arr, 13);*/
	system("pause");
	return 0;
}