#include "stdafx.h"  // Больше внешних зависимостей богу внешних зависимостей! 
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <fstream>
#include <random>
#include <time.h>
#include <iomanip>
using namespace std;
using namespace System;

int n, m;
string menu_list[] = { "Работа с электронным журналом:", "Запись нового ученика", "Удаление ученика","Вывод всего стака","Запись всего стака в файл","Поиск по стаку по имени","Поиск по стаку по группе","Вывод средней оценки по предмету ученика","Выход" };

int code, l, l1;
string inpt;

COORD position;										// Объявление необходимой структуры
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int print_menu(string menu[], int l)
{
	char ch;
	int i, m;
	system("cls");
	position.X = 5;										// Установка координаты X
	position.Y = 1;										// Установка координаты Y
	SetConsoleCursorPosition(hConsole, position);		// Перемещение каретки по заданным координатам
	cout << menu[0];										// Вывод сообщения
	position.X = 3;

	for (i = 1; i <l; i++)
	{
		position.Y = i + 1;
		SetConsoleCursorPosition(hConsole, position);
		cout << menu[i];
	}
	position.X = 2;
	do
	{
		ch = _getch();
		code = static_cast<int>(ch);
		SetConsoleCursorPosition(hConsole, position);
		puts(" ");
		switch (code) {
		case 80: if (position.Y<l) position.Y++;
				 else position.Y = 2;
				 SetConsoleCursorPosition(hConsole, position);
				 puts(">");
				 break;
		case 72: if (position.Y>2) position.Y--;
				 else position.Y = l;
				 SetConsoleCursorPosition(hConsole, position);
				 puts(">");
				 break;
		}
	} while (code != 13);
	return position.Y;
}

struct Mark {
	int score;
	string date;
	Mark *next;

};

struct Student {
	string name;
	Mark *lesson1;
	Mark *lesson2;
	Mark *lesson3;
	Mark *lesson4;
	Mark *lesson5;
	Student *next;
};

struct Group {
	string group_num;
	Student *student;
	Group *next;
};

struct Stack {
	int num = 0;
	Group *group;
};

Stack *stack = new Stack();
void stash() {
	Stack *tmp;
		if (stack->num > 0) {
			tmp = new Stack(*stack);
		}
		stack->group = new Group(); // ввод группы
		stack->group->student = new Student(); // студент
		stack->group->student->lesson1 = new Mark(); // оценки
		stack->group->student->lesson2 = new Mark();
		stack->group->student->lesson3 = new Mark();
		stack->group->student->lesson4 = new Mark();
		stack->group->student->lesson5 = new Mark();
		stack->group->student->lesson1->next = stack->group->student->lesson2; // ссылки оценок
		stack->group->student->lesson2->next = stack->group->student->lesson3;
		stack->group->student->lesson3->next = stack->group->student->lesson4;
		stack->group->student->lesson4->next = stack->group->student->lesson5; 
		if (stack->num > 0) {
			stack->group->next = tmp->group;
			stack->group->student->next = tmp->group->student;
		}
		delete tmp;
		stack->num += 1;
		cout << "Введите номер группы студента <КурсФакультет-НомерГруппы>:"<< endl; // ввод
		cin >> stack->group->group_num;
		cout << "Веведите ФИО студента:" << endl;
		cin >> stack->group->student->name;
		cout << "Введите оценку за 1 урок" << endl;
		cin >> stack->group->student->lesson1->score;
		cout << "Введите дату 1 урока" << endl;
		cin >> stack->group->student->lesson1->date;
		cout << "Введите оценку за 2 урок" << endl;
		cin >> stack->group->student->lesson2->score;
		cout << "Введите дату 2 урока" << endl;
		cin >> stack->group->student->lesson2->date;
		cout << "Введите оценку за 3 урок" << endl;
		cin >> stack->group->student->lesson3->score;
		cout << "Введите дату 3 урока" << endl;
		cin >> stack->group->student->lesson3->date;
		cout << "Введите оценку за 4 урок" << endl;
		cin >> stack->group->student->lesson4->score;
		cout << "Введите дату 4 урока" << endl;
		cin >> stack->group->student->lesson4->date;
		cout << "Введите оценку за 5 урок" << endl;
		cin >> stack->group->student->lesson5->score;
		cout << "Введите дату 5 урока" << endl;
		cin >> stack->group->student->lesson5->date;
}

void pop() {
	if (stack->num > 0) {
		stack->group = stack->group->next;
		stack->num -= 1;
	}
	else
	{
		cout << "Cтак пуст!" << endl;
	}
}

void show_stack() {
	int stack_count = stack->num;
	Group *tmp = stack->group;
	cout.setf(ios::right);
	while (stack_count > 0)
	{
		cout << "________________________________" << endl; // 33
		cout << "|Группа : "<< setw(21) << tmp->group_num << "|" << endl;
		cout << "|ФИО : " << setw(24) << tmp->student->name << "|" << endl;
		cout << "|Урок 1|Дата: " << setw(10) << tmp->student->lesson1->date << "|Балл " << setw(2) <<  to_string(tmp->student->lesson1->score) + "|" << endl;
		cout << "|Урок 2|Дата: " << setw(10) << tmp->student->lesson2->date << "|Балл " << setw(2) << to_string(tmp->student->lesson2->score) + "|" << endl;
		cout << "|Урок 3|Дата: " << setw(10) << tmp->student->lesson3->date << "|Балл " << setw(2) << to_string(tmp->student->lesson3->score) + "|" << endl;
		cout << "|Урок 4|Дата: " << setw(10) << tmp->student->lesson4->date << "|Балл " << setw(2) << to_string(tmp->student->lesson4->score) + "|" << endl;
		cout << "|Урок 5|Дата: " << setw(10) << tmp->student->lesson5->date << "|Балл " << setw(2) << to_string(tmp->student->lesson5->score) + "|" << endl;
		cout << "________________________________" << endl;
		tmp = tmp->next;
		stack_count -= 1;
	}
	
}
void search_group(string group) {
	int stack_count = stack->num;
	Group *tmp = stack->group;
	cout.setf(ios::right);
	while (stack_count > 0)
	{
		if (group == tmp->group_num) {
			cout << "________________________________" << endl; // 33
			cout << "|Группа : " << setw(21) << tmp->group_num << "|" << endl;
			cout << "|ФИО : " << setw(24) << tmp->student->name << "|" << endl;
			cout << "|Урок 1|Дата: " << setw(10) << tmp->student->lesson1->date << "|Балл " << setw(2) << to_string(tmp->student->lesson1->score) + "|" << endl;
			cout << "|Урок 2|Дата: " << setw(10) << tmp->student->lesson2->date << "|Балл " << setw(2) << to_string(tmp->student->lesson2->score) + "|" << endl;
			cout << "|Урок 3|Дата: " << setw(10) << tmp->student->lesson3->date << "|Балл " << setw(2) << to_string(tmp->student->lesson3->score) + "|" << endl;
			cout << "|Урок 4|Дата: " << setw(10) << tmp->student->lesson4->date << "|Балл " << setw(2) << to_string(tmp->student->lesson4->score) + "|" << endl;
			cout << "|Урок 5|Дата: " << setw(10) << tmp->student->lesson5->date << "|Балл " << setw(2) << to_string(tmp->student->lesson5->score) + "|" << endl;
			cout << "________________________________" << endl;
			tmp = tmp->next;
		}
		stack_count -= 1;
	}
}

void search_name(string name) {
	int stack_count = stack->num;
	Group *tmp = stack->group;
	cout.setf(ios::right);
	while (stack_count > 0)
	{
		if (name == tmp->student->name) {
			cout << "________________________________" << endl; // 33
			cout << "|Группа : " << setw(21) << tmp->group_num << "|" << endl;
			cout << "|ФИО : " << setw(24) << tmp->student->name << "|" << endl;
			cout << "|Урок 1|Дата: " << setw(10) << tmp->student->lesson1->date << "|Балл " << setw(2) << to_string(tmp->student->lesson1->score) + "|" << endl;
			cout << "|Урок 2|Дата: " << setw(10) << tmp->student->lesson2->date << "|Балл " << setw(2) << to_string(tmp->student->lesson2->score) + "|" << endl;
			cout << "|Урок 3|Дата: " << setw(10) << tmp->student->lesson3->date << "|Балл " << setw(2) << to_string(tmp->student->lesson3->score) + "|" << endl;
			cout << "|Урок 4|Дата: " << setw(10) << tmp->student->lesson4->date << "|Балл " << setw(2) << to_string(tmp->student->lesson4->score) + "|" << endl;
			cout << "|Урок 5|Дата: " << setw(10) << tmp->student->lesson5->date << "|Балл " << setw(2) << to_string(tmp->student->lesson5->score) + "|" << endl;
			cout << "________________________________" << endl;
			tmp = tmp->next;
		}
		stack_count -= 1;
	}
}

void write_stack() {
	ofstream fout("stack.txt");
	int stack_count = stack->num;
	Group *tmp = stack->group;
	fout.setf(ios::right);
	while (stack_count > 0)
	{
		fout << "________________________________" << endl; // 33
		fout << "|Группа : " << setw(21) << tmp->group_num << "|" << endl;
		fout << "|ФИО : " << setw(24) << tmp->student->name << "|" << endl;
		fout << "|Урок 1|Дата: " << setw(10) << tmp->student->lesson1->date << "|Балл " << setw(2) << to_string(tmp->student->lesson1->score) + "|" << endl;
		fout << "|Урок 2|Дата: " << setw(10) << tmp->student->lesson2->date << "|Балл " << setw(2) << to_string(tmp->student->lesson2->score) + "|" << endl;
		fout << "|Урок 3|Дата: " << setw(10) << tmp->student->lesson3->date << "|Балл " << setw(2) << to_string(tmp->student->lesson3->score) + "|" << endl;
		fout << "|Урок 4|Дата: " << setw(10) << tmp->student->lesson4->date << "|Балл " << setw(2) << to_string(tmp->student->lesson4->score) + "|" << endl;
		fout << "|Урок 5|Дата: " << setw(10) << tmp->student->lesson5->date << "|Балл " << setw(2) << to_string(tmp->student->lesson5->score) + "|" << endl;
		fout << "________________________________" << endl;
		tmp = tmp->next;
		stack_count -= 1;
	}
	fout.close();
}

void name_srball(string name) {
	int stack_count = stack->num;
	Group *tmp = stack->group;
	cout.setf(ios::right);
	while (stack_count > 0)
	{
		if (name == tmp->student->name) {
			_asm {


			}
		}
		tmp = tmp->next;
		stack_count -= 1;
	}

}


void menu() {
	l = print_menu(menu_list, 9);
	switch (l)
	{
	case 2:
		break;
	case 3:
		break;
	case 4: 
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		exit(0);
		break;
	default:
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	menu();
	system("pause");
	return 0;
}

