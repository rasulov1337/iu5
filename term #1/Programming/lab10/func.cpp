#include "F.h"

void Aout(double** A, int sizeA) {
	for (int i = 0; i < sizeA / 2; i++) {
		for (int j = 0; j < sizeA; j++) {
			cout << " " << A[i][j];
		}
		cout << endl;
	}
}
void AAout(double** A, int sizeA) {
	for (int i = 0; i < sizeA / 2; i++) {
		for (int j = 4; j < sizeA; j++) {
			cout << " " << A[i][j];
		}
		cout << endl;
	}
}

void AA_out(double** A, int sizeA, int ConsSize)
{
	int len = 0, N = sizeA;
	while (N < sizeA * 2)
	{
		for (int i = 0; i < sizeA; i++)
		{
			for (int j = N; j<int(ConsSize / len) + N; j++)
			{
				if (j == sizeA * 2) break;
				if (A[i][j] >= 0 && A[i][j] < 10) cout << " ";
				cout << " " << fixed << A[i][j];
			}
			cout << endl;
		}
		N += int(ConsSize / len);
		cout << endl;
	}
}

void A_out(double** A, int sizeA, int prec, int com, int ConsSize) {
	int len = 0, N = sizeA;
	if (com == 1) 
	{ //Фиксированная точка
		len = 4 + prec; //пробел, знак, до запятой, запятая, точность
		while (N < sizeA * 2) 
		{
			for (int i = 0; i < sizeA; i++) 
			{
				for (int j = N; j<int(ConsSize / len) + N; j++) 
				{
					if (j == sizeA * 2) break;
					if (A[i][j] >= 0 && A[i][j] < 10) cout << " ";
					cout << " " << fixed << setprecision(prec) << A[i][j];
				}
				cout << endl;
			}
			N += int(ConsSize / len);
			cout << endl;
		}
	}
	else 
	{ //Научный
		len = 9 + prec;
		while (N < sizeA * 2) {
			for (int i = 0; i < sizeA; i++) {
				for (int j = N; j<int(ConsSize / len) + N; j++) {
					if (j == sizeA * 2) break;
					if (A[i][j] < 0)	cout << " " << scientific << setprecision(prec) << A[i][j];
					else cout << "  " << scientific << setprecision(prec) << A[i][j];
				}
				cout << endl;
			}
			N += int(ConsSize / len);
			cout << endl;
		}
	}
}

int ForwStr(double** A, int sizeA) {
	for (int j = 0; j < sizeA; j++) {
		if (A[j][j] != 1) return 0; //На главной диагонали не единица
		for (int i = j + 1; i < sizeA; i++) {
			if (A[i][j] != 0) return 0; //Под главной диагональю не нули
		}
	}
	return 1;
}

int ReverseStr(double** A, int sizeA) {
	for (int j = sizeA - 1; j > -1; j--) {
		for (int i = j - 1; i > -1; i--) {
			if (A[i][j] != 0) return 0; // Над главной диагональю не нули
		}
	}
	return 1;
}

int ChangeRows(double** A, int sizeA, int N) {
	for (int j = N + 1; j < sizeA; j++) {
		if (A[j][N] != 0) {
			double* MatrixRow = new double[sizeA * 2];
			for (int k = 0; k < sizeA * 2; k++) {
				MatrixRow[k] = A[N][k];
			}
			for (int k = 0; k < sizeA * 2; k++) {
				A[N][k] = A[j][k];
			}
			for (int k = 0; k < sizeA * 2; k++) {
				A[j][k] = MatrixRow[k];
			}
			delete[]MatrixRow;
			return 0;  //Замена прошла удачно
		}
	}
	return 1; //Замены не было, обратной матрицы не существует
}

void Iskluch(double* A_Row2, double* A_Row1, int sizeA, int N) {
	double c = 0;
	c = (A_Row2[N] / A_Row1[N]);
	for (int i = N; i < sizeA * 2; i++) {
		A_Row2[i] -= A_Row1[i] * c;
	}
}

void Delenie(double* A_Row, int sizeA, int N) {
	double c = A_Row[N];
	for (int i = N; i < sizeA * 2; i++) {
		if (A_Row[i] != 0) A_Row[i] /= c;
		else A_Row[i] = abs(A_Row[i]) / c;
	}
}

void productArr(double** A1, double** A2, int sizeA, double** New_Arr) {
	int row = 0; double sum;
	for (int i = 0; i < sizeA; i++) {
		row = 0;
		while (row < sizeA) {
			sum = 0;
			for (int j = 0; j < sizeA; j++) {
				sum += A1[i][j + sizeA] * A2[j][row];
			}
			if (int(sum) == -0) sum = 0;
			New_Arr[i][row] = sum;
			row += 1;
		}
	}
}