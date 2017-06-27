#include <stdio.h>

int main(void) {

	printf("Hello world \n");
	printf("%d \n", 10 + 20);
	// 32bit(4바이트) 메모리공간 확보
	int a, b, c;
	a = 10;
	b = 20;
	printf("%d + %d = %d \n", a, b, a + b);
	
	printf("당신의 나이는? \n");
	scanf("%d", &c);
	printf("%d \n", c);

	return 0;
}