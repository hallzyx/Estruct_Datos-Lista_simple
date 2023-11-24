#pragma once
#include<iostream>

using namespace std;

class Empanada {


private:
	string sabor;
	double precio;
	int n_entrega;

public:
	Empanada(string _sabor, int _n_entrega) {
		this->sabor = _sabor;
		this->n_entrega = _n_entrega;

		if (sabor == "queso") {
			this->precio = 1.50;
		}
		else if (sabor == "jamon") {
			this->precio = 2.50;
		}
		else {
			this->precio = 3.50;
		}
	};



	string getSabor() {
		return this->sabor;
	};
	double getPrecio() {
		return this->precio;
	};
	int getN_entrega() {
		return this->n_entrega;
	};

	void setSabor(string _sabor) {
		this->sabor = _sabor;
	};
	void setPrecio(double _precio) {
		this->precio = _precio;
	};
	void setN_entrega(int _n_entrega) {
		this->n_entrega = _n_entrega;
	};
	
	

	void infoEmpanada() {
		
		cout << "Sabor: " << sabor << endl;
		cout << "Precio: " << precio << endl;
		cout << "N_entrega: " << n_entrega << endl;
	}

};