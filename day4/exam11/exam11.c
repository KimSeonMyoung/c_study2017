#include <stdio.h>

int main(void) {

	int a, b;
	double c;

	printf("���ȣ�� �Է��ϼ��� \n");
	scanf("%d", &a);
	printf("Ÿ���� �Է��ϼ��� \n");
	scanf("%lf", &c);
	printf("���̸� �Է��ϼ��� \n");
	scanf("%d", &b);
	printf("%d�� ������ Ÿ���� %lf�̰� ���̴� %d �Դϴ�. \n", a, c, b);

	return 0;
}