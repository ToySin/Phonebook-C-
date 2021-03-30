#include <stdio.h>
#include <string.h>
#include "function.h"

int insert(Info* st, const int user_cnt) {
	//예외처리
	if (user_cnt == 100) {
		printf("OVERFLOW");
		return 0;
	}

	//입력받은 값 저장(가장 뒤)
	printf("Enter the name without blank: ");
	scanf("%s", (st + user_cnt)->name);
	printf("Enter the phone number without '-': ");
	scanf("%s", (st + user_cnt)->phone_number);
	printf("Enter the birthday(YYYYMMDD): ");
	scanf("%s",(st + user_cnt)->birth);

	//이름순으로 정렬
	for (int i = 0; i < user_cnt; i++) {
		if (strcmp((st + i)->name, (st + user_cnt)->name) == 1) {
			Info tmp = st[user_cnt];
			for (int j = user_cnt; j > i; j--)
				st[j] = st[j - 1];
			st[i] = tmp;

			//main함수에서 user_cnt += insert() 방식으로 활용 가능
			return 1;
		}
	}
	return 1;
}

int delete_tel(Info* st, const int user_cnt) {
	//exception handling
	if (user_cnt == 0) {
		printf("NO MEMBER\n");
		return 0;
	}
	
	//user input
	char target_name[21] = { 0 };
	printf("Enter the name you want to delete: ");
	scanf("%s", target_name);

	//empty init struct for delete
	Info empty = { 0, 0, 0 };

	//delete target name
	for (int i = 0; i < user_cnt; i++) {
		//if found
		if (strcmp(st[i].name, target_name) == 0) {
			//if target is last of list
			if (i == 99)
				st[i] = empty;
			//else pull the data forward one space and input empty at last
			else {
				for (int j = i; j < user_cnt - 1; j++)
					st[j] = st[j + 1];
				st[user_cnt - 1] = empty;
			}
			//use like "user_cnt -= delete_tel()"
			return 1;
		}
	}

	//can't find target
	printf("Can't find \"%s\".\n", target_name);
	return 0;
}

void print_all(const Info* st, const int user_cnt) {
	//예외처리
	if (!user_cnt)
		printf("Phone Book is empty.\n");
	else
		for (int i = 0; i < user_cnt; i++)
			printf("%s %s %s\n", st[i].name, st[i].phone_number, st[i].birth);
}

void find_by_birth(const Info* st, const int user_cnt) {
	char target_birth[3] = { 0 };
	int flag = 0;

	printf("Enter the birthday(month) you would like to find. ex) 03, 11 : ");
	scanf("%s", target_birth);

	for (int i = 0; i < user_cnt; i++) {
		if (strncmp(&st[i].birth[4], target_birth, 2) == 0) {
			printf("%s %s %s\n", st[i].name, st[i].phone_number, st[i].birth);
			flag = 1;
		}
	}

	if (flag == 0)
		printf("Can't find the birthday person\n");
}