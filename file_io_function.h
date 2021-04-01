#ifndef FILE_IO_FUNCTION
#define FILE_IO_FUNCTION
#include <stdio.h>
#include "struct_info.h"

/*********************
	Function name
	- read_file_to_Info

	Pre-Conditio
	- ����� ���Ͽ��� ������ �о� ���� �� ����ü�����͹迭�� ���޹޴´�.
	- ������ ���ϸ� ���� �� �ִ�.

	Post-Condition
	- ���Ͽ��� �о� �� ������ ����ü�����͹迭�� �����Ҵ��Ѵ�.
	- ����� ������ ���� ��ȯ�Ѵ�.

	Exception-Handling
	- ������ ���� ��� "Couldn't open file!"�� ����ϰ� ���� �۵��Ѵ�.(ó�� ����ϴ� ���)

	Describe
	- ���Ͽ� ����� ������ �о�´�.
**********************/
int read_file_to_Info(Info **st);

/*********************
	Function name
	- write_file_by_Info

	Pre-Conditio
	- ���Ͽ� ������ �ϴ� �������� ���� �� ����ü�����͹迭�� ���޹޴´�.

	Post-Condition
	- ������ ���ϸ����� ������ �����Ѵ�.

	Exception-Handling
	- none

	Describe
	- ������ ���Ͽ� �����Ѵ�.
**********************/
void write_file_by_Info(Info **st);

#endif
