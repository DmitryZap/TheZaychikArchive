#include "stdafx.h"
#include <iostream>
using namespace System;
using namespace pr5;
using namespace std;

int main()
{
	int count, a, sum = 0, cr3 = 0;
	bool if_sum = false;
	Console::WriteLine("Введите кол-во повторений");
	count = Convert::ToInt32(Console::ReadLine());

	for (int i = 0; i < count; i++) {
		Console::WriteLine("Введите a, для остановки введите 0");
		a = Convert::ToInt32(Console::ReadLine());
		if (a == 0)
			break;
		ClassFunc::func_for(a, sum, cr3, if_sum);
		if (if_sum)
			Console::WriteLine("Вы ввели 3-х значное число.\nСумма его цифр: " + sum);
		Console::WriteLine("Кол-во чисел кратных трем: " + cr3);
		Console::WriteLine("---------------------------------");
	}
	Console::ReadLine();
    return 0;
}
