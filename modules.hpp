#include "header.hpp"

/**
 * @brief Definition of the BitCell class.
 *
 * The BitCell class represents a single bit cell that can store a bit value.
 * It provides functions for comparison and conditional writing of values.
 */
class BitCell{
    private:
        int _value;
    public:
        BitCell(int value = 0){this->_value = value;}
        int compare(int key, int mask);
        void write(int key, int mask, int tag);
        void print(){std::cout << this->_value << " ";}
        void changeValue(int value){this->_value = value;}
};


/**
 * @brief Definition of the APU class.
 *
 * The APU (Associative Processing Unit) class represents a matrix of BitCells
 * and provides functions for writing, comparing, and printing the matrix.
 */
class APU{
    private:
        BitCell _cellMatrix[APU_SIZE][APU_SIZE];
        int _tag[APU_SIZE];
    public:
        APU(){for(int i = 0; i < APU_SIZE; i++){this->_tag[i] = 0;}}
        void write(int * key, int * mask);
        void print();
        void compare(int * key, int * mask);
        void printCell(int i, int j){this->_cellMatrix[i][j].print(); std::cout << std::endl;}
        void changeRowValue(int row, int * value){for(int i = 0; i < APU_SIZE; i++){this->_cellMatrix[row][i].changeValue(value[i]);}}
};