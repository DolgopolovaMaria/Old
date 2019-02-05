#pragma once

/*вывести на экран массив, состоящий из переменных типа bool (false = 0, true = 1)*/
void coutArray(bool array[], int length);

/*перевести число в двоичную систему счисления и записать результат в массив binaryArray*/
void binaryCode(bool binaryArray[], int number);

/*сложить 2 числа в двоичной системе счисления*/
void sum(bool array1[], bool array2[], bool sumArray[], int length);

/*перевести число из двоичной системы счисления в десятичную*/
int decimal(bool array[], int length);
