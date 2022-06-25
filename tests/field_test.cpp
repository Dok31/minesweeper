#include "Field.h"
#include "Cell.h"
#include "doctest.h"
#include "utils.h"

TEST_CASE("Check Field constructor") {
    Field f;
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        for (int j = 0; j < DEFAULT_SIZE; j++) {
            CHECK(f.get(i, j).get_type() == EMPTY);
            CHECK(f.get(i, j).get_mines() == 0);
        }
    }
}

TEST_CASE("Check that mines around the cell are counted correctly") {
    Field f;
    int d = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j< 2; j++) {
            if (!(i == 0 && j == 0)) {
                f.fill(1 + i, 1 + j, Cell(BOMB, 0));
                CHECK(f.count_mines(1, 1) == (i + 1) * 3 + j + 2 + d);
            } else {
                d = -1;
            }
        }
    }
}

TEST_CASE("Check that count_mines don't count far mines") {
    Field f;
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        for (int j = 0; j < DEFAULT_SIZE; j++) {
            f.fill(i, j, Cell(BOMB, 0));
        }
    }
    f.fill(DEFAULT_SIZE / 2, DEFAULT_SIZE / 2, Cell());
    CHECK(f.count_mines(DEFAULT_SIZE / 2, DEFAULT_SIZE / 2) == 8);
}

TEST_CASE("Check that there are less mines in the field than MAX_MINES after gen_field") {
    Field f;
    f.gen_field(MAX_MINES);

    int c = 0;
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        for (int j = 0; j < DEFAULT_SIZE; j++) {
            c += (f.get(i, j).get_type() == BOMB ? 1 : 0);
        }
    }
    CHECK(c <= MAX_MINES);
}


