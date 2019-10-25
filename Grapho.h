//
// Created by VICTOR on 7/10/2019.
//

#ifndef UNTITLED26_GRAPHO_H
#define UNTITLED26_GRAPHO_H

#include "Node.h"
#include "Edge.h"
#include "MST.h"
#include <iostream>
#include <vector>

#define COOR 0
#define INT 1
#define LETRA 2

using namespace std;

template<typename N, typename T, int type>
class Grapho {
public:
    vector<Node<N,COOR>*> nodes;
    vector<Edge<N,COOR>*> edges;
    Grapho(){}

    double density(){
        double result = 0;
        result = (2 * nodes.size())/(edges.size()*(edges.size()-1));
        return result;
    }

    ~Grapho(){}
};

template<typename N, typename T>
class Grapho <N, T, COOR>{
public:
    vector<Node<N,COOR>*> nodes;
    vector<Edge<T,COOR>*> edges;
    Grapho(){}
    void insert_Node(float _X, float _Y){
        Node<N,COOR>* new_node = new Node<N,COOR>(_X,_Y);
        nodes.push_back(new_node);
    }
    void insert_Edge(Node<N,COOR>* node_1, Node<N,COOR>* node_2, T weight){
        Edge<T,COOR>* new_edge = new Edge<T,COOR>(node_1, node_2, weight);
        edges.push_back(new_edge);
    }

    double density(){
        double result = 0;
        result = (2 * nodes.size())/(edges.size()*(edges.size()-1));
        return result;
    }

    ~Grapho(){}
};

template<typename N, typename T>
class Grapho <N, T, INT>{
public:
    Node<N,INT>* head;
    Grapho(){}
    double density(){
        double result = 0;
        result = (2 * nodes.size())/(edges.size()*(edges.size()-1));
        return result;
    }
    ~Grapho(){}
};

template<typename N, typename T>
class Grapho <N, T, LETRA>{
public:
    Node<N,LETRA>* head;
    Grapho(){}
    double density(){
        double result = 0;
        result = (2 * nodes.size())/(edges.size()*(edges.size()-1));
        return result;
    }
    ~Grapho(){}
};

#endif //UNTITLED26_GRAPHO_H
