// Partial_persistence.cpp: define el punto de entrada de la aplicación.
//

#include "Partial_persistence.h"



int main()
{
    vector<int> lista;
    for (int i = 10; i < 20; i++) {
        lista.push_back(i);
    }
    /// Aqui creamos una lista para poder insertar un vector a la cabeza
    LPP<int> a(lista); //Inicializamos la lista Partial Persistence con un vector lista
    for (int i = 0; i < 10; i++) {
        a.insert(i);
    }//Insertamos elementos unicos a nuestra lista
    for (Nodo<int>* i = a.head; i != nullptr; i = i->next) {
        cout << i->valor[0] << "_tam(" << i->valor.size() << ")->"; //Imprimimos los valores iniciales de nuestra lista con su respectivo tamaño
    }
    cout << endl;
    cout << "Numero de versiones" << a.head->PP.size() << endl;
    a.insertar(a.head, 3, 8); //Insertamos al nodo cabeza los datos a modificar y sus respectivas modificaciones
    cout << "Numero de versiones con una modificaciones con insert: " << a.head->PP.size() << " Se modifico el puntero cabeza, siendo el campo 3 con el numero 8" << endl;
    a.insertar(a.head, 4, 40);
    cout << "Numero de versiones con dos modificaciones con insert: " << a.head->PP.size() << " Se modifico el puntero cabeza, siendo el campo 4 con el numero 5" << endl;
    cout << endl << endl << "Imprimimos la version 0 o prima de la cabeza " << endl;
    for (int i = 0; i < a.head->valor.size(); i++) {
        cout << a.head->valor[i] << "->";
    }
    cout << endl << endl << "Imprimimos la version 1" << endl << "Para esto buscamos en la posicion 0 ya que es la que tiene la lista,la version 1,el campo 3" << endl;
    Nodo<int>* temporal1 = a.buscar(0, 1, 3);
    for (int i = 0; i < a.head->valor.size(); i++) {
        cout << temporal1->valor[i] << "->";
    }
    cout << endl << endl << "Imprimimos la version 2" << endl << "Para esto buscamos en la posicion 0 ya que es la que tiene la lista,la version 2,el campo 3" << endl;
    temporal1 = a.buscar(0, 2, 4);
    for (int i = 0; i < a.head->valor.size(); i++) {
        cout << temporal1->valor[i] << "->";
    }
    cout << endl << endl << endl;
    a.insertar(a.head, 4, a.head->next->next->next);
    for (Nodo<int>* i = a.head; i != nullptr; i = i->next) {
        cout << i->valor[0] << "->"; //Imprimimos los valores iniciales de nuestra lista con su respectivo tamaño
    }
    cout << endl;
    cout << "el valor actual de head es : " << a.head->valor[0] << endl;
    cout << "El siguiente despues de head normalmente es: " << a.head->next->valor[0] << endl;
    cout << "Con el insert nodo es :" << a.head->PP.back()->next->valor[0] << endl;
}
