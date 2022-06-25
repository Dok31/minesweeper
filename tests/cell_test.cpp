#include "Cell.h"
#include "doctest.h"

TEST_CASE("Check empty constructor") {
    Cell c;

    CHECK(c.get_mines() == 0);
    CHECK(c.get_type() == 0);
}

TEST_CASE("Check non empty constructor") {
    Cell c(BOMB, 0);
    CHECK(c.get_type() == BOMB);
    CHECK(c.get_mines() == 0);

    c = Cell(EMPTY, 10);
    CHECK(c.get_type() == EMPTY);
    CHECK(c.get_mines() == 10);
}

TEST_CASE("Check set_mines ") {
    Cell c(BOMB, 0);
    CHECK(c.get_mines() == 0);
    c.set_mines(5);
    CHECK(c.get_mines() == 5);
}






