#include "stdafx.h"

using namespace std;

void main() {
	const double PI = atan(1.0) * 4;
	//y = sin(PI*x)
	//y'' = (-1)*(PI)*(PI)*sin(PI*x)

	const int N = 3, M = 4;
	
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
	
	y[0] = 0;
	y[4] = 0;

	printf("\n y0 = %lf y4 = %lf \n", y[0], y[4]);
	printf("\n");

	double *f = new double[n];

	for (int i = 0; i < n; i++) {
		f[i] = ((PI)*(PI)*sin(PI * x[i+1]  )) * (-1);
	}

	for (int i = 0; i < N; i++) {
		printf("f[%d] = %lf ", i, f[i]);
	} printf("\n\n");

	double** A = new double*[N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new double[M];
	}

	A[0][0] = -2; A[0][1] = 1; A[0][2] = 0; A[0][3] = f[0];
	A[1][0] = 1; A[1][1] = -2; A[1][2] = 1; A[1][3] = f[1];
	A[2][0] = 0; A[2][1] = 1; A[2][2] = -2; A[2][3] = f[2];

	printf("Matrix A: \n");
	OutputDescMatr(A, N, M);

	double *xx = new double[3];

	Solve(A, xx, N);

	for (int i = 0; i < N; i++) {
		y[i + 1] = xx[i];
	} 

	double *yt = new double[n+2];

	for (int i = 0; i < n+2; i++) {
		yt[i] = sin(PI*x[i]);
	}

	for (int i = 0; i < N+2; i++) {
		printf("y[%d] = %lf, yt[%d] = %lf, y[%d] - yt[%d] = %lf \n", i, y[i], i, yt[i], i, i, abs(y[i] - yt[i]));
	} printf("\n");

	delete[] xx; xx = NULL;	for (int j = 0; j <= N - 1; j++)
	{
		delete[] A[j];
	}
	delete[] A;
	A = NULL;


}