#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "functions.h"
#include "Euler.h"
#include "big_number.h"

/* Есть структура, которая хранит дату и время. Написать функции: 
	по двум датам определяет разницу во времени,
	определяет високосный год или нет,
	на вход дата - выводит кол-во прошедших дней с начала года
*/

int main()
{
	int number = 0;

	int time1 = 0;
	int time2 = 0;

	time_t start, end;

	int choice = 0;
	printf("Enter the problem(6, 7, 8, 9, 10) ");
	scanf_s("%d", &choice);


	if (choice == 6)
	{
		printf("Enter the number ");
		scanf_s("%d", &number);

		printf("\n");
		start = clock();
		printf("Answer: %f\n", Problem_6(number));
		end = clock();
		double time_taken = (double)(end - start) / (double)CLOCKS_PER_SEC;
		printf("%f\n", time_taken);
	}
	else if (choice == 7)
	{
		printf("Enter the number ");
		scanf_s("%d", &number);

		printf("\n");
		start = clock();
		printf("Answer: %d\n", Problem_7(number));
		end = clock();
		double time_taken = (double)(end - start) / (double)CLOCKS_PER_SEC;
		printf("%f\n", time_taken);
	}
	else if (choice == 8)
	{
		char str[] =
"73167176531330624919225119674426574742355349194934\
96983520312774506326239578318016984801869478851843\
85861560789112949495459501737958331952853208805511\
12540698747158523863050715693290963295227443043557\
66896648950445244523161731856403098711121722383113\
62229893423380308135336276614282806444486645238749\
30358907296290491560440772390713810515859307960866\
70172427121883998797908792274921901699720888093776\
65727333001053367881220235421809751254540594752243\
52584907711670556013604839586446706324415722155397\
53697817977846174064955149290862569321978468622482\
83972241375657056057490261407972968652414535100474\
82166370484403199890008895243450658541227588666881\
16427171479924442928230863465674813919123162824586\
17866458359124566529476545682848912883142607690042\
24219022671055626321111109370544217506941658960408\
07198403850962455444362981230987879927244284909188\
84580156166097919133875499200524063689912560717606\
05886116467109405077541002256983155200055935729725\
71636269561882670428252483600823257530420752963450";

		printf("Enter the number ");
		scanf_s("%d", &number);

		BigNumber* bn = CreateBN(str);
		if (bn == NULL)
			printf("bn == NULL!\n");
		
		start = clock();
		printf("Answer: %lld\n", Problem_8(number, bn));
		end = clock();
		double time_taken = (double)(end - start) / (double)CLOCKS_PER_SEC;
		printf("%f\n", time_taken);

		DeleteBN(&bn);
	}
	else if (choice == 9)
	{
		printf("Enter the number ");
		scanf_s("%d", &number);

		printf("\n");

		start = clock();
		if (Problem_9(number) == 0)
			printf("There is no such Pythagorean triple\n");
		else
			printf("Answer: %lld\n", Problem_9(number));
		end = clock();
		double time_taken = (double)(end - start) / (double)CLOCKS_PER_SEC;
		printf("%f\n", time_taken);
	}
	else if (choice == 10)
	{
		printf("Enter the number ");
		scanf_s("%d", &number);

		start = clock();
		printf("%lld\n", Problem_10(number));
		end = clock();
		double time_taken = (double)(end - start) / (double)CLOCKS_PER_SEC;
		printf("%f\n", time_taken);

	}
	else
		printf("No such problem");
	//printf("Enter the number ");
	//scanf_s("%d", &number);

	//printf("The difference between the sum of the squares of the first ten natural numbers and the square of the sum is %f\n", Problem_6(number));

	//printf("The %d prime number is %d", number, Problem_7(number));

	//printf("\n");


	//

	return 0;
}

