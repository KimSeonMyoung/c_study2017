#include <stdio.h>

int main(void) {

	//32bit (4바이트)
	int a, b, c;
	int num = 100;
	a = 10;
	b = 20;
	printf("%d + %d = %d \n", a, b, a + b);
	printf("%d \n", num);

	printf("당신의 나이는? \n");
	scanf("%d", &c);
	printf("%d \n", c);

	return 0;
}