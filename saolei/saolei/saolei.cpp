#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 10
#define MAX_COL 10
#define minecount 10
void Init(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL]){
	srand(time(0));
	for (int i = 0; i < MAX_ROW; ++i){
		for (int j = 0; j < MAX_COL; ++j){
			show_map[i][j] = '*';
			mine_map[i][j] = '0';
		}
	}
	
	int count = 10; 
	while (count){                   //避免随机重复，不可直接for循环10次！
		int x = rand() % 10;
		int y = rand() % 10;
		if (mine_map[x][y] == '0')
		{ mine_map[x][y] = 'X'; 
		  count--;
		} 
	}
	for (int i = 0; i < MAX_ROW; ++i){
		for (int j = 0; j < MAX_COL; ++j){
			if (mine_map[i][j] != 'X'){
			int mine_count = 0;
			if (i - 1 >= 0 && j - 1 >= 0 && mine_map[i - 1][j - 1] == 'X'){
				++mine_count;
			}
			if (i - 1 >= 0 && mine_map[i - 1][j] == 'X'){
				++mine_count;
			}
			if (i - 1 >= 0 && j + 1 < MAX_ROW && mine_map[i - 1][j + 1] == 'X'){
				++mine_count;
			}
			if (j - 1 >= 0 && mine_map[i][j - 1] == 'X'){
				++mine_count;
			}
			if (j + 1 < MAX_COL && mine_map[i][j + 1] == 'X'){
				++mine_count;
			}
			if (i + 1 < MAX_COL && j - 1 >= 0 && mine_map[i + 1][j - 1] == 'X'){
				++mine_count;
			}
			if (i + 1 < MAX_ROW && mine_map[i + 1][j] == 'X'){
				++mine_count;
			}
			if (i + 1 < MAX_ROW && j + 1 < MAX_COL && mine_map[i][j] == 'X'){
				++mine_count;
			}

			mine_map[i][j] = mine_count + 48;

		}
	  }
	}
  }
void print_map(char show_map[MAX_ROW][MAX_COL]){
	printf("   |");
	for (int i = 0; i < MAX_ROW; ++i){
		printf("%d  ", i);
	
	}
	printf("\n");
	printf("---+-------------------------------\n");
	for (int i = 0; i < MAX_ROW; ++i){
		printf("%d  |", i);
		for (int j = 0; j < MAX_COL; ++j){
		
			printf("%c  ", show_map[i][j]);
		}
		printf("\n");
	}



}
void GetPos(int *row, int *col, char show_map[MAX_ROW][MAX_COL]){
while (1){
	printf("请输入你的点开的位置(0-9):\n");
	scanf("%d %d", row, col);
	
		if (*row<0 || *row>=MAX_ROW || *col<0 || *col>=MAX_COL){
			printf("输入错误，请重新输入\n");
			continue;

		}
		if (show_map[*row][*col] != '*'){
			printf("你输入的地方已被选取，请重新输入\n");
			continue;
		}
		break;



	}
}
void update(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL],int row,int col){
	int mine_count = 0;
	if (row - 1 >= 0 && col - 1 >= 0 && mine_map[row - 1][col - 1] == 'X'){
		++mine_count;
	}
	if (row - 1 >= 0 && mine_map[row - 1][col] == 'X'){
		++mine_count;
	}
	if (row - 1 >= 0 && col + 1 < MAX_ROW && mine_map[row - 1][col + 1] == 'X'){
		++mine_count;
	}
	if (col - 1 >= 0 && mine_map[row][col - 1] == 'X'){
		++mine_count;
	}
	if (col + 1 < MAX_COL && mine_map[row][col + 1] == 'X'){
		++mine_count;
	}
	if (row+ 1 < MAX_COL && col - 1 >= 0 && mine_map[row + 1][col - 1] == 'X'){
		++mine_count;
	}
	if (row + 1 < MAX_ROW && mine_map[row + 1][col] == 'X'){
		++mine_count;
	}
	if (row + 1 < MAX_ROW && col + 1 < MAX_COL && mine_map[row+1][col+1] == 'X'){
		++mine_count;
	}

	show_map[row][col] = mine_count + 48; 
}
/*void spread(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL], int row, int col){
	int i = row;
	int j = col;
	while (mine_map[i][j] == '0' && i - 1 >= 0 && j - 1 >= 0){
		show_map[i][j] = '0';
		i--;
		j--;
			
		}
	i = row;
	j = col;
	while (mine_map[i][j] == '0' && i - 1 >= 0){
		show_map[i][j] = '0';
		i--;

	}
	i = row;
	j = col;
	while (mine_map[i][j] == '0' && i - 1 >= 0 && j + 1 <MAX_COL){
		show_map[i][j] = '0';
		i--;
		j++;

	}
	i = row;
	j = col;
	while (mine_map[i][j] == '0'&& j - 1 >= 0){
		show_map[i][j] = '0';
		j--;

	}
	i = row;
	j = col;
	while (mine_map[i][j] == '0'&& j + 1 <MAX_COL){
		show_map[i][j] = '0';
		
		j++;

	}
	i = row;
	j = col;
	while (mine_map[i][j] == '0' && i + 1 <MAX_ROW && j - 1 >= 0){
		show_map[i][j] = '0';
		i++;
		j--;

	}
	i = row;
	j = col;
	while (mine_map[i][j] == '0' && i + 1<MAX_ROW ){
		show_map[i][j] = '0';
		i++;

	}
	i = row;
	j = col;
	while (mine_map[i][j] == '0' && i + 1 < MAX_ROW && j +1<MAX_COL){
		show_map[i][j] = '0';
		i++;
		j++;

	}


}*/
int main(){
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	Init(show_map,mine_map);
	int safe_mine = 0; 
	int row = 0;
	int col = 0;
	int x = 0;
	while (1){
	print_map(show_map);
	print_map(mine_map);
	GetPos(&row,&col,show_map);
	if (mine_map[row][col] == 'X'){
		
		system("cls");
		print_map(mine_map);
		printf("游戏结束！\n");
		break;
	}
	++safe_mine;
	if (safe_mine == MAX_COL*MAX_ROW - minecount){
		
		system("cls");
		print_map(mine_map);
		printf("你赢了\n");
		break;
	}
    update(show_map, mine_map,row,col);
	//spread(show_map, mine_map, row, col);
	system("cls");

}
	
	system("pause");
	return 0;

}