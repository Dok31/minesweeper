#include "doctest.h"
#include "Game.h"

TEST_CASE("checking that check_win works correctly") {
    Game g;
    CHECK(!g.check_win());
}