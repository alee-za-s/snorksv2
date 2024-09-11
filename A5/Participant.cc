#include <iostream>
using namespace std;
#include <string>

#include "Participant.h"
#include "MoveBehaviour.h"


Participant::Participant(char a, int r , int c, MoveBehaviour* m){

    avatar =a;
    row =r;
    col =c;
    dead = false;
    movePart =m;

}

Participant:: ~Participant(){

    delete movePart;
}

bool Participant:: collide(Participant* p){

    if (row == p->row && col == p->col){
        return true;
    }

    return false;
}


bool Participant::isDead(){

    return dead;
}

char Participant::getAvatar(){

    return avatar;
}

int Participant::getRow(){

    return row;
}

int Participant::getCol(){

    return col;
}

void Participant::setMove(MoveBehaviour* m){


    MoveBehaviour* temp = movePart;
    movePart =m;

    delete temp;
}

void Participant::move(){
    
    movePart->move(row,col,row,col);
}