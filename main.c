/**************************************************************************************************

													 ����ó ���� ���α׷�(v2.0)

1. ����
	����ڷκ��� �̸�, ��ȭ��ȣ, ��������� �Է¹޾� �����ϰ�
	���� �� ����, �˻��� �� �� �ִ� ����� �����Ѵ�.

2. �Լ� ���� �� ����
	����ü�� ���õ� �Լ��� "struct_function.h"�� ����, "struct_function.c"�� ���ǵǾ��ִ�.
	���θ޴��� ���õ� �Լ��� "main_menu.h"�� ����, "main_menu.c"�� ���ǵǾ��ִ�.
	���� ����°� ���õ� �Լ��� "file_io_function.h"�� ����, "file_io_function.c"�� ���ǵǾ��ִ�.

3. ���
	������� ����ó�� �ؽ�Ʈ ���Ϸ� �����ϰ� �ҷ��� �� �ִ�.
	����ڰ�	������ �߰��ϰ� �����ϸ� ������ �� �ִ�.

4. ����ȭ��
	1. registration
	2. ShowAll
	3. Delete
	4. FindByBirth
	5. Exit

5. ��������
	0.0 - �ִ� ���� ������ 100���� ���ѵǾ���.
	1.0 - ���� ���� ���� ������ ���� �ʰ� �޸� Ȱ�뵵�� ������.
			�̸�, ��ȭ��ȣ, ������ �ִ� 100BYTE���� ���� �����ϴ�.
	2.0 - ���α׷� ���� �� �����, "Phone_book.txt"���Ͽ� ������ �����ϰ� ���� ���� ��
			������ �о� �� �� �ִ�.
**************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "struct_info.h"
#include "struct_function.h"
#include "main_menu.h"
#include "file_io_function.h"

int main() {
	Info** book = (Info**)malloc(sizeof(Info*));
	int current_user_cnt = 0;
	int flag = 0;

	current_user_cnt = read_file_to_Info(book);

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

	write_file_by_Info(book, current_user_cnt);

	for (int i = 0; i < current_user_cnt; i++)
		free_Info(book[i]);
}