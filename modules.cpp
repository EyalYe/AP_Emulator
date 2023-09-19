#include "header.hpp"

int BitCell::compare(int key, int mask){
    return (key & mask) ^ this->_value;
}