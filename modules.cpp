#include "header.hpp"

/**
 * @brief Compare the BitCell value with a key using a mask.
 *
 * This function compares the value stored in the BitCell with a key while
 * applying a mask. It returns the result of the comparison.
 *
 * @param key The key to compare with the BitCell value.
 * @param mask The mask to apply to the comparison.
 * @return The result of the comparison.
 */
int BitCell::compare(int key, int mask){
    // this is the implantation according to our understanding of the operation
    // and not according to the paper (fig 4 in https://webee.technion.ac.il/~ran/papers/YavitsAssociative.pdf) ((!key & mask)^_value)
    return (!key  ^ this->_value) | !mask;

}

/**
 * @brief Write a value to the BitCell based on a key, mask, and tag.
 *
 * This function conditionally updates the value stored in the BitCell based
 * on a provided key, mask, and tag. If the tag and mask conditions are met,
 * the value is updated with the key.
 *
 * @param key The key to write to the BitCell if conditions are met.
 * @param mask The mask used to determine whether to update the BitCell.
 * @param tag The tag value used for conditional writing.
 */
void BitCell::write(int key, int mask, int tag){
    this->_value = (tag & mask) ? key : this->_value;
}

/**
 * @brief Compare APU values with key and mask arrays and update tags.
 *
 * This function compares the values stored in the APU matrix with provided
 * key and mask arrays. It updates tag values based on the comparison results.
 *
 * @param key An array of key values to use for comparison.
 * @param mask An array of mask values to apply to the comparison.
 */
void APU::compare(int * key, int * mask){
    for(int row = 0; row < APU_SIZE; row++){
        this->_tag[row] = this->_cellMatrix[row][0].compare(key[0], mask[0]);
        for(int col = 1; col < APU_SIZE; col++){
            this->_tag[row] = (this->_cellMatrix[row][col].compare(key[col], mask[col]))& this->_tag[row];
        }
    }
}

/**
 * @brief Write values to the APU based on key and mask arrays.
 *
 * This function writes values to the BitCells in the APU matrix based on
 * provided key and mask arrays. It uses the tag values to determine whether
 * to update the BitCell values.
 *
 * @param key An array of key values to be written to the APU.
 * @param mask An array of mask values to be used for conditional writing.
 */
void APU::write(int * key, int * mask){
    for(int row = 0; row < APU_SIZE; row++){
        for(int col = 0; col < APU_SIZE; col++){
            this->_cellMatrix[row][col].write(key[col], mask[col], this->_tag[row]);
        }
    }
}

void APU::print(){
    for(int i = 0; i < APU_SIZE; i++){
        for(int j = 0; j < APU_SIZE; j++){
            this->_cellMatrix[i][j].print();
        }
        std::cout << std::endl;
    }
}



