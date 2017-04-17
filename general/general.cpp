#include "../general/general.h"

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

void OutputDescMatr(double** M, int n, int m)
{ // function for output matrix on screen
	int i, j;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
			printf("%g ", M[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

void FillMatrix( /* Çàïîëíåíèå ìàòðèöû */
	double **M, //Ìàòðèöà
	double *y, //×òîáû çíàòü ãðàíèöû
	double *f, //×òîáû çíà÷èòü f(i)
	double h, // Øàã
	int N
)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{


			if (i == j)
			{
				M[i][j] = -2 / (h*h);
			}
			else if (j == i + 1)
			{
				M[i][j] = 1 / (h*h);
			}
			else if (i == j + 1)
			{
				M[i][j] = 1 / (h*h);
			}
			else {
				M[i][j] = 0;
			}

		}
	}

	for (int i = 0; i < N; i++)
	{
		M[i][N] = f[i];
	}
}