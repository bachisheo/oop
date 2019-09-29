// oop_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
class Fraction {
public:
	void Init(int a, int b);
	void Read();
	void Display();
	float Separator();
    Fraction Add(Fraction b);
private:
	int num = 1;                     //числитель
	int denom = 1;                   //знаменатель
};
void Fraction::Init(int a, int b) {                 //инициализация
	this->num = a;
	this->denom = b;
	printf("\nДробь инициализированна.");
}
void Fraction::Read() {                //ввод с клавиатуры
	printf("\nВведите числитель: ");
	std::cin >> this->num;
	printf("\nВведите знаменатель: ");
	std::cin >> this->denom;
}
void Fraction::Display() {             //вывод на экран
	printf("\n   %d\n   - \n   %d\n", this->num, this->denom);
}
int nod(int a, int b) {                    //нахождение наименьшего общего кратного через нод
	while (a != 0 && b != 0) {             //нахождение наибольшего общего делимого через алгоритм Евклида
		if (a > b)
			a = a % b;
		else b = b % a;
	}
	return a + b;
}
Fraction Fraction::Add(Fraction b) {				 //сложение дробей без сокращения
	Fraction summ;
	summ.denom = (this->denom == b.denom ? this->denom: this->denom * b.denom/nod(this->denom, b.denom));
	summ.num = (this->num * b.denom + b.num * this->denom) /nod(denom, b.denom);
	return summ;
}
float Fraction::Separator() {                      //метод выделения дробной части
	float ost = num > denom ? num % denom : num;
	ost /= 1.0 * denom;
	return ost;
}					                            


int main()
{
	setlocale(LC_ALL, "rus");
	int * n = new int;
	*n = 3;
	Fraction* fr_array = new Fraction[*n];
	fr_array[0].Init(14, 7);
	fr_array[0].Display();
	printf("\nВведите новую дробь!");
	fr_array[1].Read();
	printf("\nВаша дробь:");
	fr_array[1].Display();
	fr_array[2] = fr_array[0].Add(fr_array[1]);
	printf("Их сумма:");
	fr_array[2].Display();
	printf("Давайте найдем ее дробную часть! Она равна ");
	printf("%g", fr_array[2].Separator());
	delete [] fr_array;
	delete n;
}

