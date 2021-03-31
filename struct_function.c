#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_function.h"

int insert(Info** st, const int user_cnt) {
	//memory allocation
	st[user_cnt] = (Info*)malloc(sizeof(Info));

	//user input
	new_Info_insert(st[user_cnt]);

	//sort by name(ASCII)
	for (int i = 0; i < user_cnt; i++) {
		if (strcmp(st[i]->name, st[user_cnt]->name) == 1) {
			Info* tmp = st[user_cnt];
			for (int j = user_cnt; j > i; j--)
				st[j] = st[j - 1];
			st[i] = tmp;

			//in main function, can be used in "user_cnt += insert()"
			return 1;
		}
	}
	return 1;
}

int delete_tel(Info** st, const int user_cnt) {
	//exception handling
	if (user_cnt == 0) {
		printf("NO MEMBER\n");
		return 0;
	}

	//user input
	char target_name[MAX_NUM] = { 0 };
	printf("Enter the name you want to delete: ");
	scanf("%s", target_name);

	//delete target name
	for (int i = 0; i < user_cnt; i++) {
		//if found
		if (strcmp(st[i]->name, target_name) == 0) {
			//pull the data forward one space and realloc st
			for (int j = i; j < user_cnt - 1; j++)
				st[j] = st[j + 1];
			free_Info(st[user_cnt - 1]);
			st = (Info**)realloc(st, sizeof(Info*) * (user_cnt - 1));
			//in main function, can be used in "user_cnt -= delete_tel()"
			return 1;
		}
	}

	//can't find target
	printf("CAN'T FIND \"%s\".\n", target_name);
	return 0;
}

void print_all(const Info** st, const int user_cnt) {
	//exception handling
	if (!user_cnt)
		printf("Phone Book is empty.\n");
	else
		for (int i = 0; i < user_cnt; i++)
			printf("%d. Name: %s, Phone Number: %s, Birthday: %s\n",
				i + 1, st[i]->name, st[i]->phone_number, st[i]->birth);
}

void find_by_birth(const Info** st, const int user_cnt) {
	char target_birth[3] = { 0 };
	int flag = 0;

	printf("Enter the birthday(month) you would like to find. ex) 03, 11 : ");
	scanf("%s", target_birth);

	for (int i = 0; i < user_cnt; i++) {
		if (strncmp(&st[i]->birth[4], target_birth, 2) == 0) {
			printf("%d. Name: %s, Phone Number: %s, Birthday: %s\n",
				++flag, st[i]->name, st[i]->phone_number, st[i]->birth);
		}
	}

	if (flag == 0)
		printf("Can't find the match person\n");
}

void new_Info_insert(Info* st) {
	if (!st) {
		printf("NULL PTR\n");
		return;
	}
	
	char tmp[MAX_NUM];
	
	printf("Enter the name without blank: ");
	scanf("%s", tmp);
	st->name = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
	strcpy(st->name, tmp);
	printf("Enter the phone number without '-': ");
	scanf("%s", tmp);
	st->phone_number = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
	strcpy(st->phone_number, tmp);
	printf("Enter the birthday(YYYYMMDD): ");
	scanf("%s", tmp);
	st->birth = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
	strcpy(st->birth, tmp);
}

void free_Info(Info* st) {
	//exception handling
	if (!st)
		printf("NULL PTR\n");
	else {
		free(st->name);
		free(st->phone_number);
		free(st->birth);
		free(st);
	}
}