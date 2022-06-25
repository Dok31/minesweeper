#ifndef GAME_H
#define GAME_H

#include <utility>
#include "Field.h"
#include "Cell.h"
#include "utils.h"

/**
 * @brief The class of a game
 */
class Game {
private:
    Field gen_field; /*!< Generated field hidden from user */
    Field user_field; /*!< Field that user see */
    bool checked[DEFAULT_SIZE][DEFAULT_SIZE]{};  /*!< 2D Array showing which cells have already been shown to the user */
public:

    //! A function that performs init manipulations
    /*!
     * @return
     */
    void init();

    //! Getting coordinates from stdin
    /*!
     * @return pair of x and y coordinate
     */
    static std::pair<int, int> get_cell();

    //! Check whether user win or not
    /*!
     * @return true if win and false if not
     */
    [[nodiscard]] bool check_win() const;

    //! Opens cell i,j if it was hidden or returns false if there is a bomb in this cell
    /*!
     * @param i X-coordinate
     * @param j Y-coordinate
     * @return false if bomb on i,j coordinate
     */
    bool update_cell(int i, int j);

    //! Print user field
    /*!
     * @return
     */
    void print_field() const;

    //! Print greeting message
    /*!
     * @return
     */
    void game_start() const;

    //! Print win message
    /*!
     * @return
     */
    void game_win() const;

    //! Print game over message
    /*!
     * @return
     */
    void game_end() const;
};

#endif //GAME_H
