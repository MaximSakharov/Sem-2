#include "big_number.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_string.h"

BigNumber* CreateBN(char* number_)
{
	if (number_ == NULL || strlen(number_) == 0 || !IsIntString(number_))
		return NULL;

	BigNumber* bn = (BigNumber*)malloc(sizeof(BigNumber));
	if (bn == NULL)
		return NULL;

	size_t size = strlen(number_);

	if (*number_ == '-')
	{
		bn->is_negative = true;
		size--; 
		number_++; 
	}
	else
		bn->is_negative = false;

	while (*number_ == '0' && size > 1)
	{
		number_++;
		size--;
	}

	bn->size = (unsigned int)(size);
	bn->digits = (digit*)calloc(bn->size, sizeof(digit));
	if (bn->digits == NULL)
	{
		free(bn);
		return NULL;
	}

	for (size_t i = 0; i < bn->size; ++i)
		bn->digits[i] = number_[i] - '0';

	return bn;
}

void DeleteBN(BigNumber** bn_)
{
	free((*bn_)->digits);
	free(*bn_);

	*bn_ = NULL;
}

void PrintBN(BigNumber* bn_)
{
	if (bn_ == NULL)
	{
		printf("BigNumber is empty!\n");
		return;
	}

	if (bn_->is_negative)
		printf("-");

	for (size_t i = 0; i < bn_->size; ++i)
		printf("%u", bn_->digits[i]);

	printf("\n");
}

int CompareBn(BigNumber* bn1_, BigNumber* bn2_)
{
	if (bn1_->size > bn2_->size)
		return 1;
	else if (bn1_->size < bn2_->size)
		return -1;

	int i = bn1_->size;

	while (i > 0)
	{
		if (bn1_->digits[i - 1] > bn2_->digits[i - 1])
			return 1;
		else if (bn1_->digits[i - 1] < bn2_->digits[i - 1])
			return -1;
		--i;
	}

	return 0;
}

BigNumber* SumBN(BigNumber* bn1_, BigNumber* bn2_)
{
	BigNumber* maxBn = (bn1_->size >= bn2_->size ? bn1_ : bn2_);
	BigNumber* minBn = (bn1_->size >= bn2_->size ? bn2_ : bn1_);

	BigNumber* sumBn = (BigNumber*)malloc(sizeof(BigNumber));
	if (sumBn == NULL)
		return NULL;

	size_t size = (size_t)(maxBn->size + 1);

	sumBn->digits = (digit*)calloc(size, sizeof(digit));
	if (sumBn->digits == NULL)
	{
		free(sumBn);
		return NULL;
	}

	if ((maxBn->is_negative == true && minBn->is_negative == true) || (maxBn->is_negative == false && minBn->is_negative == false))
	{
		if (maxBn->is_negative == true)
			sumBn->is_negative = true;
		else
			sumBn->is_negative = false;

		sumBn->size = (unsigned int)(size);

		int e = 0;

		int i = (int)(maxBn->size - 1);
		int j = (int)(minBn->size - 1);

		while (j >= 0)
		{
			int addition = (maxBn->digits[i] + minBn->digits[j]) + e;
			sumBn->digits[i + 1] = addition % 10;
			e = addition / 10;

			--i;
			--j;
		}

		while (i >= 0)
		{
			int addition = maxBn->digits[i] + e;
			sumBn->digits[i + 1] = addition % 10;
			e = addition / 10;

			--i;
		}

		if (e > 0)
			sumBn->digits[0] = e;
		else
			if (sumBn->digits[0] == 0) {
				for (int k = 0; k < (int)(sumBn->size) - 1; k++) {
					sumBn->digits[k] = sumBn->digits[k + 1];
				}
				sumBn->size--;
			}
	}
	else if (maxBn->is_negative == false && minBn->is_negative == true)
	{
		minBn->is_negative = false;
		sumBn = SubBN(maxBn, minBn);
	}
	else if (maxBn->is_negative == true && minBn->is_negative == false)
	{
		maxBn->is_negative = false;
		sumBn = SubBN(maxBn, minBn);
		sumBn->is_negative = true;
	}
	return sumBn;
}

BigNumber* SubBN(BigNumber* bn1_, BigNumber* bn2_)
{
	BigNumber* maxBn = (bn1_->size >= bn2_->size ? bn1_ : bn2_);
	BigNumber* minBn = (bn1_->size >= bn2_->size ? bn2_ : bn1_);

	if (bn1_->size == bn2_->size)
		for (int i = 0; i < (int)(bn1_->size); ++i)
			if (bn1_->digits[i] > bn2_->digits[i])
			{
				maxBn = bn1_;
				minBn = bn2_;
				break;
			}
			else if (bn1_->digits[i] < bn2_->digits[i])
			{
				maxBn = bn2_;
				minBn = bn1_;
				break;
			}
	BigNumber* subBn = (BigNumber*)malloc(sizeof(BigNumber));
	if (subBn == NULL)
		return NULL;

	size_t size = maxBn->size;

	subBn->digits = (digit*)calloc(size, sizeof(digit));
	if (subBn->digits == NULL)
	{
		free(subBn);
		return 0;
	}

	if (maxBn != bn1_)
		subBn->is_negative = true;
	else
		subBn->is_negative = false;

	if (maxBn->is_negative == false && minBn->is_negative == false)
	{
		subBn->size = (unsigned int)(size);

		int dif = (int)(maxBn->size - minBn->size);
		
		for (int i = 0; i < dif; ++i)
			subBn->digits[i] = maxBn->digits[i];

		int borrow = 0;
		int n = size - 1;
		int m = minBn->size - 1;

		for (int i = size - 1; i >= 0; --i)
		{
			int diff = maxBn->digits[i] - borrow;
			if (m >= 0)
				diff -= minBn->digits[m];
			if (diff < 0)
			{
				diff += 10;
				borrow = 1;
			}
			else
			{
				borrow = 0;
			}
			subBn->digits[n--] = diff;
			m--;
		}

		while (subBn->digits[0] == 0 && subBn->size > 1)
		{
			for (int k = 0; k < (int)(subBn->size) - 1; k++) {
				subBn->digits[k] = subBn->digits[k + 1];
			}
			subBn->size--;
		}
	}
	else if (maxBn->is_negative == false && minBn->is_negative == true)
	{
		minBn->is_negative = false;
		subBn = SumBN(maxBn, minBn);
	}
	else if (maxBn->is_negative == true && minBn->is_negative == false)
	{
		minBn->is_negative = true;
		subBn = SumBN(maxBn, minBn);
	}
	else if (maxBn->is_negative == true && minBn->is_negative == true)
	{
		minBn->is_negative = false;
		subBn = SumBN(maxBn, minBn);
	}
	return subBn;
}

BigNumber* MultBN(BigNumber* bn1_, BigNumber* bn2_)
{
	BigNumber* maxBn = (bn1_->size >= bn2_->size ? bn1_ : bn2_);
	BigNumber* minBn = (bn1_->size >= bn2_->size ? bn2_ : bn1_);

	BigNumber* multBn = (BigNumber*)malloc(sizeof(BigNumber));
	if (multBn == NULL)
		return NULL;

	size_t size = (size_t)(maxBn->size + minBn->size);

	multBn->digits = (digit*)calloc(size, sizeof(digit));
	if (multBn->digits == NULL)
	{
		free(multBn);
		return NULL;
	}

	multBn->size = (unsigned int)(size);

	if ((maxBn->is_negative == true || minBn->is_negative == true) && !(maxBn->is_negative == true && minBn->is_negative == true))
		multBn->is_negative = true;
	else
		multBn->is_negative = false;
	
	int e = 0;

	unsigned int i = (maxBn->size - 1);
	unsigned int j = (minBn->size);
	unsigned int m = (multBn->size - 1);

	int count = 0;

	while (j > 0)
	{
		m = (multBn->size - 1) - count;
		i = (maxBn->size);

		while (i > 0)
		{
			int multiplication = (maxBn->digits[i - 1] * minBn->digits[j - 1]) + e;
			multBn->digits[m] += multiplication % 10;
			e = multiplication / 10;
			if (multBn->digits[m] > 9)
			{
				e += multBn->digits[m] / 10;
				multBn->digits[m] %= 10;
			}
			--m;
			--i;
		}
		multBn->digits[m] += e;
		++count;
		e = 0;
		--j;
	}
	
	if (e > 0)
		multBn->digits[0] = e;
	else
		if (multBn->digits[0] == 0) {
			for (int k = 0; k < (int)(multBn->size) - 1; k++) {
				multBn->digits[k] = multBn->digits[k + 1];
			}
			multBn->size--;
		}

	return multBn;
}

BigNumber* DivBN(BigNumber* bn1_, BigNumber* bn2_)
{
	// Проверка на нулевые указатели или размер нулевых чисел
	if (bn1_ == NULL || bn2_ == NULL || bn1_->size == 0 || bn2_->size == 0)
		return NULL;


	// Проверка деления на ноль
	if (bn2_->size == 1 && bn2_->digits[0] == 0)
		return NULL;


	// Определение максимального и минимального чисел
	BigNumber* maxBn = (bn1_->size >= bn2_->size ? bn1_ : bn2_);
	BigNumber* minBn = (bn1_->size >= bn2_->size ? bn2_ : bn1_);

	// Выделение памяти под результат
	BigNumber* divBn = CreateBN("0");
	if (divBn == NULL)
		return NULL;

	char str_one[] = "1";
	
	BigNumber* bn_one = CreateBN(str_one);
	if (bn_one == NULL)
	{
		free(divBn);
		return NULL;
	}

	// Выделение памяти под массив цифр
	divBn->digits = (digit*)calloc(maxBn->size, sizeof(digit));
	if (divBn->digits == NULL)
	{
		free(divBn);
		return NULL;
	}

	bn1_->is_negative = 0;

	while (bn1_->is_negative == 0)
	{
		bn1_ = SubBN(bn1_, bn2_);
		if (bn1_->is_negative == 0)
			divBn = SumBN(divBn, bn_one);
	}

	return divBn;
}