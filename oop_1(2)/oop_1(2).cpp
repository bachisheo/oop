// oop_1(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
typedef struct apples {
	int count = 1;                     //количество
	int weight = 1;                    //вес
};
void Init(apples &appl, int a, int b) {                 //инициализация
	appl.count = a;
	appl.weight = b;
	printf("\nФрукты инициализированы.");
}
void Read(apples &appl) {                //ввод с клавиатуры
	printf("\nВведите количество яблок: ");
	scanf_s("%d", &appl.count);
	printf("\nВведите вес яблок: ");
	scanf_s("%d", &appl.weight);
}
void Display(apples appl) {             //вывод на экран
	printf ("\\");
	for (int i = appl.count; i > 0; i--)
		//printf("Ѽ");
		printf("() ");
	printf("/");
}

apples Add(apples a, apples b) {				 //сложение дробей без сокращения
	apples summ;
	summ.weight = a.weight + b.weight;
	summ.count = a.count + b.count;
	return summ;
}
float middle_w(apples appl) {                      //метод нахождения среднего веса яблок

	return 1.0 * appl.weight/ appl.count;
}					                            


int main()
{
	setlocale(LC_ALL, "rus");
	apples one, two, sum;
	Init(one, 8, 65);
	Display(one);
	printf("\nВведите новую порцию яблок!");
	Read(two);
	printf("\nВаша порция:");
	Display(two);
	sum = Add(one, two);
	printf("Их сумма:");
	Display(sum);
	printf("Давайте найдем средний вес яблока! Он равен %g кг", middle_w(sum));
}
