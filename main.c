/*********************************************

				   ����ó ���� ���α׷�

1. ����
	����ڷκ��� �̸�, ��ȭ��ȣ, ��������� �Է¹޾� �����ϰ�
	���� �� ����, �˻��� �� �� �ִ� ����� �����Ѵ�.

2. �Լ� ���� �� ����
	����ü�� ���õ� �Լ��� "function.h"�� ����, "function.c"�� ���ǵǾ��ִ�.
	���θ޴��� ���õ� �Լ��� "main_menu.h"�� ����, "main_menu.c"�� ���ǵǾ��ִ�.

3. ���
	���α׷� ���� �� ����ü�迭 ���� �� �ʱ�ȭ�� �̷������. �� ����ü�迭�� ����ڰ�
	������ �߰��ϰ� �����ϸ� ������ �� �ִ�.
	��ȭ��ȣ�θ� �����ϴ� ����� ���� ������, txt�������� �����ϰ� �ҷ� �� �� �ִ�
	����� �߰� �� �����̴�.

4. ����ȭ��
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