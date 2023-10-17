#include<iostream>

int main()
{
    int pos{3};

    while(--pos)
    {
        std::cout << "printing" << std::endl;
    }

    pos = 3;

    while(pos--)
    {
        std::cout << "lmaoing" << std::endl;
    }
}