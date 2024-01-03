#include"app.h"
#include"lib.h"

#define CONST  3

extern int sound_length;

void show();
int get_data(int param);

int rect{8} , oval;

int main()
{
    int dia {22};
    int area = get_data(dia);
    play_sound();
    return 0;
}

int get_data(int param)
{
    param *=CONST;
    return param;
}