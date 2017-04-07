// stdafx.cpp: исходный файл, содержащий только стандартные включаемые модули
// differential-equations.pch будет предкомпилированным заголовком
// stdafx.obj будет содержать предварительно откомпилированные сведения о типе

#include "stdafx.h"

// TODO:

void triangMatr(double** A, double **B, int N)
{
	int i, j, k;
	float koef;
	for (i = 0; i<N; i++)
		for (j = 0; j<N + 1; j++)
			B[i][j] = A[i][j];

	for (k = 0; k<N; k++)
	{
		for (i = k + 1; i<N; i++)
		{
			koef = -1.0 *B[i][k] / B[k][k];
			for (j = k; j<N + 1; j++)
				B[i][j] = B[i][j] + B[k][j] * koef;
		}
	}
}

void Solve(double **A, double *x, int N)
{
	int i, j, k;
	double res = 0;
	double **B = new double *[N];
	for (i = 0; i<N; i++)
		B[i] = new double[N + 1];

	triangMatr(A, B, N);
	for (i = N - 1; i >= 0; i--)
	{
		res = 0;
		for (j = i + 1; j <= N - 1; j++)
			res -= x[j] * B[i][j];
		res += B[i][N];
		x[i] = res / B[i][i];
	}
	for (i = 0; i<N; i++)
		delete[] B[i];
	delete[]B;
}

void InputDescMatr(double** M, int n, int m)
{ // function for input matrix on screen
	int i, j;
	printf("\n Please enter the matrix %d x %d\n", n, m);
	for (i = 0; i<n; i++)
		for (j = 0; j<m; j++)
			scanf_s("%lf", &M[i][j]);
	printf("\n\n");
}

void OutputDescMatr(double** M, int n, int m)
{ // function for output matrix on screen
	int i, j;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
			printf("%lf ", M[i][j]);
		printf("\n");
	}
	printf("\n\n");
}