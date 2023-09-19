#include "header.hpp"

int BitCell::compare(int key, int mask){
    return (key & mask) xor this->_value;
}