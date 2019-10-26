//
// Created by VICTOR on 7/10/2019.
//

#ifndef UNTITLED26_GRAPHO_H
#define UNTITLED26_GRAPHO_H

#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

#define COOR 0
#define INT 1
#define LETRA 2

template<typename N, typename T, int type>
class Grapho {
public:
    vector<Node<N,COOR>*> nodes;
    vector<Edge<N,COOR>*> edges;
    Grapho(){}
    ~Grapho(){}
};

template<typename N, typename T>
class Grapho <N, T, COOR>{
public:
    vector<Node<N,COOR>*> nodes;
    vector<Edge<T,COOR>*> edges;
    Grapho(){}
    Grapho(string nombre_archivo){
        string cadena;
        ifstream fe(nombre_archivo);
        while (!fe.eof()) {
            fe >> cadena;
            if(cadena == "POINTS"){break;}
        }
        fe >> cadena;
        int num_nodes = atoi(cadena.c_str());
        fe >> cadena;
        for(int i = 0; i < num_nodes; i++){
            fe >> cadena;
            float _X = atoi(cadena.c_str());
            fe >> cadena;
            float _Y = atoi(cadena.c_str());
            fe >> cadena;
            insert_Node(_X,_Y);
        }
        while (!fe.eof()) {
            fe >> cadena;
            if(cadena == "CELLS"){break;}
        }
        fe >> cadena;
        int num_edge = atoi(cadena.c_str());
        fe >> cadena;
        for(int i = 0; i < num_edge; i++){
            fe >> cadena;
            fe >> cadena;
            Node<N,COOR>* node_1 = nodes[atoi(cadena.c_str())];
            fe >> cadena;
            Node<N,COOR>* node_2 = nodes[atoi(cadena.c_str())];
            fe >> cadena;
            Node<N,COOR>* node_3 = nodes[atoi(cadena.c_str())];
            insert_Edge(node_1,node_2,1);
            insert_Edge(node_2,node_3,1);
            insert_Edge(node_3,node_1,1);
        }
        fe.close();
    }
    void insert_Node(float _X, float _Y){
        Node<N,COOR>* new_node = new Node<N,COOR>(_X,_Y);
        nodes.push_back(new_node);
    }
    void insert_Edge(Node<N,COOR>* node_1, Node<N,COOR>* node_2, T weight){
        Edge<T,COOR>* new_edge = new Edge<T,COOR>(node_1, node_2, weight);
        edges.push_back(new_edge);
    }
    void remove_Edge(Node<N,COOR>* node_1, Node<N,COOR>* node_2){
        Edge<T,COOR>* edge_to_remove= new Edge<T,COOR>(node_1,node_2);
        for (int i = 0; i < edges.size(); i++){
            if(edges[i]==edge_to_remove)
                edges.pop_back(edges.begin()+i)
        }
        edges.pop_back(edge_to_remove);
    }
    void remove_node(float _X, float _Y){
        Node<N,COOR>* node_to_remove= new Node<N,COOR>(_X,_Y);
        for(int i=0;i<nodes.size();i++){
            if(nodes[i]==node_to_remove){
                for (int j = 0; j < edges.size(); j++)
                {
                    if (edges[j].node_1 == node_to_remove || edges[j].node_2 == node_to_remove)
                        edges.erase(edges.begin()+j);
                nodes.pop_back(nodes.begin()+i);
            }
        }
    }
       
    float density(){
        return ((2*edges.size())/((nodes.size())*(nodes.size()-1)));
    }

    ~Grapho(){}
};

template<typename N, typename T>
class Grapho <N, T, INT>{
public:
    Node<N,INT>* head;
    Grapho(){}
    ~Grapho(){}
};

template<typename N, typename T>
class Grapho <N, T, LETRA>{
public:
    Node<N,LETRA>* head;
    Grapho(){}
    ~Grapho(){}
};

#endif //UNTITLED26_GRAPHO_H
