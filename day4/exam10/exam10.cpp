#include <stdio.h>

int main(void) {

	printf("%d %c %d \n", 65, 65, 'A');

	printf("%d %d %d \n", 'A', 'B', 'C');

	printf("%c %c %c \n", 65, 66, 67);

	//hello
	printf("%c%c%c%c%c \n", 104, 101, 108, 108, 111);

	char blood_types;
	printf("����� �������� ? \n");

	scanf("%c", &blood_types);
	
	printf("%c �Դϴ�.", blood_types);
	
	return 0;
}