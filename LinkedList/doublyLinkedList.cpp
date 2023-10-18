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
                    : data {data}
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

        bool isEmpty()
        {
            return size==0;
        }

        void insertAtStart(const T& data)
        {
            if(isEmpty())
            {
                head = new NODE<T>(data);
                tail = head;
                size++;
            }
            else
            {
                NODE<T>* newNode = new NODE<T>(data);

                newNode->next = head;
                head->prev = newNode;
                head = newNode;

                size++;
            }
        }

        void insertAtEnd(const T data)
        {
            if(isEmpty())
            {
                head = new NODE<T>(data);
                tail = head;
                size++;
            }
            else
            {
                NODE<T>* newNode = new NODE<T>(data);

                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;

                size++;
            }

        }

        void insertAtNth(const T data, int position)
        {
            if(position == 1)
            {
                insertAtStart(data);
            }
            else if(position == size+1)
            {
                insertAtEnd(data);
            }
            else
            {
                
            }
        }

        void printList()
        {
            NODE<T>* trav = head;
            int position{1};

            while(trav != nullptr)
            {
                std::cout << "Position: " << position++ << " ("<< trav->data << ") " << "\t";
                trav = trav->next;
            }
            std::cout << '\n';
        }
};


int main()
{
    doublyLinkedList<int> obj1;
    
    obj1.insertAtEnd(10);
    obj1.printList();
    
    obj1.insertAtStart(20);
    obj1.printList();

    obj1.insertAtStart(500);
    obj1.printList();

    obj1.insertAtEnd(100);
    obj1.printList();

    obj1.insertAtEnd(200);
    obj1.printList();

    return 0;
}