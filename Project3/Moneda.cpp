#include "Moneda.h"

CMoneda::CMoneda() {

}


CMoneda::~CMoneda()
{
}

CMoneda::CMoneda(int x, int y) {
	this->x = x;
	this->y = y;
	dx = 20;
	dy = 20;
	indiceX = 0;
	Random r;
	transformacion = r.Next(0, 4);
	dy2 = 10; dx2 = 20; // movimiento de los obstaculos
	x1 = x2 = 300;
	y1 = y3 = y5 = 670;
	y2 = y4 = y6 = 100;
	x3 = x4 = 700; 
	x5 = x6 = 1100; 
	x7 = 200;
	y7 = 380;

	aaa = 50;
}



void	CMoneda::dibujar(BufferedGraphics ^buffer,Image ^img) {

	ancho = img->Width;
	alto = img->Height;

	int anchoimagen = ancho / 4;

	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(anchoimagen*indiceX, 0, anchoimagen, alto);

	switch (transformacion)
	{
	case 0: //ROTACION 
	{
		System::Drawing::Rectangle aumento = System::Drawing::Rectangle(x, y, anchoimagen / 2, alto / 2);
		buffer->Graphics->DrawImage(img, aumento, porcion, System::Drawing::GraphicsUnit::Pixel);

		x = dx + x;
		y = dy + y;

		if (y + Get_alto() > buffer->Graphics->VisibleClipBounds.Height || y <= 0)
		{
			dy *= -1;
			Random r;
			transformacion = r.Next(0, 4);
		}

		if (x + Get_ancho() > buffer->Graphics->VisibleClipBounds.Width || x <= 0)
		{
			dx *= -1;
			Random r;
			transformacion = r.Next(0, 4);
		}
		break;
	}
	case 1: //REFLEXION
	{
		System::Drawing::Rectangle aumento = System::Drawing::Rectangle(x, y, anchoimagen / 2, alto / 2);
		buffer->Graphics->DrawImage(img, aumento, porcion, System::Drawing::GraphicsUnit::Pixel);

		x = dx + x;
		y = dy + y;


		if (y + Get_alto() > buffer->Graphics->VisibleClipBounds.Height || y <= 0)
		{
			dy *= -1;
			Random r;
			transformacion = r.Next(0, 4);
		}

		if (x + Get_ancho() > buffer->Graphics->VisibleClipBounds.Width || x <= 0)
		{
			dx *= -1;
			Random r;
			transformacion = r.Next(0, 4);
		}
		break;
	}
	case 2: //HOMOTECIA
	{
		System::Drawing::Rectangle aumento = System::Drawing::Rectangle(x, y, anchoimagen, alto);
		buffer->Graphics->DrawImage(img, aumento, porcion, System::Drawing::GraphicsUnit::Pixel);

		x = dx + x;
		y = dy + y;

		if (y + Get_alto() > buffer->Graphics->VisibleClipBounds.Height || y <= 0)
		{
			dy *= -1;
			Random r;
			transformacion = r.Next(0, 4);
		}

		if (x + Get_ancho() > buffer->Graphics->VisibleClipBounds.Width || x <= 0)
		{
			dx *= -1;
			Random r;
			transformacion = r.Next(0, 4);
		}
		break;
	}
	case 3: //REFLEXION 2
	{
		System::Drawing::Rectangle aumento = System::Drawing::Rectangle(x, y, anchoimagen/2, alto/2);
		buffer->Graphics->DrawImage(img, aumento, porcion, System::Drawing::GraphicsUnit::Pixel);

		x = dx + x;
		y = dy + y;

		if (y + Get_alto() > buffer->Graphics->VisibleClipBounds.Height || y <= 0)
		{
			dy *= -1;
			Random r;
			transformacion = r.Next(0, 4);
		}

		if (x + Get_ancho() > buffer->Graphics->VisibleClipBounds.Width || x <= 0)
		{
			dx *= -1;
			Random r;
			transformacion = r.Next(0, 4);
		}
		break;
	}
	case 4: //HOMOTECIA 2
	{
		System::Drawing::Rectangle aumento = System::Drawing::Rectangle(x, y, anchoimagen / 1.5, alto / 1.5);
		buffer->Graphics->DrawImage(img, aumento, porcion, System::Drawing::GraphicsUnit::Pixel);

		x = dx + x;
		y = dy + y;

		if (y + Get_alto() > buffer->Graphics->VisibleClipBounds.Height || y <= 0)
		{
			dy *= -1;
			Random r;
			transformacion = r.Next(0, 4);
		}

		if (x + Get_ancho() > buffer->Graphics->VisibleClipBounds.Width || x <= 0)
		{
			dx *= -1;
			Random r;
			transformacion = r.Next(0, 4);
		}
		break;
	}
	default:
		break;
	}


	
}



int CMoneda::Get_x() { return x; }
int CMoneda::Get_y() { return y; }
int CMoneda::Get_dx() { return dx; }
int CMoneda::Get_dy() { return dy; }
int CMoneda::Get_alto() {

	switch (transformacion)
	{
	case 0: 
	{
		return alto/2;
		break;
	}
	case 1: 
	{
		return alto/2;
		break;
	}
	case 2: 
	{
		return alto;
		break;
	}
	case 3: 
	{
		return alto/2;
		break;
	}
	case 4: 
	{
		return alto / 1.5;
		break;
	}
	default:
		break;
	}

}
int CMoneda::Get_ancho() {
	switch (transformacion)
	{
	case 0:
	{
		return (ancho / 4) / 2;
		break;
	}
	case 1:
	{
		return (ancho / 4) / 2;
		break;
	}
	case 2:
	{
		return (ancho / 4);
		break;
	}
	case 3:
	{
		return (ancho / 4) / 2;
		break;
	}
	case 4:
	{
		return ((ancho / 4) / 1.5);
		break;
	}
	default:
		break;
	}
}

void CMoneda::Cambiar(BufferedGraphics ^buffer) {

	Rectangle r1 = Rectangle(x1, y1, aaa, aaa); //ABAJO 
	buffer->Graphics->FillRectangle(Brushes::LightGreen, r1);

	Rectangle r2 = Rectangle(x2, y2, aaa, aaa); //ARRIBA
	buffer->Graphics->FillRectangle(Brushes::Blue, r2);

	Rectangle r3 = Rectangle(x3, y3, aaa, aaa); //ABAJO
	buffer->Graphics->FillRectangle(Brushes::LightGreen, r3);

	Rectangle r4 = Rectangle(x4, y4, aaa, aaa);//ARRIBA
	buffer->Graphics->FillRectangle(Brushes::Blue, r4);

	Rectangle r5 = Rectangle(x5, y5, aaa, aaa);//ABAJO
	buffer->Graphics->FillRectangle(Brushes::LightGreen, r5);

	Rectangle r6 = Rectangle(x6, y6, aaa, aaa);//ARRIBA
	buffer->Graphics->FillRectangle(Brushes::Blue, r6);

	Rectangle r7 = Rectangle(x7, y7, 200, aaa); //ULTIMO
	buffer->Graphics->FillRectangle(Brushes::Red, r7);

	y1 -= dy2;
	y2 += dy2;
	y3 -= dy2;
	y4 += dy2;
	y5 -= dy2;
	y6 += dy2;

	x7 += dx2;


	if (y2 + aaa >= ((buffer->Graphics->VisibleClipBounds.Height/2)-60))
	{
		dy2 *= -1;
	}
	if (y2 <= 0)
	{
		dy2 *= -1;
	}

	if (x7 + 200 >= buffer->Graphics->VisibleClipBounds.Width)
	{
		dx2 *= -1;
	}
	if (x7 <= 0)
	{
		dx2 *= -1;
	}




	Rectangle Moneda = Rectangle(x, y, Get_ancho(), Get_alto());

	if (Moneda.IntersectsWith(r1))
	{
		Random r;
		int rand = r.Next(0, 100);

		if (rand % 2 == 0)
		{
			dx *= -1;
			dy *= -1;
			if (indiceX < 3)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
		else
		{
			if (x + Get_ancho() > r1.X || x <= r1.X + r1.Width)
			{
				dx *= -1;
			}
			else
			{
				if (y + Get_alto() > r1.Y || y <= r1.Y + r1.Height)
				{
					dy *= -1;
					dx *= -1;
				}
			}

			if (indiceX < 3)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
	}

	if (Moneda.IntersectsWith(r2))
	{
		Random r;
		int rand = r.Next(0, 100);

		if (rand % 2 == 0)
		{
			dx *= -1;
			dy *= -1;
			if (indiceX < 3)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
		else
		{
			if (x + Get_ancho() > r2.X || x <= r2.X + r2.Width)
			{
				dx *= -1;
			}
			else
			{
				if (y + Get_alto() > r2.Y || y <= r2.Y + r2.Height)
				{
					dy *= -1;
					dx *= -1;
				}
			}

			if (indiceX < 3)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
	}

	if (Moneda.IntersectsWith(r3))
	{
		Random r;
		int rand = r.Next(0, 100);

		if (rand % 2 == 0)
		{
			dx *= -1;
			dy *= -1;
			if (indiceX < 3)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
		else
		{
			if (x + Get_ancho() > r3.X || x <= r3.X + r3.Width)
			{
				dx *= -1;
			}
			else
			{
				if (y + Get_alto() > r3.Y || y <= r3.Y + r3.Height)
				{
					dy *= -1;
					dx *= -1;
				}
			}

			if (indiceX < 3)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
	}

	if (Moneda.IntersectsWith(r4))
	{
		Random r;
		int rand = r.Next(0, 100);

		if (rand % 2 == 0)
		{
			dx *= -1;
			dy *= -1;
			if (indiceX < 3)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
		else
		{
			if (x + Get_ancho() > r4.X || x <= r4.X + r4.Width)
			{
				dx *= -1;
			}
			else
			{
				if (y + Get_alto() > r4.Y || y <= r4.Y + r4.Height)
				{
					dy *= -1;
					dx *= -1;
				}
			}

			if (indiceX < 3)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
	}
	
	if (Moneda.IntersectsWith(r5))
	{
		Random r;
		int rand = r.Next(0, 100);

		if (rand % 2 == 0)
		{
			dx *= -1;
			dy *= -1;
			if (indiceX < 3)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
		else
		{
			if (x + Get_ancho() > r5.X || x <= r5.X + r5.Width)
			{
				dx *= -1;
			}
			else
			{
				if (y + Get_alto() > r5.Y || y <= r5.Y + r5.Height)
				{
					dy *= -1;
					dx *= -1;
				}
			}

			if (indiceX < 3)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
	}

	if (Moneda.IntersectsWith(r6))
	{
		Random r;
		int rand = r.Next(0, 100);

		if (rand % 2 == 0)
		{
			dx *= -1;
			dy *= -1;
			if (indiceX < 3)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
		else
		{
			if (x + Get_ancho() > r6.X || x <= r6.X + r6.Width)
			{
				dx *= -1;
			}
			else
			{
				if (y + Get_alto() > r6.Y || y <= r6.Y + r6.Height)
				{
					dy *= -1;
					dx *= -1;
				}
			}

			if (indiceX < 3)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
	}

	if (Moneda.IntersectsWith(r7))
	{
		Random r;
		int rand = r.Next(0, 100);

		if (rand % 2 == 0)
		{
			dx *= -1;
			dy *= -1;
			if (indiceX < 3)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
		else
		{
			if (x + Get_ancho() > r7.X || x <= r7.X + r7.Width)
			{
				dx *= -1;
			}
			else
			{
				if (y + Get_alto() > r7.Y || y <= r7.Y + r7.Height)
				{
					dy *= -1;
					dx *= -1;
				}
			}

			if (indiceX < 3)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;
			}
		}
	}

}

void CMoneda::Set_X(int CambiarX) { x = CambiarX; }
void CMoneda::Set_Y(int CambiarY) { y = CambiarY; }