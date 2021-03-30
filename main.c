/*********************************************

				   연락처 저장 프로그램

1. 개요
	사용자로부터 이름, 전화번호, 생년월일을 입력받아 저장하고
	삭제 및 열람, 검색을 할 수 있는 기능을 제공한다.

2. 함수 선언 및 정의
	구조체와 관련된 함수는 "function.h"에 선언, "function.c"에 정의되어있다.
	메인메뉴와 관련된 함수는 "main_menu.h"에 선언, "main_menu.c"에 정의되어있다.

3. 기능
	프로그램 실행 시 구조체배열 선언 및 초기화가 이루어진다. 이 구조체배열에 사용자가
	정보를 추가하고 삭제하며 열람할 수 있다.
	전화번호부를 저장하는 기능은 현재 없으며, txt형식으로 저장하고 불러 올 수 있는
	기능을 추가 할 예정이다.

4. 메인화면
	1. registration
	2. ShowAll
	3. Delete
	4. FindByBirth
	5. Exit
*********************************************/
#include <stdio.h>
#include "struct_info.h"
#include "function.h"
#include "main_menu.h"

#define MAX_NUM 100

int main() {
	Info book[MAX_NUM] = { { '0', '0', '0' } };
	int current_user_cnt = 0;
	int flag = 0;

	while (!flag) {
		print_main_menu();
		switch (user_input_number(1, 5)) {
		case 1:
			current_user_cnt += insert(book, current_user_cnt);
			break;
		case 2:
			print_all(book, current_user_cnt);
			break;
		case 3:
			current_user_cnt -= delete_tel(book, current_user_cnt);
			break;
		case 4:
			find_by_birth(book, current_user_cnt);
			break;
		case 5:
			flag = 1;
			break;
		}
		printf("\n");
	}
}