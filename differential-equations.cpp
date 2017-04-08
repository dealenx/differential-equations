#include "stdafx.h"

using namespace std;

void main() {
	setlocale(LC_CTYPE, "rus");
	const double PI = atan(1.0) * 4; //Число Pi
	//y = sin(PI*x)
	//y'' = (-1)*(PI)*(PI)*sin(PI*x)
	
	double a; // Левая граница
	double b; // Правая граница
	int n; // Количество всех точек, включая границы
	double h; // Шаг
	int s; // Количество отрезков
	int k; // Количество точек, помимо границ

	printf("y'' = ((-1)*(PI)^2)*sin(PI*x) \n");

	printf("Введите границы [a;b] в формале 'a b': ");
	scanf_s("%lf %lf",&a, &b);

	printf("Введите количество отрезков: ");
	scanf_s("%d", &s);
	n = s + 1;
	k = s - 1;
	h = (b - a) / s;

	double *y = new double[n];

	printf("\n");
	
	printf("Введите y(%g): ",a);
	scanf_s("%lf", &y[0]);

	printf("Введите y(%g): ", b);
	scanf_s("%lf", &y[s]);

	printf("H  = %lf", h);

	const int N = k, M = s; // Размерность матрицы

	double *x = new double[n];

	for (int i = 0; i < n; i++) 
	{
		x[i] = a + (i*h);
		printf("x[%d]=%g ",i,x[i]);
	}
	printf("\n");

	double *f = new double[s];

	for (int i = 0; i < n; i++) 
	{
		f[i] = ((PI)*(PI)*sin(PI * x[i+1]  )) * (-1);

		if (i == 0)
		{
			f[i] = f[i] - y[0];
		}
		if (i == n - 1)
		{
			f[i] = f[i] - y[s];
		}
	}

	for (int i = 0; i < N; i++) 
	{
		printf("f[%d] = %g ", i, f[i]);
	} printf("\n\n");

	double** A = new double*[N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new double[M];
	}

	FillMatrix(A,y,f,h,N);

	printf("Matrix A: \n");
	OutputDescMatr(A, N, M);

	double *xx = new double[k];

	Solve(A, xx, N);

	for (int i = 0; i < N; i++) 
	{
		y[i + 1] = xx[i];
	} 
	
	// Вычисление теоритическое 'y'
	double *yt = new double[n];

	for (int i = 0; i < n; i++) 
	{
		yt[i] = sin(PI*x[i]);
	}

	for (int i = 0; i < n; i++) 
	{
		printf("y[%d] = %lf, yt[%d] = %lf, y[%d] - yt[%d] = %lf \n", i, y[i], i, yt[i], i, i, abs(y[i] - yt[i]));
	} printf("\n");

	delete[] xx; xx = NULL;
	for (int j = 0; j <= N - 1; j++)
	{
		delete[] A[j];
	}
	delete[] A;
	A = NULL;
}