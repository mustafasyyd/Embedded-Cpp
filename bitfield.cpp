#include<iostream>
#include<iomanip>

struct bitfield
{
    uint16_t x:10;
    uint16_t y:9;
};

struct Ubitfield
{
    uint16_t x;
    uint8_t y:1;
};

int main()
{
    bitfield bf 
    { 1 , 5 };

    Ubitfield ubf;

    std::cout 
    << "struct \"bitfield\" Grosse:"
    << std::setw(2) 
    << sizeof(bf) << " bytes" 
    << std::endl;

    std::cout 
    << "union \"Ubitfield\" Grosse:"
    << std::setw(2) 
    << sizeof(ubf) << " bytes" 
    << std::endl;


    // std::cout
    // << "Es sieht aus, dass struct beim bitfield wie union wird\n";

    // return 0;
}


/**************** ERRORS *****************************

uint8_t y:9; // warning: width of ‘bitfield::y’ exceeds its type



/***************************************************/