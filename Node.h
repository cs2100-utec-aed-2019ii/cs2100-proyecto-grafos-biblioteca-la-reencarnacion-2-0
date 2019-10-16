//
// Created by VICTOR on 16/10/2019.
//

#ifndef UNTITLED26_NODE_H
#define UNTITLED26_NODE_H

#include "Coordenadas.h"

class Node {
public:
    Coordenadas coordenadas;
    Node(int _X, int _Y): coordenadas(_X,_Y){}
    ~Node(){}
};

#endif //UNTITLED26_NODE_H
