// oop_1(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#define SIZE 20
using namespace std;
 void space(int lenght) {
	int i;
	for (i = 0; i < lenght - 1; i++)
		cout << ' ' ;
		
}
class Apples {
public:
	float Middle_w();
	Apples Add(Apples a);
	void Display();
	void Init(int a, int b, float infection);
	void Read();
private:
	int count = 0;                     //количество
	int weight = 0;                    //вес
	float infect = 0.0;
};
void Apples::Init(int a, int b, float infection) {                 //инициализация
	count = a;
	weight = b;
	infect = infection;
	printf("\nФрукты инициализированы.");
}
void Apples::Read() {                //ввод с клавиатуры
	do {
		printf("\nВведите количество яблок: ");
		scanf_s("%d", &count);
	} while (count < 0);
	do {
		printf("\nВведите вес яблок: ");
		scanf_s("%d", &weight);
	} while (weight < 0);
	do {
		printf("\nВведите зараженность яблок в процентах: ");
		scanf_s("%f", &infect);
	} while (infect < 0 || infect > 100);
}
void Apples::Display() {             //вывод на экран
	if (count < 1) {
		cout << "Яблок нет(((";
		weight = 0;
		infect = 0;
	}
	else if(count < 20) 
	{
		printf("\n\\");
		for (int i = count; i > 0; i--)
			//printf("Ѽ");
			printf("() ");
		printf("/\n ");
		for (int i = 0; i < count; i++)
			cout << "___";
		cout << endl;
		space(count * 1.6);

		cout << "| |";

		cout << endl;
		space(count);
		cout << "  ________" << endl;
		space(count);
		cout << "|          |" << endl;
		space(count);
		cout << "|";
		cout.width(7);

		cout.flags(ios_base::left);
		cout << weight << "kg |" << endl;
		space(count);
		cout << "|          |" << endl;
		space(count);
		cout << " __________\n";
		cout << endl << "Средняя зараженность яблок:  " << infect << endl;
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
		cout  << count;
		cout << "|\n";
		cout << "|      яблок      |\n";
		cout << "|  Их вес (в кг): |\n";
		cout << "|";
		cout.width(17);
		cout.flags(ios_base::right);
		cout << weight;
		cout << "|\n";
		cout << " \\                |\n";
		cout << "  \\______________/\n";
		cout << endl << "Средняя зараженность яблок:  " << infect << endl;
		cout << "\n";
	}
}

Apples Apples::Add(Apples a) {				
	Apples summ;
	summ.weight = a.weight + this->weight;
	summ.count = a.count + this->count;
	summ.infect = (a.infect + this->infect) / 2;
	return summ;
}
float Apples::Middle_w() {                      //метод нахождения среднего веса яблок

	return 1.0 * weight/ count;
}					                            


int main()
{
	setlocale(LC_ALL, "rus");
	Apples one, two, sum;
	one.Init(8, 65, 34);
	one.Display();
	printf("\nВведите новую порцию яблок!");
	two.Read();
	printf("\nВаша порция:");
	two.Display();
	sum = one.Add(two);
	printf("Их сумма:");
	sum.Display();
	printf("Давайте найдем средний вес яблока! Он равен %g кг", sum.Middle_w());
}
