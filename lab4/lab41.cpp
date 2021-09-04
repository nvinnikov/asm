#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <cstdlib>
#include <iostream>

int main()
{
	setlocale(LC_ALL, "ru");
	setlocale(LC_NUMERIC, "en");
	unsigned int res;
	char a[16] = {-1,
		-2,
		-3,
		-4,
		-6,
		-7,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9
	};
	char b[16] = {-3,
		-2,
		-1,
		0,
		-1,
		-2,
		3,
		1,
		1,
		2,
		2,
		6,
		6,
		8,
		8,
		9
	};
	unsigned int c[16];
	printf("Исходные массивы:\n");
	for (unsigned int i = 0; i < 16; i++)
	{
		printf("A.%.2d=%d\tB.%.2d=%d\n", i, (int) a[i], i, (int) b[i]);
	}
	_asm
	{
		lea esi, a	// esi - указатель на элементы массива a
		lea edi, b	// edi - указатель на элементы массива b
		xor ebx, ebx	// ebx - счетчик элементов в массиве c
		xor ecx, ecx	// ecx = 0, номер элемента массива число
		элементов массивов
		m2:
			mov al, [esi]	// Берем очередной элемент массива a
		cmp al, [edi]	// Сравниваем с очередным элементом
		массива b
		jle m1	// Меньше или равно, ничего делать
		не надо
		// a > b
		mov c[ebx *4], esi	// Если надо сохранять абсолютный адрес массива a
		// mov byte ptr c[ebx *4], cl	// Заносим смещение
		элементов относительно начала массива в массив c
		inc ebx	// ebx++ - следующий элемент
		массива c
		mov ah, [edi]	// меняем местами элементы массивов a и b
		mov[edi], al
		mov[esi], ah
		m1:
			inc esi	// esi++ следующий элемент массива
		a
		inc edi	// edi++ следующий элемент массива
		b
		inc ecx	// ecx++ увеличение счетчика
		cmp cl, 16	// cl = 16?
		jnz m2	// Нет. Следующая итерация
		mov res, ebx	// res = число обменов
	}
	printf("Результат:\nЧисло обменов: %d\n", res);
	for (unsigned int i = 0; i < 16; i++)
	{
		printf("A.%.2d=%d\tB.%.2d=%d\n", i, (int) a[i], i, (int) b[i]);
	}
	for (unsigned int i = 0; i < res; i++)
	{
		printf("C.%.2d=%X\n", i, c[i]);
	}
	system("pause");
}