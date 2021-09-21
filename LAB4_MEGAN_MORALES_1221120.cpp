#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;
int num_Nodos = 1; //variable global
int posicion_conejo = 1;
int posicion_liebre = 1;

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
int funcionRandom();
void moverTortuga();

int main() {
	srand(time(NULL));
	for (int i = 0; i < 70; i++) {
		insertarNodo();
	}
	comenzarCarrera();
	moverTortuga();
}

int funcionRandom() {
	int numeroAleatorio = 0;
	numeroAleatorio = 1 + rand() % (10);
	return numeroAleatorio;
	
}
void moverTortuga() {
	nodo* nodo_Temporal = new nodo();
	nodo_Temporal = primero;
	
	
	for (int i=0; i < 3; i++) {
		int numero = funcionRandom();

		if (numero <= 5) {
			
			for (int i = 0; i < 3; i++) {
				nodo_Temporal->siguiente;
				nodo_Temporal->id_Posicion++;

			}
			posicion_conejo = nodo_Temporal->id_Posicion;
		}
		else if (numero > 5 && numero <= 7) {
			for (int i = 0; i < 6; i++) {
				nodo_Temporal->atras;
				nodo_Temporal->id_Posicion--;
			}
			posicion_conejo = nodo_Temporal->id_Posicion;
		}
		else if (numero > 7 && numero <= 10) {
			for (int i = 0; i < 1; i++) {
				nodo_Temporal->siguiente;
				nodo_Temporal->id_Posicion++;
				
			}
			posicion_conejo = nodo_Temporal->id_Posicion;
		}
	}
	if (posicion_conejo < 1) {
		posicion_conejo = 1;
	}
	
	cout << "" + to_string(posicion_conejo);
	
}

void comenzarCarrera() {
	primero->liebre_en_Nodo = true;
	primero->tortuga_en_Nodo = true;
	cout << "              ---------------------------------- BANG! ----------------------------------" << endl;
	cout << "              |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "              ------------------------------- Y ARRANCA! --------------------------------"<< endl<<endl;
	mostrarLista();
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

				cout << "    |L,T| ";
			}
			else if (nodo_Temporal->liebre_en_Nodo == true ) {

				cout << "    |L, | ";
			}
			else if (nodo_Temporal->tortuga_en_Nodo==true) {

				
				cout << "    | ,T| ";
			}
			else {
				cout << "    | , | ";
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
