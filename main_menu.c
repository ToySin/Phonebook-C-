#include "main_menu.h"

void print_main_menu() {
	printf("1. registration\n");
	printf("2. ShowAll\n");
	printf("3. Delete\n");
	printf("4. FindByBirth\n");
	printf("5. Exit\n");
}

int user_input_number(int min, int max) {
	int user_input = 0;
	
	while (1) {
		printf("Input number(%d~%d): ", min, max);
		scanf("%d", &user_input);
		if (user_input >= min && user_input <= max)
			return user_input;
		printf("Input right number(%d~%d)\n", min, max);
	}
}