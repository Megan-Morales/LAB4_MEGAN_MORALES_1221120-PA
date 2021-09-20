#include <iostream>
#include <string>

using namespace std;
int num_Nodos = 1; //variable global

struct nodo { //Nodos de la lista
	int id_Posicion=0;
	bool tortuga_en_Nodo = false;
	bool liebre_en_Nodo = false;
	nodo* siguiente= NULL;
	nodo* atras= NULL;
}*primero, *ultimo;

void comenzarCarrera();
void insertarNodo();
void mostrarLista();

int main() {
	for (int i = 0; i < 70; i++) {
		insertarNodo();
	}
	comenzarCarrera();
	mostrarLista();
}

void comenzarCarrera() {
	nodo* nodo_Temporal = new nodo();
	nodo_Temporal = primero;
	nodo_Temporal->liebre_en_Nodo = true;
	nodo_Temporal->tortuga_en_Nodo = true;
}
void insertarNodo() {
	nodo* nuevo = new nodo();

	if (primero == NULL) {
		primero = nuevo;
		ultimo = primero;
		primero->id_Posicion = num_Nodos;
	}
	else {
		ultimo->siguiente = nuevo;
		nuevo->atras = ultimo;
		nuevo->id_Posicion = num_Nodos;
		ultimo = nuevo;
	}
	
	num_Nodos++;
}
void mostrarLista() {
	nodo* nodo_Temporal = new nodo();
	nodo_Temporal = primero;

	if (primero != NULL) {
		int contador = 1;

		while (nodo_Temporal != NULL) {

			if (nodo_Temporal->liebre_en_Nodo == true && nodo_Temporal->tortuga_en_Nodo==true) {

				cout << "|L,T|";
			}
			else if (nodo_Temporal->liebre_en_Nodo == true ) {

				cout << "|L  |";
			}
			else if (nodo_Temporal->tortuga_en_Nodo==true) {

				cout << "|  T|";
			}
			else {
				cout << "|   |";
			}
			if (contador % 10 == 0) {
				cout << endl;
			}
			nodo_Temporal = nodo_Temporal->siguiente;
			contador++;
		}
	}
	else {
		cout << "\n La lista se encuentra vacia\n\n";
	}

}
