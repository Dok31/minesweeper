#include <iostream>

#include "Field.h"
#include "Cell.h"
#include "utils.h"

Field::Field() {
    n = DEFAULT_SIZE;
    m = DEFAULT_SIZE;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fill(i, j, Cell());
        }
    }
}

void Field::fill(int i, int j, Cell c) {
    f[i][j] = c;
}

Cell Field::get(int i, int j) const {
    return f[i][j];
}

int Field::count_mines(int i, int j) const {
    int res = 0;
    for (int k = -1; k < 2; k++) {
        for (int l = -1; l < 2; l++) {
            bool in_bounds = 0 <= i + k && i + k < n && 0 <= j + l && j + l < m;
            bool not_same = !(k == 0 && l == 0);
            bool is_bomb = f[i + k][j + l].get_type() == BOMB;
            if (in_bounds && not_same && is_bomb) {
                res++;
            }
        }
    }
    return res;
}

void Field::print() const {
    std::cout << " ";
    for (int i = 0; i < m; i++) std::cout << i;
    std::cout << " \n";

    for (int i = 0; i < n; i++) {
        std::cout << i;
        for (int j = 0; j < m; j++) {
            get(i, j).print();
        }
        std::cout << i;
        std::cout << std::endl;
    }

    std::cout << " ";
    for (int i = 0; i < m; i++) std::cout << i;
    std::cout << " \n";
}

int Field::get_mines() const {
    return all_mines;
}

void Field::gen_field(int mines) {
    int tmp = mines;
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mines > 0) {
                int type = rand() % 100 < mines * 100 / (n * m) ? BOMB : EMPTY;
                mines -= type == BOMB ? 1 : 0;
                fill(i, j, Cell(type, 0));
            } else {
                fill(i, j, Cell(EMPTY, 0));
                f[i][j] = Cell(EMPTY, 0);
            }
        }
    }
    all_mines = tmp - mines;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f[i][j].set_mines(count_mines(i, j));
        }
    }
}