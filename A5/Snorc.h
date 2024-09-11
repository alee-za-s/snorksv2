#ifndef SNORC_H
#define SNORC_H


#include "Participant.h"
#include "MoveBehaviour.h"

#include <iostream>
#include <string>
using namespace std;

//A class that inherits from the abstract class participant.


class Snorc : public Participant
{
  public:
    Snorc(int=0,int=0, int =0);
    virtual void incurDamage(Participant*);
    virtual int causeDamage();
    virtual bool isSafe();
    
   
    

  private:
    int strength;
   
};

#endif