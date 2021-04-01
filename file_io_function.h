#ifndef FILE_IO_FUNCTION
#define FILE_IO_FUNCTION
#include <stdio.h>
#include "struct_info.h"

/*********************
	Function name
	- read_file_to_Info

	Pre-Conditio
	- 저장된 파일에서 정보를 읽어 저장 할 구조체포인터배열을 전달받는다.
	- 지정된 파일명만 읽을 수 있다.

	Post-Condition
	- 파일에서 읽어 온 정보로 구조체포인터배열을 동적할당한다.
	- 저장된 정보의 수를 반환한다.

	Exception-Handling
	- 파일이 없는 경우 "Couldn't open file!"을 출력하고 정상 작동한다.(처음 사용하는 경우)

	Describe
	- 파일에 저장된 정보를 읽어온다.
**********************/
int read_file_to_Info(Info **st);

/*********************
	Function name
	- write_file_by_Info

	Pre-Conditio
	- 파일에 쓰고자 하는 정보들이 저장 된 구조체포인터배열을 전달받는다.

	Post-Condition
	- 지정된 파일명으로 정보를 저장한다.

	Exception-Handling
	- none

	Describe
	- 정보를 파일에 저장한다.
**********************/
void write_file_by_Info(Info **st);

#endif
