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

template<typename N, int type>
class Edge {
public:
    N weight;
    Node<Coordenadas,COOR>* node_1;
    Node<Coordenadas,COOR>* node_2;
    Edge(Node<Coordenadas,COOR>* _node_1, Node<Coordenadas,COOR>* _node_2) : node_1(_node_1), node_2(_node_2){}
    Edge(Node<Coordenadas,COOR>* _node_1, Node<Coordenadas,COOR>* _node_2, N _weight) : node_1(_node_1), node_2(_node_2), weight(_weight){}
    ~Edge(){}
};

template<typename N>
class Edge <N, COOR>{
public:
    N weight;
    Node<Coordenadas,COOR>* node_1;
    Node<Coordenadas,COOR>* node_2;
    Edge(Node<Coordenadas,COOR>* _node_1, Node<Coordenadas,COOR>* _node_2) : node_1(_node_1), node_2(_node_2){}
    Edge(Node<Coordenadas,COOR>* _node_1, Node<Coordenadas,COOR>* _node_2, N _weight) : node_1(_node_1), node_2(_node_2), weight(_weight){}
    ~Edge(){}
};

template<typename N>
class Edge <N, INT>{
public:
    N weight;
    Node<N,INT>* node_1;
    Node<N,INT>* node_2;
    Edge(Node<N,INT>* _node_1, Node<N,INT>* _node_2) : node_1(_node_1), node_2(_node_2){}
    Edge(Node<N,INT>* _node_1, Node<N,INT>* _node_2, N _weight) : node_1(_node_1), node_2(_node_2), weight(_weight){}
    ~Edge(){}
};

template<typename N>
class Edge <N, LETRA>{
public:
    N weight;
    Node<N,LETRA>* node_1;
    Node<N,LETRA>* node_2;
    Edge(Node<N,LETRA>* _node_1, Node<N,LETRA>* _node_2) : node_1(_node_1), node_2(_node_2){}
    Edge(Node<N,LETRA>* _node_1, Node<N,LETRA>* _node_2, N _weight) : node_1(_node_1), node_2(_node_2), weight(_weight){}
    ~Edge(){}
};

#endif //UNTITLED26_EDGE_H
