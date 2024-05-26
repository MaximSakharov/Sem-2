#include "DataBase.h"


struct DataBase
{
   struct Rhombus* rhombus; 
};

void Print_Menu() 
{
   system("cls");  // очищаем экран
   printf("What do you want to do?\n");
   printf("1. Add rhombus in database\n");
   printf("2. Print all rhombuses in database\n");
   printf("3. Sort database by key\n");
   printf("4. Find rhombuses in database\n");
   printf("5. Delete rhombuses in database\n");
   printf("6. Print extra information about rhombuses\n");
   printf("7. Exit\n");
   printf(">");
}

int get_variant(int count) 
{
   int variant;

   while (scanf_s("%d", &variant) != 1 || variant < 1 || variant > count) {
      printf("Incorrect input. Try again: ");
   }

   return variant;
}

void Add_DataBase(DataBase** data_base_, int* size_)
{
   double side = 0;
   double greatest_angle = 0;
   double smallest_angle = 0;

   printf("Enter side and two angles\n");
   scanf_s("%lf %lf %lf", &side, &greatest_angle, &smallest_angle);

   Rhombus* rhombus = CreateRhombus(side, greatest_angle, smallest_angle);
   if (rhombus == NULL)
   {
      printf("Not a rhombus. Try again.\n");
      return;
   }

   (*size_)++;

   int size = *size_;

   struct DataBase* temp = (struct DataBase*)realloc(*data_base_, (*size_) * sizeof(struct DataBase));
   if (temp == NULL) {
      printf("Memory allocation failed. Exiting...\n");
      exit(EXIT_FAILURE);
   }
   *data_base_ = temp;

   (*data_base_)[size - 1].rhombus = rhombus;
}

void Print_DataBase(DataBase* data_base_, int size_)
{
   printf("|  N  |   Side   | Greatest_angle | Smallest_angle |\n");
   
   for (int i = 0; i < size_; ++i)
   {
      printf("   %d   ", i);
      Print_Rhombus(data_base_[i].rhombus);
   }
   
}

void Print_List_Keys()
{
   printf("1. Side\n");
   printf("2. Greatest angle\n");
   printf("3. Smallest angle\n");
}

void Sort_DataBase(DataBase* data_base_, int size_)
{
   Print_List_Keys();
   int key = get_variant(3);

   int B = size_;
   while (B != 0)
   {
      int t = 0;
      for (int i = 0; i < B - 1; ++i)
      {
         if (Rhombus_Data(data_base_[i].rhombus, key) > Rhombus_Data(data_base_[i + 1].rhombus, key))
         {
            struct DataBase temp = data_base_[i];
            data_base_[i] = data_base_[i + 1];
            data_base_[i + 1] = temp;
            t = i + 1;
         }
      }
      if (t == 0)
         break;
      B = t;
   }
}

void Find_DataBase(DataBase* data_base_, int size_)
{
   int key[4] = { 0, 0, 0, 0 };

   printf("Insert keys: \n");
   Print_List_Keys();
   printf("4. Stop insert\n");

   for (int j = 0; j < 4; ++j) 
   {
      while (scanf_s("%ld", &key[j]) != 1 || key[j] < 1 || key[j]>4)
      {
         printf("Incorrect input. Try again: ");
      }

      if (key[j] == 4)
      {
         key[j] = 0;
         break;
      }
   }
   
   double data1 = 0;
   double data2 = 0;
   double data3 = 0;

   if (key[0] == 1 || key[1] == 1 || key[2] == 1)
   {
      printf("Insert side: \n");
      scanf_s("%lf", &data1);
   }

   if (key[0] == 2 || key[1] == 2 || key[2] == 2)
   {
      printf("Insert greatest angle: \n");
      scanf_s("%lf", &data2);
   }
   if (key[0] == 3 || key[1] == 3 || key[2] == 3)
   {
      printf("Insert smallest angle: \n");
      scanf_s("%lf", &data3);
   }

   for (int i = 0; i < size_; ++i)
   {
      if ((Rhombus_Data(data_base_[i].rhombus, 1) == data1 || data1 == 0) && ((Rhombus_Data(data_base_[i].rhombus, 2) == data2 || data2 == 0) && ((Rhombus_Data(data_base_[i].rhombus, 3) == data3 || data3 == 0))))
      {
         printf("%d ", i);
         Print_Rhombus(data_base_[i].rhombus);
      }
   }
}

void Delete_Data_DataBase(DataBase** data_base_, int* size_)
{
   int key[4] = { 0, 0, 0, 0 };

   printf("Insert keys: \n");
   Print_List_Keys();
   printf("4. Stop insert\n");

   for (int j = 0; j < 4; ++j)
   {
      while (scanf_s("%ld", &key[j]) != 1 || key[j] < 1 || key[j]>4)
      {
         printf("Incorrect input. Try again: ");
      }

      if (key[j] == 4)
      {
         key[j] = 0;
         break;
      }
   }

   double data1 = 0;
   double data2 = 0;
   double data3 = 0;

   if (key[0] == 1 || key[1] == 1 || key[2] == 1)
   {
      printf("Insert side: \n");
      scanf_s("%lf", &data1);
   }

   if (key[0] == 2 || key[1] == 2 || key[2] == 2)
   {
      printf("Insert greatest angle: \n");
      scanf_s("%lf", &data2);
   }
   if (key[0] == 3 || key[1] == 3 || key[2] == 3)
   {
      printf("Insert smallest angle: \n");
      scanf_s("%lf", &data3);
   }

   int size = *size_;
   int i = 0;

   while (i < size)
   {
      if ((Rhombus_Data((*data_base_)[i].rhombus, 1) == data1 || data1 == 0) && ((Rhombus_Data((*data_base_)[i].rhombus, 2) == data2 || data2 == 0) && ((Rhombus_Data((*data_base_)[i].rhombus, 3) == data3 || data3 == 0))))
      {
         DeleteRhombus(&((*data_base_)[i].rhombus));
         for (int j = i; j < size - 1; ++j)
         {
            (*data_base_)[j].rhombus = (*data_base_)[j + 1].rhombus;
         }
         --(*size_);
         --size;
      }
      else
         ++i;
   }
}

void Extra_Information(DataBase* data_base_, int size_)
{
      printf("|  N  |   Side   | Greatest_angle | Smallest_angle |\n");

      for (int i = 0; i < size_; ++i)
      {
         printf("   %d   ", i);
         Print_Rhombus(data_base_[i].rhombus);
         Rhombus_Diagonals(data_base_[i].rhombus);
         Rhombus_Area(data_base_[i].rhombus);
         Rhombus_Height(data_base_[i].rhombus);
      }
}