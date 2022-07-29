#include "Board.hpp"

class Game{

private:

    Board board;
    bool isRunning = false;
    sf::Texture texture;
    sf::Texture texture2;
    sf::Texture run_texture;
    sf::Sprite cell_sprite;
    sf::Sprite net_sprite;
    sf::Sprite run_sprite;

public:

    Game();
    void run();
    void draw(sf::RenderWindow *window);
    sf::Vector2i chosen_cell(sf::RenderWindow *window);


};