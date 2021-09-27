#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

int main() {
    LinkedList<int> l1;
    LinkedList<int> l2;
    l1.pushBack(2);
    l1.pushBack(3);
    l1.pushBack(4);
    l1.pushBack(1);
    l1.pushFront(1);

    l1.pushBack(6);
    l1.pushBack(7);
    l1.pushBack(8);
    l1.pushBack(9);
    l1.pushBack(10);
    l1.pushBack(11);
    l1.pushBack(12);

    l2.pushFront(13);
    l2.pushFront(23);
    l2.pushFront(33);

    cout << l1 << endl;
    cout << l1.Maxelemen()<<endl;
    l1.Buscar(6);
    l1.Buscar(20);

    l1.delete_pos(2);
    l1.popFront();
    l1.print();

    l1.invertir();
    cout <<"Invertido: " << l1 << endl;

    l1.delete_prede(2);
    cout << l1 << endl;

    //l1.palindromo();
    // 
    //l1.delete_repe();
    //cout << l1 << endl;
    //concadenar listas L1 y L2
    cout<<"CONCADENAR: " << l1 + l2;
    

    return 0;
}
//grover.org.rf@gmail.com
