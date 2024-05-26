#include <stdio.h> 
#include <stdlib.h>

typedef struct Rhombus Rhombus;

/*
* @brief Проверяет является ли фигура ромбом
* @param side_: длина стороны ромба
* @param angle1_: угол ромба
* @param angle2_: угол ромба
* @return true - является ромбом, false - иначе
*/
bool Is_Rhombus(double side_, double angle1_, double angle2_);

/*
* @brief Создание ромба
* @param side_: длина стороны ромба
* @param angle1_: угол ромба
* @param angle2_: угол ромба
* @return указатель на выделенную память с ромбом
*/
Rhombus* CreateRhombus(double side_, double angle1_, double angle2_);

/*
* @brief Печать ромба
* @param rhombus_: ромб
*/
void Print_Rhombus(Rhombus* rhombus_);

/*
* @brief Удаление ромба
* @param rhombus_: ромб
*/
void DeleteRhombus(Rhombus** rhombus_);

/*
* @brief Выводит диагонали ромба
* @param rhombus_: ромб
*/
void Rhombus_Diagonals(Rhombus* rhombus_);

/*
* @brief Выводит площадь ромба
* @param rhombus_: ромб
*/
void Rhombus_Area(Rhombus* rhombus_);

/*
* @brief Выводит высоту ромба
* @param rhombus_: ромб
*/
void Rhombus_Height(Rhombus* rhombus_);

/*
* @brief Находит параметры ромба
* @param rhombus_: ромб
* @param pos_: позиция параметра (1 - длина стороны, 2 - наибольший угол, 3 - наименьший угол)
* @return Возращает значение параметра
*/
double Rhombus_Data(Rhombus* rhombus_, int pos_);