#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <iostream>

#define FrameLimit 10
#define Texture_size 40
#define def_x 1840
#define def_y 980

Game::Game(){
    texture.loadFromFile("assets/cell.png");
    cell_sprite.setTexture(texture, false);

    line_x.setSize(sf::Vector2f(def_x,3));
    line_x.setOutlineColor(sf::Color::Blue);
    line_y.setSize(sf::Vector2f(def_y,3));
    line_y.setOutlineColor(sf::Color::Blue);

    line_y.rotate(90);
    
}

void Game::run(){

    sf::RenderWindow window( sf::VideoMode( def_x, def_y), "LifeGame");
    window.setFramerateLimit(FrameLimit);

    draw_net(&window);

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

    window -> clear(sf::Color(0,0,0));

    for(int j = 0; j < 25; j++){
        for(int i = 0; i < 46; i++){
            if(board.Cells_isLiving[i][j]){
                cell_sprite.setPosition(i * Texture_size, j * Texture_size);
                window -> draw(cell_sprite);
            }
        }
    }

}

void Game::draw_net(sf::RenderWindow *window){

    for(int i = 0; i <= def_x; i += 40){
        line_x.move(def_x,0);
        window -> draw(line_x);
    }

    for(int i = 0; i <= def_y; i += 40){
        line_y.setPosition(0,i);
        line_x.move(0,def_y);
        window -> draw(line_y);
    }
}