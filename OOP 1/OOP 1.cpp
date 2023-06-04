#include "classes.h"

HDC hdc;//Контекст устройства(содержит описание видеокарты и всех необходимых графических элементов)

int main()
{
	//получим дескриптор консольного окна
	HWND hwnd = GetConcolWindow();
	hdc = GetWindowDC(hwnd);    // контекст устройства консольного окна

	// Зададим перо и цвет пера
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);

	Point APoint(200, 200);
	Tower tow(200, 200);

	PressKey(49);			//1
	APoint.set_visible();

	//PressKey(50);			//2
	//APoint.Move_To(APoint.Get_X() + 200, APoint.Get_Y());

	PressKey(51);			//3
	tow.set_visible();

	PressKey(52);			//4
	tow.Move_To(tow.Get_X() + 200, tow.Get_Y());

	PressKey(53);			//5
	tow.Drag();

	DeleteObject(Pen);

	return 0;
}