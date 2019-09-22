// oop_1(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#define SIZE 20
using namespace std;
 void space(int lenght) {
	char spaces[SIZE];
	int i;
	for (i = 0; i < lenght - 1; i++)
		cout << ' ' ;
		
}
typedef struct apples {
	int count = 0;                     //количество
	int weight = 0;                    //вес
	float infect = 0.0;
};
void Init(apples &appl, int a, int b, float infection) {                 //инициализация
	appl.count = a;
	appl.weight = b;
	appl.infect = infection;
	printf("\nФрукты инициализированы.");
}
void Read(apples &appl) {                //ввод с клавиатуры
	do {
		printf("\nВведите количество яблок: ");
		scanf_s("%d", &appl.count);
	} while (appl.count < 0);
	do {
		printf("\nВведите вес яблок: ");
		scanf_s("%d", &appl.weight);
	} while (appl.weight < 0);
	do{
		printf("\nВведите зараженность яблок в процентах: ");
		scanf_s("%f", &appl.infect);
	} while (appl.infect < 0 || appl.infect > 100);
}
void Display(apples appl) {             //вывод на экран
	if (appl.count < 1) {
		cout << "Яблок нет(((";
		appl.weight = 0;
		appl.infect = 0;
	}
	else if(appl.count < 20) 
	{
		printf("\n\\");
		for (int i = appl.count; i > 0; i--)
			//printf("Ѽ");
			printf("() ");
		printf("/\n ");
		for (int i = 0; i < appl.count; i++)
			cout << "___";
		cout << endl;
		space(appl.count * 1.6);

		cout << "| |";

		cout << endl;
		space(appl.count);
		cout << "  ________" << endl;
		space(appl.count);
		cout << "|          |" << endl;
		space(appl.count);
		cout << "|";
		cout.width(7);

		cout.flags(ios_base::left);
		cout << appl.weight << "kg |" << endl;
		space(appl.count);
		cout << "|          |" << endl;
		space(appl.count);
		cout << " __________\n";
		cout << endl << "Средняя зараженность яблок:  " << appl.infect << " %" <<  endl;
	}
	else {
		cout << "\n    ___________    \n";
		cout << "    \\         /    \n";
		cout << "     \\____.__/     \n";
		cout << "     /   / \\ \\     \n";
		cout << "   /    /      \\   \n";
		cout << " /               \\ \n";
		cout << "|                 |\n";
		cout << "|   В этом мешке  |\n";
		cout << "|";

		cout.width(17);
		cout.flags(ios_base::right);
		cout  << appl.count;
		cout << "|\n";
		cout << "|      яблок      |\n";
		cout << "|  Их вес (в кг): |\n";
		cout << "|";
		cout.width(17);
		cout.flags(ios_base::right);
		cout << appl.weight;
		cout << "|\n";
		cout << " \\                |\n";
		cout << "  \\______________/\n";
		cout << endl << "Средняя зараженность яблок:  " << appl.infect << " %" << endl;
		cout << "\n";
	}
}

apples Add(apples a, apples b) {				
	apples summ;
	summ.weight = a.weight + b.weight;
	summ.count = a.count + b.count;
	summ.infect = (a.infect + b.infect) / 2;
	return summ;
}
float middle_w(apples appl) {                      //метод нахождения среднего веса яблок

	return 1.0 * appl.weight/ appl.count;
}					                            


int main()
{
	setlocale(LC_ALL, "rus");
	apples one, two, sum;
	Init(one, 8, 65, 34);
	Display(one);
	printf("\nВведите новую порцию яблок!");
	Read(two);
	printf("\nВаша порция:");
	Display(two);
	sum = Add(one, two);
	printf("\nИх сумма:");
	Display(sum);
	printf("\nДавайте найдем средний вес яблока! Он равен %g кг", middle_w(sum));
}
