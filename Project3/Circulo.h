#pragma once
class CCirculo
{
	int x;
	int y;
	int dx;
	int dy;
	int Radio;
	int Soy;
	//	int Color;
public:
	int A;
	int B;
	int C;
	CCirculo(int Tipo/*,int Color*/);
	~CCirculo();

	int Get_X();
	int Get_Y();
	int Get_dx();
	int Get_dy();
	int Get_Radio();
	void Set_X(int Value);
	void Set_Y(int Value);
	void Set_dx(int Value);
	void Set_dy(int Value);

	void Dibujar(System::Drawing::BufferedGraphics ^Bufer);
	void Mover(System::Drawing::BufferedGraphics ^Bufer);

};

