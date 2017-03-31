#include "file.h"

void main() {
	double a, b, n, h;

	printf("Enter a,b, n: ");
	scanf_s("%lf %lf %lf",&a, &b, &n);
	h = (b - a) / n;
	printf("a - %lf, b - %lf, n - %lf, h - %lf \n", a, b, n, h);

	double *x = new double[n];

	for (int i = 1; i < n + 1; i++) {
		x[i] = a + (i*h);
		printf("x[%d]=%lf ",i,x[i]);
	}

}

