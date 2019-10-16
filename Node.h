//
// Created by VICTOR on 16/10/2019.
//

#ifndef UNTITLED26_NODE_H
#define UNTITLED26_NODE_H

#include "Coordenadas.h"

class Node {
public:
    Coordenadas coordenadas;
    Node(int _X, int _Y, int _Z): coordenadas(_X,_Y,_Z){}
    ~Node(){}
};

#endif //UNTITLED26_NODE_H
