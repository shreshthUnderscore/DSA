#include<iostream>

template <typename T>
class dynamicArray
{
    private:
        T* array;  
        int length;
        int capacity;
    
    public:

        dynamicArray()
        {
            array = new T[0];
            length = 0;
            capacity = 0;
        }

        dynamicArray(int length)
        {
            array = new T[length];
            this->length = length;
            capacity = 0;
        }

        dynamicArray(const dynamicArray& obj)
        {
            array = new T[obj.length];

            for(int i{0}; i < obj.length; i++)
            {
                array[i] = obj.array[i];
            }
            this->length = obj.length;
            this->capacity = obj.capacity;
        }

        ~dynamicArray()
        {
            delete[] array;
        }

        bool isEmpty()
        {
            return (capacity != length);
        }

        bool isFull()
        {
            return (capacity == length);
        }

        void grow()
        {
            T* temp = new T[2*length];

            for(int i=0; i < length; i++)
            {
                temp[i] = array[i];
            }

            delete[] array;
            array = temp;
            length *= 2;
        }

        void insert(int data, int index=0)
        {
            if(isFull())
            {
                grow();
            }
            
            for(int i=capacity-1; i >= index; i--)
            {
                array[i+1] = array[i];
            }

            array[index] = data;
            capacity++;
        }

        void remove(int index = 0)
        {
            if(isEmpty())
            {
                return;
            }

            for(int i=index; i<= (capacity-1) ; i++)
            {
                array[i] = array[i+1];
            }

            array[capacity-1] = 0;

            capacity--;
        }

        T get(int index=0)
        {
            if(index <= capacity-1)
            {
                return array[index];
            }

            return -1;
        }

        void printLength()
        {
            std::cout << "Length: " << length << '\n';
            std::cout << "\n";
        }

        void printCapacity()
        {
            std::cout << "Capacity: " << capacity << "\n";
            std::cout << "\n";
        }
        
        void printarray()
        {
            for(int i=0; i < length; i++)
            {
                std::cout << "Index " << i << ": " << array[i] << std::endl;
            }
            std::cout << "\n";
        } 
};


int main()
{

    dynamicArray <int> obj(6);
    
    return 0;
}