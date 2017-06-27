#include <stdio.h>

int main(void) {

	int a, b;
	double c;

	printf("등번호를 입력하세요 \n");
	scanf("%d", &a);
	printf("타율을 입력하세요 \n");
	scanf("%lf", &c);
	printf("나이를 입력하세요 \n");
	scanf("%d", &b);
	printf("%d번 선수의 타율은 %lf이고 나이는 %d 입니다. \n", a, c, b);

	return 0;
}