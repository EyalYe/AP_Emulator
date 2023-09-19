/******
    Created by Eyal Yemini and Harel Markel.
*****/


#include "header.hpp"
#define APU_SIZE 4
int main(){
    APU apu;
    int row[APU_SIZE] = {1, 0, 1, 1};
    apu.changeRowValue(2, row);
    int mask[APU_SIZE] = {1, 1, 1, 1};
    apu.compare(row, mask);
    apu.print();
    std::cout << std::endl;
    std::cout << std::endl;
    int mask2[APU_SIZE] = {1, 0, 1, 0};
    int key[APU_SIZE] = {1, 1, 1, 0};
    apu.write(key, mask2);
    apu.print();


    return 0;
}