#pragma once
#include <iostream>
#include <String>
using namespace System;
using namespace std;
using namespace System::Drawing::Drawing2D;
using namespace System::Drawing;
using namespace System::Windows::Forms;
class Cuadrado {
	int x;
	int y;
	int ancho;
	int alto;
	int direccion;
	int peso;
	int Color;
	int fuerza;
public:
	Cuadrado(int x, int y, int anc, int alt, int peso,int direccion ,int Color) {
		this->x = x;
		this->y = y;
		this->ancho = anc;
		this->alto = alt;
		this->direccion = direccion;
		this->peso = peso;
		this->Color = Color;
		this->fuerza = peso;
	}
	int getX() { return x; }
	int getY() { return y; }
	int getDireccion() { return direccion; }
	int getAlto() { return alto; }
	int getAncho() { return ancho; }
	int getPeso() { return peso; }
	int getFuerza() { return fuerza; }
	void setX(int x){this->x=x;}
	void setY(int y){this->y=y;}
	void setDireccion(int direccion){this->direccion=direccion;}
	void setFuerza(int fuerza) { this->fuerza=fuerza; }
	void Draw(Graphics^ lienso) {
		if (Color==1) {
			lienso->DrawString(gcnew String("" + peso),
				gcnew System::Drawing::Font("arial", 10), Brushes::Blue, x + ancho / 2.5, y - 80);
			lienso->DrawRectangle(Pens::Blue, x, y, ancho, alto);
			lienso->FillRectangle(Brushes::Blue, x, y, ancho, alto);
		}
		else if (Color==2) {
			lienso->DrawString(gcnew String("" + peso),
				gcnew System::Drawing::Font("arial", 10), Brushes::Aqua, x + ancho / 2.5, y - 80);
			lienso->DrawRectangle(Pens::Aqua, x, y, ancho, alto);
			lienso->FillRectangle(Brushes::Aqua, x, y, ancho, alto);
		}
	}
	void Move() {
		x += direccion;
		if (x<= 30 || x>=550) {
			direccion *= -1;
		}
		if (x<= 28) {
			x = 50;
		}
	}
	
};