#include <stdio.h> 
#include <stdlib.h>

typedef struct Rhombus Rhombus;

/*
* @brief ��������� �������� �� ������ ������
* @param side_: ����� ������� �����
* @param angle1_: ���� �����
* @param angle2_: ���� �����
* @return true - �������� ������, false - �����
*/
bool Is_Rhombus(double side_, double angle1_, double angle2_);

/*
* @brief �������� �����
* @param side_: ����� ������� �����
* @param angle1_: ���� �����
* @param angle2_: ���� �����
* @return ��������� �� ���������� ������ � ������
*/
Rhombus* CreateRhombus(double side_, double angle1_, double angle2_);

/*
* @brief ������ �����
* @param rhombus_: ����
*/
void Print_Rhombus(Rhombus* rhombus_);

/*
* @brief �������� �����
* @param rhombus_: ����
*/
void DeleteRhombus(Rhombus** rhombus_);

/*
* @brief ������� ��������� �����
* @param rhombus_: ����
*/
void Rhombus_Diagonals(Rhombus* rhombus_);

/*
* @brief ������� ������� �����
* @param rhombus_: ����
*/
void Rhombus_Area(Rhombus* rhombus_);

/*
* @brief ������� ������ �����
* @param rhombus_: ����
*/
void Rhombus_Height(Rhombus* rhombus_);

/*
* @brief ������� ��������� �����
* @param rhombus_: ����
* @param pos_: ������� ��������� (1 - ����� �������, 2 - ���������� ����, 3 - ���������� ����)
* @return ��������� �������� ���������
*/
double Rhombus_Data(Rhombus* rhombus_, int pos_);