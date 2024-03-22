#include "bomb.h"
#include "de2i.h"

int Bomb::drawBomb(int* frameCounter){
    
    ClearBackground(WHITE);
    drawTela();

   if(*frameCounter>60){
        tempo++;
        *frameCounter=0;
        std:: cout << tempo << " segundos\n";
        
        if(tempo > 30){
            return 2;
        }
    } 

    int c=0;

    for (int i = 0; i < 18; i++){

        if(fios[i]){
            std::cout << "1 ";
        }
        else{
            std::cout << "0 ";
        }
        if(pushed[i]){
            std::cout << "1 \n";
        }
        else{
            std::cout << "0 \n";
        }

        if(fios[i]==pushed[i]){
                        c++;
        }
        if(pushed[i]){ 
            if(!fios[i]){
                return 2;
            }
        }
    }

    if(c==18){
        return 1;
    }   

    std::cout << "\n";
    
    pressed();

    return 0;
}

void Bomb::randomFios(){

    for (int i = 0; i < 18; i++){

        fios[i]= (std::rand())%2;
        if(fios[i]){
            std::cout << "1 ";
        }
        else{
            std::cout << "0 ";
        }
        pushed[i]=0;
    }   
    std::cout << "\n";
}

void Bomb::drawTela(){

        int inc = 50;
    for (int i = 0; i < 18; i++)
    {
        if (!fios[i]||(fios[i]&&pushed[i])) DrawCircle(50 + i*inc,480,20, GREEN);
        else DrawCircle(50 + i*inc,480,20, RED);
        
    }
    DrawRectangle (480,60,20,50,BROWN);
    DrawCircle(480,200,100, BLACK);
    DrawCircle(430,160,20, WHITE);
    DrawCircle(500,160,20, WHITE);
    DrawCircle(440,160,10, RED);
    DrawCircle(510,160,10, RED);

}

void Bomb::setBomb(int d){
    randomFios();
    tempo = 0;
    std::cout << "setado \n";
    is_s_pressed(saveSwitch);
}

void Bomb::pressed(){

    bool rdS[18];
    is_s_pressed(rdS);

    for(int i =0; i <18; i++){

        if(saveSwitch[i]!=rdS[i]){
            pushed[17-i]=true;
        }else{
            pushed[17-i]=false;
        }
    }

}
