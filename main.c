/**************************************************************************************************

													 연락처 저장 프로그램(v1.0)

1. 개요
	사용자로부터 이름, 전화번호, 생년월일을 입력받아 저장하고
	삭제 및 열람, 검색을 할 수 있는 기능을 제공한다.

2. 함수 선언 및 정의
	구조체와 관련된 함수는 "struct_function.h"에 선언, "struct_function.c"에 정의되어있다.
	메인메뉴와 관련된 함수는 "main_menu.h"에 선언, "main_menu.c"에 정의되어있다.

3. 기능
	프로그램 실행 시 구조체포인터배열 선언 및 초기화가 이루어진다.
	사용자가	정보를 추가하고 삭제하며 열람할 수 있다.
	전화번호부를 외부에 저장하는 기능은 현재 없으며,
	txt형식으로 저장하고 불러 올 수 있는 기능을 추가 할 예정이다.

4. 메인화면
	1. registration
	2. ShowAll
	3. Delete
	4. FindByBirth
	5. Exit

5. 버전설명
	0.0 - 구조체배열을 이용하여 최대 저장 정보가 100개로 제한되었다.
	1.0 - 구조체포인터를 이용하여 저장 정보 수에 제한을 두지 않고, 동적할당을 이용한
			메모리 활용도를 높였다. 이름, 전화번호, 생일은 최대 100BYTE까지 저장 가능하다.
**************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "struct_info.h"
#include "struct_function.h"
#include "main_menu.h"

int main() {
	Info** book = NULL;
	int current_user_cnt = 0;
	int flag = 0;

	while (!flag) {
		print_main_menu();
		switch (user_input_number(1, 5)) {
		case 1:
			book = (Info**)realloc(book, sizeof(Info*) * (current_user_cnt + 1));
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