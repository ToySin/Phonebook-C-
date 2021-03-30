#ifndef MAIN_MENU
#define MAIN_MENU

/*********************
	Function name
	- print_main_menu

	Pre-Condition
	- none

	Post-Condition
	- 정해진 메인메뉴를 화면에 출력한다.

	Describe
	- 메인메뉴 단순 출력
**********************/
void print_main_menu();

/*********************
	Function name
	- user_input_number

	Pre-Condition
	- 입력받을 최소값과 최대값을 지정한다.

	Post-Condition
	- 지정한 최소값과 최대값을 반환한다. 지정값이 입력 될 때까지 반복한다.

	Describe
	- 사용자로부터 값을 입력받는다.
**********************/
int user_input_number(int user_input_min, int user_input_max);

#endif // !MAIN_MENU

