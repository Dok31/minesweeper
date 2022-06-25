#ifndef FIELD_H
#define FIELD_H

#include <cstdlib>
#include "Cell.h"
#include "utils.h"


/**
 * @brief The class of a whole field of minesweeper
 */
class Field {
private:
    int all_mines = 0; /*!< Number of all mines on a field */
    int n; /*!< X Size of a field */
    int m; /*!< Y Size of a field */
    Cell f[DEFAULT_SIZE][DEFAULT_SIZE]; /*!< 2D Array of a field */

public:
    //! Constructor that creates an field of DEFAULT_SIZE size with empty cells
    /*!
     * @return Field
     */
    Field();

    //! Set cell i,j to c
    /*!
     * @param i X-coordinate
     * @param j Y-coordinate
     * @param c New cell
     */
    void fill(int i, int j, Cell c);

    //! Get number of mines on a field
    /*!
     * @return number of mines
     */
    [[nodiscard]] int get_mines() const;

    //! Get cell on i,j coordinate
    /*!
     * @param i X-coordinate
     * @param j Y-coordinate
     * @return Cell on i,j coordinate
     */
    [[nodiscard]] Cell get(int i, int j) const;

    //! Count mines around i,j coordinate
    /*!
     * @param i X-coordinate
     * @param j Y-coordinate
     * @return number of mines around i,j coordinate
     */
    [[nodiscard]] int count_mines(int i, int j) const;

    //! Print whole field
    /*!
     * @return
     */
    void print() const;

    //! Fills the field with mines and sets the number of mines around it for each cell
    /*!
     * @param mines The number of mines will be <= than this value
     */
    void gen_field(int mines);
};

#endif //FIELD_H
