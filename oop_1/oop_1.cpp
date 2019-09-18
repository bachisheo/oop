// oop_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
typedef struct fraction {
	int num = 1;                     //числитель
	int denom = 1;                   //знаменатель
};
void Init(fraction &fract, int a, int b) {                 //инициализация
	fract.num = a;
	fract.denom = b;
	printf("\nДробь инициализированна.");
}
void Read(fraction &fract) {                //ввод с клавиатуры
	printf("\nВведите числитель: ");
	scanf_s("%d", &fract.num);
	printf("\nВведите знаменатель: ");
	scanf_s("%d", &fract.denom);
}
void Display(fraction fract) {             //вывод на экран
	printf("\n   %d\n   - \n   %d\n", fract.num, fract.denom);
}
int nod(int a, int b) {                    //нахождение наименьшего общего кратного через нод
	while (a != 0 && b != 0) {             //нахождение наибольшего общего делимого через алгоритм Евклида
		if (a > b)
			a = a % b;
		else b = b % a;
	}
	return a + b;
}
fraction Add(fraction a, fraction b) {				 //сложение дробей без сокращения
	fraction summ;
	summ.denom = (a.denom == b.denom ? a.denom: a.denom * b.denom/nod(a.denom, b.denom));
	summ.num = (a.num * b.denom + b.num * a.denom) /nod(a.denom, b.denom);
	return summ;
}
float separator(fraction fract) {                      //метод выделения дробной части
	float ost = fract.num > fract.denom ? fract.num % fract.denom : fract.num;
	ost /= 1.0 * fract.denom;
	return ost;
}					                            


int main()
{
	setlocale(LC_ALL, "rus");
	fraction one, two, sum;
	Init(one, 14, 7);
	Display(one);
	printf("\nВведите новую дробь!");
	Read(two);
	printf("\nВаша дробь:");
	Display(two);
	sum = Add(one, two);
	printf("Их сумма:");
	Display(sum);
	printf("Давайте найдем ее дробную часть! Она равна ");
	printf("%g", separator(sum));
	
}

