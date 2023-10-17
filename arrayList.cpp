#include<iostream>
using namespace std;

void insertFront(int array[], int data, int currentSize)
{
    array[currentSize] = data;
    currentSize++;
}
int main()
{
    int array[5]{};
    int currentSize{0};
    int MaxSize{0};

    for(int i=0; i<5; i++)  
    {
        cout << array[i] << '\n';
    }
    cout << "-------END OF LIST--------" << endl;

    insertFront(array, 5, currentSize);

    for(int i=0; i<5; i++)
    {
        cout << array[i] << '\n';
    }
    cout << "-------END OF LIST--------" << endl;

    insertFront(array, 5, currentSize);

    for(int i=0; i<5; i++)
    {
        cout << array[i] << '\n';
    }
    cout << "-------END OF LIST--------" << endl;

    insertFront(array, 5, currentSize);

    for(int i=0; i<5; i++)
    {
        cout << array[i] << '\n';
    }
    cout << "-------END OF LIST--------" << endl;
    
}