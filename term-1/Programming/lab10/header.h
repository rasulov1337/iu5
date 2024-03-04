#pragma once
#include <iostream>
#include <iomanip>

using namespace std;


void printMatrix(double** matrix, int n);
double** createMatrix(int n);
double** multiplyMatrixes(double** A, double** B, int n);
void findNewLineAndSwap(double** matrix, int n, int c, bool& reverseMatrixExists);
void straightWay(double** matrix, int n, bool& reverseMatrixExists);
void reverseWay(double** matrix, int n);
void printExtendedMatrix(double** matrix, int n);
void deleteMatrix(double** matrix, int n);