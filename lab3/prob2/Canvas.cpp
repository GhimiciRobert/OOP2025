#include "Canvas.h"
#include<cmath>
#include<stdio.h>


Canvas::Canvas(int width, int height)
{
    this->width = width;
    this->height = height;
    matrice = new char* [height];
    for (int i = 0; i < height; i++)
    {
        matrice[i] = new char[width];
    }
    Clear();
}

Canvas::~Canvas()
{
    for (int i = 0; i < height; i++) {
        delete[] matrice[i];
    }
    delete[] matrice;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if ((i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray - 1) && (i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1))
                matrice[i][j] = ch;
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray))
                matrice[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = left;i <= right;i++)
    {
        matrice[top][i] = ch;
        matrice[bottom][i] = ch;
    }
    for (int i = top + 1;i <= bottom - 1;i++)
    {
        matrice[i][left] = ch;
        matrice[i][right] = ch;
    }
   
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = left;i <= right;i++)
        for (int j = top;j <= bottom;j++)
            matrice[i][j] = ch;
   
}

void Canvas::SetPoint(int x, int y, char ch)
{
    matrice[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1; // Direcția pe axa X
    int sy = (y1 < y2) ? 1 : -1; // Direcția pe axa Y
    int err = dx - dy; // Inițializarea erorii

    while (true) {
        SetPoint(x1, y1, ch); // Desenează punctul curent

        if (x1 == x2 && y1 == y2) break; // Oprire când se ajunge la final

        int err2 = 2 * err;

        if (err2 > -dy) { // Se deplasează pe X
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx) { // Se deplasează pe Y
            err += dx;
            y1 += sy;
        }
    }
}

void Canvas::Print()
{
    for (int i = 0;i < height;i++)

    {
        for (int j = 0;j < width;j++)
            printf("%c", matrice[i][j]);
        printf("\n");
    }
}

void Canvas::Clear()
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            matrice[i][j] = ' ';
}
