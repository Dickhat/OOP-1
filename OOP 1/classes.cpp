#include "classes.h"

extern HDC hdc;//Контекст устройства(содержит описание видеокарты и всех необходимых графических элементов)

//Делает видимой точку
void Point::set_visible()
{
	SetPixel(hdc, X, Y, RGB(255, 0, 0));		//рисуем точку установленным цветом
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));	//рисуем точку установленным цветом
	SetPixel(hdc, X, Y + 1, RGB(255, 0, 0));	//рисуем точку установленным цветом
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));//рисуем точку установленным цветом
};

//Делает невидимой точку
void Point::set_invisible()
{
	SetPixel(hdc, X, Y, RGB(0, 0, 0));			//рисуем точку установленным цветом
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 0));		//рисуем точку установленным цветом
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 0));		//рисуем точку установленным цветом
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 0));	//рисуем точку установленным цветом
};

//Перемещает точку
void Point::Move_To(int X, int Y)
{
	set_invisible();
	Set_X(X);
	Set_Y(Y);
	set_visible();
}

//Перетаскивание точки
void Point::Drag()
{
	//while 7 - выход
	while (!KEY_DOWN(55))
	{
		// A - влево
		if (KEY_DOWN(65))
		{
			Move_To(Get_X() - 20, Get_Y());
		}
		// W - вверх
		else if (KEY_DOWN(87))
		{
			Move_To(Get_X(), Get_Y() - 20);
		}
		// D - вправо
		else if (KEY_DOWN(68))
		{
			Move_To(Get_X() + 20, Get_Y());
		}
		// S - Вниз
		else if (KEY_DOWN(83))
		{
			Move_To(Get_X(), Get_Y() + 20);
		}
		Sleep(10);
	}
}

//Рисование Башни
void Tower::Paint()
{
	//Основание башни
	MoveToEx(hdc, X, Y, NULL);
	LineTo(hdc, X + 60, Y);
	LineTo(hdc, X + 60, Y + 125);
	LineTo(hdc, X + 40, Y + 125);
	LineTo(hdc, X + 40, Y + 80);
	LineTo(hdc, X + 20, Y + 80);
	LineTo(hdc, X + 20, Y + 125);
	LineTo(hdc, X + 40, Y + 125);
	LineTo(hdc, X, Y + 125);
	LineTo(hdc, X, Y);

	//Крыша башни
	LineTo(hdc, X - 30, Y);
	LineTo(hdc, X - 30, Y - 60);
	LineTo(hdc, X - 5, Y - 60);
	LineTo(hdc, X - 5, Y - 30);
	LineTo(hdc, X + 25, Y - 30);
	LineTo(hdc, X + 25, Y - 60);
	LineTo(hdc, X + 50, Y - 60);
	LineTo(hdc, X + 50, Y - 30);
	LineTo(hdc, X + 75, Y - 30);
	LineTo(hdc, X + 75, Y - 30);
	LineTo(hdc, X + 75, Y - 60);
	LineTo(hdc, X + 95, Y - 60);
	LineTo(hdc, X + 95, Y);
	LineTo(hdc, X, Y);
}

//Делает видимой точку
void Tower::set_visible()
{
	HPEN PenBlack = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	//делаем перо активным 
	SelectObject(hdc, PenBlack);
	Paint();

	DeleteObject(PenBlack);
};

//Делает невидимой точку
void Tower::set_invisible()
{
	//Белый цвет (сейчас)
	HPEN PenBlack = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
	//делаем перо активным 
	SelectObject(hdc, PenBlack);
	Paint();

	DeleteObject(PenBlack);
};