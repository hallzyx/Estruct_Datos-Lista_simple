#pragma once
template <class T>
class Nodo
{
private:
	
public:
	//propiedades o atributos
	T elem;
	Nodo* sgte;

	//Constructores
	Nodo()
	{
		sgte = nullptr;
	}
	Nodo(T pelem)
	{
		elem = pelem;
		sgte = nullptr;
	}

	//M�todos Setter / Getter
	void set_Elem(T pelem)
	{
		elem = pelem;
	}
	T get_Elem()
	{
		return elem;
	}
	void set_Sgte(Nodo* pSgte)
	{
		sgte = pSgte;
	}
	Nodo* get_Sgte()
	{
		return sgte;
	}

	//M�todos de Servicio
	bool es_vacio()
	{
		return sgte == NULL;
	}

};
