#include<iostream> //add deletion and other functions

template <typename T>
class singlyLinkedList;  //forward declaration of linked list class

template <typename T>
class singlyLinkedList
{
    public:        
        template <typename U> // internal NODE class
        class NODE
        {
            private:
                T data;
                NODE<T>* next;

                friend class singlyLinkedList;

            public:
                NODE()
                    : next{nullptr}
                {
                }

                NODE(const T& data)
                    : data{data}
                    , next{nullptr}
                {
                }

        };

    private:
        int size;
        NODE<T>* head;
        NODE<T>* tail;

    public:
        singlyLinkedList()
            : size{0}
            , head{nullptr}
            , tail{nullptr}
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
                head = new NODE<T>(data);  //head is a ptr of type NODE<T> which is being assigned
                                                       //to a ptr pointing to a dynamically allocated NODE class
                tail = head;
                size++;
            }
            else
            {
                NODE<T>* newnode = new NODE<T>(data);

                newnode->next = head;
                head = newnode;

                size++;
            }
        }

        void insertAtEnd(const T& data)
        {
            if(isEmpty())
            {
                NODE<T>* newnode = new NODE<T>(data);

                head = newnode;
                tail = newnode;
                size++;
            }
            else
            {
                NODE<T>* newnode = new NODE<T>(data); 
                
                tail->next = newnode;
                tail = newnode;
                size++;
            }
        }

        void insertAtNth(const T& data, int pos)
        {
            if(isEmpty())    

            {
                NODE<T>* newnode = new NODE<T>(data);

                head = newnode;
                tail = newnode;
                size++;
            }
            else if(pos == 1)
            {
                insertAtStart(data);
            }
            else if(pos >= size+1)
            {
                insertAtEnd(data);
            } 
            else
            {
                NODE<T>* newnode = new NODE<T>(data);
                NODE<T>* trav = head;  
                
                for(int i=1; i < pos-1; i++)
                {
                    trav = trav->next;
                }

                newnode->next = trav->next;
                trav->next = newnode;
                size++;
            }
        }

        void printElements()
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
    singlyLinkedList<int> mylist;

    mylist.insertAtStart(10);
    mylist.printElements();

    mylist.insertAtStart(20);
    mylist.printElements();

    mylist.insertAtEnd(30);
    mylist.printElements();

    mylist.insertAtEnd(40);
    mylist.printElements();
    
    mylist.insertAtNth(100, 3);
    mylist.printElements();
}