//single linear 

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
                      
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyLL
{
    private:
        PNODE First;
        int iCount;
    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(int No);
        void InsertLast(int No);
        void InsertAtPos(int No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};



SinglyLL::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

void SinglyLL::Display()
{
    PNODE temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

int SinglyLL::Count()
{
    return iCount;
}

void SinglyLL::InsertFirst(int No)
{
    PNODE newn = NULL;

    newn = new NODE;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

void SinglyLL::InsertLast(int No)
{
    PNODE newn = NULL;
    PNODE temp = First;

    newn = new NODE;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

void SinglyLL::InsertAtPos(int No, int iPos)
{
    PNODE newn = NULL;
    int i = 0;
    PNODE temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new NODE;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

void SinglyLL::DeleteFirst()
{
    PNODE temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

void SinglyLL::DeleteLast()
{
    PNODE temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

void SinglyLL::DeleteAtPos(int iPos)
{
    int i = 0;
    PNODE temp1;
    PNODE temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}
int main()
{
    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    obj.InsertAtPos(105,5);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    obj.DeleteAtPos(5);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    return 0;
}   
//singly circular

#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyCL
{
public:
    PNODE First;
    int iCount;

    SinglyCL()
    {
        First = NULL;
        iCount = 0;
    }

    void InsertFirst(int No);
    void InsertLast(int No);
    void InsertAtPos(int iPos, int No);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
    int Count();
};

void SinglyCL::InsertFirst(int No)
{
    PNODE newn = new NODE;
    newn->data = No;
    newn->next = NULL;

    if (First == NULL) // Empty list
    {
        First = newn;
        newn->next = First;
    }
    else // List contains elements
    {
        PNODE temp = First;
        while (temp->next != First)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->next = First;
        First = newn;
    }
    iCount++;
}

void SinglyCL::InsertLast(int No)
{
    PNODE newn = new NODE;
    newn->data = No;
    newn->next = NULL;

    if (First == NULL) // Empty list
    {
        First = newn;
        newn->next = First;
    }
    else // List contains elements
    {
        PNODE temp = First;
        while (temp->next != First)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->next = First;
    }
    iCount++;
}

void SinglyCL::InsertAtPos(int iPos, int No)
{
    if (iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid Position!" << endl;
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        PNODE newn = new NODE;
        newn->data = No;
        newn->next = NULL;

        PNODE temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

void SinglyCL::DeleteFirst()
{
    if (First == NULL)
    {
        return;
    }
    else if (First->next == First)
    {
        delete First;
        First = NULL;
    }
    else
    {
        PNODE temp = First;
        while (temp->next != First)
        {
            temp = temp->next;
        }
        temp->next = First->next;
        delete First;
        First = temp->next;
    }
    iCount--;
}

void SinglyCL::DeleteLast()
{
    if (First == NULL)
    {
        return;
    }
    else if (First->next == First)
    {
        delete First;
        First = NULL;
    }
    else
    {
        PNODE temp = First;
        while (temp->next->next != First)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = First;
    }
    iCount--;
}

void SinglyCL::DeleteAtPos(int iPos)
{
    if (iPos < 1 || iPos > iCount)
    {
        cout << "Invalid Position!" << endl;
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        PNODE target = temp->next;
        temp->next = target->next;
        delete target;
        iCount--;
    }
}

void SinglyCL::Display()
{
    if (First == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    PNODE temp = First;
    do
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    } while (temp != First);
    cout << endl;
}

int SinglyCL::Count()
{
    return iCount;
}

int main()
{
    SinglyCL obj;

    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertLast(51);
    obj.InsertLast(101);

    obj.Display(); // Output should be: |11|->|21|->|51|->|101|->

    cout << "Number of nodes: " << obj.Count() << endl; // Output should be 4

    obj.DeleteFirst();
    obj.Display(); // Output should be: |21|->|51|->|101|->

    obj.DeleteLast();
    obj.Display(); // Output should be: |21|->|51|->

    obj.InsertAtPos(2, 31);
    obj.Display(); // Output should be: |21|->|31|->|51|->

    obj.DeleteAtPos(2);
    obj.Display(); // Output should be: |21|->|51|->

    return 0;
}

//doubly linear
#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL
{
    public:
    PNODE First;
    int iCount;

    DoublyLL()
    {
        First = NULL;
        iCount = 0;
    }

    void Display();
    int Count();
    void InsertFirst(int No);
    void InsertLast(int No);
    void InsertAtPos(int No, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

void DoublyLL::Display()
{
    PNODE temp = First;
    while(temp != NULL)
    {
        cout << "|" << temp->data << "|<=>";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int DoublyLL::Count()
{
    return iCount;
}

void DoublyLL::InsertFirst(int No)
{
    PNODE newn = new NODE;
    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
}

void DoublyLL::InsertLast(int No)
{
    PNODE newn = new NODE;
    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        PNODE temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

void DoublyLL::InsertAtPos(int No, int iPos)
{
    if(iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid position!\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        PNODE temp = First;
        for(int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        PNODE newn = new NODE;
        newn->data = No;
        newn->next = temp->next;
        newn->prev = temp;

        if(temp->next != NULL)
            temp->next->prev = newn;
        
        temp->next = newn;

        iCount++;
    }
}

void DoublyLL::DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }

    if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        PNODE temp = First;
        First = First->next;
        First->prev = NULL;
        delete temp;
    }
    iCount--;
}

void DoublyLL::DeleteLast()
{
    if(First == NULL)
    {
        return;
    }

    if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        PNODE temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }
    iCount--;
}

void DoublyLL::DeleteAtPos(int iPos)
{
    if(iPos < 1 || iPos > iCount)
    {
        cout << "Invalid position!\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = First;
        for(int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        PNODE toDelete = temp->next;
        temp->next = toDelete->next;

        if(toDelete->next != NULL)
            toDelete->next->prev = temp;
        
        delete toDelete;

        iCount--;
    }
}

int main()
{
    DoublyLL obj;

    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertLast(51);
    obj.InsertAtPos(31, 2);

    obj.Display();

    cout << "Number of nodes: " << obj.Count() << endl;

    obj.DeleteFirst();
    obj.Display();
    cout << "Number of nodes: " << obj.Count() << endl;

    obj.DeleteLast();
    obj.Display();
    cout << "Number of nodes: " << obj.Count() << endl;

    obj.DeleteAtPos(2);
    obj.Display();
    cout << "Number of nodes: " << obj.Count() << endl;

    return 0;
}


//doubly circular 
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyCL
{
    private:
        PNODE First;
        PNODE Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(int No);
        void InsertLast(int No);
        void InsertAtPos(int No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

DoublyCL :: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

void DoublyCL::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

int DoublyCL::Count()
{
    return iCount;
}

void DoublyCL::InsertFirst(int No)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}

void DoublyCL::InsertLast(int No)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

void DoublyCL::InsertAtPos(int No, int iPos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new NODE;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

void DoublyCL::DeleteFirst()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

void DoublyCL::DeleteLast()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

void DoublyCL::DeleteAtPos(int iPos)
{
    PNODE temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}

int main()
{
    DoublyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    obj.Display();
    iRet = obj.Count();

    obj.DeleteAtPos(5);
    
    obj.Display();
    iRet = obj.Count();

    return 0;
}



//stack
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class Stack
{
    private:
        PNODE First;
        int iCount;

    public:
        Stack();
        void Display();
        int Count();
        void Push(int No);  // InsertFirst()
        int Pop();   // DeleteFirst()
};

Stack :: Stack()
{
    First = NULL;
    iCount = 0;
}

void Stack ::Display()
{
    cout<<"Elements of stack are : \n";
    PNODE temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
    cout<<"\n";
}

int Stack ::Count()
{
    return iCount;
}

void Stack ::Push(int No)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

int Stack ::Pop()
{
    int iValue = 0;
    PNODE temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to pop the element as stack is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;
        
        iCount--;
    }

    return iValue;
}

int main()
{
    Stack obj;
    int iRet = 0;

    obj.Push(10);
    obj.Push(20);
    obj.Push(30);
    obj.Push(40);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements in the stack are : "<<iRet<<"\n";
    
    iRet = obj.Pop();

    cout<<"Poped element is : "<<iRet<<"\n";

    iRet = obj.Pop();

    cout<<"Poped element is : "<<iRet<<"\n";
    
    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements in the stack are : "<<iRet<<"\n";

    obj.Push(50);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number of elements in the stack are : "<<iRet<<"\n";
    
    return 0;
}

//queue

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class Queue
{
    private:
        PNODE First;
        int iCount;

    public:
        Queue();
        void Display();
        int Count();
        void EnQueue(int No);  // InsertLast()
        int DeQueue();   // DeleteFirst()
};

Queue :: Queue()
{
    First = NULL;
    iCount = 0;
}

void Queue ::Display()
{
    cout<<"Elements of Queue are : \n";
    PNODE temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

int Queue ::Count()
{
    return iCount;
}

void Queue ::EnQueue(int No)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp ->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
    iCount++;
}

int Queue ::DeQueue()
{
    int iValue = 0;
    PNODE temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to remove the element as queue is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;
        
        iCount--;
    }

    return iValue;
}

int main()
{
    Queue obj;
    int iChoice = 0;
    int iNo = 0;

    cout<<"----------- Implementaion of Queue -----------\n";
    while(iChoice != 5)
    {
        cout<<"Please select your choice : \n";
        cout<<"1 : Insert new element in Queue\n";
        cout<<"2 : Remove the element from Queue\n";
        cout<<"3 : Display the elements form Queue\n";
        cout<<"4 : Count number of elements in Queue\n";
        cout<<"5 : Exit\n";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter the element that you want to insert : \n";
                cin>>iNo;
                obj.EnQueue(iNo);
            break;

            case 2:
                iNo = obj.DeQueue();
                if(iNo != -1)
                {
                    cout<<"Removed element from Queue is : "<<iNo<<"\n";
                }
            break;

            case 3:
                obj.Display();
            break;

            case 4:
                iNo = obj.Count();
                cout<<"Number of elements in Queue are : "<<iNo<<"\n";
            break;

            case 5:
                cout<<"Thank you for using our application\n";
            break;
        }
    }

    return 0;
}
