#include <iostream>
using namespace std;
#include <iostream>
#include <string>
#include "Hero.h"


Hero::Hero(char a, int r,int c, string n) : Participant(a,r,c,new EscapeeBehaviour), name(n),health(MAX_HEALTH),rescued(false) {

}

void Hero::incurDamage(Participant* p){


    if (p->causeDamage() == RESCUE){

        rescued =true;
        setMove(new RescuedBehaviour);
        
    }else{


    if (health - p->causeDamage() <0 ){

        health =0;

    }else {

        health -= p->causeDamage();
    }

    
    if (health <= 0){

        avatar = '+';
        dead = true;
    }

    }
}


int Hero::causeDamage(){

    return 0;
}

int Hero::getHealth(){

    return health;
}

string Hero::getName(){

    return name;
}

bool Hero::getRescue(){

    return rescued;
}

bool Hero::isSafe(){

    return (row == 0);
}

