#include "header.hpp"

int BitCell::compare(int key, int mask){
    return (!key  ^ this->_value) | !mask;

}

void BitCell::write(int key, int mask, int tag){
    this->_value = (tag & mask) ? key : this->_value;
}

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

void APU::compare(int * key, int * mask){
    for(int row = 0; row < APU_SIZE; row++){
        this->_tag[row] = this->_cellMatrix[row][0].compare(key[0], mask[0]);
        for(int col = 1; col < APU_SIZE; col++){
            this->_tag[row] = (this->_cellMatrix[row][col].compare(key[col], mask[col]))& this->_tag[row];
        }
    }
}

