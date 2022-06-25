#include <iostream>
#include "Game.h"

int main() {
    Game g;
    g.init();
    g.game_start();
    g.print_field();
    while (true) {
        std::pair<int, int> p = g.get_cell();
        if (p.second == -1) {
            continue;
        }
        bool t = g.update_cell(p.first, p.second);
        if (!t){
            g.game_end();
            break;
        }
        if (g.check_win()) {
            g.game_win();
            break;
        }
        g.print_field();
    }
    return 0;
}
