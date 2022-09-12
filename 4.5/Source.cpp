#include <Windows.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(void)
{
    HWND hWnd = GetConsoleWindow();
    HDC hDC = GetDC(hWnd);
    HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));

    SelectObject(hDC, Pen);

    // Отрисовка вертикальной и горизонтальной линии графика
    MoveToEx(hDC, 0, 170, NULL);
    LineTo(hDC, 400, 170);
    MoveToEx(hDC, 200, 0, NULL);
    LineTo(hDC, 200, 340);

    // отрисовка графика sin(x)
    for (float x = -15.0f; x <= 15.0f; x += 0.001f)
    {
        MoveToEx(hDC, 20 * x + 100, -20 * sin(x) + 170, NULL);
        LineTo(hDC, 20 * x + 100, -20 * sin(x) + 170);
    }

    ReleaseDC(hWnd, hDC);
    cin.get();

    return 0;
}