#include "Board.hpp"

class Game{

private:

    Board board;
    bool isRunning = false;
    sf::Texture texture;
    sf::RectangleShape line_y; 
    sf::RectangleShape line_x;
    sf::Sprite cell_sprite;

public:

    Game();
    void run();
    void draw(sf::RenderWindow *window);
    void draw_net(sf::RenderWindow *window);
    sf::Vector2i chosen_cell(sf::RenderWindow *window);


};