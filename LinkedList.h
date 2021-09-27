#pragma once
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>
#include "Node.h"

using namespace std;
template <typename T>
class LinkedList;

template<typename T>
std::ostream& operator<<(std::ostream& salida1, const LinkedList<T>& C);

template <typename T>
class LinkedList {
    int size;

public:
    Node<T>* head;
    Node<T>* fin;

    LinkedList();
    LinkedList(T);
    LinkedList(const LinkedList&);

    ~LinkedList();

    void print();

    
    void pushFront(T);
    //problema 2
    void pushBack(T);

    void elimi_ulti();

    //problema 3 
    void delete_pos(int);

    void popFront();

    //problema 4
    int Maxelemen();
    
    bool buscar_num(T);
    void Buscar(T);


    //problema 5
    void delete_imp();
    void delete_par();

    //problema 6
    void delete_prede(int);

    //problema 7
    void invertir();

    //problema 8 falta
    void palindromo();

    //problema 10
    void delete_repe();
    friend std::ostream& operator<<<T>(std::ostream& salida1, const LinkedList& C);
};

template<typename T>
LinkedList<T>::LinkedList() {
    this->size = 0;
    this->head = nullptr;
    this->fin = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(T value) {
    this->size = 1;
    this->head = new Node<T>(value);
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& o) {
    this->size = 0;
    this->head = nullptr;
    Node<T>* actual_o = o.head;
    while (actual_o)
    {
        this->pushBack(actual_o->getValue());
        actual_o = actual_o->getNext();
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& salida1, const LinkedList<T>& C) {
    Node<T>* aux = C.head;
    while (aux != nullptr) {
        salida1 << "[" << aux->getValue() << "]->";
        aux = aux->getNext();
    }
    return salida1;
}

template <typename T>
void LinkedList<T>::pushFront(T value) {
    head = new Node<T>(value, head);
    size++;
}

//problema 2
template<typename T>
void LinkedList<T>::pushBack(T value) {
    Node<T>* newNode = new Node<T>(value);
    Node<T>* tmp = head;
    if (head == nullptr) {
        head = newNode;
    }
    else {
        while (tmp->getNext() != nullptr)
        {
            tmp = tmp->getNext();
        }
        newNode->setNext(tmp->getNext());
        tmp->setNext(newNode);
    }
    size++;
}

template<typename T>
void LinkedList<T>::print() {
    Node<T>* aux = head;
    cout << "lista enlazada: ";
    while (aux != nullptr) {
        cout << aux->getValue() << "-> ";
        aux = aux->getNext();
    }
    cout << endl;
}

template<typename T>
void LinkedList<T>::elimi_ulti() {
    int tam = size - 1;
    Node<T>* aux=nullptr, * actual = head;
    if (tam != 0) {
        int i = 0;
        while (i < tam) {
            aux = actual; actual = actual->getNext();
            i++;
        }
        aux->setNext(actual->getNext());
        delete actual;
    }
    else {
        head = head->getNext();
        delete actual;
    }
    size--;
}

//problema 3 
template<typename T>
void LinkedList<T>::delete_pos(int pos) {
    if (pos < size) {
        Node<T>* tmp = nullptr, * actual = head;
        if (pos != 0) {
            int i = 0;
            while (i < pos) {
                tmp = actual;
                actual = actual->getNext();
                i++;
            }
            tmp->setNext(actual->getNext());
            delete actual;
        }

        else {
            head = head->getNext();
            delete actual;
        }
        size--;
    }
}

template <typename T>
bool LinkedList<T>:: buscar_num(T value){
    Node<T>* actual = head;
    if (size - 1 != 0) {
        int i = 0;
        while (actual != nullptr) {
            if (value == actual->getValue()) {
                return true;
                break;
            }

            else {
                actual = actual->getNext();
                i++;
            }
            
        }
    }
}

template<typename T>
void LinkedList<T>::Buscar(T value) {
    if (this->buscar_num(value) == true) {
        cout << "Si se encontro el numero " << value << endl;
    }
    else {
        cout<< "No se encontro el numero " << value << endl;
    }
}

//problema 4
template<typename T>
int LinkedList<T>::Maxelemen(){
    Node *aux = head;
    int max = aux->getValue(); 
    while(aux != nullptr){
        if(max < aux->getValue()){
            max = aux->getValue();
        }
        aux = aux->getNext();
    }
    return max;
}

//problema 5
template<typename T>
void LinkedList<T>::delete_imp() {
    if (size % 2 == 0) {
        for (int impar = 0; impar <= (size/2)+3 ; impar++) {
            cout << impar << endl;
            this->delete_pos(impar);
        }
    }
    else {
        for (int impar = 0; impar <= (size ); impar++) {
            cout << impar << endl;
            this->delete_pos(impar);
        }
    }
}

template<typename T>
void LinkedList<T>::delete_par() {
    for (int par = 1; par <= size; par++) {
        this->delete_pos(par);
        
    }
}


template<typename T>
void LinkedList<T>::popFront() {
    if (head) {
        Node<T>* actual = head;
        head = head->getNext();
        delete actual;
        size--;
    }
}

//problema 6
template<typename T>
void LinkedList<T>::delete_prede(int pun) {
    if (pun < size) {
        Node<T>* tmp = nullptr, * actual = head;
        if (pun != 1) {
            int i = 0;
            while (i < pun-1) {
                tmp = actual;
                actual = actual->getNext();
                i++;
            }
            tmp->setNext(actual->getNext());
            delete actual;
        }

        else {
            head = head->getNext();
            delete actual;
        }
        size--;
    }
}

//problema 7
template<typename T>
void LinkedList<T>::invertir() {
    Node<T>* ini = head;
    Node<T>* final = nullptr, * sig = nullptr;
    while (ini != nullptr) {
        sig = ini->getNext();
        ini->setNext(final);
        final = ini;
        ini = sig;
    }
    head=final;
}

//problema 8
template<typename T>
void LinkedList<T>::palindromo() {
    if (head == nullptr || head->getNext() == nullptr) {
        cout << "PALINDROMO";
    }

}
//problema 9
template<typename T>
LinkedList<T> operator +(LinkedList<T>& L1, LinkedList<T>& L2) {
    Node<T>* aux1 = L1.head;
    Node<T>* aux2 = L2.head;
    LinkedList<T> L3;

    if (aux1 == nullptr) {
        aux1 = aux2;
    }

    else {
        while (aux2->getNext() != nullptr) {
            while (aux1->getNext() != nullptr) {
                L3.pushBack(aux1->getValue());
                aux1 = aux1->getNext();
            }
            L3.pushBack(aux2->getValue());
            aux2 = aux2->getNext();
        }
        L3.pushBack(aux2->getValue());
    }
    return L3;
}

//problema 10
template<typename T>
void LinkedList<T>::delete_repe() {
    Node<T>* ini = head, * tmp = head->getNext();
    int i = 0;
    while (ini != nullptr) {
        while (tmp != nullptr) {
            if (ini->getValue() == tmp->getValue()) {
                this->delete_pos(i);
                break;
            }
            else {
                tmp = tmp->getNext();
                i++;
                
            }
        }
        ini = ini->getNext();
      
    }
   
}
template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* actual;
    while (head != nullptr) {
        actual = head->getNext();
        delete head;
        head = actual;
    }
    delete head;
}

#endif
