#include <stdio.h>

int main(void) {

	printf("Hello world \n");
	printf("%d \n", 10 + 20);
	// 32bit(4����Ʈ) �޸𸮰��� Ȯ��
	int a, b, c;
	a = 10;
	b = 20;
	printf("%d + %d = %d \n", a, b, a + b);
	
	printf("����� ���̴�? \n");
	scanf("%d", &c);
	printf("%d \n", c);

	return 0;
}