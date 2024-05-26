#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#define _USE_MATH_DEFINES 
#include <math.h>

#include "closed_type.h" 

struct Rhombus
{
   double side; //длина стороны ромба
   double greatest_angle; // размер наибольшего угла
   double smallest_angle; // размер наименьшего угла
};

bool Is_Rhombus(double side_, double angle1_, double angle2_)
{
   if (side_ <= 0 || angle1_ <= 0 || angle2_ <= 0 || angle1_ >= 180 || angle2_ >= 180)
      return false;
   
   if (angle1_ + angle2_ == 180)
      return true;
   else
      return false;
}

Rhombus* CreateRhombus(double side_, double angle1_, double angle2_)
{
   Rhombus* rhombus = malloc(sizeof(Rhombus));
   if (!rhombus)
      return NULL;

   if (Is_Rhombus(side_, angle1_, angle2_) == false)
      return NULL;

   rhombus->side = side_;
   rhombus->greatest_angle = (angle1_ > angle2_) ? angle1_ : angle2_;
   rhombus->smallest_angle = (angle1_ < angle2_) ? angle1_ : angle2_;

   return rhombus;
}

void Print_Rhombus(Rhombus* rhombus_)
{
   if (rhombus_ == NULL)
   {
      printf("Not a rhombus");
      return;
   }

   printf("%7.2f    %14.2f  %14.2f ", rhombus_->side, rhombus_->greatest_angle, rhombus_->smallest_angle);
   printf("\n");
}

void DeleteRhombus(Rhombus** rhombus_)
{
   if (*rhombus_)
   {
      free(*rhombus_);
      *rhombus_ = NULL;
   }
}

void Rhombus_Diagonals(Rhombus* rhombus_)
{
   double greatest_diag = (double)rhombus_->side * (double)sqrt(2-2 * cos(rhombus_->greatest_angle * (M_PI / 180)));
   double smallest_diag = (double)rhombus_->side * sqrt(2 - 2 * cos(rhombus_->smallest_angle * (M_PI / 180)));

   printf("Greatest diagonal: %f\n", greatest_diag);
   printf("Smallest diagonal: %f\n", smallest_diag);
}

void Rhombus_Area(Rhombus* rhombus_)
{
   double area = (pow(rhombus_->side, 2) * sin(rhombus_->smallest_angle * (M_PI / 180)));
   
   printf("Square: %f\n", area);
}

void Rhombus_Height(Rhombus* rhombus_)
{
   double height = (rhombus_->side * sin(rhombus_->smallest_angle * (M_PI / 180)));

   printf("Height: %f\n", height);
}

double Rhombus_Data(Rhombus* rhombus_, int pos_)
{
   if (pos_ == 1)
      return rhombus_->side;
   else if (pos_ == 2)
      return rhombus_->greatest_angle;
   else if (pos_ == 3)
      return rhombus_->smallest_angle;
   else
      return 0;
}