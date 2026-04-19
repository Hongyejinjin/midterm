#include <iostream>

int main()
{
    for (int i = 0; i < 3; i++)
        std::cout << i << std::endl;
    
int x2 = 3;
int y2 = ++x2;
int z2 = x2;

std::cout << x2 << y2 << z2 << std::endl;
int out{};
int in{};
for (out = 0; out < 5; out++)
    for (in = 7; in > 2; in--)
        std::cout << out << " " << in << std::endl;
return 0;
}

