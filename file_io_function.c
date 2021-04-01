#include <stdlib.h>
#include <string.h>
#include "file_io_function.h"

int read_file_to_Info(Info** st) {
	FILE* fp = fopen(FILE_NAME, "r");
	//exception handling
	if (fp == NULL) {
		printf("Couldn't open file!\n");
		return 0;
	}
	int user_cnt = 0;
	char tmp[MAX_NUM];
	fscanf(fp, "%d", &user_cnt);
	st = (Info**)realloc(st, sizeof(Info*) * user_cnt);
	fgetc(fp);
	st[0] = (Info*)malloc(sizeof(Info));
	fscanf(fp, "%s", tmp);
	st[0]->name = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
	strcpy(st[0]->name, tmp);
	fscanf(fp, "%s", tmp);
	st[0]->phone_number = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
	strcpy(st[0]->phone_number, tmp);
	fscanf(fp, "%s", tmp);
	st[0]->birth = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
	strcpy(st[0]->birth, tmp);
	
	for (int i = 1; !feof(fp); i++) {
		st[i] = (Info*)malloc(sizeof(Info));
		fscanf(fp, "%s", tmp);
		st[i]->name = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
		strcpy(st[i]->name, tmp);
		fscanf(fp, "%s", tmp);
		st[i]->phone_number = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
		strcpy(st[i]->phone_number, tmp);
		fscanf(fp, "%s", tmp);
		st[i]->birth = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
		strcpy(st[i]->birth, tmp);
	}
	fclose(fp);

	return user_cnt;
}

void write_file_by_Info(Info** st, int user_cnt) {
	FILE* fp = fopen(FILE_NAME, "w");
	fprintf(fp, "%d\n", user_cnt);
	for (int i = 0; i < user_cnt; i++)
		fprintf(fp, "%s %s %s\n", st[i]->name, st[i]->phone_number, st[i]->birth);
	fclose(fp);
}
