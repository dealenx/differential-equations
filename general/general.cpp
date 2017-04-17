#include "../general/general.h"

// TODO:

double MaxVector(double *y, int length) 
{
	double max = y[0];

	for (int i = 1; i < length; i++)
	{
		if ( max < y[i] )
		{
			max = y[i];
		}
	}

	return max;
}

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

void FillMatrix( /* Заполнение матрицы */
	double **M, //Матрица
	double *f, //заполнения массива f(i)
	double h, // Шаг
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

void GeneralFunc
(	
	double a, // Левая граница
	double b, // Правая граница
	double yFirst,  // Значение функции y(a)
	double yLast, // Значение функции y(b)
	 int s // Количество сегментов
)
{
	int k = s - 1; // количество точек, не включая границы

	long int n = s + 1; // Количество всех точек, включая границы
	double h = (b - a) / s; // Шаг

	double *y = new double[n];
	y[0] = yFirst; y[s] = yLast;

	const int N = k, M = s; // Размерность матрицы

	double *x = new double[n];

	for (int i = 0; i < n; i++)
	{
		x[i] = a + (i*h);
		//printf("x[%d]=%g ", i, x[i]);
	}
	printf("\n");

	double *f = new double[s];

	for (int i = 0; i < n; i++)
	{
		f[i] = ((PI)*(PI)*sin(PI * x[i + 1])) * (-1);

		if (i == 0)
		{
			f[i] = f[i] - y[0];
		}
		if (i == n - 1)
		{
			f[i] = f[i] - y[s];
		}
	}


	double** A = new double*[N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new double[M];
	}

	printf("Заполнение матрицы . . . \n");
	FillMatrix(A, f, h, N);

	double *yy = new double[k];

	printf("Решение метода Гаусса . . . \n");
	Solve(A, yy, N);

	for (int i = 0; i < N; i++)
	{
		y[i + 1] = yy[i];
	}

	// Теоритическая 'y'
	double *yTheoretical = new double[n];

	for (int i = 0; i < n; i++)
	{
		yTheoretical[i] = sin(PI*x[i]);
	}

	// Дельта 'y'
	double *yDelta = new double[n];

	for (int i = 0; i < n; i++)
	{
		yDelta[i] = abs(y[i] - yTheoretical[i]);
	}

	printf("\n Шаг: %lf , Дельта 'y' максимальное: %lf \n", h, MaxVector(yDelta, n));
}