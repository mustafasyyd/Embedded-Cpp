# 1 "app.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "app.c"

double get_data(double param);


int main()
{
    double dia = 22.6;
    double area = get_data(dia);

    return 0;
}

double get_data(double param)
{
    param *=3.14;
    return param;
}
