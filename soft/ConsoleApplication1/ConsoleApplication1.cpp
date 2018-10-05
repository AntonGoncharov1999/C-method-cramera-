#include "pch.h"
#include <iostream>

using namespace std;

const unsigned int aa = 3;
const unsigned int bb = 3;

int i1 = 0, i2 = 0, i = 0, j = 0, x = 0, y = 0, z = 0, dx = 0, dy = 0, dz = 0, res1 = 0, res2 = 0, res3 = 0, d = 0;

int massiv[aa][bb];

// функции

void print() {  // функця вывода массива
	cout << "massiv: " << endl;
	for (i = 0; i < aa; i++)
	{
		for (j = 0; j < bb; j++)
			cout << massiv[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

//основное приложение

int main()
{

	//инициализируем

	cout << "vvedi element" << endl;
	for (i = 0; i < aa; i++)
		for (j = 0; j < bb; j++)
			cin >> massiv[i][j];

	//вводим данные x y z

	cout << "vvedite x";
	cin >> x;
	cout << "vvedite y";
	cin >> y;
	cout << "vvedite z";
	cin >> z;

	print();

	//метод крамера
	// дискременант дельты 
	d = (massiv[0][0] * massiv[1][1] * massiv[2][2] + massiv[2][1] * massiv[1][0] * massiv[0][2] + massiv[2][0] * massiv[0][1] * massiv[1][2])
		-
		(massiv[0][2] * massiv[1][1] * massiv[2][0] + massiv[2][1] * massiv[0][0] * massiv[1][2] + massiv[2][2] * massiv[1][0] * massiv[0][1]);

	if (d != 0){
		//дискрименанты матрицы дэльта x 

		dx = (x * massiv[1][1] * massiv[2][2] + massiv[2][1] * y * massiv[0][2] + z * massiv[0][1] * massiv[1][2])
			-
			(massiv[0][2] * massiv[1][1] * z + massiv[2][1] * x * massiv[1][2] + massiv[2][2] * y * massiv[0][1]);

		//дискрименанты матрицы дэльта y 

		dy = (massiv[0][0] * y * massiv[2][2] + z * massiv[1][0] * massiv[0][2] + massiv[2][0] * x * massiv[1][2])
			-
			(massiv[0][2] * y * massiv[2][0] + z * massiv[0][0] * massiv[1][2] + massiv[2][2] * massiv[1][0] * x);


		//дискрименанты матрицы дэльта z

		dz = (massiv[0][0] * massiv[1][1] * z + massiv[2][1] * massiv[1][0] * x + massiv[2][0] * massiv[0][1] * y)
			-
			(x * massiv[1][1] * massiv[2][0] + massiv[2][1] * massiv[0][0] * y + z * massiv[1][0] * massiv[0][1]);


		cout << "diskrimenant x = " << dx << endl << "diskrimenant y = " << dy << endl << "diskrimenant z = " << dz << endl;

		res1 = dx / d;
		res2 = dy / d;
		res3 = dz / d;

		cout << res1 << endl << res2 << endl << res3 << endl;

	}else {
		cout << "ne reshaets" << endl;
	}
		

	system("pause");

}

