#include <stdio.h>
#include <math.h>
#include "functions.h"
#include <stdbool.h>

double SumOfSquares(int number_)
{
	double sum = 0;

	for (int i = 0; i <= number_; i++)
		sum += pow(i, 2);

	return sum;
}

double SquareOfTheSum(int number_)
{
	double sum = 0;

	for (int i = 0; i <= number_; i++)
		sum += i;

	sum = pow(sum, 2);

	return sum;
}

bool Is_Prime(unsigned const long long value_)
{
	if (value_ <= 1)
		return false;

	if (value_ == 2)
		return true;

	if (value_ % 2 == 0)
		return false;

	for (unsigned long long n = 3; n <= sqrt((double)(value_)); n += 2)
	{
		if (value_ % n == 0)
			return false;
	}

	return true;
}

bool IsIntString(char* str_)
{
	if (str_[0] == '-')
		str_++;

	while (*str_)
	{
		if (*str_ < '0' || *str_ > '9')
			return false;

		str_++;
	}

	return true;
}

bool IsItPythTriple(int a_, int b_, int c_)
{
	if (pow(a_, 2) + pow(b_, 2) == pow(c_, 2))
		return true;
	else
		return false;
}

int GeneratSumPythTriple(int m_, int n_)
{
	int a = (int)(pow(m_, 2) - pow(n_, 2));
	int b = (int)(2 * n_ * m_);
	int c = (int)(pow(m_, 2) + pow(n_, 2));

	int sum = a + b + c;

	return sum;
}
