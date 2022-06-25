#include "Game.h"
#include "Field.h"
#include "Cell.h"

#include <utility>
#include <iostream>

void Game::init() {
    gen_field = Field();
    gen_field.gen_field(MAX_MINES);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            Cell c = gen_field.get(i, j);
            c.set_is_print();
            gen_field.fill(i, j, c);
        }
    }

    user_field = Field();
    for (auto &i: checked) {
        for (bool &j: i) {
            j = false;
        }
    }
}

std::pair<int, int> Game::get_cell() {
    std::string s;
    std::getline(std::cin, s);
    std::string s1[2];
    int ind = 0;

    std::pair<int, int> p;
    p.first = -1;
    p.second = -1;
    for (char i: s) {
        if (i == ' ') {
            ind++;
            if (ind > 1) {
                return p;
            }
        } else if ('0' <= i && i <= '9') {
            s1[ind] += i;
        } else {
            return p;
        }

    }
    if (s1[1].empty()) {
        return p;
    }
    p.first = std::stoi(s1[0]);
    p.second = std::stoi(s1[1]);
    if (p.first < 0 || p.first >= DEFAULT_SIZE || p.second < 0 || p.second >= DEFAULT_SIZE) {
        p.second = -1;
    }
    return p;
}

bool Game::check_win() const {
    int ans = 0;
    for (auto i: checked)
        for (int j = 0; j < DEFAULT_SIZE; j++)
            if (i[j])
                ans++;

    return gen_field.get_mines() == (DEFAULT_SIZE * DEFAULT_SIZE - ans);
}

bool Game::update_cell(int i, int j) {
    if (checked[i][j]) return true;
    if (gen_field.get(i, j).get_type() == BOMB) {
        return false;
    }
    checked[i][j] = true;
    Cell c = Cell(EMPTY, gen_field.get(i, j).get_mines());
    c.set_is_print();
    user_field.fill(i, j, c);

    if (gen_field.get(i, j).get_mines() == 0) {
        for (int k = -1; k < 2; k++) {
            for (int l = -1; l < 2; l++) {
                bool is_not_same = !(k == 0 && l == 0);
                bool is_in_bounds = 0 <= i + k && i + k < DEFAULT_SIZE && 0 <= j + l && j + l < DEFAULT_SIZE;
                bool is_clear = gen_field.get(i + k, j + l).get_mines() == 0;
                bool is_not_checked = !checked[i + k][j + l];
                if (is_not_same && is_in_bounds && is_clear && is_not_checked) {
                    update_cell(i + k, j + l);

                }
                if (is_not_same && is_in_bounds && !is_clear && is_not_checked) {
                    Cell nc = Cell(EMPTY, gen_field.get(i + k, j + l).get_mines());
                    nc.set_is_print();
                    checked[i + k][j + l] = true;
                    user_field.fill(i + k, j + l, nc);
                }
            }
        }
    }
    return true;
}

void Game::print_field() const {
    user_field.print();
}

void Game::game_start() const {
    std::cout << GREETING_MESSAGE;
}

void Game::game_win() const {
    std::cout << WIN_MESSAGE;
}

void Game::game_end() const {
    std::cout << LOSE_MESSAGE;
}
