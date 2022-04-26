#include "Board.hpp"
#include <iostream>

Board::Board(){
    for(int j = 0; j < 25; j++){
        for(int i = 0; i < 46; i++){
            Cells_isLiving[i][j] = false;
        }
    }

    for(int j = 0; j < 25; j++){
        for(int i = 0; i < 46; i++){
            Cells[i][j] = 0;
        }
    }

    set_cell(5,4,1);
    set_cell(5,5,1);
    set_cell(5,6,1);
}

void Board::set_cell(int x, int y, int mode){
    

    for(int j = y - 1; j <= y + 1; j++){
        for(int i = x - 1; i <= x + 1; i++){

            if(i > 0 && i < 46 && j > 0 && j < 25)
                if(i != x || j != y){
                    Cells[i][j] += mode;
                    if(Cells[i][j] < 0)
                        Cells[i][j] = 0;
                }

        }
    }

    if(mode == 1)
        Cells_isLiving[x][y] = true;
    else
        Cells_isLiving[x][y] = false;

}

void Board::update_life(){

    for(int j = 0; j < 25; j++){
        for(int i = 0; i < 46; i++){
            if(Cells_isLiving[i][j] == false){
                if(Cells[i][j] == 3) Cells_isLiving[i][j] = true;
            }   
            else
                if(Cells[i][j] != 2 && Cells[i][j] != 3) Cells_isLiving[i][j] = false;
        }
    }

    for(int j = 0; j < 25; j++){
        for(int i = 0; i < 46; i++){
            Cells[i][j] = 0;
        }
    }


    for(int j = 0; j < 25; j++){
        for(int i = 0; i < 46; i++){
            if(Cells_isLiving[i][j] == true)
                set_cell(i,j, 1);
        }
    }


}