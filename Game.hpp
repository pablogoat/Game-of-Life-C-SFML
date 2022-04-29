#include "Board.hpp"

class Game{

private:

    Board board;
    bool isRunning = false;
    sf::Texture texture;
    sf::Texture texture2;
    sf::Sprite cell_sprite;
    sf::Sprite net_sprite;

public:

    Game();
    void run();
    void draw(sf::RenderWindow *window);
    sf::Vector2i chosen_cell(sf::RenderWindow *window);


};