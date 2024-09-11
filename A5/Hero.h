#ifndef HERO_H
#define HERO_H

#include "Participant.h"
#include "MoveBehaviour.h"
#include "defs.h"


#include <iostream>
#include <string>
using namespace std;


//A class that inherits from the abstract class participant.



class Hero : public Participant
{
  public:

    Hero(char = '-', int=0,int=0, string = "");
    int getHealth();
    string getName();
    bool getRescue();
    virtual void incurDamage(Participant*);
    virtual int causeDamage();
    virtual bool isSafe();
   
    

  private:

    string name;
    int health;
    bool rescued;
    
   
};

#endif