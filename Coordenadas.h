//
// Created by VICTOR on 16/10/2019.
//

#ifndef UNTITLED26_COORDENADAS_H
#define UNTITLED26_COORDENADAS_H

class Coordenadas {
public:
    float X;
    float Y;

    Coordenadas(){}
    Coordenadas(float _X, float _Y): X(_X), Y(_Y){}

    bool operator == (const Coordenadas& it) const {
        return X == it.X and Y == it.Y;
    }

    bool operator != (const Coordenadas& it) const {
        return X != it.X or Y != it.Y;
    }

    ~Coordenadas(){}
};

#endif //UNTITLED26_COORDENADAS_H
