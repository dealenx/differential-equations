// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once

#include "targetver.h"

#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <math.h>
#include <clocale>


// TODO: 

void triangMatr(double** A, double **B, int N);
void Solve(double **A, double *x, int N);
void OutputDescMatr(double** M, int n, int m);
void FillMatrix(
	double **M, //Матрица
	double *y, //Чтобы знать границы
	double *f, //Чтобы значить f(i)
	double h, // Шаг
	int N
);