//
// Created by VICTOR on 7/10/2019.
//

#ifndef UNTITLED26_GRAPHO_H
#define UNTITLED26_GRAPHO_H

#include <GL/glut.h>
#include "Node.h"
#include "Edge.h"
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

    void MST(int primkruskal, Node<N,COOR>* node){
        Node<N,COOR>* root = node;
        Edge<N,COOR>* NoReturn = nullptr;
        Edge<N,COOR>* HelperEdge = edges[0];
        int min = HelperEdge->weight;
        int max = 0;
        if (primkruskal == 0 ){ //Prim = 0
            for (int i = 0; i < nodes.size(); i++) {
                if ((edges[i]->node_1 == root || edges[i]->node_2 == root)&&(edges[i] != NoReturn)){

                    //dibujo

                    if (edges[i]->weight < min){
                        min = edges[i]->weight;
                        if(edges[i]->node_1 == root){
                            root = edges[i]->node_2;
                            NoReturn = edges[i];
                        }
                        if(edges[i]->node_2 == root){
                            root = edges[i]->node_1;
                            NoReturn = edges[i];
                        }
                    }
                }
            }
        }
        if (primkruskal == 1 ) { //Kruskal = 1
            int cant = 0;
            int verifier = min;
            while(min != max){
                for (int i = 0; i < edges.size(); ++i) {
                    if (edges[i]->weight <= min){
                        min = edges[i]->weight;
                        if(min == verifier){
                            cant++;
                        }
                        else{
                            cant = 1;
                        }
                    }
                    if (edges[i]->weight > max){
                        max = edges[i]->weight;
                    }
                }
                for (int j = 0; j < edges.size(); ++j) {
                    if (edges[j]->weight == min){
                        if(edges[j]){
                            glBegin(GL_LINE_STRIP);
                                glColor3f(1.0f,0.0f,0.0f);
                                glVertex3f(edges[j]->node_1->coordenadas.X,HelperEdge->node_1->coordenadas.Y,0);
                                glVertex3f(edges[j]->node_2->coordenadas.X,HelperEdge->node_2->coordenadas.Y,0);
                            glEnd();
                        }
                    }
                }
            }
        }
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
