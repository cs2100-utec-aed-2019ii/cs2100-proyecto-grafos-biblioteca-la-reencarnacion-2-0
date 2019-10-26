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
#include <ctime>
using namespace std;

#define COOR 0
#define INT 1
#define LETRA 2

template<typename N, typename T, int type>
class Grapho {
public:
    vector<Node<N,COOR>*> nodes;
    vector<Edge<T,COOR>*> edges;
    float promedio = 0;
    Grapho(){}
    ~Grapho(){}
};

template<typename N, typename T>
class Grapho <N, T, COOR>{
public:
    vector<Node<N,COOR>*> nodes;
    vector<Edge<T,COOR>*> edges;

    Grapho(){}
    Grapho(Grapho<N,T,COOR> const &grafo){
        nodes = grafo.nodes;
        edges = grafo.edges;
        setVecinos();
    }
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

    void remove_Edge(Node<N,COOR>* node_1, Node<N,COOR>* node_2){
        Edge<T,COOR>* edge_to_remove= new Edge<T,COOR>(node_1,node_2);
        for (int i = 0; i < edges.size(); i++){
            if(edges[i]==edge_to_remove)
                edges.pop_back(edges.begin()+i);
        }
        edges.pop_back(edge_to_remove);
    }
    void remove_Node(float _X, float _Y){
        Node<N,COOR>* node_to_remove= new Node<N,COOR>(_X,_Y);
        for(int i=0;i<nodes.size();i++){
            if(nodes[i]==node_to_remove){
                for (int j = 0; j < edges.size(); j++)
                {
                    if (edges[j]->node_1 == node_to_remove || edges[j]->node_2 == node_to_remove)
                        edges.erase(edges.begin()+j);
                    nodes.erase(nodes.begin()+i);
                }
            }
        }
    }

    float density(){
        float result = 0;
        result = (2 * nodes.size())/(edges.size()*(edges.size()-1));
        return result;
    }

    void setVecinos(){
        vector<Node<Coordenadas,COOR>*> Helper;
        T promedio = 0;
        T suma = 0;
        for (int k = 0; k < edges.size(); ++k) {
            suma = suma + edges[k]->weight;
        }
        promedio = suma / edges.size();
        for (int i = 0; i < nodes.size(); i++) {
            for (int j = 0; j < edges.size(); j++) {
                if(edges[i]->weight <= promedio){
                    if(edges[j]->node_1 == nodes[i]){
                        Helper = nodes[i]->vecinos;
                        Helper.push_back(edges[j]->node_2);
                    }
                    if(edges[j]->node_2 == nodes[i]){
                        Helper = nodes[i]->vecinos;
                        Helper.push_back(edges[j]->node_1);
                    }
                }
            }
        }
    }
    void MST(int primkruskal, int position) {
        Node<N,COOR>* root = nodes[position];
        Edge<T,COOR>* NoReturn = nullptr;
        int min = edges[0]->weight;
        int max = 0;
        if (primkruskal == 0 ) { //Prim =
            for(int j = 0; j < nodes.size(); j++){
                for (int i = 0; i < edges.size(); i++) {
                    if ((edges[i]->node_1 == root || edges[i]->node_2 == root) && (edges[i] != NoReturn)) {
                        if (edges[i]->weight < min) {
                            min = edges[i]->weight;
                            if (edges[i]->node_1 == root) {
                                root = edges[i]->node_2;
                                NoReturn = edges[i];
                                edges[i]->G = 0;
                                edges[i]->B = 0;
                            }
                            if (edges[i]->node_2 == root) {
                                root = edges[i]->node_1;
                                NoReturn = edges[i];
                                edges[i]->G = 0;
                                edges[i]->B = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    ~Grapho(){}

    void saved (string nombre_archivo){
        string cadena;
        ofstream fe (nombre_archivo);
        fe << "POINTS " << nodes.size() << " double" << endl;
        vector<Node<Coordenadas,COOR>*>::iterator it = nodes.begin();
        for(;it != nodes.end();it++){
            fe << (*it)->coordenadas.X << ' ' << (*it)->coordenadas.X << " 0" << endl;
        }
        fe << '\n' << "CELLS " << edges.size() << " 1740" << endl;
        vector<Edge<int,COOR>*>::iterator et = edges.begin();
        for(;et != edges.end();et++){
            vector<Node<Coordenadas,COOR>*>::iterator at = nodes.begin();
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
};

template<typename N, typename T>
class Grapho <N, T, INT>{
public:
    vector<Node<N,INT>*> nodes;
    vector<Edge<T,INT>*> edges;
    float promedio = 0;
    Grapho(){}
    Grapho(Grapho<N,T,INT> const &grafo){
        nodes = grafo.nodes;
        edges = grafo.edges;
        
    }
    Grapho(string nombre_archivo){
        string cadena;
        ifstream fe(nombre_archivo);
        while (!fe.eof()) {
            fe >> cadena;
            if(cadena == "VALUES"){break;}
        }
        fe >> cadena;
        int num_nodes = atoi(cadena.c_str());
        fe >> cadena;
        for(int i = 0; i < num_nodes; i++){
            fe >> cadena;
            N value = atoi(cadena.c_str());
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
            Node<N,INT>* node_1 = nodes[atoi(cadena.c_str())];
            fe >> cadena;
            Node<N,INT>* node_2 = nodes[atoi(cadena.c_str())];
            fe >> cadena;
            T weight = atoi(cadena.c_str());
            insert_Edge(node_1,node_2,weight);
        }
        fe.close();
        
    }
    void insert_Node(N value){
        Node<N,INT>* new_node = new Node<N,INT>(value);
        nodes.push_back(new_node);
    }
    void insert_Edge(Node<N,INT>* node_1, Node<N,INT>* node_2, T weight){
        Edge<T,INT>* new_edge = new Edge<T,INT>(node_1, node_2, weight);
        edges.push_back(new_edge);
    }
    Grapho(int _nodes, int _edges, int rango_min = 0, int rango_max = 100){
        srand(time(NULL));
        for(int i = 0; i < _nodes; i++){
            N value = rand()%((rango_max-rango_min)+1);
            insert_Node(value);
        }
        for(int i = 0; i < _edges; i++){
            Node<N,INT>* node_1 = nodes[rand()%_nodes];
            Node<N,INT>* node_2 = nodes[rand()%_nodes];
            insert_Edge(node_1,node_2,rand()%(rango_max-rango_min));
        }
        
    }

    ~Grapho(){}

    void saved (string nombre_archivo){
        string cadena;
        ofstream fe (nombre_archivo);
        fe << "VALUES " << nodes.size() << " double" << endl;
        vector<Node<int,INT>*>::iterator it = nodes.begin();
        for(;it != nodes.end();it++){
            fe << (*it)->value << endl;
        }
        fe << '\n' << "EDGE " << edges.size() << " 2019" << endl;
        vector<Edge<int,INT>*>::iterator et = edges.begin();
        for(;et != edges.end();et++){
            vector<Node<int,INT>*>::iterator at = nodes.begin();
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
};

template<typename N, typename T>
class Grapho <N, T, LETRA>{
public:
    vector<Node<N,LETRA>*> nodes;
    vector<Edge<T,LETRA>*> edges;
    float promedio = 0;
    Grapho(){}
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

    ~Grapho(){}

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
};

#endif //UNTITLED26_GRAPHO_H

