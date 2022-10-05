#include <Windows.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void drawSin(HWND& hWnd, const float scaleX = 1, const float scaleY = 1, int offsetX = 0, int offsetY = 0)
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
    for (float x = -10.0f; x <= 10.0f; x += 0.001f)
    {
        MoveToEx(hDC, x * scaleX + 10 * scaleX + offsetX * scaleX, sin(x) * scaleY + 8 * scaleY + offsetY * scaleY, NULL);
        LineTo(hDC, x * scaleX + 10 * scaleX + offsetX * scaleX, sin(x) * scaleY + 8 * scaleY + offsetY * scaleY);
    }

    ReleaseDC(hWnd, hDC);
    cin.get();
}


// Синусоида
int main(void)
{
    setlocale(LC_ALL, "Russian");
    HWND hWnd = GetConsoleWindow();
    int offset_x, offset_y;

    const float scaleX = 42;
    const float scaleY = 42;

    drawSin(hWnd, scaleX, scaleY);
    
    return EXIT_SUCCESS;
}