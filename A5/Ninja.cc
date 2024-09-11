#include <iostream>
using namespace std;
#include <iostream>
#include <string>
#include "Ninja.h"


Ninja::Ninja(int r,int c) : Participant('N',r,c, new RescuerBehaviour), strength(0),poisoned(false) {

}


void Ninja::incurDamage(Participant* p){


    if (poisoned){

        return;
    }


    if (p->causeDamage() == 0){

        setMove(new RescuedBehaviour);

        if(row <= MAX_ROW -1){

            row = row + 1;
        }


    }else if (p->causeDamage() != RESCUE ){

        int rand =0;
        rand = random(2) + 6;
        avatar = 'S';
        strength = rand;
        poisoned = true;

        setMove( new VillainBehaviour);  
    }
    


}


int Ninja::causeDamage(){


    if (poisoned) {
        return strength;
    }

    return RESCUE;
}




bool Ninja::isSafe(){


    if (!poisoned && row ==0){

        return true;
    } else if (!poisoned && row ==MAX_ROW && col==MAX_COL){

        return true;
    }

    return false;

}