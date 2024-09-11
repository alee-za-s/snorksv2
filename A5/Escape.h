#ifndef ESCAPE_H
#define ESCAPE_H


#include "Ninja.h"
#include "Hero.h"
#include "Snorc.h"
#include "Participant.h"
#include "MoveBehaviour.h"
#include "defs.h"
#include "List.h"
#include <iostream>
#include <string>
using namespace std;

//Escape class is a control class that amkes the participants and simulates behaviour in the pit.

class Escape
{
  public:
    void runEscape();
    Escape();
    ~Escape();

  protected:

  private:
    void spawnSnorc();
    void moveParticipants();
    Participant* checkforCollision(Participant*);
    bool isOver();
    void printOutcome();
    void spawnNinja();
    void print() ;
    List<Participant*> list;
    Hero* hero1;
    Hero* hero2;
    int numSnorcs;
    int listSize;

};

#endif