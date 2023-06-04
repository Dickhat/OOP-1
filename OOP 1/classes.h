#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include "support.h"

using namespace std;

//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

//Класс местоположение
class Location
{
protected:
	int X;//Координата X
	int Y;//Координата Y

public:
	//Конструктор
	Location(int ind_X, int ind_Y)
	{
		X = ind_X;
		Y = ind_Y;
	}

	//Возвращает X
	int Get_X(){return X;};

	//Возвращает Y
	int Get_Y(){return Y;}

	//Устанавливает X
	void Set_X(int ind_X){X = ind_X;};

	//Устанавливает Y
	void Set_Y(int ind_Y){Y = ind_Y;};
};

//Класс точка
class Point :public Location
{
public:
	//КОНСТРУКТОР
	Point(int X, int Y) :Location(X, Y){};

	//static 
	void set_visible();

	//static
	void set_invisible();

	////virtual Делает видимой точку
	//virtual void set_visible();

	////virtual Делает невидимой точку
	//virtual void set_invisible();

	//Перемещает точку
	void Move_To(int X, int Y);

	//Перетаскивание точки
	void Drag();
};

//Класс фигура (Башня)
class Tower :public Point
{
public:
	Tower(int X, int Y) :Point(X, Y) {};

	//Рисование башни
	void Paint();

	//Делает видимой башню
	void set_visible();

	//Делает невидимой башню
	void set_invisible();

	//Перемещает башню (static)
	void Move_To(int X, int Y)
	{
		set_invisible();
		Set_X(X);
		Set_Y(Y);
		set_visible();
	}
	
	//Перетаскивание точки (static)
	void Drag()
	{
		//while 7 - выход
		while (!KEY_DOWN(55))
		{
			// A - влево
			if (KEY_DOWN(65)) Move_To(Get_X() - 20, Get_Y());
			// W - вверх
			else if (KEY_DOWN(87)) Move_To(Get_X(), Get_Y() - 20);
			// D - вправо
			else if (KEY_DOWN(68)) Move_To(Get_X() + 20, Get_Y());
			// S - Вниз
			else if (KEY_DOWN(83)) Move_To(Get_X(), Get_Y() + 20);
			Sleep(10);
		}
	}
};
