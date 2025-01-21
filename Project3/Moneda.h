#pragma once
using namespace System::Drawing;
using namespace System;

class CMoneda
{
private:
	int x;
	int y;
	int dx;
	int dy;
	int dy2;
	int dx2;
	int alto;
	int ancho;
	int indiceX;
	int transformacion;
	int rand;
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int x4, y4;
	int x5, y5;
	int x6, y6;
	int x7, y7;
	int aaa;
public:
	CMoneda();
	~CMoneda();
	CMoneda(int x, int y);

	void dibujar(BufferedGraphics ^buffer, Image^img);
	void Cambiar(BufferedGraphics ^buffer);
	int Get_x();
	int Get_y();
	int Get_dx();
	int Get_dy();
	int Get_alto();
	int Get_ancho();

	void Set_X(int CambiarX);
	void Set_Y(int CambiarY);
};

