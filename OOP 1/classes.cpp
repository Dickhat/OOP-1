#include "classes.h"

extern HDC hdc;//�������� ����������(�������� �������� ���������� � ���� ����������� ����������� ���������)

//������ ������� �����
void Point::set_visible()
{
	SetPixel(hdc, X, Y, RGB(255, 0, 0));		//������ ����� ������������� ������
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));	//������ ����� ������������� ������
	SetPixel(hdc, X, Y + 1, RGB(255, 0, 0));	//������ ����� ������������� ������
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));//������ ����� ������������� ������
};

//������ ��������� �����
void Point::set_invisible()
{
	SetPixel(hdc, X, Y, RGB(0, 0, 0));			//������ ����� ������������� ������
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 0));		//������ ����� ������������� ������
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 0));		//������ ����� ������������� ������
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 0));	//������ ����� ������������� ������
};

//���������� �����
void Point::Move_To(int X, int Y)
{
	set_invisible();
	Set_X(X);
	Set_Y(Y);
	set_visible();
}

//�������������� �����
void Point::Drag()
{
	//while 7 - �����
	while (!KEY_DOWN(55))
	{
		// A - �����
		if (KEY_DOWN(65))
		{
			Move_To(Get_X() - 20, Get_Y());
		}
		// W - �����
		else if (KEY_DOWN(87))
		{
			Move_To(Get_X(), Get_Y() - 20);
		}
		// D - ������
		else if (KEY_DOWN(68))
		{
			Move_To(Get_X() + 20, Get_Y());
		}
		// S - ����
		else if (KEY_DOWN(83))
		{
			Move_To(Get_X(), Get_Y() + 20);
		}
		Sleep(10);
	}
}

//��������� �����
void Tower::Paint()
{
	//��������� �����
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

	//����� �����
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

//������ ������� �����
void Tower::set_visible()
{
	HPEN PenBlack = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	//������ ���� �������� 
	SelectObject(hdc, PenBlack);
	Paint();

	DeleteObject(PenBlack);
};

//������ ��������� �����
void Tower::set_invisible()
{
	//����� ���� (������)
	HPEN PenBlack = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
	//������ ���� �������� 
	SelectObject(hdc, PenBlack);
	Paint();

	DeleteObject(PenBlack);
};