#include <stdbool.h>
#pragma once

/*
* @brief ����� ������� �����, ��������� ���������� ������ ����������� �����
* @param number_: ���������� ������ ����������� �����
* @return ������� ����� ��������� ���������� ������ ����������� �����
*/
double SquareOfTheSum(int number_);

/*
* @brief ����� ����� ���������, ��������� ���������� ������ ����������� �����
* @param number_: ���������� ������ ����������� �����
* @return ����� ���������, ��������� ���������� ������ ����������� �����
*/
double SumOfSquares(int number_);

/*
* @brief ���������� �������� �� ����� �������
* @param value_: �����
* @return true - �������, false - �� �������
*/
bool Is_Prime(unsigned const long long value_);

/*
* @brief ��������: �������� �� ��� ������ �� �����
* @param str_: ������
* @return 1 - ���������� ������, 0 - ������������ ������
*/
bool IsIntString(char* str_);

bool IsItPythTriple(int a_, int b_, int c_);

int GeneratSumPythTriple(int m_, int n_);