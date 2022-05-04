/*
 * credits: 
 * asstets: https://gvituri.itch.io/space-shooter
 * fonts: https://www.1001fonts.com/pixel-fonts.html
*/

/*
 * file system:
 * settings:
 *       volum
 *       (contorale)
 * (controale){
 *      shoot
 *      pause
 * }
 *   
*/

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

int WIDTH = 1920;//Daca va uitati prin cod si vedeti ca rezolutia e prea mare/mica chill ca se schimba in funtie de ecran cand se face fullscreen
int HEIGHT = 1080;

sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "astroner!", sf::Style::Fullscreen);
float DeltaTime; //Delta time, seconds since the last frame has beenm drawn

bool open = 1;

enum scenes{
    MENIU,
    SETTINGS,
    LEVELSELECTOR,
    LEVEL1,
    LEVEL2,
    LEVEL3,
    LEVEL4,
    LEVEL5,
    LEVEL6,
    LEVEL7,
    LEVEL8,
    LEVEL9,
    FINAL,
    TEST
};

scenes Cscene = MENIU;
#include "bullet.hpp"
#include "others.cpp"

//cea mai mare greseala sa folosesc namespace-uri da bine ca e doar in main() deci pana la urma e 20% ok
using namespace std;
using namespace sf;

sf::Texture shipTextureStatic;
sf::Texture shipTextureDown;
sf::Texture shipTextureUp;

sf::Texture enemyTexture;
sf::Texture buletTX;

sf::Font f2; //light_pixel-7 font

astr::entity ship(20 * WIDTH/HEIGHT, 20 * WIDTH/HEIGHT, 20 * WIDTH/HEIGHT, 20 * WIDTH/HEIGHT);
astr::entity enemy(40 * WIDTH/HEIGHT, 40 * WIDTH/HEIGHT, 40 * WIDTH/HEIGHT, 40 * WIDTH/HEIGHT);
float px, py, enemHP = 10;

#include "meniu.cpp"

#include "saves.cpp"

#define Tsx 8
#define Tsy 8



float enemyPlayerX = 0, enemyPlayerY = 0; //experimental!!
CircleShape enemyB(5);
bool shot = 0;
int HP = 3;

//RectangleShape ship(Vector2f(30, 20));
//RectangleShape enemy(Vector2f(40, 40));

#include "bullet.hpp"
#include "player.cpp"

Clock cl2, enemyclock;

Time bulletDelay = cl2.getElapsedTime();
vector <bullet> glont;

bool setup();
bool colision(float x1, float x2, float y1, float y2, float w1, float w2, float h1, float h2);


//include Levels
#include "testLevel.cpp"
#include "level1.cpp"

int main(){
    // Cscene = LEVEL1;
    //maximum e de 60fps ca altfel bubuie placa video :D

    win.setFramerateLimit(60);
    f.loadFromFile("fonts\\PressStart.ttf");
    f2.loadFromFile("fonts\\light_pixel-7.ttf");
    // std::thread load(setup);

    if(setup()){
        printf("Failed to load the textures!\n");
        return 0;
    }

    ship.setOrigin(ship.getSize().x/2, ship.getSize().y/2);
    enemy.setOrigin(enemy.getSize().x/2, enemy.getSize().y/2);
    ship.rotate(90);
    enemy.rotate(90);

    // enemy.setOrigin(0, 0);
    // ship.setOrigin(0, 0);
    //enemy.setFillColor(Color::Red);

    enemy.setPosition(700 * WIDTH/HEIGHT, 300 * WIDTH/HEIGHT);
    enemyB.setFillColor(Color::White); //experimental!!
    // ship.setPosition(400, 300);

    ship.thing.setTexture(&shipTextureStatic);
    enemy.thing.setTexture(&enemyTexture);

    sf::Clock D_time;
    MupdateB();
    Updt();
    Supdate();
    while(win.isOpen()){
        if(!open) {win.close(); break;}
        Event event;
        while(win.pollEvent(event)){
            if(event.type == Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))){
                win.close();
            }
            WIDTH = win.getSize().x;
            HEIGHT = win.getSize().y;
        }

        switch(Cscene){
            case MENIU:
                meniu();
            break;
            case SETTINGS:
                settings();
            break;
            case LEVELSELECTOR:
                Cscene = scenes(saves()+2);
                // levelTest();
            break;
            case LEVEL1:
                lvl1(win);
            break;
        }

        DeltaTime = D_time.restart().asSeconds();
    }

    // load.join();
    ofstream of("settings.ast");

    of<<sound.getValue()<<'\n';

    for(auto i:k){
        of<<i<<'\n';
    }
}

//e doar pt level test da mna, e si asta folositor la ceva
//testez pentru coliziune a 2 obiecte, e cam rubish da mere
bool colision(float x1, float x2, float y1, float y2, float w1, float w2, float h1, float h2){
    if((x1 + w1 >= x2 && x1 <= x2 + w2) && (y1 + h1 >= y2 && y1 <= y2 + h2)){
        return 1;
    }
    return 0;
}

//load data, nu te atinge ca poate.l strici, doar adauga chestii :D
bool setup(){
    sf::Image textures, bullets;
    if(!textures.loadFromFile("textures\\ships_models.png") && !bullets.loadFromFile("textures\\bullets.png")){
        return 0;
    }

    // buletTX.loadFromFile("textures\\bullets_textures.png", IntRect(Tsx*1, Tsy*1, 8, 8));
    //open form the image, ca na e mai convenabil :)

    // shipTextureStatic.loadFromImage(textures, IntRect(Tsx*1, Tsy*0, 8, 8));
    // shipTextureDown.loadFromImage(textures, IntRect(Tsx*2, Tsy*0, 8, 8));
    // shipTextureUp.loadFromImage(textures, IntRect(Tsx*0, Tsy*0, 8, 8));
    


    // enemyTexture.loadFromImage(textures, IntRect(Tsx*8, Tsy*6, 16, 16)); //doar pt test

    //elementele pt UI, muzica, meniu, etc.
    {
        theme.openFromFile("sounds\\main_meniu.ogg");
        theme.play();
        theme.setLoop(true);

        img.loadFromFile("textures\\meniu_background.png", IntRect(0, 0, WIDTH, HEIGHT));
        background.setTexture(img);
        background.setScale(3, 3);
        background.setOrigin(img.getSize().x/2, img.getSize().y/2);
        background.setPosition(Vector2f(WIDTH/2, HEIGHT/2));

        //meniu Buttons
        welcome.setFont(f);
        welcome.setString("ASTRONER");
        welcome.setCharacterSize(50);
        welcome.setPosition(sf::Vector2f(10,10));

        playButton.setPosition(10 * WIDTH/HEIGHT, 70 * WIDTH/HEIGHT);
        playButton.setColor(sf::Color(10, 10, 10, 255));

        settingsButton.setPosition(10 * WIDTH/HEIGHT, 130 * WIDTH/HEIGHT);
        settingsButton.setColor(sf::Color(10, 10, 10, 255));

        quitButton.setPosition(10 * WIDTH/HEIGHT, 190 * WIDTH/HEIGHT);
        quitButton.setColor(sf::Color(10, 10, 10, 255));
        //pana aici
        //setings buttons
        //sa le fac sa se seteze automat din fisier la alea cu *!*
        backButton.setPosition(10 * WIDTH/HEIGHT, 10 * WIDTH/HEIGHT);
        backButton.setColor(sf::Color(10, 10, 10, 255));

        sound.setPosition(10 * WIDTH/HEIGHT, 100 * WIDTH/HEIGHT);
        sound.setTextPos(250 * WIDTH/HEIGHT, 90 * WIDTH/HEIGHT);
        
        ifstream in("settings.ast");
        int s;
        in>>s;
        sound.setValue(s);
        theme.setVolume(s);
        sound.setText("SOUND(" + std::to_string(s) + "%)");
        // for(int i = 0; i<2; i++){
        //     in>>ss;
        //     k[i] = (sf::Keyboard::Key)ss;
        // }
        sLoad();
    }

    //Level1
    {
        
        if(!Enemy1.loadFromImage(textures, IntRect(Tsx * 8, Tsy * 6, 16, 16))) return 0;
    }
    return 0;
}

