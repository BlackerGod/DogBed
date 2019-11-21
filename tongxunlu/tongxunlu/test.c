#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define Max_name 1024
#define Max_sex  4
#define Max_number 15
#define Max_address 1024
typedef struct contact
{
	char name[Max_name];
	char sex[Max_sex];
	int age;
	char number[Max_number];
	char address[Max_address];
}contact;
typedef struct person{
	contact  *persinInfo;
	int sequence;
	int capacity; //当前数组的最大容量
}person;
person addr_num;
typedef void(*Fun)(person *);
void Init(person *addr_num){
	assert(addr_num !=NULL);
	addr_num->sequence = 0;
	addr_num->capacity = 10;
	addr_num->persinInfo = (contact*)malloc(sizeof(contact)*addr_num->capacity);

	for (int i = 0; i < addr_num->capacity; ++i){
		memset(addr_num->persinInfo[i].name, 0, Max_name);
		memset(addr_num->persinInfo[i].address, 0, Max_address);
		memset(addr_num->persinInfo[i].number, 0, Max_number);
		memset(addr_num->persinInfo[i].sex, 0, Max_sex);
		addr_num->persinInfo[i].age = 0;
	}
}
int print_menu(){
	printf("**********************************\n");
	printf("**    1. 添加联系人信息         **\n");
	printf("**    2. 删除指定联系人信息     **\n");
	printf("**    3. 查找指定联系人信息     **\n");
	printf("**    4. 修改指定联系人信息     **\n");
	printf("**    5. 显示所有联系人信息     **\n");
	//printf("**    6. 清空所有联系人         **\n");
	//printf("**    7. 以名字排序所有联系     **\n");
	//printf("**    8. 保存联系人到文件       **\n");
	//printf("**    9. 加载联系人             **\n");
	printf("**    0. 退出                   **\n");
	printf("**********************************\n");
	printf("请输入你要选择的选项：\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void add_people(person *addr_num){

	assert(addr_num != NULL);
	if (addr_num->sequence >= addr_num->capacity)
	{
		addr_num->capacity += 10;
		addr_num->persinInfo = (contact *)realloc(addr_num->persinInfo,addr_num->capacity);
	}
	contact *per = &addr_num->persinInfo[addr_num->sequence];
	printf("请输入你要添加的名字\n");
	scanf("%s", per->name);
	printf("请输入你要添加的性别\n");
	scanf("%s",per->sex);
	printf("请输入你要添加的年龄\n");
	scanf("%d", &(per->age));
	printf("请输入你要添加的电话号码\n");
	scanf("%s", per->number);
	printf("请输入你要添加的地址\n");
	scanf("%s", per->address);
	++addr_num->sequence;
	printf("添加完成\n");


}
void del_people(person *addr_num){
	int choice = 0;
	assert(addr_num != NULL);

	if (addr_num->sequence==0)
	{
		printf("当前没有人可删，请添加后进行操作\n");
		return;
	}
	else {
		while (1){
			printf("请输入你要删除的人的序号:\n");
			scanf("%d", &choice);
			if (choice <= 0 || choice > addr_num->sequence){
				printf("没有该序号，请核对后进行选择\n");
				continue;
			}
			else {
				contact *p = &addr_num->persinInfo[choice-1];
				contact *per = &addr_num->persinInfo[addr_num->sequence - 1];
				strcpy(p->name, per->name);
				strcpy(p->sex, per->sex);
				strcpy(p->address, per->address);
				strcpy(p->number, per->number);
				p->age = per->age;
				--addr_num->sequence;
				break;
			}

		}
	}
		printf("已经删除\n");
	
}
void printf_people(person *addr_num){
	assert(addr_num != NULL);
	if (addr_num->sequence == 0){ printf("共有%d条记录\n", addr_num->sequence); return; }

	printf("共有%d条记录\n", addr_num->sequence);
	for (int i = 0; i < addr_num->sequence; ++i){
		contact*per = &addr_num->persinInfo[i];
		printf("序号[%d]\n", i+1);
		printf("姓名%s            电话号码:%s\n", per->name, per->number);
		printf("性别:%s       年龄：%d     住址:%s\n",per->sex, per->age, per->address);
		printf("\n");
	}
	printf("显示完成\n");
}
void find_people(person *addr_num){
	assert(addr_num != NULL);
	int choice = 0;
	char name[15];
	char number[15];
	int i = 0;
	while (1){
		printf("请输入你要查找的类型：\n");
		printf("1.姓名\n");
		printf("2.电话号\n");
		scanf("%d", &choice);
		if (choice != 1 && choice != 2){
			printf("输入错误请重新输入\n");
			continue;
		}
		else if (choice == 1){
			printf("请输入你要找的姓名\n");
			scanf("%s", name);
			for (i; i < addr_num->sequence; ++i){
				if (strcmp(name,&addr_num->persinInfo[i].name)==0){
					printf("该人的序号为%d\n", i+1);
					printf("姓名为：%s\n",addr_num->persinInfo[i].name);
					printf("性别为：%s\n", addr_num->persinInfo[i].sex);
					printf("年龄为：%d\n", addr_num->persinInfo[i].age);
					printf("电话为：%s\n",addr_num->persinInfo[i].number );
					printf("地址为：%s\n", addr_num->persinInfo[i].address);
					return;

				}

			}
		}
		else {
			printf("请输入你要找的电话：\n");
			scanf("%s", number);
			for (i; i < addr_num->sequence; ++i){
				if (strcmp(number, &addr_num->persinInfo[i].number) == 0){
					printf("该人的序号为%d\n", i + 1);
					printf("姓名为：%s\n", addr_num->persinInfo[i].name);
					printf("性别为：%s\n", addr_num->persinInfo[i].sex);
					printf("年龄为：%d\n", addr_num->persinInfo[i].age);
					printf("电话为：%s\n", addr_num->persinInfo[i].number);
					printf("地址为：%s\n", addr_num->persinInfo[i].address);
					return;
                  }
				
			}
		}
		printf("没找到人，请重新核对\n");
		return ;
	}
	return ;
}
void modify_people(person *addr_num){
	assert(addr_num != NULL);
	int choice = 0;
	while (1){
		printf("请输入你要修改的序号(输入0退出)\n");
		scanf("%d", &choice);
		if (choice == 0){ return; }
		if (choice<0 || choice>addr_num->sequence)
		{
			printf("没有该序号，请核对\n");
			continue;
		}
		else{
			printf("请输入你要修改的值:\n");
			printf("1.姓名\t2.性别\t3.年龄\t4.电话号码\t5.地址 \n");
            int choose = 0;
			scanf("%d", &choose);
			if (choose == 1){
				printf("请输入要修改的姓名:\n");
				scanf("%s", addr_num->persinInfo[choice-1].name);
				continue;
			}
			else if (choose == 2){
				printf("请输入要修改的性别:\n");
				scanf("%s", addr_num->persinInfo[choice - 1].sex);
				continue;;
			}
			else if (choose == 3){
				printf("请输入要修改的年龄:\n");
				scanf("%d", addr_num->persinInfo[choice - 1].age);
				continue;
			}
			else if (choose == 4){
				printf("请输入要修改的电话:\n");
				scanf("%s", addr_num->persinInfo[choice - 1].number);
			continue;
			}
			else if (choose == 5){
				printf("请输入要修改的地址:\n");
				scanf("%s", addr_num->persinInfo[choice - 1].address);
				continue;
			}
			else printf("选择错误\n");
		}

	}

}
int main(){

	Init(&addr_num);
	Fun arr[] = {
		NULL,
	  add_people,
 	  del_people,
 	  find_people,
 	  modify_people,
	  printf_people,
	  
	};
	int index = 0;
	while (1){
		index=print_menu();
		if (index==0)
		{
			printf("通讯录已结束\n");
			break;
		}
		else if (index<0 || index>6){
			printf("你输入的有误，请重新输入\n");
			continue;
		}
		system("cls");
		arr[index](&addr_num);
			}
	system("pause");
	return 0;
}