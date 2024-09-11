#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <iostream>
#include <string>
using namespace std;

//The base class for ninjas, heros and snorks.

#include "MoveBehaviour.h"

class Participant
{
  public:
    
    Participant(char = '-', int =0, int =0, MoveBehaviour* = nullptr);
    virtual~Participant();
    virtual void move();
    virtual void incurDamage(Participant*) =0;
    virtual int causeDamage() =0;
    virtual bool collide(Participant*);
    virtual bool isDead();
    virtual bool isSafe() =0;
    virtual char getAvatar();
    virtual int getRow();
    virtual int getCol();
    void setMove(MoveBehaviour*);


  protected:

    char avatar;
    bool dead;
    MoveBehaviour* movePart;
    int row;
    int col;

    

  private:

  

};

#endif