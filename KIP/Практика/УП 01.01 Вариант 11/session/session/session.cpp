#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace System;

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

int main()
{
	setlocale(LC_ALL, "rus");
	stash();
	stash();
	show_stack();
	write_stack();
	system("pause");
	return 0;
}

