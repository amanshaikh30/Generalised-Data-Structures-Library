#include<iostream>
using namespace std;

template <class T>
struct nodeSLL
{
    T data;
    struct nodeSLL *next;
}; 

template <class T>
class SinglyLL
{
    public:
        struct nodeSLL<T> *head;
        int iCount;

        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no , int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count(); 
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct nodeSLL<T> * newn = NULL;

    newn = new nodeSLL<T>;    
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct nodeSLL<T> * newn = NULL;
    struct nodeSLL<T> * temp = NULL;

    newn = new nodeSLL<T>;   
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no , int ipos)
{
    int i = 0;
    struct nodeSLL<T> * newn = NULL;
    struct nodeSLL<T> * temp = NULL;

    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new nodeSLL<T>;
        newn->data = no;
        newn->next = NULL;

        temp = head;

        for(i =1; i< ipos -1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSLL<T> * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;

        head = head -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSLL<T> * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int ipos)
{
    int i = 0;
    struct nodeSLL<T> * temp = NULL;
    struct nodeSLL<T> * target = NULL;

    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = head;

        for(i =1; i< ipos -1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp -> next = target->next;
        delete target;

        iCount--;
    }
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSLL<T> * temp = head;

    cout<<"Elements of Singly Linear LinkedList are : \n\n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    }

    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
struct nodeDLL
{
    T data;
    struct nodeDLL *next;
    struct nodeDLL *prev;
};

template <class T>
class DoublyLL
{
    public:
        struct nodeDLL<T> *head;
        int iCount;
 
        DoublyLL();

        void InsertFirst(T no);

        void InsertLast(T no);

        void DeleteFirst();

        void DeleteLast();

        void Display();

        int Count();

        void InsertAtPos(T no, int iPos);

        void DeleteAtPos(int iPos);

};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct nodeDLL<T> *newn = NULL;

    newn = new nodeDLL<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;

        head = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct nodeDLL<T> *newn = NULL;
    struct nodeDLL<T> *temp = NULL;

    newn = new nodeDLL<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(head == NULL)
    {
        cout<<"LinkedList is Empty!\n";
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    if(head == NULL)
    {
        cout<<"LinkedList is Empty!\n";
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        struct nodeDLL<T> *temp = NULL;
        temp = head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T> :: Display()
{
    struct nodeDLL<T> *temp = NULL;
    temp = head;

    cout<<"Elements of Doubly Linear LinkedList are : \n\n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T> :: InsertAtPos(T no, int iPos)
{
    if(iPos < 1 || iPos > iCount + 1)
    {
        cout<<"Invalid Input!\n";
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeDLL<T> *temp = NULL;
        struct nodeDLL<T> *newn = NULL;
        int i = 0;

        newn = new nodeDLL<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = head;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Input!\n";
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeDLL<T> *temp = NULL;
        int i = 0;

        temp = head;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

template <class T>
struct nodeSCL
{
    T data;
    struct nodeSCL *next;
};

template <class T>
class SinglyCL
{ 
    public:
    struct nodeSCL<T> *head; 
    struct nodeSCL<T> *tail;
    int iCount;

    SinglyCL();

    void InsertFirst(T no);

    void InsertLast(T no);

    void DeleteFirst();

    void DeleteLast();

    void Display();

    int Count();

    void InsertAtPos(T no, int iPos);

    void DeleteAtPos(int iPos);
};

template <class T>
SinglyCL<T> :: SinglyCL()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T> :: InsertFirst(T no) 
{
    struct nodeSCL<T> *newn = NULL;

    newn = new nodeSCL<T>;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL && tail == NULL)
    {
        head = newn;
        tail = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    tail->next = head;

    iCount++;
}

template <class T>
void SinglyCL<T> :: InsertLast(T no)
{
    struct nodeSCL<T> *newn = NULL;

    newn = new nodeSCL<T>;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL && tail == NULL)
    {
        head = newn;
        tail = newn;
    }
    else
    {
        tail->next = newn;

        tail = newn;
    }
    tail->next = head;

    iCount++;
}

template <class T>
void SinglyCL<T> :: DeleteFirst()
{
    if(head == NULL && tail == NULL)
    {
        return;
    }
    else if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
        
    }
    else
    {
        struct nodeSCL<T> *temp = head;

        head = head->next;
        delete temp;

        tail->next = head;
    }
    iCount--;
}

template <class T>
void SinglyCL<T> :: DeleteLast()
{
    if(head == NULL && tail == NULL)
    {
        return;
    }
    else if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        struct nodeSCL<T> *temp = head;

        while(temp->next != tail)
        {
            temp = temp->next;
        }

        tail = temp;
        delete tail->next;

        tail->next = head;
    }
    iCount--;
}

template <class T>
void SinglyCL<T> :: Display()
{
    struct nodeSCL<T> *temp = NULL;

    temp = head;

    if(head == NULL && tail == NULL)
    {
        cout<<"LinkedList is Empty\n";
        return;
    }

    cout<<"Elements of Singly Circular LinkedList are : \n\n";

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }while(temp != tail->next);

    cout<<"REPEAT\n";
}

template <class T>
int SinglyCL<T> :: Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T> :: InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Input!\n";
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        int i = 0;
        struct nodeSCL<T> *temp = head;

        struct nodeSCL<T> *newn = NULL;

        newn = new nodeSCL<T>;
        newn->data = no;
        newn->next = NULL;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        tail->next = head;

        iCount++;
    }
}

template <class T>
void SinglyCL<T> :: DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Input!\n";
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        int i = 0;
        struct nodeSCL<T> *temp = head;
        struct nodeSCL<T> *target = NULL;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete target;

        tail->next = head;

        iCount--;
    }
}

template <class T>
struct nodeDCL
{
    T data;
    struct nodeDCL *next;
    struct nodeDCL *prev;
};

template <class T>
class DoublyCL
{
    public:
    struct nodeDCL<T> *head; 
    struct nodeDCL<T> *tail;
    int iCount;
 
    DoublyCL();

    void InsertFirst(T no);

    void InsertLast(T no);

    void DeleteFirst();

    void DeleteLast();

    void Display();

    int Count();

    void InsertAtPos(T no, int iPos);

    void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T> :: DoublyCL()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    struct nodeDCL<T> *newn = NULL;

    newn = new nodeDCL<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL && tail == NULL)
    {
        head = newn;
        tail = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;

        head = newn;
    }
    tail->next = head;
    head->prev = tail;

    iCount++;
}

template <class T>
void DoublyCL<T> :: InsertLast(T no)
{
    struct nodeDCL<T> *newn = NULL;

    newn = new nodeDCL<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL && tail == NULL)
    {
        head = newn;
        tail = newn;
    }
    else
    {
        tail->next = newn;
        newn->prev = tail;

        tail = newn;
    }
    tail->next = head;
    head->prev = tail;

    iCount++;
}

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
    if(head == NULL && tail == NULL)
    {
        return;
    }
    else if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
        
    }
    else
    {
        head = head->next;
        delete head->prev;

        tail->next = head;
        head->prev = tail;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if(head == NULL && tail == NULL)
    {
        return;
    }
    else if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;

        tail->next = head;
        head->prev = tail;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> :: Display()
{
    struct nodeDCL<T> *temp = NULL;

    temp = head;

    if(head == NULL && tail == NULL)
    {
        cout<<"LinkedList is Empty\n";
        return;
    }

    cout<<"Elements of Doubly Circular LinkedList are : \n\n";

    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }while(temp != tail->next);

    cout<<"REPEAT\n";
}

template <class T>
int DoublyCL<T> :: Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T> :: InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Input!\n";
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        int i = 0;
        struct nodeDCL<T> *temp = head;

        struct nodeDCL<T> *newn = NULL;

        newn = new nodeDCL<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        tail->next = head;
        head->prev = tail;

        iCount++;
    }
}

template <class T>
void DoublyCL<T> :: DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Input!\n";
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        int i = 0;
        struct nodeDCL<T> *temp = head;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        tail->next = head;
        head->prev = tail;

        iCount--;
    }
}

template <class T>
struct nodeStack
{
    T data;
    struct nodeStack *next;
};

template <class T>
class Stack
{ 
    public:
        struct nodeStack<T> *head;
        int iCount;

        Stack();

        void push(T no);
 
        T pop();

        void Display();

        int Count();
};

template <class T>
Stack<T> :: Stack()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void Stack<T> :: push(T no)
{
    struct nodeStack<T> *newn = NULL;

    newn = new nodeStack<T>;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    iCount++;
}

template <class T>
T Stack<T> :: pop()
{
    int no = -1;
    struct nodeStack<T> *temp = NULL;

    if(head == NULL)
    {
        cout<<"Stack is empty!\n";
        return -1;
    }
    else if(head->next == NULL)
    {
        no = head->data;
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;

        no = head->data;
        head = head->next;
        delete temp;
    }
    iCount--;
    return no;
}

template <class T>
void Stack<T> :: Display()
{
    struct nodeStack<T> *temp = NULL;
    temp = head;

    cout<<"Elements of Stack are : \n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |"<<"\n";
        temp = temp->next;
    }
}

template <class T>
int Stack<T> :: Count()
{
    return iCount;
}

template <class T>
struct nodeQueue
{
    T data;
    struct nodeQueue *next;
};

template <class T>
class Queue 
{
    public:
        struct nodeQueue<T> *head;
        int iCount;

        Queue();

        void enqueue(T no);

        T dequeue();

        void Display();
 
        int Count();
};

template <class T>
Queue<T> :: Queue()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void Queue<T> :: enqueue(T no)
{
    struct nodeQueue<T> *newn = NULL;
    struct nodeQueue<T> *temp = NULL;

    newn = new nodeQueue<T>;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
T Queue<T> :: dequeue()
{
    int no = -1;
    struct nodeQueue<T> *temp = NULL;

    if(head == NULL)
    {
        cout<<"Queue is empty!\n";
        return -1;
    }
    else if(head->next == NULL)
    {
        no = head->data;
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;

        no = head->data;
        head = head->next;
        delete temp;
    }
    iCount--;
    return no;
}

template <class T>
void Queue<T> :: Display()
{
    struct nodeQueue<T> *temp = NULL;
    temp = head;

    cout<<"Elements of Queue are : \n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |"<<"\n";
        temp = temp->next;
    }
}

template <class T>
int Queue<T> :: Count()
{
    return iCount;
}

int main()
{
    int iInput = 0, iInput1 = 0;
    int DataType = 0, pos = 0, iRet = 0;
    char Arr[20];

    cout<<"----------------------------------------------------------------------\n";
    cout<<"----------- Welcome to Generalised Data Structures Library -----------\n";
    cout<<"----------------------------------------------------------------------\n\n";
    cout<<"1. Singly Linear LinkedList\n";
    cout<<"2. Doubly Linear LinkedList\n";
    cout<<"3. Singly Circular LinkedList\n";
    cout<<"4. Doubly Circular LinkedList\n";
    cout<<"5. Stack\n";
    cout<<"6. Queue\n";
    cout<<"7. Exit\n\n";

    cout<<"Select an operation that you want to perform : ";
    cin>>iInput;

    cout<<"\n----------------------------------------------------------------------\n";

    if(iInput == 1)
    {
        cout<<"---------------------- Singly Linear LinkedList ----------------------\n\n";
            
        cout<<"1. int\n";
        cout<<"2. float\n";
        cout<<"3. double\n";
        cout<<"4. char\n\n";
        cout<<"Select the Data type of the Singly Linear LinkedList : ";
        cin>>DataType;

        if(DataType == 1)
        {
            SinglyLL <int>sobj;
            int no = 0;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element at first position\n";
                cout<<"2. Insert element at last position\n";
                cout<<"3. Delete element at first position\n";
                cout<<"4. Delete element at last position\n";
                cout<<"5. Insert element at given position\n";
                cout<<"6. Delete element at given position\n";
                cout<<"7. Count Nodes in the Singly Linear LinkedList\n";
                cout<<"8. Display Singly Linear LinkedList\n";
                cout<<"9. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertFirst(no);
                    cout<<"\nElement inserted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertLast(no);
                    cout<<"\nElement inserted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    sobj.DeleteFirst();
                    cout<<"Element deleted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.DeleteLast();
                    cout<<"Element deleted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    cout<<"\nEnter the Position : ";
                    cin>>pos;
                    sobj.InsertAtPos(no,pos);
                    cout<<"\nElement inserted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 6)
                {
                    cout<<"Enter the Position : ";
                    cin>>pos;
                    sobj.DeleteAtPos(pos);
                    cout<<"Element deleted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 7)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 8)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 9)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 2)
        {
            SinglyLL <float>sobj;
            float no = 0.0f;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element at first position\n";
                cout<<"2. Insert element at last position\n";
                cout<<"3. Delete element at first position\n";
                cout<<"4. Delete element at last position\n";
                cout<<"5. Insert element at given position\n";
                cout<<"6. Delete element at given position\n";
                cout<<"7. Count Nodes in the Singly Linear LinkedList\n";
                cout<<"8. Display Singly Linear LinkedList\n";
                cout<<"9. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertFirst(no);
                    cout<<"\nElement inserted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertLast(no);
                    cout<<"\nElement inserted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    sobj.DeleteFirst();
                    cout<<"Element deleted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.DeleteLast();
                    cout<<"Element deleted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    cout<<"\nEnter the Position : ";
                    cin>>pos;
                    sobj.InsertAtPos(no,pos);
                    cout<<"\nElement inserted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 6)
                {
                    cout<<"Enter the Position : ";
                    cin>>pos;
                    sobj.DeleteAtPos(pos);
                    cout<<"Element deleted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 7)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 8)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 9)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 3)
        {
            SinglyLL <double>sobj;
            double no = 0.0;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element at first position\n";
                cout<<"2. Insert element at last position\n";
                cout<<"3. Delete element at first position\n";
                cout<<"4. Delete element at last position\n";
                cout<<"5. Insert element at given position\n";
                cout<<"6. Delete element at given position\n";
                cout<<"7. Count Nodes in the Singly Linear LinkedList\n";
                cout<<"8. Display Singly Linear LinkedList\n";
                cout<<"9. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertFirst(no);
                    cout<<"\nElement inserted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertLast(no);
                    cout<<"\nElement inserted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    sobj.DeleteFirst();
                    cout<<"Element deleted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.DeleteLast();
                    cout<<"Element deleted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    cout<<"\nEnter the Position : ";
                    cin>>pos;
                    sobj.InsertAtPos(no,pos);
                    cout<<"\nElement inserted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 6)
                {
                    cout<<"Enter the Position : ";
                    cin>>pos;
                    sobj.DeleteAtPos(pos);
                    cout<<"Element deleted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 7)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 8)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 9)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 4)
        {
            SinglyLL <char>sobj;
            char no = '\0';

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element at first position\n";
                cout<<"2. Insert element at last position\n";
                cout<<"3. Delete element at first position\n";
                cout<<"4. Delete element at last position\n";
                cout<<"5. Insert element at given position\n";
                cout<<"6. Delete element at given position\n";
                cout<<"7. Count Nodes in the Singly Linear LinkedList\n";
                cout<<"8. Display Singly Linear LinkedList\n";
                cout<<"9. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertFirst(no);
                    cout<<"\nElement inserted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertLast(no);
                    cout<<"\nElement inserted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    sobj.DeleteFirst();
                    cout<<"Element deleted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.DeleteLast();
                    cout<<"Element deleted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    cout<<"\nEnter the Position : ";
                    cin>>pos;
                    sobj.InsertAtPos(no,pos);
                    cout<<"\nElement inserted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 6)
                {
                    cout<<"Enter the Position : ";
                    cin>>pos;
                    sobj.DeleteAtPos(pos);
                    cout<<"Element deleted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 7)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 8)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 9)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else
        {
            cout<<"\nInvalid Input!\n";
            return 0;
        }        
    }
    else if(iInput == 2)
    {
        cout<<"---------------------- Doubly Linear LinkedList ----------------------\n\n";
            
        cout<<"1. int\n";
        cout<<"2. float\n";
        cout<<"3. double\n";
        cout<<"4. char\n\n";
        cout<<"Select the Data type of the Doubly Linear LinkedList : ";
        cin>>DataType;

        if(DataType == 1)
        {
            DoublyLL <int>sobj;
            int no = 0;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element at first position\n";
                cout<<"2. Insert element at last position\n";
                cout<<"3. Delete element at first position\n";
                cout<<"4. Delete element at last position\n";
                cout<<"5. Insert element at given position\n";
                cout<<"6. Delete element at given position\n";
                cout<<"7. Count Nodes in the Doubly Linear LinkedList\n";
                cout<<"8. Display Doubly Linear LinkedList\n";
                cout<<"9. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertFirst(no);
                    cout<<"\nElement inserted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertLast(no);
                    cout<<"\nElement inserted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    sobj.DeleteFirst();
                    cout<<"Element deleted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.DeleteLast();
                    cout<<"Element deleted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    cout<<"\nEnter the Position : ";
                    cin>>pos;
                    sobj.InsertAtPos(no,pos);
                    cout<<"\nElement inserted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 6)
                {
                    cout<<"Enter the Position : ";
                    cin>>pos;
                    sobj.DeleteAtPos(pos);
                    cout<<"Element deleted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 7)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 8)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 9)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 2)
        {
            DoublyLL <float>sobj;
            float no = 0.0f;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element at first position\n";
                cout<<"2. Insert element at last position\n";
                cout<<"3. Delete element at first position\n";
                cout<<"4. Delete element at last position\n";
                cout<<"5. Insert element at given position\n";
                cout<<"6. Delete element at given position\n";
                cout<<"7. Count Nodes in the Doubly Linear LinkedList\n";
                cout<<"8. Display Doubly Linear LinkedList\n";
                cout<<"9. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertFirst(no);
                    cout<<"\nElement inserted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertLast(no);
                    cout<<"\nElement inserted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    sobj.DeleteFirst();
                    cout<<"Element deleted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.DeleteLast();
                    cout<<"Element deleted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    cout<<"\nEnter the Position : ";
                    cin>>pos;
                    sobj.InsertAtPos(no,pos);
                    cout<<"\nElement inserted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 6)
                {
                    cout<<"Enter the Position : ";
                    cin>>pos;
                    sobj.DeleteAtPos(pos);
                    cout<<"Element deleted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 7)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 8)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 9)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 3)
        {
            DoublyLL <double>sobj;
            double no = 0.0;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element at first position\n";
                cout<<"2. Insert element at last position\n";
                cout<<"3. Delete element at first position\n";
                cout<<"4. Delete element at last position\n";
                cout<<"5. Insert element at given position\n";
                cout<<"6. Delete element at given position\n";
                cout<<"7. Count Nodes in the Doubly Linear LinkedList\n";
                cout<<"8. Display Doubly Linear LinkedList\n";
                cout<<"9. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertFirst(no);
                    cout<<"\nElement inserted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertLast(no);
                    cout<<"\nElement inserted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    sobj.DeleteFirst();
                    cout<<"Element deleted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.DeleteLast();
                    cout<<"Element deleted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    cout<<"\nEnter the Position : ";
                    cin>>pos;
                    sobj.InsertAtPos(no,pos);
                    cout<<"\nElement inserted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 6)
                {
                    cout<<"Enter the Position : ";
                    cin>>pos;
                    sobj.DeleteAtPos(pos);
                    cout<<"Element deleted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 7)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 8)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 9)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 4)
        {
            DoublyLL <char>sobj;
            char no = '\0';

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element at first position\n";
                cout<<"2. Insert element at last position\n";
                cout<<"3. Delete element at first position\n";
                cout<<"4. Delete element at last position\n";
                cout<<"5. Insert element at given position\n";
                cout<<"6. Delete element at given position\n";
                cout<<"7. Count Nodes in the Doubly Linear LinkedList\n";
                cout<<"8. Display Doubly Linear LinkedList\n";
                cout<<"9. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertFirst(no);
                    cout<<"\nElement inserted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertLast(no);
                    cout<<"\nElement inserted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    sobj.DeleteFirst();
                    cout<<"Element deleted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.DeleteLast();
                    cout<<"Element deleted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    cout<<"\nEnter the Position : ";
                    cin>>pos;
                    sobj.InsertAtPos(no,pos);
                    cout<<"\nElement inserted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 6)
                {
                    cout<<"Enter the Position : ";
                    cin>>pos;
                    sobj.DeleteAtPos(pos);
                    cout<<"Element deleted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 7)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 8)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 9)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else
        {
            cout<<"\nInvalid Input!\n";
            return 0;
        }
    }
    else if(iInput == 3)
    {
        cout<<"---------------------- Singly Circular LinkedList ----------------------\n\n";
            
        cout<<"1. int\n";
        cout<<"2. float\n";
        cout<<"3. double\n";
        cout<<"4. char\n\n";
        cout<<"Select the Data type of the Singly Circular LinkedList : ";
        cin>>DataType;

        if(DataType == 1)
        {
            SinglyCL <int>sobj;
            int no = 0;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element at first position\n";
                cout<<"2. Insert element at last position\n";
                cout<<"3. Delete element at first position\n";
                cout<<"4. Delete element at last position\n";
                cout<<"5. Insert element at given position\n";
                cout<<"6. Delete element at given position\n";
                cout<<"7. Count Nodes in the Singly Circular LinkedList\n";
                cout<<"8. Display Singly Circular LinkedList\n";
                cout<<"9. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertFirst(no);
                    cout<<"\nElement inserted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertLast(no);
                    cout<<"\nElement inserted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    sobj.DeleteFirst();
                    cout<<"Element deleted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.DeleteLast();
                    cout<<"Element deleted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    cout<<"\nEnter the Position : ";
                    cin>>pos;
                    sobj.InsertAtPos(no,pos);
                    cout<<"\nElement inserted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 6)
                {
                    cout<<"Enter the Position : ";
                    cin>>pos;
                    sobj.DeleteAtPos(pos);
                    cout<<"Element deleted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 7)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 8)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 9)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 2)
        {
            SinglyCL <float>sobj;
            float no = 0.0f;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element at first position\n";
                cout<<"2. Insert element at last position\n";
                cout<<"3. Delete element at first position\n";
                cout<<"4. Delete element at last position\n";
                cout<<"5. Insert element at given position\n";
                cout<<"6. Delete element at given position\n";
                cout<<"7. Count Nodes in the Singly Circular LinkedList\n";
                cout<<"8. Display Singly Circular LinkedList\n";
                cout<<"9. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertFirst(no);
                    cout<<"\nElement inserted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertLast(no);
                    cout<<"\nElement inserted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    sobj.DeleteFirst();
                    cout<<"Element deleted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.DeleteLast();
                    cout<<"Element deleted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    cout<<"\nEnter the Position : ";
                    cin>>pos;
                    sobj.InsertAtPos(no,pos);
                    cout<<"\nElement inserted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 6)
                {
                    cout<<"Enter the Position : ";
                    cin>>pos;
                    sobj.DeleteAtPos(pos);
                    cout<<"Element deleted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 7)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 8)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 9)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 3)
        {
            SinglyCL <double>sobj;
            double no = 0.0;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element at first position\n";
                cout<<"2. Insert element at last position\n";
                cout<<"3. Delete element at first position\n";
                cout<<"4. Delete element at last position\n";
                cout<<"5. Insert element at given position\n";
                cout<<"6. Delete element at given position\n";
                cout<<"7. Count Nodes in the Singly Circular LinkedList\n";
                cout<<"8. Display Singly Circular LinkedList\n";
                cout<<"9. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertFirst(no);
                    cout<<"\nElement inserted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertLast(no);
                    cout<<"\nElement inserted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    sobj.DeleteFirst();
                    cout<<"Element deleted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.DeleteLast();
                    cout<<"Element deleted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    cout<<"\nEnter the Position : ";
                    cin>>pos;
                    sobj.InsertAtPos(no,pos);
                    cout<<"\nElement inserted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 6)
                {
                    cout<<"Enter the Position : ";
                    cin>>pos;
                    sobj.DeleteAtPos(pos);
                    cout<<"Element deleted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 7)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 8)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 9)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 4)
        {
            SinglyCL <char>sobj;
            char no = '\0';

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element at first position\n";
                cout<<"2. Insert element at last position\n";
                cout<<"3. Delete element at first position\n";
                cout<<"4. Delete element at last position\n";
                cout<<"5. Insert element at given position\n";
                cout<<"6. Delete element at given position\n";
                cout<<"7. Count Nodes in the Singly Circular LinkedList\n";
                cout<<"8. Display Singly Circular LinkedList\n";
                cout<<"9. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertFirst(no);
                    cout<<"\nElement inserted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertLast(no);
                    cout<<"\nElement inserted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    sobj.DeleteFirst();
                    cout<<"Element deleted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.DeleteLast();
                    cout<<"Element deleted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    cout<<"\nEnter the Position : ";
                    cin>>pos;
                    sobj.InsertAtPos(no,pos);
                    cout<<"\nElement inserted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 6)
                {
                    cout<<"Enter the Position : ";
                    cin>>pos;
                    sobj.DeleteAtPos(pos);
                    cout<<"Element deleted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 7)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 8)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 9)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else
        {
            cout<<"\nInvalid Input!\n";
            return 0;
        }
    }
    else if(iInput == 4)
    {
        cout<<"---------------------- Doubly Circular LinkedList ----------------------\n\n";
            
        cout<<"1. int\n";
        cout<<"2. float\n";
        cout<<"3. double\n";
        cout<<"4. char\n\n";
        cout<<"Select the Data type of the Doubly Circular LinkedList : ";
        cin>>DataType;

        if(DataType == 1)
        {
            DoublyCL <int>sobj;
            int no = 0;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element at first position\n";
                cout<<"2. Insert element at last position\n";
                cout<<"3. Delete element at first position\n";
                cout<<"4. Delete element at last position\n";
                cout<<"5. Insert element at given position\n";
                cout<<"6. Delete element at given position\n";
                cout<<"7. Count Nodes in the Doubly Circular LinkedList\n";
                cout<<"8. Display Doubly Circular LinkedList\n";
                cout<<"9. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertFirst(no);
                    cout<<"\nElement inserted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertLast(no);
                    cout<<"\nElement inserted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    sobj.DeleteFirst();
                    cout<<"Element deleted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.DeleteLast();
                    cout<<"Element deleted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    cout<<"\nEnter the Position : ";
                    cin>>pos;
                    sobj.InsertAtPos(no,pos);
                    cout<<"\nElement inserted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 6)
                {
                    cout<<"Enter the Position : ";
                    cin>>pos;
                    sobj.DeleteAtPos(pos);
                    cout<<"Element deleted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 7)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 8)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 9)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 2)
        {
            DoublyCL <float>sobj;
            float no = 0.0f;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element at first position\n";
                cout<<"2. Insert element at last position\n";
                cout<<"3. Delete element at first position\n";
                cout<<"4. Delete element at last position\n";
                cout<<"5. Insert element at given position\n";
                cout<<"6. Delete element at given position\n";
                cout<<"7. Count Nodes in the Doubly Circular LinkedList\n";
                cout<<"8. Display Doubly Circular LinkedList\n";
                cout<<"9. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertFirst(no);
                    cout<<"\nElement inserted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertLast(no);
                    cout<<"\nElement inserted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    sobj.DeleteFirst();
                    cout<<"Element deleted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.DeleteLast();
                    cout<<"Element deleted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    cout<<"\nEnter the Position : ";
                    cin>>pos;
                    sobj.InsertAtPos(no,pos);
                    cout<<"\nElement inserted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 6)
                {
                    cout<<"Enter the Position : ";
                    cin>>pos;
                    sobj.DeleteAtPos(pos);
                    cout<<"Element deleted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 7)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 8)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 9)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 3)
        {
            DoublyCL <double>sobj;
            double no = 0.0;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element at first position\n";
                cout<<"2. Insert element at last position\n";
                cout<<"3. Delete element at first position\n";
                cout<<"4. Delete element at last position\n";
                cout<<"5. Insert element at given position\n";
                cout<<"6. Delete element at given position\n";
                cout<<"7. Count Nodes in the Doubly Circular LinkedList\n";
                cout<<"8. Display Doubly Circular LinkedList\n";
                cout<<"9. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertFirst(no);
                    cout<<"\nElement inserted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertLast(no);
                    cout<<"\nElement inserted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    sobj.DeleteFirst();
                    cout<<"Element deleted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.DeleteLast();
                    cout<<"Element deleted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    cout<<"\nEnter the Position : ";
                    cin>>pos;
                    sobj.InsertAtPos(no,pos);
                    cout<<"\nElement inserted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 6)
                {
                    cout<<"Enter the Position : ";
                    cin>>pos;
                    sobj.DeleteAtPos(pos);
                    cout<<"Element deleted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 7)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 8)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 9)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 4)
        {
            DoublyCL <char>sobj;
            char no = '\0';

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element at first position\n";
                cout<<"2. Insert element at last position\n";
                cout<<"3. Delete element at first position\n";
                cout<<"4. Delete element at last position\n";
                cout<<"5. Insert element at given position\n";
                cout<<"6. Delete element at given position\n";
                cout<<"7. Count Nodes in the Doubly Circular LinkedList\n";
                cout<<"8. Display Doubly Circular LinkedList\n";
                cout<<"9. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertFirst(no);
                    cout<<"\nElement inserted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.InsertLast(no);
                    cout<<"\nElement inserted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    sobj.DeleteFirst();
                    cout<<"Element deleted successfully at first position!\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.DeleteLast();
                    cout<<"Element deleted successfully at last position!\n";
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    cout<<"\nEnter the Position : ";
                    cin>>pos;
                    sobj.InsertAtPos(no,pos);
                    cout<<"\nElement inserted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 6)
                {
                    cout<<"Enter the Position : ";
                    cin>>pos;
                    sobj.DeleteAtPos(pos);
                    cout<<"Element deleted successfully at given position!\n";
                    continue;
                }
                else if(iInput1 == 7)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 8)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 9)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else
        {
            cout<<"\nInvalid Input!\n";
            return 0;
        }
    }
    else if(iInput == 5)
    {
        cout<<"-------------------------------- Stack -------------------------------\n\n";
            
        cout<<"1. int\n";
        cout<<"2. float\n";
        cout<<"3. double\n";
        cout<<"4. char\n\n";
        cout<<"Select the Data type of the Stack : ";
        cin>>DataType;

        if(DataType == 1)
        {
            Stack <int>sobj;
            int no = 0, result = 0;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element in Stack\n";
                cout<<"2. Delete element in Stack\n";
                cout<<"3. Count Nodes in the Stack\n";
                cout<<"4. Display Stack\n";
                cout<<"5. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.push(no);
                    cout<<"\nElement inserted successfully in Stack!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    result = sobj.pop();
                    cout<<"Element deleted successfully in Stack is : "<<result<<"\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 2)
        {
            Stack <float>sobj;
            float no = 0.0f, result = 0.0f;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element in Stack\n";
                cout<<"2. Delete element in Stack\n";
                cout<<"3. Count Nodes in the Stack\n";
                cout<<"4. Display Stack\n";
                cout<<"5. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.push(no);
                    cout<<"\nElement inserted successfully in Stack!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    result = sobj.pop();
                    cout<<"Element deleted successfully in Stack is : "<<result<<"\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 3)
        {
            Stack <double>sobj;
            double no = 0.0, result = 0.0;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element in Stack\n";
                cout<<"2. Delete element in Stack\n";
                cout<<"3. Count Nodes in the Stack\n";
                cout<<"4. Display Stack\n";
                cout<<"5. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.push(no);
                    cout<<"\nElement inserted successfully in Stack!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    result = sobj.pop();
                    cout<<"Element deleted successfully in Stack is : "<<result<<"\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 4)
        {
            Stack <char>sobj;
            char no = '\0', result = '\0';

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element in Stack\n";
                cout<<"2. Delete element in Stack\n";
                cout<<"3. Count Nodes in the Stack\n";
                cout<<"4. Display Stack\n";
                cout<<"5. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.push(no);
                    cout<<"\nElement inserted successfully in Stack!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    result = sobj.pop();
                    cout<<"\nElement deleted from Stack is : "<<result<<"\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else
        {
            cout<<"\nInvalid Input!\n";
            return 0;
        }
    }
    else if(iInput == 6)
    {
        cout<<"-------------------------------- Queue -------------------------------\n\n";
            
        cout<<"1. int\n";
        cout<<"2. float\n";
        cout<<"3. double\n";
        cout<<"4. char\n\n";
        cout<<"Select the Data type of the Queue : ";
        cin>>DataType;

        if(DataType == 1)
        {
            Queue <int>sobj;
            int no = 0, result = 0;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element in Queue\n";
                cout<<"2. Delete element in Queue\n";
                cout<<"3. Count Nodes in the Queue\n";
                cout<<"4. Display Queue\n";
                cout<<"5. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.enqueue(no);
                    cout<<"\nElement inserted successfully in Queue!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    result = sobj.dequeue();
                    cout<<"Element deleted successfully in Queue is : "<<result<<"\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 2)
        {
            Queue <float>sobj;
            float no = 0.0f, result = 0.0f;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element in Queue\n";
                cout<<"2. Delete element in Queue\n";
                cout<<"3. Count Nodes in the Queue\n";
                cout<<"4. Display Queue\n";
                cout<<"5. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.enqueue(no);
                    cout<<"\nElement inserted successfully in Queue!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    result = sobj.dequeue();
                    cout<<"Element deleted successfully in Queue is : "<<result<<"\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 3)
        {
            Queue <double>sobj;
            double no = 0.0, result = 0.0;

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element in Queue\n";
                cout<<"2. Delete element in Queue\n";
                cout<<"3. Count Nodes in the Queue\n";
                cout<<"4. Display Queue\n";
                cout<<"5. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.enqueue(no);
                    cout<<"\nElement inserted successfully in Queue!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    result = sobj.dequeue();
                    cout<<"Element deleted successfully in Queue is : "<<result<<"\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else if(DataType == 4)
        {
            Queue <char>sobj;
            char no = '\0', result = '\0';

            while(1)
            {
                cout<<"\n----------------------------------------------------------------------\n\n";
                cout<<"1. Insert element in Queue\n";
                cout<<"2. Delete element in Queue\n";
                cout<<"3. Count Nodes in the Queue\n";
                cout<<"4. Display Queue\n";
                cout<<"5. Exit\n\n";

                cout<<"Select an operation that you want to perform : ";
                cin>>iInput1;

                cout<<"----------------------------------------------------------------------\n\n";

                if(iInput1 == 1)
                {
                    cout<<"Enter the Element : ";
                    cin>>no;
                    sobj.enqueue(no);
                    cout<<"\nElement inserted successfully in Queue!\n";
                    continue;
                }
                else if(iInput1 == 2)
                {
                    result = sobj.dequeue();
                    cout<<"\nElement deleted from Queue is : "<<result<<"\n";
                    continue;
                }
                else if(iInput1 == 3)
                {
                    iRet = sobj.Count();
                    cout<<"Number of elements are : "<<iRet<<"\n";
                    continue;
                }
                else if(iInput1 == 4)
                {
                    sobj.Display();
                    continue;
                }
                else if(iInput1 == 5)
                {
                    cout<<"Thank you for using Generalised Data Structures Library...\n";
                    break;
                }
                else
                {
                    cout<<"\nInvalid Input!\n";
                    break;
                }
            }
        }
        else
        {
            cout<<"\nInvalid Input!\n";
            return 0;
        }
    }
    else if(iInput == 7)
    {
        cout<<"Thank you for using Generalised Data Structures Library...\n";
    }
    else
    {
        cout<<"\nInvalid Input!\n";
    }

    return 0;
}