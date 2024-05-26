#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"
#include "Euler.h"
#include <stdbool.h>

double Problem_6(int number_)
{
	double sum = 0;

	sum = SquareOfTheSum(number_) - SumOfSquares(number_);

	return sum;
}

int Problem_7(int number_)
{
	int counter = 0;
	int result = 0;

	for (int i = 0; counter != number_; i++)
		if (Is_Prime(i) == true)
		{
			counter++;
			result = i;
		}

	return result;
}

long long int Problem_8(int number_, BigNumber* bn_)
{
	long long int product1 = 0;
	long long int product2 = 1;

	size_t size = bn_->size;

	for (int i = 0; i < (size - number_); ++i)
	{
		for (int flag = i; flag < number_ + i; ++flag)
			product2 = product2 * bn_->digits[flag];
		if (product2 > product1)
			product1 = product2;
		product2 = 1;
	}

	return product1;
}

long long int Problem_9(int number_)
{
	long long int a, b, c = 0;

	for (a = 1; a < number_; a++) 
		for (b = a + 1; b < number_; b++) 
		{
			c = number_ - a - b;
			if (a * a + b * b == c * c) 
				return (a * b * c);
		}

	return 0;
}

long long int Problem_10(const int number_)
{
	long long int* arr = (long long int*)malloc((number_ + 1) * sizeof(long long int));
	if (!arr)
		return -1;

	int* prime = (int*)malloc((number_ + 1) * sizeof(int));
	if (!prime)
	{
		free(arr);
		return -1;
	}

	for (long long int i = 0; i < number_; ++i)
	{
		arr[i] = i;
		prime[i] = 1;
	}

	long long int sum = 0;

	for (long long int i = 2; i * i <= number_; ++i)
		if (prime[i] == 1)
			for (long long int j = i * i; j <= number_; j += i)
				prime[j] = 0;

	if (number_ >= 2)
	{
		prime[0] = 0;
		prime[1] = 0;
	}

	for (long long int i = 0; i <= number_; ++i)
		if (prime[i] == 1)
			sum += i;

	free(arr);
	free(prime);

	return sum;
}
