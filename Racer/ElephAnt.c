#include "Myre.h"


enum {Right = 1, Left = 3, Up = 4, Down = 2, UpWithFood = 12, RightWithFood = 9, LeftWithFood = 11, DownWithFood = 10};

int goRandomDirection(u_long random);

struct AntBrain {
   u_long random;
   short x,y;
   short foodx[10],foody[10];
   u_long timeout;
   short currentx, currenty;
};


int AntFunc(struct SquareData *felter, struct AntBrain *mem) {

    
    int selectedDirection = 0;
    
    
    
    //Hvis myren står alene på en base, gå et random sted hen efter mad.
    if((felter->Base == 1))
    {
        (mem->x) = 0;
        (mem->y) = 0;
        selectedDirection = goRandomDirection(mem->random);
    }
    
    //Hvis myren ikke står på en base, gå et random sted hed efter mad.
    if(felter->NumFood == 0)
    {
        selectedDirection = goRandomDirection(mem->random);
    }
    
    //Hvis der er mad på pågældende felt, tag det med til basen.
    if(felter->NumFood != 0)
    {
        if(mem->x < mem->currentx)
        {
            selectedDirection = LeftWithFood;
            
        }
        
        if(mem->x > mem->currentx)
        {
            selectedDirection = RightWithFood;
            
        }
        if(mem->y < mem->currenty)
        {
            selectedDirection = DownWithFood;
            
        }
        if(mem->y > mem->currenty)
        {
            selectedDirection = UpWithFood;
         
        }
        
    }
    
    switch(selectedDirection)
    {
        case(Right):
        {
           mem->currentx += 1;
        }
        case(Down):
        {
           mem->currenty -= 1; 
        }
        case(Left):
        {
           mem->currentx -= 1;
        }
        case(Up):
        {
           mem->currenty += 1;
        }
        case(RightWithFood):
        {
           mem->currentx += 1;
        }
        case(DownWithFood):
        {
           mem->currenty -= 1; 
        }
        case(LeftWithFood):
        {
           mem->currentx -= 1;
        }
        case(UpWithFood):
        {
           mem->currenty += 1;
        }
        default:
            break;
    }
    
    
 



    return selectedDirection;
}

int goRandomDirection(u_long random)
{
    if(random < 1073741823)
    {
        return Right;
    }
    
    if((random > 1073741823) && (random < 2147483647))
    {
        return Left;
    }
    
    if((random > 2147483647) && (random < 3221225471))
    {
        return Up;
    }
    
    if(random > 3221225471)
    {
        return Down;
    }
    
    else
    {
        return 0;
    }
}

DefineAnt(ElephAnt, "ElephAnt", AntFunc, struct AntBrain);