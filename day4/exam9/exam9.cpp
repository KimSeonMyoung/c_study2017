#include <stdio.h>

int main(void) {

	//double a, b, c;

	//a = 2.5;
	//b = 2.5;

	////printf("%f %d \n", a, b);

	////printf("실수값을 입력하시오 \n");
	////scanf("%f \n", &c);
	////printf("%f \n", c);

	float num;
	printf("float 실수를 입력하시오 \n");
	scanf("%lf", &num);
	printf("%lf 를 입력하였습니다. \n", num);

	return 0;
}