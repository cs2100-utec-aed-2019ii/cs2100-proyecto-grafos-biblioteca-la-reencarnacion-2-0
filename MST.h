//
// Created by Usuario on 24/10/2019.
//

#ifndef MST_H
#define MST_H

#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <vector>

#define PRIM "p"
#define KRUSKAL "k"

using namespace std;
template <typename T>
class MST{
    Node<T>* root;
    MST(Node<T>* node){
        root = node;
    }
    ~MST(){}
};
class MST<PRIM>{
    Node<T>* root;
    MST(Node<T>* node){
        root = node;
    }
    ~MST(){}
};
class MST<KRUSKAL>{
    Node<T>* root;
    MST(Node<T>* node){
        root = node;
    }
    ~MST(){}
};


#endif //MST_H
