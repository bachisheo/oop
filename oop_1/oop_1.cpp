// oop_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
typedef struct apples {
	int count = 1;                     //числитель
	int weight = 1;                   //знаменатель
};
void Init(apples &fract, int a, int b) {                 //инициализация
	fract.count = a;
	fract.weight = b;
	printf("\nДробь инициализированна.");
}
void Read(apples &fract) {                //ввод с клавиатуры
	printf("\nВведите числитель: ");
	scanf_s("%d", &fract.count);
	printf("\nВведите знаменатель: ");
	scanf_s("%d", &fract.weight);
}
void Display(apples fract) {             //вывод на экран
	printf("\n   %d\n   - \n   %d\n", fract.count, fract.weight);
}
int nod(int a, int b) {                    //нахождение наименьшего общего кратного через нод
	while (a != 0 && b != 0) {             //нахождение наибольшего общего делимого через алгоритм Евклида
		if (a > b)
			a = a % b;
		else b = b % a;
	}
	return a + b;
}
apples Add(apples a, apples b) {				 //сложение дробей без сокращения
	apples summ;
	summ.weight = (a.weight == b.weight ? a.weight: a.weight * b.weight/nod(a.weight, b.weight));
	summ.count = (a.count * b.weight + b.count * a.weight) /nod(a.weight, b.weight);
	return summ;
}
float middle_w(apples fract) {                      //метод выделения дробной части
	float ost = fract.count > fract.weight ? fract.count % fract.weight : fract.count;
	ost /= 1.0 * fract.weight;
	return ost;
}					                            


int main()
{
	setlocale(LC_ALL, "rus");
	apples one, two, sum;
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
	printf("%g", middle_w(sum));
	
}

