//
// Created by VICTOR on 16/10/2019.
//

#ifndef UNTITLED26_NODE_H
#define UNTITLED26_NODE_H

#include "Coordenadas.h"
#include <iostream>
#include <map>

#define COOR 0
#define INT 1
#define LETRA 2

template<typename N, typename T, int type>
class Node {
public:
    Coordenadas coordenadas;
    int grade;
    Node(float _X, float _Y): coordenadas(_X,_Y),grade(0){}
    ~Node(){}
};

template<typename N, typename T>
class Node<N, T, COOR>{
public:
    Coordenadas coordenadas;
    int grade;
    float R = 1, G = 1, B = 1;
    map<Node<Coordenadas,T,COOR>*,T> vecinos;
    Node(float _X, float _Y): coordenadas(_X,_Y), grade(0) {}
    ~Node(){}
};

template<typename N, typename T>
class Node<N, T, INT>{
public:
    N value;
    int grade;
    vector<Node<N,T,INT>*> vecinos;
    Node(N _value): value(_value), grade(0){}
    ~Node(){}
};

template<typename N, typename T>
class Node<N, T, LETRA>{
public:
    N value;
    int grade;
    vector<Node<N,T,LETRA>*> vecinos;
    Node(N _value): value(_value), grade(0){}
    ~Node(){}
};

#endif //UNTITLED26_NODE_H
