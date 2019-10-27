#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

#include <GL/glut.h>
#include <iterator>
#include "macros.h"
#include "Grapho.h"
#include "Coordenadas.h"

#define RED 0
#define GREEN 0
#define BLUE 0
#define ALPHA 1
#define ECHAP 27
#define COOR 0
#define INT 1
#define LETRA 2

Grapho<Coordenadas, int, COOR> grafo_0;
Grapho<Coordenadas, int, COOR> grafo_1("Prueba_2.txt");
Grapho<Coordenadas, int, COOR> grafo_prueba_0("100points.vtk");
Grapho<Coordenadas, int, COOR> grafo_prueba_1("1000points.vtk");
Grapho<Coordenadas, int, COOR> grafo_prueba_2("2000points.vtk");
Grapho<Coordenadas, int, COOR> grafo_prueba_3("binary_fire_symbolmesh_image.vtk");
Grapho<Coordenadas, int, COOR> grafo_prueba_4("boingo_mesh_image_rgb_cell_data.vtk");
Grapho<Coordenadas, int, COOR> grafo_3(5,12);
Grapho<Coordenadas, int, COOR> grafo_2(grafo_1);
Grapho<int, int, INT> grafo_4(12,12);
Grapho<string, string, LETRA> grafo_5(15,15);

double rotacion = 0;
double move_x = 0;
double move_y = 0;

// inicializamos glut
GLvoid initGL(){
    glClearColor(RED, GREEN, BLUE, ALPHA);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

GLvoid window_display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, ANCHO, 0.0f, ALTO, 0.0f, PROFUNDIDAD);

    // Graficamos los voids
    //dibujar();

    vector<Node<Coordenadas,COOR>*>::iterator it = grafo_2.nodes.begin();
    for(;it != grafo_2.nodes.end();it++){
        glPushMatrix();
        glColor3f(1.0f,1.0f,1.0f);
        glTranslatef((*it)->coordenadas.X,(*it)->coordenadas.Y,0);
        if(grafo_2.nodes.size() < 50)
            glutSolidSphere(5,20,10);
        else if(grafo_2.nodes.size() < 100)
            glutSolidSphere(3,20,10);
        else
            glutSolidSphere(1,20,10);
        glPopMatrix();
    }

    vector<Edge<int,COOR>*>::iterator et = grafo_2.edges.begin();
    for(;et != grafo_2.edges.end();et++){
        glPushMatrix();
        glColor3f((*et)->R,(*et)->G,(*et)->B);
        glBegin(GL_LINE_STRIP);
        glVertex3f((*et)->node_1->coordenadas.X,(*et)->node_1->coordenadas.Y,0);
        glVertex3f((*et)->node_2->coordenadas.X,(*et)->node_2->coordenadas.Y,0);
        glEnd();
        glPopMatrix();
    }


    glutSwapBuffers();
    glFlush();
}

GLvoid window_reshape(GLsizei width, GLsizei height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, ANCHO, 0.0f, ALTO, 0.0f, PROFUNDIDAD);
    glMatrixMode(GL_MODELVIEW);
//	gluLookAt(0,50, 100, 0,0,0, 0, 1, 0);

}

GLvoid window_key(unsigned char key, int x, int y){
    switch (key) {
        case ECHAP:
            exit(1);
            break;

        default:
            break;
    }
}

// funcion de mouse, para colocar elementos en las coodenadas del mouse
// problema::  coloca en otras coordenadas mas no en el x,y
GLvoid callback_mouse(int button, int state, int x, int y){
    if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
        //boids.push_back(boid(x,600-y));
        //predador =  vector_t(x, 600-y,0);
    }
}

// timer , para demorar el tiempo de redibujado de glut
// permite que veamos mas lentamente la simulacion
void Timer	(int value){ // intervalo en miliseg
    glutPostRedisplay	(	);
    rotacion++;
    move_x++;
    move_y++;

    //actualizar(); //ACTUALIZAMOS los BOIDS

    glutTimerFunc		(DURATION,Timer, 10);
}/// Timer



int main (int argc, char* argv[]){
    srand(time(NULL));

    grafo_0.insert_Node(20.0,10.0);
    grafo_0.insert_Node(500.0,30.0);
    grafo_0.insert_Node(400.0,100.0);
    grafo_0.insert_Node(200.0,100.0);
    grafo_0.insert_Node(600.0,200.0);
    grafo_0.insert_Node(300.0,200.0);
    grafo_0.insert_Node(600.0,700.0);
    grafo_0.insert_Edge(grafo_0.nodes[0],grafo_0.nodes[1],10);
    grafo_0.insert_Edge(grafo_0.nodes[1],grafo_0.nodes[2],20);
    grafo_0.insert_Edge(grafo_0.nodes[2],grafo_0.nodes[3],30);
    grafo_0.insert_Edge(grafo_0.nodes[3],grafo_0.nodes[4],60);
    grafo_0.insert_Edge(grafo_0.nodes[4],grafo_0.nodes[0],15);
    grafo_0.insert_Edge(grafo_0.nodes[1],grafo_0.nodes[4],5);
    grafo_0.insert_Edge(grafo_0.nodes[3],grafo_0.nodes[5],7);
    //grafo_0.MST(0,0);
    grafo_0.saved("Prueba_2.txt");


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(ANCHO, ALTO);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Grafo");
    initGL();
    glEnable(GL_TEXTURE_2D);
    glutDisplayFunc(&window_display);
    glutReshapeFunc(&window_reshape);
    glutKeyboardFunc(&window_key);
    glutTimerFunc(DURATION, Timer, 1);
    glutMouseFunc(&callback_mouse);
    glutMainLoop();
    return true;
}