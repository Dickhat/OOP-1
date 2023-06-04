#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include "support.h"

using namespace std;

//������ ��� ����������� ���� ������� �������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

//����� ��������������
class Location
{
protected:
	int X;//���������� X
	int Y;//���������� Y

public:
	//�����������
	Location(int ind_X, int ind_Y)
	{
		X = ind_X;
		Y = ind_Y;
	}

	//���������� X
	int Get_X(){return X;};

	//���������� Y
	int Get_Y(){return Y;}

	//������������� X
	void Set_X(int ind_X){X = ind_X;};

	//������������� Y
	void Set_Y(int ind_Y){Y = ind_Y;};
};

//����� �����
class Point :public Location
{
public:
	//�����������
	Point(int X, int Y) :Location(X, Y){};

	//static 
	void set_visible();

	//static
	void set_invisible();

	////virtual ������ ������� �����
	//virtual void set_visible();

	////virtual ������ ��������� �����
	//virtual void set_invisible();

	//���������� �����
	void Move_To(int X, int Y);

	//�������������� �����
	void Drag();
};

//����� ������ (�����)
class Tower :public Point
{
public:
	Tower(int X, int Y) :Point(X, Y) {};

	//��������� �����
	void Paint();

	//������ ������� �����
	void set_visible();

	//������ ��������� �����
	void set_invisible();

	//���������� ����� (static)
	void Move_To(int X, int Y)
	{
		set_invisible();
		Set_X(X);
		Set_Y(Y);
		set_visible();
	}
	
	//�������������� ����� (static)
	void Drag()
	{
		//while 7 - �����
		while (!KEY_DOWN(55))
		{
			// A - �����
			if (KEY_DOWN(65)) Move_To(Get_X() - 20, Get_Y());
			// W - �����
			else if (KEY_DOWN(87)) Move_To(Get_X(), Get_Y() - 20);
			// D - ������
			else if (KEY_DOWN(68)) Move_To(Get_X() + 20, Get_Y());
			// S - ����
			else if (KEY_DOWN(83)) Move_To(Get_X(), Get_Y() + 20);
			Sleep(10);
		}
	}
};
