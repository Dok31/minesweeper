#ifndef CELL_H
#define CELL_H

#define EMPTY 0
#define BOMB 1

/**
 * @brief The class of a single cell on the field
 */
class Cell {
private:
    int type; /*!< One of two types of cells: empty or with a bomb */
    int mines; /*!< Number of mines around this cell */
    bool is_print = false; /*!< Whether to display the contents of this cell or not */

public:

    //! Constructor that creates an empty cell with 0 mines
    /*!
     * @return Cell
     */
    Cell();

    //! Constructor that creates an _type cell with _mines mines
    /*!
     * @param _type type of created cell
     * @param _mines number of mines around this cell
     * @return Cell
     */
    explicit Cell(int _type, int _mines);

    //! Get type of that cell
    /*!
     * @return type of that cell
     */
    [[nodiscard]] int get_type() const;

    //! Get number of mines around that cell
    /*!
     * @return number of mines around that cell
     */
    [[nodiscard]] int get_mines() const;

    //! Change is_print to true
    /*!
     * @return
     */
    void set_is_print();

    //! Set number of mines to _mines
    /*!
     * @param _mines changed number of mines
     */
    void set_mines(int _mines);

    //! Print that cell to console
    /*!
     * @return
     */
    void print() const;
};

#endif //CELL_H
