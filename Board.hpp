
class Board{

    int Cells[46][25] = {};
    

public:
    bool Cells_isLiving[46][25];

    Board();
    void set_cell(int x, int y, int mode);
    void update_life();


};