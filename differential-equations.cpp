#include "stdafx.h"

using namespace std;

void triangMatr(int** A, float **B, int N)
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

void Solve(int **A, float *x, int N)
{
	int i, j, k;
	float res = 0;
	float **B = new float *[N];
	for (i = 0; i<N; i++)
		B[i] = new float[N + 1];

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


/*
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
*/
void InputDescMatr(int** M, int n, int m)
{ // function for input matrix on screen
	int i, j;
	printf("\n Please enter the matrix %d x %d\n", n, m);
	for (i = 0; i<n; i++)
		for (j = 0; j<m; j++)
			scanf_s("%d", &M[i][j]);
	printf("\n\n");
}

void OutputDescMatr(int** M, int n, int m)
{ // function for output matrix on screen
	int i, j;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
			printf("%d ", M[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

void main() {

const int N = 3, M = 4;

int** A = new int*[N];
for (int i = 0; i < N ; i++)
{
	A[i] = new int[M];
}
A[0][0] = 2; A[0][1] = 4; A[0][2] = 1; A[0][3] = 36;
A[1][0] = 5; A[1][1] = 2; A[1][2] = 1; A[1][3] = 47;
A[2][0] = 2; A[2][1] = 3; A[2][2] = 4; A[2][3] = 37;

OutputDescMatr(A, N, M);

float *x = new float[3];

Solve(A, x, N);

for (int i = 0; i < N; i++) {
	printf("%f ",x[i]);
}


delete[] x; x = NULL;for (int j = 0; j <= N - 1; j++)
{
	delete[] A[j];
}
delete[] A;
A = NULL;

}