//
// Created by VICTOR on 7/10/2019.
//

#ifndef UNTITLED26_GRAPHO_H
#define UNTITLED26_GRAPHO_H

#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <vector>
<<<<<<< HEAD
=======
#include <fstream>
#include <cstdlib>
using namespace std;
>>>>>>> Víctor

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
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
    Grapho(Grapho<N,T,COOR> const &grafo){
        nodes = grafo.nodes;
        edges = grafo.edges;
    }
>>>>>>> parent of 6225525... feat(grapho)
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
>>>>>>> Víctor
    void insert_Node(float _X, float _Y){
        Node<N,COOR>* new_node = new Node<N,COOR>(_X,_Y);
        nodes.push_back(new_node);
    }
    void insert_Edge(Node<N,COOR>* node_1, Node<N,COOR>* node_2, T weight){
        Edge<T,COOR>* new_edge = new Edge<T,COOR>(node_1, node_2, weight);
        edges.push_back(new_edge);
    }
<<<<<<< HEAD
=======
<<<<<<< HEAD

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
=======
    Grapho(int _nodes, int _edges){
        srand(time(NULL));
        for(int i = 0; i < _nodes; i++){
            float _X = rand()%(ANCHO+1);
            float _Y = rand()%(ALTO+1);
            insert_Node(_X,_Y);
        }
        for(int i = 0; i < _edges; i++){
            Node<N,COOR>* node_1 = nodes[rand()%_nodes];
            Node<N,COOR>* node_2 = nodes[rand()%_nodes];
            insert_Edge(node_1,node_2,rand()%51);
        }
    }

    Edge<T,COOR>* search_edge(Node<N,COOR>* node_1, Node<N,COOR>* node_2) {
        vector<Edge<int,COOR>*>::iterator et = edges.begin();
        for(;et != edges.end();et++){
            if(node_1 == (*et)->node_1 || node_2 == (*et)->node_2){
                return *et;
            }
        }
    }

>>>>>>> parent of 6225525... feat(grapho)
    void remove_Edge(Node<N,COOR>* node_1, Node<N,COOR>* node_2){
        Edge<T,COOR>* edge_to_remove= new Edge<T,COOR>(node_1,node_2);
        for (int i = 0; i < edges.size(); i++){
            if(edges[i]==edge_to_remove)
<<<<<<< HEAD
                edges.pop_back(edges.begin()+i)
        }
        edges.pop_back(edge_to_remove);
    }
    void remove_node(float _X, float _Y){
=======
                edges.pop_back(edges.begin()+i);
        }
        edges.pop_back(edge_to_remove);
    }
    void remove_Node(float _X, float _Y){
>>>>>>> parent of 6225525... feat(grapho)
        Node<N,COOR>* node_to_remove= new Node<N,COOR>(_X,_Y);
        for(int i=0;i<nodes.size();i++){
            if(nodes[i]==node_to_remove){
                for (int j = 0; j < edges.size(); j++)
                {
<<<<<<< HEAD
                    if (edges[j].node_1 == node_to_remove || edges[j].node_2 == node_to_remove)
                        edges.erase(edges.begin()+j);
                nodes.pop_back(nodes.begin()+i);
=======
                    if (edges[j]->node_1 == node_to_remove || edges[j]->node_2 == node_to_remove)
                        edges.erase(edges.begin()+j);
                    nodes.erase(nodes.begin()+i);
                }
>>>>>>> parent of 6225525... feat(grapho)
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
<<<<<<< HEAD
    ~Grapho(){}
=======
    Grapho(Grapho<N,T,LETRA> const &grafo){
        nodes = grafo.nodes;
        edges = grafo.edges;
    }
    Grapho(string nombre_archivo){
        string cadena;
        ifstream fe(nombre_archivo);
        while (!fe.eof()) {
            fe >> cadena;
            if(cadena == "LETRAS"){break;}
        }
        fe >> cadena;
        int num_nodes = atoi(cadena.c_str());
        fe >> cadena;
        for(int i = 0; i < num_nodes; i++){
            fe >> cadena;
            N value = cadena;
            fe >> cadena;
            insert_Node(value);
        }
        while (!fe.eof()) {
            fe >> cadena;
            if(cadena == "EDGES"){break;}
        }
        fe >> cadena;
        int num_edge = atoi(cadena.c_str());
        fe >> cadena;
        for(int i = 0; i < num_edge; i++){
            fe >> cadena;
            Node<N,LETRA>* node_1 = nodes[atoi(cadena.c_str())];
            fe >> cadena;
            Node<N,LETRA>* node_2 = nodes[atoi(cadena.c_str())];
            fe >> cadena;
            T weight = cadena;
            insert_Edge(node_1,node_2,weight);
        }
        fe.close();
    }
    void insert_Node(N value){
        Node<N,LETRA>* new_node = new Node<N,LETRA>(value);
        nodes.push_back(new_node);
    }
    void insert_Edge(Node<N,LETRA>* node_1, Node<N,LETRA>* node_2, T weight){
        Edge<T,LETRA>* new_edge = new Edge<T,LETRA>(node_1, node_2, weight);
        edges.push_back(new_edge);
    }
    Grapho(int _nodes, int _edges, int rango_min = 0, int rango_max = 100){
        string alfabeto[26] = {"A","B","C","D","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        srand(time(NULL));
        for(int i = 0; i < _nodes; i++){
            N value = alfabeto[rand()%(26)];
            insert_Node(value);
        }
        for(int i = 0; i < _edges; i++){
            Node<N,LETRA>* node_1 = nodes[rand()%_nodes];
            Node<N,LETRA>* node_2 = nodes[rand()%_nodes];
            insert_Edge(node_1,node_2,alfabeto[rand()%(26)]);
        }
    }

    ~Grapho(){

    }

    void saved (string nombre_archivo){
        string cadena;
        ofstream fe (nombre_archivo);
        fe << "LETRAS " << nodes.size() << " double" << endl;
        vector<Node<string,LETRA>*>::iterator it = nodes.begin();
        for(;it != nodes.end();it++){
            fe << (*it)->value << endl;
        }
        fe << '\n' << "EDGE " << edges.size() << " 2019" << endl;
        vector<Edge<string,LETRA>*>::iterator et = edges.begin();
        for(;et != edges.end();et++){
            vector<Node<string,LETRA>*>::iterator at = nodes.begin();
            int i = 0;
            while((*at) != (*et)->node_1){i++;at++;}
            fe << i << ' ';
            at = nodes.begin();
            i = 0;
            while((*at) != (*et)->node_2){i++;at++;}
            fe << i  << ' ' << (*et)->weight << endl;
        }
        fe.close();
    }
>>>>>>> Víctor
>>>>>>> parent of 6225525... feat(grapho)
};

#endif //UNTITLED26_GRAPHO_H
