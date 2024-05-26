#include "big_number.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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