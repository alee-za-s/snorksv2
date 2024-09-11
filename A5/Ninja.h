#ifndef NINJA_H
#define NINJA_H

#include "Participant.h"
#include "MoveBehaviour.h"
#include "defs.h"

#include <iostream>
#include <string>
using namespace std;


//A class that inherits from the abstract class participant.



class Ninja : public Participant
{
  public:

    Ninja(int=0,int=0);
    int getHealth();
    string getName();
    bool getRescue();
    virtual void incurDamage(Participant*);
    virtual int causeDamage();
    virtual bool isSafe();
   
    

  private:

    
    int strength;
    bool poisoned;
    
   
};

#endif