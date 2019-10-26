//
// Created by VICTOR on 16/10/2019.
//

#ifndef UNTITLED26_NODE_H
#define UNTITLED26_NODE_H

#include "Coordenadas.h"
#include <iostream>
#include <vector>

#define COOR 0
#define INT 1
#define LETRA 2

template<typename N, int type>
class Node {
public:
    Coordenadas coordenadas;
    vector<Node<Coordenadas,COOR>*> Vecinos;
    int grade;
    Node(float _X, float _Y): coordenadas(_X,_Y),grade(0){}
    ~Node(){}
};

template<typename N>
class Node<N, COOR>{
public:
    Coordenadas coordenadas;
    vector<Node<Coordenadas,COOR>*> vecinos;
    int grade;
    Node(float _X, float _Y): coordenadas(_X,_Y), grade(0) {}
    ~Node(){}
};

template<typename N>
class Node<N, INT>{
public:
    N value;
    vector<Node<Coordenadas,COOR>*> Vecinos;
    int grade;
    Node(N _value): value(_value), grade(0){}
    ~Node(){}
};

template<typename N>
class Node<N, LETRA>{
public:
    N value;
    vector<Node<Coordenadas,COOR>*> Vecinos;
    int grade;
    Node(N _value): value(_value), grade(0){}
    ~Node(){}
};

#endif //UNTITLED26_NODE_H
