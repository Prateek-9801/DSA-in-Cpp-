#include <iostream>
#include <cstdlib>
using  namespace std;

struct emp
{
    int empno;
    char name[20];
    int sal;
    struct emp *next;
};

typedef struct emp node;

node *head, *tail;

void input(node *p)
{
    cout << "\nEmpno name salary: ";
    cin >> p->empno >> p->name >> p->sal;
    p->next = NULL;
}

void myadd()
{
    node *t;

    t = new node;

    input(t);

    if(head == NULL)
        head = t;
    else
        tail->next = t;   // purane ko naye se jodna

    tail = t;             // naye wale ko rakhna
}

void print(node *p)
{
    cout << "\nEmpno: " << p->empno
         << "\nName: " << p->name
         << "\nSalary: " << p->sal
         << endl;
}

void mylist()
{
    if(head == NULL)
    {
        cout << "\nQueue is empty!";
        return;
    }

    node *t;

    for(t = head; t != NULL; t = t->next)
        print(t);
}

void mydel()
{
    if(head == NULL)
    {
        cout << "\nQueue is empty!";
        return;
    }

    node *t;

    t = head->next;    
    delete head;  // free head; in c language
    head = t;

    cout << "\nOne record deleted";
}

int main()
{
    int ch;

    head = NULL;

    while(1)
    {
        cout << "\nMain Menu";
        cout << "\n1.Add"
             << "\n2.List"
             << "\n3.Delete"
             << "\n4.Exit"
             << "\nEnter choice: ";

        cin >> ch;

        switch(ch)
        {
            case 1:
                myadd();
                break;

            case 2:
                mylist();
                break;

            case 3:
                mydel();
                break;

            case 4:
                exit(1);
        }
    }

    return 0;
}
