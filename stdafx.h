// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once

#include "targetver.h"

#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <math.h>


// TODO: 

void triangMatr(double** A, double **B, int N);
void Solve(double **A, double *x, int N);
void InputDescMatr(double** M, int n, int m);
void OutputDescMatr(double** M, int n, int m);