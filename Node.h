//
// Created by VICTOR on 16/10/2019.
//

#ifndef UNTITLED26_NODE_H
#define UNTITLED26_NODE_H

#include "Coordenadas.h"
#include <iostream>

#define COOR 0
#define INT 1
#define LETRA 2

template<typename N, int type>
class Node {
public:
    Node(){}
    ~Node(){}
};

template<typename N>
class Node<N, COOR>{
public:
    N coordenadas;
    Node(float _X, float _Y): coordenadas(_X,_Y){}
    ~Node(){}
};

template<typename N>
class Node<N, INT>{
public:
    N value;
    Node(N _value): value(_value){}
    ~Node(){}
};

template<typename N>
class Node<N, LETRA>{
public:
    N value;
    Node(N _value): value(_value){}
    ~Node(){}
};

#endif //UNTITLED26_NODE_H
