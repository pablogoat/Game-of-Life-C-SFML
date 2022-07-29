#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <iostream>

#define FrameLimit 10
#define Texture_size 40
#define def_x 1880
#define def_y 980
#define Toolbar_x 40

Game::Game(){
    texture.loadFromFile("assets/cell.png");
    cell_sprite.setTexture(texture, false);
    texture2.setRepeated(true);
    texture2.loadFromFile("assets/net.png");

    net_sprite.setTextureRect({0, 0, def_x - Toolbar_x, def_y});
    net_sprite.setTexture(texture2, false);
    net_sprite.setPosition(0, 0);
    
}

void Game::run(){

    sf::RenderWindow window( sf::VideoMode( def_x, def_y), "LifeGame");
    window.setFramerateLimit(FrameLimit);

    while(window.isOpen()){

        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left)
                    if(!isRunning)
                        board.set_cell( chosen_cell(&window).x, chosen_cell(&window).y, 1);

                if(event.mouseButton.button == sf::Mouse::Right)
                    if(!isRunning)
                        board.set_cell( chosen_cell(&window).x, chosen_cell(&window).y, -1);
            }
                
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
                isRunning = true;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
                isRunning = false;
            }
                
        }

        draw(&window);

        if(isRunning){
            board.update_life();
            //sleep(sf::milliseconds(50));
            //std::cout << chosen_cell(&window).x << "," << chosen_cell(&window).y << '\n';
        }
        
        window.display();
    }

}

sf::Vector2i Game::chosen_cell(sf::RenderWindow *window){

    int x = sf::Mouse::getPosition(*window).x,
        y = sf::Mouse::getPosition(*window).y;

    return sf::Vector2i(
        (x - (x % Texture_size))/Texture_size,
        (y - (y % Texture_size))/Texture_size
    );
     
}

void Game::draw(sf::RenderWindow *window){

    if(isRunning){
        window -> clear(sf::Color(0,0,0));
    }
    else{
        window -> clear(sf::Color(0,0,0));
        window -> draw(net_sprite);
    }

    for(int j = 0; j < 25; j++){
        for(int i = 0; i < 46; i++){
            if(board.Cells_isLiving[i][j]){
                cell_sprite.setPosition(i * Texture_size, j * Texture_size);
                window -> draw(cell_sprite);
            }
        }
    }

}