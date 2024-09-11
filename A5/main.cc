#include "Escape.h"

/*Program Author: Aleeza Syed 
Student ID: 101267783

Program Puropse: to simulate a pit of snorks where the heros have to climb out from and can be saved from by ninjas. The heros can incur damage while the snorks can cause damage, and the heros can die. The heros, and ninjas can 
change behaviour mid program. The program uses inheritance and abstraction to control the participants, ninjas, snorks and heros, and has a control class.

*/

//Main creates and launches the controller class

int main(){


    Escape* escape = new Escape();

    escape->runEscape();

    delete escape;


    return 0;
}