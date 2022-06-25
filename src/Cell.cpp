#include <iostream>

#include "Cell.h"

Cell::Cell() {
    type = EMPTY;
    mines = 0;
}

Cell::Cell(int _type, int _mines) {
    type = _type;
    mines = _mines;
}

int Cell::get_type() const {
    return type;
}

int Cell::get_mines() const {
    return mines;
}

void Cell::set_mines(int _mines) {
    mines = _mines;
}

void Cell::set_is_print() {
    is_print = true;
}

void Cell::print() const {
    if (!is_print) {
        std::cout << "#";
    } else {
        if (type == EMPTY) {
            if (mines) {
                std::cout << mines;
            } else {
                std::cout << ".";
            }
        } else if (type == BOMB) {
            std::cout << "*";
        }
    }
}

