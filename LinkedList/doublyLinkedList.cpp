#include<iostream>

template <typename T>
class doublyLinkedList;

template <typename T>
class doublyLinkedList
{
    public:
        template <typename U>
        class NODE
        {
            private:
                T data;
                NODE<T>* prev;
                NODE<T>* next;

                friend class doublyLinkedList;

            public:
                NODE()
                    : prev{nullptr}
                    , next{nullptr}
                {
                }

                NODE(const T& data)
                    : data {data},
                    , prev {nullptr}
                    , next {nullptr}
                {
                }
        };

    private:
        NODE<T>* head;
        NODE<T>* tail;
        int size;
    
    public:
        doublyLinkedList()
            : head {nullptr}
            , tail {nullptr}
            , size {0}
        {
        }

};