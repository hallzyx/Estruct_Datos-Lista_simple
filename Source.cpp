#include<iostream>
#include<string.h>

#include"empanada.h"
#include"Lista.h"
#include"Nodo.h"

void imprimirLista(Lista<Empanada*>* lst) {
	for (int i = 0; i < lst->longitud(); i++) {
		cout << "Empanada " << i+1 << ":" << endl;
		cout << "------------------" << endl;
		lst->obtenerPos(i)->infoEmpanada();
		cout << endl;
	}
}



int main() {
	//cout << "Hola mundo!" << endl;
	Lista<Empanada*>* lst_empanadas = new Lista<Empanada*>();

	Empanada* emp1 = new Empanada("queso", 1);
	Empanada* emp2 = new Empanada("queso", 2);
	Empanada* emp3 = new Empanada("queso", 3);
	Empanada* emp4 = new Empanada("jamon", 1);
	Empanada* emp5 = new Empanada("jamon", 2);
	Empanada* emp6 = new Empanada("jamon", 3);
	
	Empanada* emp = new Empanada("Arroz", 777);

	lst_empanadas->agregaPos(emp1,0);
	lst_empanadas->agregaPos(emp2,1);
	lst_empanadas->agregaPos(emp3,2);
	lst_empanadas->agregaPos(emp4,3);
	lst_empanadas->agregaPos(emp5,4);
	lst_empanadas->agregaPos(emp6,5);

	//lst_empanadas->agregaPos(emp,5);

	//lst_empanadas->modificarPos(emp,2);

	//lst_empanadas->obtenerPos(5)->infoEmpanada();

	imprimirLista(lst_empanadas);
	

	//cout << lst_empanadas->esVacia();

	//cout << lst_empanadas->buscar(emp) << endl;

	if (lst_empanadas->buscar(emp)) {
		cout << "SI TA" << endl;
	}
	else {
		cout << "NO TA" << endl;
	}
};