#pragma once

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
	double **M, 
	double *y, 
	double *f, 
	double h, 
	int N
);