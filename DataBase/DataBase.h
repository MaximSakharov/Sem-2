#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#define _USE_MATH_DEFINES 
#include <math.h>

#include "closed_type.h" 

typedef struct DataBase DataBase;

/*
* @brief �������� ���� ��������������
*/
void Print_Menu();

/*
* @brief ���������� ���������� �������� �����
* @param count: ���������� ��������� ������
* @return ���������� �������� �������
*/
int get_variant(int count);

/*
* @brief ��������� � ���� ������ �������
* @param data_base_: ��������� �� ���� ������ 
* @param size_: ��������� �� ������ ���� ������
*/
void Add_DataBase(DataBase** data_base_, int* size_);

/*
* @brief ������� ���� ������
* @param data_base_: ���� ������
* @param size_: ������ ���� ������
*/
void Print_DataBase(DataBase* data_base_, int size_);

/*
* @brief ������� ������ ��������� ������ ��� ��������������
*/
void Print_List_Keys();

/*
* @brief ��������� ���� ������ �� �����
* @param data_base_: ���� ������
* @param size_: ������ ���� ������
*/
void Sort_DataBase(DataBase* data_base_, int size_);

/*
* @brief ���� ����� �� ����� (������)
* @param data_base_: ���� ������
* @param size_: ������ ���� ������
*/
void Find_DataBase(DataBase* data_base_, int size_);

/*
* @brief ������� ������ � ������ �� ����� (������)
* @param data_base_: ��������� �� ���� ������
* @param size_: ��������� �� ������ ���� ������
*/
void Delete_Data_DataBase(DataBase** data_base_, int* size_);

/*
* @brief ������� �������������� ���������� � ������ (���������, ������, �������)
* @param data_base_: ���� ������
* @param size_: ������ ���� ������
*/
void Extra_Information(DataBase* data_base_, int size_);