#include "scenes.h"
#include "player.h"
#include "collisions.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
const int screenWidth = 960;
const int screenHeight = 540; 

const int scenesNum = 6;

const int getScreenWidth(){
    return screenWidth;
}

const int getScreenHeight(){
    return screenHeight;
}

int main(void)
{
    
    InitWindow(screenWidth, screenHeight, "Turo's adventure");
    InitAudioDevice();      // Initialize audio device

    Collisions colisoes(scenesNum);

    Player Turo(333, 252, 3, 1.2, &colisoes);
    Scenes cenas(scenesNum, screenWidth, screenHeight, &Turo, &colisoes);

    Map *maps = new Map[scenesNum];
    maps[0].setMap("assets/map/new_Map.png", "assets/map/front_layer.png");
    maps[1].setMap("assets/map/mapa01.png", NULL);
    maps[2].setMap("assets/map/map3.png", "assets/map/map3front.png");
    maps[3].setMap("assets/map/map4.png", "assets/map/map4front.png");
    maps[4].setMap("assets/map/map5.png", "assets/map/map5front.png");
    maps[5].setMap("assets/map/map6.png", "assets/map/map6front.png");

    Sound soundTrack = LoadSound("assets/sounds/soundteste.mp3");
    PlaySound(soundTrack);

    SetTargetFPS(60);
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(BLACK);

        //std:: cout << "Posição x: " << (int)(Turo.getCurrLoc().x/10)+1 << " || " << "Posição y: " << (int)(Turo.getCurrLoc().y/10)+1 << "\n";

        cenas.sceneControl(maps); //Função responsável pelo controle do jogo

        EndDrawing();
    }

    Turo.unloadPlayer();
    cenas.unloadAllScenes(maps);
    cenas.UnloadImages();

    UnloadSound(soundTrack); // Unload sound data
    CloseAudioDevice();
    CloseWindow();

    //UnloadTexture(m);

    return 0;
}