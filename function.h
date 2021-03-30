#ifndef FUNCTION
#define FUNCTION
#include "struct_info.h"

/*********************
	Function name
	- insert

	Pre-Conditio 
	- 입력받을 정보를 저장할 구조체배열의 시작주소를 전달받는다.
	- 현재 저장되어있는 정보의 개수를 int형으로 전달받는다.
	- 동명이인은 없다.
	- 입력정보의 검증은 하지 않는다.
	- 입력정보에는 빈칸을 허용하지 않는다.

	Post-Condition
	- 전달받은 구조체배열에 입력받은 정보가 아스키코드상의 이름순으로 정렬되어 추가된다.
	- 정상적으로 저장 된 경우에는 1을 반환한다.

	Exception-Handling
	- 최대 수용 가능 한 연락처 수에 도달했으면 "OVERFLOW" 출력 후 시작하면으로 복귀한다.
	- 0을 반환한다.
	- 정보를 입력 받기전에 먼저 판단한다.
	
	Describe
	- 정보를 입력받아 이름 순으로 정렬하여 저장한다.
	- 추후 입력정보를 검증하는 방식으로 업데이트 예정이다. (동명이인 포함)
**********************/
int insert(Info*, const int);

/*********************
	Function name
	- delete_tel

	Pre-Condition
	- 삭제하고 싶은 정보를 가지고 있을 구조체배열의 시작주소를 전달받는다.
	- 현재 저장되어있는 정보의 개수를 int형으로 전달받는다.
	- 입력정보에는 빈칸을 허용하지 않는다.

	Post-Condition
	- 전달받은 구조체배열에 삭제하고 싶은 정보를 삭제하고 자료를 재 정렬한다.
	- 정상적으로 삭제 된 경우에는 1을 반환한다.

	Exception-Handling
	- 저장된 정보가 없을 경우에는 "NO MEMBER" 출력 후 시작화면으로 복귀한다.
	- 입력된 사람의 정보가 없을 경우에는 "CAN'T FIND (user_input)."출력 후 시작화면으로 복귀한다.

	Describe
	- 이름을 입력받아 구조체배열 내에서 특정 인원을 찾아 정보를 삭제한다.(제로필)
	- 동명이인 입력이 활성화되면 그에 따른 삭제 방식을 업데이트 예정이다.
**********************/
int delete_tel(Info*, const int);

/*********************
	Function name
	- print_all

	Pre-Condition
	- 출력하고자 하는 정보가 저장된 구조체배열의 시작주소를 전달받는다.
	- 현재 저장되어있는 정보의 개수를 int형으로 전달받는다.

	Post-Condition
	- 화면에 저장된 모든 전화번호가 정렬 된 순서대로 출력 후 시작화면으로 복귀한다.

	Exception-Handling
	- 저장된 정보가 없을 경우 "Phone Book is empty"를 출력 후 시작화면으로 복귀한다.

	Describe
	- 이름순으로 정렬되어있는 모든 정보를 화면에 출력한다.
**********************/
void print_all(const Info*, const int);

/*********************
	Function name
	- find_by_birth

	Pre-Condition
	- 찾고자하는 정보를 가지고 있을 구조체배열의 시작주소를 전달받는다.
	- 현재 저장되어있는 정보의 개수를 int형으로 전달받는다.
	- 입력정보는 생년월일에서 월만 입력받는다.
	- 입력정보를 검증하지 않는다.
	- 입력정보에는 빈칸을 허용하지 않는다.

	Post-Condition
	- 입력받는 월과 동일한 생년월일을 가진 사람을 모두 출력한다.
	- 여러명이 출력될 경우 아스키코드에 의해 정렬된 순서대로 출력된다.

	Describe
	- 특정 월에 태어난 사람의 정보를 찾아서 출력한다.
	- 생년월일 모두를 이용한 탐색방법을 업데이트 예정이다.
**********************/
void find_by_birth(const Info*, const int);

#endif // !FUNCTION

