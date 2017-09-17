#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

const int order = 2;


class Matrix {
public:
	int matrix[order][order];
	void populate();
	void itMultiplication( int[][order], int[][order]);
	void display();
	void StMultiplication(int[][order], int[][order]);
};

void Matrix::populate() {

	
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			matrix[i][j] = rand() % 100;
		}
	}
}

void Matrix::display() {

	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Matrix::itMultiplication(int a[][order] ,int b[][order] ) {

	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			for (int k = 0; k < order; k++) {
				matrix[i][j] += a[i][k] * b[k][j];
		}
	}
}
}

void Matrix::StMultiplication(int a[][order], int b[][order]) {

	int one = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
	int two = (a[1][0] + a[1][1]) * b[0][0];
	int three = a[0][0] * (b[0][1] - b[1][1]);
	int four = a[1][1] * (b[1][0] - b[0][0]);
	int five = (a[0][0] + a[0][1]) * b[1][1];
	int six = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
	int seven = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

	matrix[0][0] = one + four - five + seven;
	matrix[0][1] = three + five;
	matrix[1][0] = two + four;
	matrix[1][1] = one - two + three + six;
}

int main() {
	srand(time(NULL));
	Matrix a = Matrix();
	a.populate();
	a.display();
	Matrix b = Matrix();
	b.populate();
	b.display();
	Matrix c = Matrix();
	c.itMultiplication(a.matrix, b.matrix);
	c.display();
	Matrix d = Matrix();
	d.StMultiplication(a.matrix, b.matrix);
	d.display();
	system("pause");
	return 0;
}