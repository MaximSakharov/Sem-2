#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#define _USE_MATH_DEFINES 
#include <math.h>

#include "closed_type.h" 

typedef struct DataBase DataBase;

/*
* @brief Вызывает меню взаимодействия
*/
void Print_Menu();

/*
* @brief Исчитывает правильный введённый выбор
* @param count: Количество вариантов выбора
* @return Правильный введённый вариант
*/
int get_variant(int count);

/*
* @brief Добавляет в базу данных элемент
* @param data_base_: указатель на базу данных 
* @param size_: указатель на размер базы данных
*/
void Add_DataBase(DataBase** data_base_, int* size_);

/*
* @brief Выводит базу данный
* @param data_base_: база данных
* @param size_: размер базы данных
*/
void Print_DataBase(DataBase* data_base_, int size_);

/*
* @brief Выводит список доступных ключей для взаимодействия
*/
void Print_List_Keys();

/*
* @brief Сортирует базу данных по ключу
* @param data_base_: база данных
* @param size_: размер базы данных
*/
void Sort_DataBase(DataBase* data_base_, int size_);

/*
* @brief Ищет ромбы по ключу (ключам)
* @param data_base_: база данных
* @param size_: размер базы данных
*/
void Find_DataBase(DataBase* data_base_, int size_);

/*
* @brief Удаляет данные о ромбах по ключу (ключам)
* @param data_base_: указатель на базу данных
* @param size_: указатель на размер базы данных
*/
void Delete_Data_DataBase(DataBase** data_base_, int* size_);

/*
* @brief Выводит дополнительную информацию о ромбах (диагонали, высоты, площадь)
* @param data_base_: база данных
* @param size_: размер базы данных
*/
void Extra_Information(DataBase* data_base_, int size_);