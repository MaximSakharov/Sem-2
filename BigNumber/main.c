#include <stdio.h>
#include "big_number.h"

int main()
{
   char str1[] = "123456789012345678901234567890";
   char str2[] = "98765432109876543210987654";

   BigNumber* bn1 = CreateBN(str1);
   if (bn1 == NULL)
      printf("bn1 == NULL!\n");

   BigNumber* bn2 = CreateBN(str2);
   if (bn2 == NULL)
      printf("bn2 == NULL!\n");

   int choice = 0;
   printf("Insert choice:\n");
   printf("1 - Sum Big Numbers\n");
   printf("2 - Sub Big Numbers\n");
   printf("3 - Mult Big Numbers\n");
   printf("4 - Div Big Numbers\n");
   printf("> ");
   scanf_s("%d", &choice);

   if (choice == 1)
   {
      BigNumber* sumBn = SumBN(bn1, bn2);
      PrintBN(sumBn);
   }
   else if (choice == 2)
   {
      BigNumber* subBn = SubBN(bn1, bn2);
      PrintBN(subBn);
   }
   else if (choice == 3)
   {
      BigNumber* multBn = MultBN(bn1, bn2);
      PrintBN(multBn);
   }
   else if (choice == 4)
   {
      BigNumber* divBn = DivBN(bn1, bn2);
      PrintBN(divBn);
   }
   else
      printf("Not a correct choice");
   return 0;
}