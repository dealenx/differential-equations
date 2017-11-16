#include "./general/general.h"

using namespace std;



void main() {
	setlocale(LC_CTYPE, "rus");
	
									 //y = sin(PI*x)
									 //y'' = (-1)*(PI)*(PI)*sin(PI*x)

	double a; // Левая граница
	double b; // Правая граница

	printf("y'' = ((-1)*(PI)^2)*sin(PI*x) \n");

	printf("Введите границы [a;b] в формате 'a b': ");
	scanf_s("%lf %lf", &a, &b);

	int s; // Количество сегментов


	printf("Введите количество сегментов: ");
	scanf_s("%d", &s);

	int k = s - 1; // количество точек, не включая границы

	long int n = s + 1; // Количество всех точек, включая границы
	double h = (b - a) / s; // Шаг

	double *y_full = new double[n];
	double *y_forMatrix= new double[k];
	// Точное решение 'y'
	double *yt_full = new double[n];
	double *yt_forMatrix = new double[k];

	double *approx = new double[k]; // Для аппроксимации

	printf("\n");

	printf("Введите y(%g): ", a); // Значение функции y(a)
	scanf_s("%lf", &y_full[0]);

	printf("Введите y(%g): ", b);  // Значение функции y(b)
	scanf_s("%lf", &y_full[s]);

	const int N = k, M = s; // Размерность матрицы

	double *x = new double[n];

	for (int i = 0; i < n; i++)
	{
		x[i] = a + (i*h);
	}
	printf("\n");

	double *f = new double[s];

	for (int i = 0; i < n; i++)
	{
		f[i] = ((PI)*(PI)*sin(PI * x[i + 1])) * (-1);

		if (i == 0)
		{
			f[i] = f[i] - y_full[0];
		}
		if (i == s)
		{
			f[i] = f[i] - y_full[s];
		}
	}


	double** A = new double*[N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new double[M];
	}

	printf("Заполнение матрицы . . . \n");
	FillMatrix(A, f, h, N);

	printf("Решение метода Гаусса . . . \n");
	Solve(A, y_forMatrix, N);

	for (int i = 0; i < N; i++)
	{
		y_full[i + 1] = y_forMatrix[i];
	}

	for (int i = 0; i < n; i++)
	{
		yt_full[i] = sin(PI*x[i]);
	}
	for (int i = 0; i < k; i++)
	{
		yt_forMatrix[i] = yt_full[i + 1];
	}

	// Дельта 'y'
	double *yDelta = new double[n];

	for (int i = 0; i < n; i++)
	{
		yDelta[i] = abs(abs(y_full[i]) - abs(yt_full[i]));
	}

	printf("\n Шаг: %lf , практическая погрешность (только при коэффициенте равным 0): %lf \n", h, MaxVector(yDelta, n));

	cout << endl << "Проверка численного решения" << endl;
	checkFillMatrix(A, y_forMatrix, f, approx, N);
	cout << "Аппроксимация ( max|Ау-f| ): " << MaxVectorAbs(approx, k) << endl;

	cout << endl << "Проверка точного решения (только при коэффициенте равным 0)" << endl;
	checkFillMatrix(A, yt_forMatrix, f, approx, N); cout << endl;
	cout << "Аппроксимация ( max|Ау-f| ): " << MaxVectorAbs(approx, k) << endl;
}