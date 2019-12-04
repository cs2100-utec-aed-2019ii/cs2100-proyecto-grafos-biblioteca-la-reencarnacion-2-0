//
// Created by VICTOR on 16/10/2019.
//

#ifndef UNTITLED26_EDGE_H
#define UNTITLED26_EDGE_H

#include "Node.h"
#include <iostream>

#define COOR 0
#define INT 1
#define LETRA 2

template<typename N, typename T, int type>
class Edge {
public:
    N weight;
    Node<Coordenadas,N,COOR>* node_1;
    Node<Coordenadas,N,COOR>* node_2;
    Edge(Node<Coordenadas,N,COOR>* _node_1, Node<Coordenadas,T,COOR>* _node_2) : node_1(_node_1), node_2(_node_2){node_1->grade = node_1->grade + 1;node_2->grade = node_2->grade + 1;}
    Edge(Node<Coordenadas,N,COOR>* _node_1, Node<Coordenadas,T,COOR>* _node_2, T _weight) : node_1(_node_1), node_2(_node_2), weight(_weight){node_1->grade = node_1->grade + 1;node_2->grade = node_2->grade + 1;}
    ~Edge(){}
};

template<typename T>
class Edge <Coordenadas,T, COOR>{
public:
    T weight;
    float R = 1, G = 1, B = 1;
    Node<Coordenadas,T,COOR>* node_1;
    Node<Coordenadas,T,COOR>* node_2;
    Edge(Node<Coordenadas,T,COOR>* _node_1, Node<Coordenadas,T,COOR>* _node_2) : node_1(_node_1), node_2(_node_2){
        _node_2->grade++;
        _node_2->vecinos.push_back(_node_2);
        _node_2->grade++;
        _node_2->vecinos.push_back(_node_2);
    }
    Edge(Node<Coordenadas,T,COOR>* _node_1, Node<Coordenadas,T,COOR>* _node_2, T _weight) : node_1(_node_1), node_2(_node_2), weight(_weight){
        _node_1->grade++;
        _node_1->vecinos.insert({node_2,_weight});
        _node_2->grade++;
        _node_2->vecinos.insert({node_1,_weight});
    }
    ~Edge(){}
};

template<typename N, typename T>
class Edge <N,T, INT>{
public:
    T weight;
    Node<N,T,INT>* node_1;
    Node<N,T,INT>* node_2;
    Edge(Node<N,T,INT>* _node_1, Node<N,T,INT>* _node_2) : node_1(_node_1), node_2(_node_2){}
    Edge(Node<N,T,INT>* _node_1, Node<N,T,INT>* _node_2, T _weight) : node_1(_node_1), node_2(_node_2), weight(_weight){}
    ~Edge(){}
};

template<typename N, typename T>
class Edge <N,T, LETRA>{
public:
    N weight;
    Node<N,T,LETRA>* node_1;
    Node<N,T,LETRA>* node_2;
    Edge(Node<N,T,LETRA>* _node_1, Node<N,T,LETRA>* _node_2) : node_1(_node_1), node_2(_node_2){}
    Edge(Node<N,T,LETRA>* _node_1, Node<N,T,LETRA>* _node_2, T _weight) : node_1(_node_1), node_2(_node_2), weight(_weight){}
    ~Edge(){}
};

#endif //UNTITLED26_EDGE_H
