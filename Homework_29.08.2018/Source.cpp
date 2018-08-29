#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int* primes(int* a, int& n)
{
	int m = 0;
	bool *c = new bool[n];
	for (int i = 0; i < n; i++)
	{
		bool prime = true;
		for (int j = 2; j <= (int)sqrt(a[i]); j++) {
			if (a[i] % j == 0) {
				prime = false;
				break;
			}
		}
		if (prime && a[i] != 1) {
			m++;
			c[i] = true;
		}
		else
			c[i] = false;
	}
	int *b = new int[m];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (c[i])
			b[j++] = a[i];
	n = m;
	delete[] c;
	return b;
}

int* div_by_3(int* a, int& n)
{
	int m = 0;
	for (int i = 0; i < n; i++)
		if (a[i] % 3 == 0) m++;
	int *b = new int[m];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (a[i] % 3 == 0)
			b[j++] = a[i];
	n = m;
	return b;
}
int* even(int* a, int& n)
{
	int m = 0;
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0) m++;
	int *b = new int[m];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0)
			b[j++] = a[i];
	n = m;
	return b;
}
void func(int* a, int n, int* (*f)(int*, int&))
{
	a = f(a, n);
	for (int i = 0; i < n; i++)
		cout << setw(3) << a[i];
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Реализовать 3 функции каждая из которых принимает указатель на массив и количество элементов и возвращает указатель на новый массив. Первая функция ищет простые числа и заносит их в новый массив, вторая – все числа кратные трем, третья – все четные числа. Затем напишите функцию, которая принимает указатель на одну из этих функций, а указатель на массив и количество элементов. Добавьте меню, в котором пользователь может выбрать желаемую операцию." << endl;

	cout << "Введите размер массива: ";
	int n;
	cin >> n;
	cout << "Введите элементы массива: ";
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << "Выберите операцию:" << endl<< " 1. Поиск простых чисел " <<endl<< " 2. Поиск чисел кратные трем. " <<endl<< " 3. Поиск четных чисел. " <<endl<<" 0. Выход из меню"<<endl;
	int c;
	start:
	cin >> c;
	int* (*f)(int*, int&);
	switch (c) {
	case 1: f = primes;
		break;
	case 2: f = div_by_3; 
		break;
	case 3: f = even; 
		break;
	case 0:  return 0;
		break;
	}
	func(a, n, f);
	goto start;

	system("pause");
	return 0;
}