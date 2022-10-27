#pragma once
#include <SFML/Graphics.hpp>

void render(){
    if(!enemHP) enemy.setPosition(10000 * WIDTH/HEIGHT, 100000 * WIDTH/HEIGHT);


    win.draw(enemy.thing);
    win.draw(ship.thing);
    win.draw(enemyB);
    // {
    //     win.draw(ship.hitbox);
    //     win.draw(enemy.hitbox);
    // }
    win.display();
}

void buletRender(){
    for(int i = 0; i < glont.size(); i++){
        glont[i].bulletDraw();
        glont[i].update();
        if(glont[i].bx > WIDTH || glont[i].is_alive == 0) glont.erase(glont.begin() + i);
    }
}

void input(){
    Time shoot = enemyclock.getElapsedTime();
    bulletDelay = cl2.getElapsedTime();
    if(Keyboard::isKeyPressed(Keyboard::D) && ship.getPosition().x < WIDTH - ship.getSize().x){
        px += 100 * WIDTH/HEIGHT * DeltaTime;
    }
    if(Keyboard::isKeyPressed(Keyboard::A) && ship.getPosition().x > 0){
        px -= 80 * WIDTH/HEIGHT * DeltaTime;
    }
    if(Keyboard::isKeyPressed(Keyboard::W) && ship.getPosition().y > 0){
        py -= 100 * WIDTH/HEIGHT * DeltaTime;
        ship.thing.setTexture(&shipTextureUp);
    }
    else if(Keyboard::isKeyPressed(Keyboard::S) && ship.getPosition().y < HEIGHT - ship.getSize().y){
        py += 100 * WIDTH/HEIGHT * DeltaTime;
        ship.thing.setTexture(&shipTextureDown);
    }
    else ship.thing.setTexture(&shipTextureStatic);
    if(Keyboard::isKeyPressed(Keyboard::Space) && bulletDelay.asSeconds() >= 0.2){
        cl2.restart();
        bullet b(ship.getPosition().x+ship.getSize().x, ship.getPosition().y, 20 * WIDTH/HEIGHT, 20 * WIDTH/HEIGHT);
        
        // b.b.setFillColor(Color(255, 0, 0, 120));
        b.b.setTexture(&buletTX);
        b.b.rotate(90);
        glont.push_back(b);
    }
    if(shoot.asSeconds() >= 3 && !shot){ //experimental!!
        enemyPlayerX = enemy.getPosition().x- ship.getPosition().x;
        enemyPlayerY = enemy.getPosition().y- ship.getPosition().y;
        shot = 1;
        enemyclock.restart();
    }
    else if(shoot.asSeconds() >= 3) enemyclock.restart();
}

void levelTest(){
    win.clear();
    thread inp(input);
    thread detcol([](){
        for(int i = 0; i<glont.size(); i++){
            if(colision(glont[i].bx, enemy.getPosition().x-enemy.getSize().x, glont[i].by, enemy.getPosition().y,
                        glont[i].bW, enemy.getSize().x, glont[i].bH, enemy.getSize().y)){
                enemHP -= 1;
                glont.erase(glont.begin() + i);
            }
        }
    });
    
    //calculez ungiul in care trebuie sa mearga glontul enemyului
    if(shot){
        
        enemyB.setPosition(enemyB.getPosition().x + (-enemyPlayerX/10 * WIDTH/HEIGHT * DeltaTime), 
                            enemyB.getPosition().y + (-enemyPlayerY/10 * WIDTH/HEIGHT * DeltaTime));
        RectangleShape enemyBHitbox(Vector2f(10, 10));
        
        enemyBHitbox.setPosition(enemyB.getPosition());
        enemyBHitbox.setFillColor(Color(255, 0, 0, 120));
        // win.draw(enemyBHitbox);
        
        if(colision(enemyBHitbox.getPosition().x, ship.hitbox.getPosition().x-ship.getSize().x, enemyBHitbox.getPosition().y, ship.hitbox.getPosition().y,
                    enemyBHitbox.getSize().x, ship.hitbox.getSize().x, enemyBHitbox.getSize().y, ship.hitbox.getSize().y)){
            HP -= 1;
            shot = 0;
        }
        if(enemyB.getPosition().x < 0 || enemyB.getPosition().x > WIDTH || enemyB.getPosition().y < 0 || enemyB.getPosition().y > HEIGHT){
            shot = 0;
        }

    }else enemyB.setPosition(enemy.getPosition());

    

    ship.setPosition(px, py);

    
    buletRender();
    render();
    detcol.join();
    inp.join();
}
