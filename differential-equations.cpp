#include "stdafx.h"

using namespace std;

void main() {
	const double PI = atan(1.0) * 4;
	//y = sin(PI*x)
	//y'' = (-1)*(PI)*(PI)*sin(PI*x)
	
	double a, b, n, h;

	printf("Enter a,b, n: ");
	scanf_s("%lf %lf %lf",&a, &b, &n);
	h = (b - a) / (n + 1);
	printf("a=%lf, b=%lf, n=%lf, h=%lf \n", a, b, n, h);
	printf("\n");

	double *x = new double[n + 1];

	for (int i = 0; i <= (n + 1); i++) {
		x[i] = a + (i*h);
		printf("x[%d]=%lf ",i,x[i]);
	}
	printf("\n");

	double *y = new double[n + 1];
	
	y[0] = ((PI)*(PI)*sin(PI * 0)) * (-1);
	y[4] = ((PI)*(PI)*sin(PI * 1)) * (-1);

	printf("\n y0 = %lf y4 = %lf \n", y[0], y[4]);
	printf("\n");

}

