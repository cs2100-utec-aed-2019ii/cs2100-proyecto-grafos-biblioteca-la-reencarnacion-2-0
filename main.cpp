#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iterator>
#include <limits>
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

Grapho<Coordenadas, float, COOR> grafo_1("Prueba_2.txt");
Grapho<Coordenadas, float, COOR> grafo_2(grafo_1);

double rotacion = 0;
double move_x = 0;
double move_y = 0;
int node = rand()%grafo_2.nodes.size();
Coordenadas inicio;
Coordenadas final;

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

    auto it = grafo_2.nodes.begin();
    for(;it != grafo_2.nodes.end();it++){
        glPushMatrix();
        glColor3f((*it)->R,(*it)->G,(*it)->B);
        glTranslatef((*it)->coordenadas.X,(*it)->coordenadas.Y,0);
        if(grafo_2.nodes.size() < 50)
            glutSolidSphere(5,20,10);
        else if(grafo_2.nodes.size() < 100)
            glutSolidSphere(3,20,10);
        else
            glutSolidSphere(1,20,10);
        glPopMatrix();
    }

    auto et = grafo_2.edges.begin();
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

void specialKeyInput(int key, int x, int y){
    auto it = grafo_2.nodes.begin();
    for(int i = 0; i < node; it++,i++);

    if(key == GLUT_KEY_LEFT){
        (*it)->B = 1;
        (*it)->G = 1;
        (*it)->R = 1;
        float weight = 0;
        auto elegido = (*it)->vecinos.begin();
        auto et = (*it)->vecinos.begin();
        for(; et != (*it)->vecinos.end(); et++)
            if(weight < et->second){
                weight = et->second;
                elegido = et;
            }
        int i = 0;
        auto at = grafo_2.nodes.begin();
        for(; (*at)->coordenadas.X != elegido->first->coordenadas.X && (*at)->coordenadas.Y != elegido->first->coordenadas.Y; at++,i++);
        node = i;
        (*at)->B = 0;
        (*at)->G = 0;
        (*it)->R = 1;
        auto ot = grafo_2.edges.begin();
        for(; ot != grafo_2.edges.end(); ot++){
            if(((*ot)->node_1->coordenadas.X == elegido->first->coordenadas.X &&
                (*ot)->node_2->coordenadas.X == (*it)->coordenadas.X &&
                (*ot)->node_1->coordenadas.Y == elegido->first->coordenadas.Y &&
                (*ot)->node_2->coordenadas.Y == (*it)->coordenadas.Y) ||
                ((*ot)->node_1->coordenadas.X == (*it)->coordenadas.X &&
                (*ot)->node_2->coordenadas.X == elegido->first->coordenadas.X &&
                (*ot)->node_1->coordenadas.Y == (*it)->coordenadas.Y &&
                (*ot)->node_2->coordenadas.Y == elegido->first->coordenadas.Y)){
                    (*ot)->B = 0;
                    (*ot)->G = 0;
            }
        }
    }
    if(key == GLUT_KEY_RIGHT){
        (*it)->B = 1;
        (*it)->G = 1;
        (*it)->R = 1;
        float weight = numeric_limits<float>::max();
        auto elegido = (*it)->vecinos.begin();
        auto et = (*it)->vecinos.begin();
        for(; et != (*it)->vecinos.end(); et++)
            if(weight > et->second){
                weight = et->second;
                elegido = et;
            }
        int i = 0;
        auto at = grafo_2.nodes.begin();
        for(; (*at)->coordenadas.X != elegido->first->coordenadas.X && (*at)->coordenadas.Y != elegido->first->coordenadas.Y; at++,i++);
        node = i;
        (*at)->B = 0;
        (*at)->G = 0;
        (*it)->R = 1;
        auto ot = grafo_2.edges.begin();
        for(; ot != grafo_2.edges.end(); ot++){
            if(((*ot)->node_1->coordenadas.X == elegido->first->coordenadas.X &&
                (*ot)->node_2->coordenadas.X == (*it)->coordenadas.X &&
                (*ot)->node_1->coordenadas.Y == elegido->first->coordenadas.Y &&
                (*ot)->node_2->coordenadas.Y == (*it)->coordenadas.Y) ||
               ((*ot)->node_1->coordenadas.X == (*it)->coordenadas.X &&
                (*ot)->node_2->coordenadas.X == elegido->first->coordenadas.X &&
                (*ot)->node_1->coordenadas.Y == (*it)->coordenadas.Y &&
                (*ot)->node_2->coordenadas.Y == elegido->first->coordenadas.Y)){
                (*ot)->B = 0;
                (*ot)->G = 0;
            }
        }
    }
    glutPostRedisplay();
}

void mousebutton (int boton, int estado, int x, int y){
    if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN){
        auto it = grafo_2.nodes.begin();
        for(;it != grafo_2.nodes.end(); it++){
            if((*it)->coordenadas.X == inicio.X && (*it)->coordenadas.Y == inicio.Y){
                (*it)->B = 1;
                (*it)->R = 1;
                (*it)->G = 1;
            }
        }

        it = grafo_2.nodes.begin();
        for(;it != grafo_2.nodes.end(); it++){
            if((*it)->coordenadas.X-3 <= x && (*it)->coordenadas.X+3 >= x && (*it)->coordenadas.Y-3 <= ALTO-y && (*it)->coordenadas.Y+3 >= ALTO-y){
                (*it)->B = 0;
                (*it)->R = 0;
                (*it)->G = 1;
                inicio.X = (*it)->coordenadas.X;
                inicio.Y = (*it)->coordenadas.Y;
            }
        }
    }

    if (boton == GLUT_RIGHT_BUTTON && estado == GLUT_DOWN){
        auto it = grafo_2.nodes.begin();
        for(;it != grafo_2.nodes.end(); it++){
            if((*it)->coordenadas.X == final.X && (*it)->coordenadas.Y == final.Y){
                (*it)->B = 1;
                (*it)->R = 1;
                (*it)->G = 1;
            }
        }

        it = grafo_2.nodes.begin();
        for(;it != grafo_2.nodes.end(); it++){
            if((*it)->coordenadas.X-3 <= x && (*it)->coordenadas.X+3 >= x && (*it)->coordenadas.Y-3 <= ALTO-y && (*it)->coordenadas.Y+3 >= ALTO-y){
                (*it)->B = 0;
                (*it)->R = 0;
                (*it)->G = 1;
                final.X = (*it)->coordenadas.X;
                final.Y = (*it)->coordenadas.Y;
            }
        }
    }
    glutPostRedisplay ();
}

int main (int argc, char* argv[]){

    auto it = grafo_2.nodes.begin();
    for(int i = 0; i < node; it++,i++);
    (*it)->B = 0;
    (*it)->G = 0;
    (*it)->R = 1;


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(ANCHO, ALTO);
    glutInitWindowPosition(100,50);
    glutCreateWindow("Grafo");
    initGL();
    glEnable(GL_TEXTURE_2D);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,ANCHO,0.0,ALTO, -100.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutDisplayFunc(&window_display);
    glutSpecialFunc(specialKeyInput);
    glutReshapeFunc(&window_reshape);
    glutKeyboardFunc(&window_key);
    glutTimerFunc(DURATION, Timer, 1);
    glutMouseFunc(&callback_mouse);
    glutMouseFunc(&mousebutton);
    glutMainLoop();
    return true;
}