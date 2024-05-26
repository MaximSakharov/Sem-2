#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>

#include "closed_type.h" 
#include "DataBase.h"

int main()
{
   struct DataBase* db = NULL; // База данных
   int size = 0;

   int variant = 0;

   while (variant != 7)
   {
      Print_Menu();

      variant = get_variant(7);

      switch (variant)
      {
      case 1:
         Add_DataBase(&db, &size);
         break;

      case 2:
         Print_DataBase(db, size);
         break;
      case 3:
         Sort_DataBase(db, size);
         break;
      case 4:
         Find_DataBase(db, size);
         break;
      case 5:
         Delete_Data_DataBase(&db, &size);
         break;
      case 6:
         Extra_Information(db, size);
         break;
      }
      if (variant != 7)
         system("pause");
   }
   return 0;
}