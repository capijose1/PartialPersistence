// Partial_persistence.h: archivo de inclusión para archivos de inclusión estándar del sistema,
// o archivos de inclusión específicos de un proyecto.

#pragma once

#include <iostream>
#include <vector>
#include <utility>
using namespace std;
template <typename T>
struct Nodo
{
    vector<T> valor;
    Nodo <T>* next;
    vector<Nodo <T>*> PP;
    Nodo() {
        this->next = nullptr;
    }
    Nodo(vector<T> valor, Nodo* next = nullptr) {
        this->valor = valor;
        this->next = next;
    }
    Nodo(T valor, Nodo* next = nullptr) {
        this->valor.push_back(valor);
        this->next = next;
    }
    void insertar(T valor, Nodo* next = nullptr) {
        this->valor.push_back(valor);
        this->next = next;
    }

};
template <typename T>
struct LPP {
    Nodo<int>* head = new Nodo<T>;
    Nodo<int>* pos = head;
    LPP(T valor) {
        head = new Nodo<T>(valor);
        pos = head;
    }
    LPP(vector<T> valor) {
        head = new Nodo<T>(valor);
        pos = head;
    }
    void insert(T valor) {
        pos->next = new Nodo<T>(valor);
        pos = pos->next;
    }
    void insert(vector<T> valor) {
        pos->next = new Nodo<T>(valor);
        pos = pos->next;
    }
    void write(Nodo<T>* ptr, T valor) {
        if (ptr->valor.size() != 0) {
            Nodo<T>* tmp = new Nodo<T>(ptr->valor);
            tmp->insertar(valor);
            tmp->next = ptr->next;
            ptr->PP.push_back(tmp);
        }

    }
    void insertar(Nodo<T>* ptr, int campo, T val) {
        Nodo<T>* tmp;
        if (ptr->PP.size() != 0) {
            tmp = new Nodo<T>(ptr->PP.back()->valor);
        }
        else {
            tmp = new Nodo<T>(ptr->valor);
        }
        tmp->valor[campo] = val;
        tmp->next = ptr->next;
        ptr->PP.push_back(tmp);

    }
    void insertar(Nodo<T>* ptr, int campo, Nodo<T>* val) {
        Nodo<T>* tmp = new Nodo<T>(ptr->PP.back()->valor);
        tmp->next = val;
        ptr->PP.push_back(tmp);
    }
    Nodo<T>* buscar(int pos, int version, int campo) {
        Nodo<T>* tmp = head;
        for (int i = 0; i < pos; i++) {
            tmp = tmp->next;
        }
        int tam_ver = 1 + tmp->PP.size();
        if (version > tam_ver) {
            cout << "No se puede hacer esta operación , no existe la versión" << endl;
        }
        else {
            if (version == 0) {
                if (tmp->valor.size() > campo) {
                    cout << "Se encontro el elemento: " << tmp->valor[campo] << endl;
                    return tmp;
                }
            }
            else {
                if (tmp->PP[tam_ver - 1 - version]->valor.size() > campo) {
                    cout << "Se encontro el elemento: " << tmp->PP[version - 1]->valor[campo] << endl;
                    cout << "Version: " << version - 1 << endl;
                    return tmp->PP[version - 1];
                }
            }
        }

    }
};

// TODO: Haga referencia aquí a los encabezados adicionales que el programa requiere.
