//
// Created by VICTOR on 16/10/2019.
//

#ifndef UNTITLED26_EDGE_H
#define UNTITLED26_EDGE_H

template <typename T>
class Edge {
public:
    T weight;
    Edge(){}
    Edge(T _weight): weight(_weight){}
    ~Edge(){}
};

#endif //UNTITLED26_EDGE_H
