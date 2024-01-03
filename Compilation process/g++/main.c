#include"board.h"

#define PI 3.14
#define GET_AREA(rad)  PI*(rad^2)

int main()
{
    init_board();
    double val = PI; 
    double area = GET_AREA(2);

    return 0;
}
