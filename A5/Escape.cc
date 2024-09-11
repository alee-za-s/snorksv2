#include <iostream>
using namespace std;
#include <string>


#include "Escape.h"

Escape::Escape()
{
  
  listSize =0;
  int col = random(9)+7;
  srand( (unsigned)time( NULL ) );

  hero1 = new Hero('T', MAX_ROW -2,random(9)+7, "Timmy");

  while (col == hero1->getCol()){

    col = random(9)+7;
    
  }

  hero2 = new Hero('H', MAX_ROW -2,col, "Harold");

  numSnorcs=0;

  list += hero1;
  list += hero2;

  listSize += 2;

}


Escape::~Escape(){

}

void Escape::runEscape(){

  int rand =0;

  while(!isOver()){

    rand = random(9);

    if (rand <8 && numSnorcs < MAX_SNORCS){

      spawnSnorc();
        
    }

    rand = random(3);

    if (rand == 1){

        spawnNinja();
    }

    system("clear");
    print();
    moveParticipants();
   
    cout <<left << setfill(' ')<< setw(8)<< hero1->getName() << ":" <<hero1->getHealth();

    if (hero1->getRescue()){

      cout<< right << setfill(' ')<< setw(10) << "Rescued";

    } else if (hero1->isDead()){

      cout<< right << setfill(' ')<< setw(10) << "Deceased";

    }

    cout << endl; 

    cout << left << setfill(' ')<< setw(8)<<hero2->getName() << ":" << hero2->getHealth();

    if (hero2->getRescue()){

      cout<< right << setfill(' ')<< setw(10) << "Rescued";

    } else if (hero2->isDead()){

      cout<< right << setfill(' ')<< setw(10) << "Deceased";

    }

    cout << endl; 

    usleep(200000);

  }

  printOutcome();
}



void Escape::spawnSnorc(){

  int r = random(7) +(MAX_ROW -7);
  int c = random(MAX_COL -1);
  int s = random(2)+2;

  numSnorcs ++;
  listSize ++;

  Snorc* aSnorc = new Snorc(r,c +1,s);
  list += aSnorc;
  
}

void Escape::spawnNinja(){

  int r = 1;
  int c = random(MAX_COL -1);

  listSize ++;
  Ninja* aNinja = new Ninja(r,c +1);
  list += aNinja;
  
}


void Escape::moveParticipants(){


  Participant* part[listSize];
  
  list.convertToArray(part,listSize);

  for( int i =0; i < listSize; ++i){

    Participant* cur = part[i];
     
    if (!cur->isSafe()){
      cur->move();

    }

    Participant* p2 = checkforCollision(cur);

    if ( p2 != NULL){

      p2->incurDamage(part[i]);
      part[i]->incurDamage(p2);

    }

      
  }

}

Participant* Escape::checkforCollision(Participant* p){

    Participant* part[listSize];

    list.convertToArray(part,listSize);

    if (p->isSafe()){

      return NULL;
    }


  for (int j=0; j < listSize; ++j){

    if (p->collide(part[j])){

      return part[j];

      }
    }


  return NULL;

}


bool Escape::isOver(){

  return (hero1->isDead() || hero1->isSafe()) && (hero2->isDead() || hero2->isSafe());
}


void Escape::printOutcome(){


  cout << endl;

  if (hero1->isSafe() && hero2->isSafe()){


    cout << "Both heros made it out alive!";
  } else if (hero1->isDead() && hero2->isDead()){


    cout << "Both heros did not make it ..";
  } else if (hero1->isDead()){

    cout << hero1->getName() <<" did not make it ..";


  } else {

    cout << hero2->getName() <<" did not make it ..";

  }

  cout << endl;
  cout << endl;


}


void Escape::print(){

   
  Participant* arr[listSize];

  list.convertToArray(arr, listSize);
  char temp[MAX_ROW +1][MAX_COL+1];

  
  for (int j=0; j <= MAX_COL; ++j){

    temp[0][j] = '-';

    }

  for (int i=1; i < MAX_ROW; ++i){

    for (int j=0; j < MAX_COL; ++j){

        temp[i][j] = ' ';

    }

  }


  for (int i=0; i <= MAX_ROW; ++i){

    

    temp[i][0] = '|';
    temp[i][MAX_COL] = '|';


    

  }

  for (int j=0; j <= MAX_COL; ++j){

    temp[MAX_ROW][j] = '-';

    }

  for (int i=0; i < listSize; ++i){

    if (arr[i]->isSafe() == false){

      temp[arr[i]->getRow()][arr[i]->getCol()] = arr[i]->getAvatar();
        
    }

  }

  for (int i=0; i <= MAX_ROW ; ++i){

    for (int j=0; j <= MAX_COL; ++j){

      cout << temp[i][j];
    }

     cout << endl;
    }
    cout << endl;
}



