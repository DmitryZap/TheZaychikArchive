// Prakt1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void zad2() {
	unsigned char a = 139;
	unsigned char c;
	_asm {
		mov al, a
		rol al, 4
		mov c, al
	}
	printf("Результат выполнения задания №2:\n");
	printf("Число а в 10 с/с = %i\n", a);
	printf("Число a в 16 с/с = %0hx\n", a);
	printf("Число a после сдвига = %i\n", c);
	c /= 16;
	printf("Число a после деления на 16 = %i\n", c);
}

void zad1() { // u=max(x+z,2y+z)-max⁡(x+z,y+2z)
	unsigned char u, x = 5, y = 7, z = 4;
	unsigned char ax, ay, az, aq;
	ax = x + z;
	ay = 2 * y + z;
	az = x + z;
	aq = y + 2 * z;
	_asm {
		mov al, ax
		mov bl, ay
		mov cl, az
		mov bl, aq

	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	zad1();
	system("pause");
    return 0;
}

