#include <Windows.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void drawSin(HWND hWnd, const float scaleX = 1, const float scaleY = 1)
{
    HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
    HDC hDC = GetDC(hWnd);

    SelectObject(hDC, Pen);

    // Отрисовка вертикальной и горизонтальной линии графика
    MoveToEx(hDC, 0, 8 * scaleY, NULL);
    LineTo(hDC, 20 * scaleX, 8 * scaleY);
    MoveToEx(hDC, 10 * scaleX, 0, NULL);
    LineTo(hDC, 10 * scaleX, 16 * scaleY);

    // отрисовка графика sin(x)
    for (float x = -15.0f; x <= 15.0f; x += 0.001f)
    {
        MoveToEx(hDC, scaleX * x + 5 * scaleX , -scaleY * sin(x) + 8 * scaleY, NULL);
        LineTo(hDC, scaleX * x + 5 * scaleX, -scaleY * sin(x) + 8 * scaleY);
    }

    ReleaseDC(hWnd, hDC);
    cin.get();
}


// Синусоида
int main(void)
{
    HWND hWnd = GetConsoleWindow();

    const float scaleX = 42;
    const float scaleY = 42;

    drawSin(hWnd, scaleX, scaleY);
    
    return EXIT_SUCCESS;
}