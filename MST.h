//
// Created by Usuario on 24/10/2019.
//

#ifndef MST_H
#define MST_H

#include "Node.h"
#include "Edge.h"
#include "Grapho.h"
#include <iostream>
#include <vector>

#define PRIM 0
#define KRUSKAL 1

using namespace std;


template <class G, class N>
class MST{
    G grapho;
    N* root = nullptr;
    MST(G _grapho){
        grapho = _grapho;
        root = grapho.nodes.front();
    }
    ~MST(){}
};

template <class G, class N>
class MST<PRIM>{
    G grapho;
    N* root = nullptr;
    MST(G _grapho){
        grapho = _grapho;
        root = grapho.nodes.front();
    }

    void print;

    ~MST(){}
};

template <class G, class N>
class MST<KRUSKAL>{
    G grapho;
    N* root = nullptr;
    MST(G _grapho){
        grapho = _grapho;
        root = grapho.nodes.front();
    }
    ~MST(){}
};


#endif //MST_H
