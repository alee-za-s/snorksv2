#include "MoveBehaviour.h"




void EscapeeBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol){

    int randR = random(3);
    int randC = random(2);


    if (oldRow ==0){

    } else {

        if (randR ==0 && oldRow - 1 >= 0 ){
            
            newRow = oldRow - 1;

        } else if (randR ==1 && oldRow - 2 >=0 ){

            newRow = oldRow - 2;

        }else if (randR ==2 && oldRow + 1 < MAX_ROW){

            newRow = oldRow + 1;

        } else if (randR ==3 && oldRow + 2 < MAX_ROW){

            newRow = oldRow + 2;
        }


        if (randC ==0 && oldCol - 1 > 0){

            newCol = oldCol - 1;

        } else if (randC ==1 && oldCol + 1 < MAX_COL){

            newCol = oldCol + 1;
        }
    }
}


void VillainBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol){

    int randR = random(2);
    int randC = random(2);

    if (randR ==0 && oldRow -1 >= MAX_ROW -7){

        newRow = oldRow - 1;

    } else if (randR ==1 && oldRow + 1 < MAX_ROW){

        newRow = oldRow + 1;
    }


    if (randC ==0 && oldCol -1 > 0){

        newCol = oldCol - 1;

    } else if (randC ==1 && oldCol +1 < MAX_COL){

        newCol = oldCol + 1;
    }
}


void RescuerBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol){

    
    if (oldRow + 1 < MAX_ROW){

        newRow = oldRow + 1;
    }
    else{

        newRow = oldRow;
    }

    newCol =oldCol;

}

void RescuedBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol){

    
    if (oldRow - 1 >= 0){
        
        newRow = oldRow - 1;
    
    }else{

        newRow = oldRow;
    }
    
    newCol =oldCol;



}

