//
// Created by Marlon on 7/10/2019.
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
#include <cmath>
#include <queue>
#include <list>
<<<<<<< HEAD
#include <map>
=======
>>>>>>> Marlon
using namespace std;

#define COOR 0
#define INT 1
#define LETRA 2
# define INF 0x3f3f3f3f


template<typename N, typename T, int type>
class Grapho {
public:
    vector<Node<N,T,COOR>*> nodes;
    vector<Edge<N,T,COOR>*> edges;
    Grapho(){}
    ~Grapho(){}
};

template<typename N, typename T>
class Grapho <N, T, COOR>{
public:
    vector<Node<N,T,COOR>*> nodes;
    vector<Edge<N,T,COOR>*> edges;
    Grapho(){}
    Grapho(Grapho<N,T,COOR> const &grafo){
        nodes = grafo.nodes;
        edges = grafo.edges;
    }
    Grapho(string nombre_archivo){
        string cadena; // crear cadena como T
        ifstream fe(nombre_archivo);
        fe >> cadena;
        if(cadena == "BIBLIOTECA"){
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
                Node<N,T,COOR>* node_1 = nodes[atoi(cadena.c_str())];
                fe >> cadena;
                Node<N,T,COOR>* node_2 = nodes[atoi(cadena.c_str())];
                fe >> cadena;
                T weight = atoi(cadena.c_str());
                insert_Edge(node_1,node_2,weight);
            }
        } else {
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
                Node<N,T,COOR>* node_1 = nodes[atoi(cadena.c_str())];
                fe >> cadena;
                Node<N,T,COOR>* node_2 = nodes[atoi(cadena.c_str())];
                fe >> cadena;
                Node<N,T,COOR>* node_3 = nodes[atoi(cadena.c_str())];
<<<<<<< HEAD
                insert_Edge(node_1,node_2,sqrt(pow(node_1->coordenadas.X-node_2->coordenadas.X,2)+pow(node_1->coordenadas.Y-node_2->coordenadas.Y,2)));
                insert_Edge(node_2,node_3,sqrt(pow(node_2->coordenadas.X-node_3->coordenadas.X,2)+pow(node_2->coordenadas.Y-node_3->coordenadas.Y,2)));
                insert_Edge(node_3,node_1,sqrt(pow(node_3->coordenadas.X-node_1->coordenadas.X,2)+pow(node_3->coordenadas.Y-node_1->coordenadas.Y,2)));
=======
                insert_Edge(node_1,node_2,sqrt(abs((node_1->coordenadas.X-node_2->coordenadas.X)/(node_1->coordenadas.Y-node_2->coordenadas.Y))));
                insert_Edge(node_2,node_3,sqrt(abs((node_2->coordenadas.X-node_3->coordenadas.X)/(node_2->coordenadas.Y-node_3->coordenadas.Y))));
                insert_Edge(node_3,node_1,sqrt(abs((node_3->coordenadas.X-node_1->coordenadas.X)/(node_3->coordenadas.Y-node_1->coordenadas.Y))));
>>>>>>> Marlon
            }
        }
        fe.close();
    }
    Grapho(int _nodes, int _edges){
        srand(time(NULL));
        for(int i = 0; i < _nodes; i++){
            float _X = rand()%(ANCHO+1);
            float _Y = rand()%(ALTO+1);
            insert_Node(_X,_Y);
        }
        for(int i = 0; i < _edges; i++){
            Node<N,T,COOR>* node_1 = nodes[rand()%_nodes];
            Node<N,T,COOR>* node_2 = nodes[rand()%_nodes];
            insert_Edge(node_1,node_2,rand()%51);
        }
    }
    void insert_Node(float _X, float _Y){
        Node<N,T,COOR>* new_node = new Node<N,T,COOR>(_X,_Y);
        nodes.push_back(new_node);
    }
    void insert_Edge(Node<N,T,COOR>* node_1, Node<N,T,COOR>* node_2, T weight){
        Edge<N,T,COOR>* new_edge = new Edge<N,T,COOR>(node_1, node_2, weight);
        edges.push_back(new_edge);
    }

    void remove_Edge(Node<N,T,COOR>* node_1, Node<N,T,COOR>* node_2){
        Edge<N,T,COOR>* edge_to_remove= new Edge<N,T,COOR>(node_1,node_2);
        for(auto it = edges.begin(); it != edges.end(); it++){
            if((*it)->node_1 == edge_to_remove->node_1 || (*it)->node_2== edge_to_remove->node_2){
                edges.erase(it);
            }
        }
    }
    void remove_Node(float _X, float _Y){
        Node<N,T,COOR>* remove_node = new Node<N,T,COOR>(_X,_Y);

        for(auto it= nodes.begin(); it != nodes.end(); it++){
            if((*it)->coordenadas.X == remove_node->coordenadas.X || (*it)->coordenadas.Y==remove_node->coordenadas.Y){
                nodes.erase(it);
            }
        }
        for(auto it = edges.begin(); it != edges.end(); it++){
            if((*it)->node_1 == remove_node || (*it)->node_2== remove_node){
                edges.erase(it);
            }
        }
<<<<<<< HEAD

    }

=======

    }
>>>>>>> Marlon
    Edge<N,T,COOR>* search_edge(Node<N,T,COOR>* node_1, Node<N,T,COOR>* node_2) {
        auto et = edges.begin();
        for(;et != edges.end();et++){
            if(node_1 == (*et)->node_1 || node_2 == (*et)->node_2){
                return *et;
            }
        }
    }

    float density(){
        return (double)(2 * nodes.size())/(double)(edges.size()*(edges.size()-1));
    }

<<<<<<< HEAD


    ~Grapho(){}

    void dijkstras(Node<N,T,COOR>* node_inicio, Node<N,T,COOR>* node_final){
        T weight = 0;
        map<Node<Coordenadas, T, COOR>, T> tabla;
        auto elegido = node_inicio->vecinos.begin();
        auto et = node_inicio->vecinos.begin();
        for(; et != node_inicio->vecinos.end(); et++)
            dijkstras(tabla, et->first, node_final, weight + et->second);
        auto at = nodes.begin();

    }

    T dijkstras(vector<Node<Coordenadas, T, COOR>> recorrido,Node<N,T,COOR>* node_inicio, Node<N,T,COOR>* node_final, T weight){
        auto elegido = node_inicio->vecinos.begin();
        auto et = node_inicio->vecinos.begin();
        for(; et != node_inicio->vecinos.end(); et++) {
            dijkstras(et->first, node_final, weight + et->second);
        }
        auto at = nodes.begin();
=======
    ~Grapho(){}

    void help_dijkstra(vector<Node<N,T,COOR>*> path_nodes,Node<N,T,COOR>* node_inicio, Node<N,T,COOR>* node_final, T weight){
        if (node_inicio==node_final)
            path_nodes.insert(node_inicio,node_final);
        auto it= node_inicio->vecinos.begin();
        help_dijkstra(path_nodes,(*it)->first,node_final,weight + (*it)->second);


    }

    void dijkstras(Node<N,T,COOR>* node_inicio, Node<N,T,COOR>* node_final, T weight){
        //se halla la minima distancia
        map<vector<Node<N,T,COOR>*>,int> paths;
        auto et= node_inicio->vecinos.begin();
        for(; et != node_inicio->vecinos.end(); et++){
            vector<Node<N,T,COOR>*> paths_nodes;
            dijkstras((*et)->first, node_final, weight + (*et)->second);

            paths.insert(paths_nodes,weight);
            weight =0;

        }



    }
    //Ejemplo_2

    void dijkstras(Node<N,T,COOR>* node_inicio, Node<N,T,COOR>* node_final, T weight){
        auto elegido = node_inicio->vecinos.begin();
        for(auto et= node_inicio->vecinos.begin(); et != node_inicio->vecinos.end(); et++) {
            dijkstras((*et)->first, node_final, weight + (*et)->second);
        }
        auto at = nodes.begin();
        for(;at!=nodes.end();at++){
            (*at)->
        }

>>>>>>> Marlon
    }

    void saved (string nombre_archivo){
        string cadena;
        ofstream fe (nombre_archivo);
        fe << "BIBLIOTECA" << endl;
        fe << "POINTS " << nodes.size() << " double" << endl;
        auto it = nodes.begin();
        for(;it != nodes.end();it++){
            fe << (*it)->coordenadas.X << ' ' << (*it)->coordenadas.Y << " 0" << endl;
        }
        fe << '\n' << "CELLS " << edges.size() << " 1740" << endl;
        auto et = edges.begin();
        for(;et != edges.end();et++){
            auto at = nodes.begin();
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
    vector<Node<N,T,INT>*> nodes;
    vector<Edge<N,T,INT>*> edges;
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
            Node<N,T,INT>* node_1 = nodes[atoi(cadena.c_str())];
            fe >> cadena;
            Node<N,T,INT>* node_2 = nodes[atoi(cadena.c_str())];
            fe >> cadena;
            T weight = atoi(cadena.c_str());
            insert_Edge(node_1,node_2,weight);
        }
        fe.close();
    }
    void insert_Node(N value){
        Node<N,T,INT>* new_node = new Node<N,T,INT>(value);
        nodes.push_back(new_node);
    }
    void insert_Edge(Node<N,T,INT>* node_1, Node<N,T,INT>* node_2, T weight){
        Edge<N,T,INT>* new_edge = new Edge<N,T,INT>(node_1, node_2, weight);
        edges.push_back(new_edge);
    }
    Grapho(int _nodes, int _edges, int rango_min = 0, int rango_max = 100){
        srand(time(NULL));
        for(int i = 0; i < _nodes; i++){
            N value = rand()%((rango_max-rango_min)+1);
            insert_Node(value);
        }
        for(int i = 0; i < _edges; i++){
            Node<N,T,INT>* node_1 = nodes[rand()%_nodes];
            Node<N,T,INT>* node_2 = nodes[rand()%_nodes];
            insert_Edge(node_1,node_2,rand()%(rango_max-rango_min));
        }
    }

    ~Grapho(){}

    void saved (string nombre_archivo){
        string cadena;
        ofstream fe (nombre_archivo);
        fe << "BIBLIOTECA" << endl;
        fe << "VALUES " << nodes.size() << " double" << endl;
        auto it = nodes.begin();
        for(;it != nodes.end();it++){
            fe << (*it)->value << endl;
        }
        fe << '\n' << "EDGE " << edges.size() << " 2019" << endl;
        auto et = edges.begin();
        for(;et != edges.end();et++){
            auto at = nodes.begin();
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
    vector<Node<N,T,LETRA>*> nodes;
    vector<Edge<N,T,LETRA>*> edges;
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
            Node<N,T,LETRA>* node_1 = nodes[atoi(cadena.c_str())];
            fe >> cadena;
            Node<N,T,LETRA>* node_2 = nodes[atoi(cadena.c_str())];
            fe >> cadena;
            T weight = cadena;
            insert_Edge(node_1,node_2,weight);
        }
        fe.close();
    }
    void insert_Node(N value){
        Node<N,T,LETRA>* new_node = new Node<N,T,LETRA>(value);
        nodes.push_back(new_node);
    }
    void insert_Edge(Node<N,T,LETRA>* node_1, Node<N,T,LETRA>* node_2, T weight){
        Edge<N,T,LETRA>* new_edge = new Edge<N,T,LETRA>(node_1, node_2, weight);
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
            Node<N,T,LETRA>* node_1 = nodes[rand()%_nodes];
            Node<N,T,LETRA>* node_2 = nodes[rand()%_nodes];
            insert_Edge(node_1,node_2,alfabeto[rand()%(26)]);
        }
    }

    ~Grapho(){

    }

    void saved (string nombre_archivo){
        string cadena;
        ofstream fe (nombre_archivo);
        fe << "BIBLIOTECA" << endl;
        fe << "LETRAS " << nodes.size() << " double" << endl;
        auto it = nodes.begin();
        for(;it != nodes.end();it++){
            fe << (*it)->value << endl;
        }
        fe << '\n' << "EDGE " << edges.size() << " 2019" << endl;
        auto et = edges.begin();
        for(;et != edges.end();et++){
            auto at = nodes.begin();
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
