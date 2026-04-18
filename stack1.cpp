#include<iostream>
#include<cstdlib>
using namespace std;
int a[5]; // global variable intialisation
int i = -1;

void myadd()
{
 if(i==4)
 {
  cout<<"\n Stack is full";
  return;
 }
 cout<<"\n Enter data : ";
 cin>>a[++i];
}
void mylist()
{
 if(i==-1)
 {
  cout<<"\n Stack is empty";
  return;
 }
 cout<<"\n Data in Stack is : ";
 for(int j=i; j>=0; j--)
  cout<<" "<<a[j];
}
void mydel()
{
 if(i==-1)
 {
  cout<<"\n Stack is empty";
  return;
 }
 i--;
 cout<<"\n One element deleted";
}

int main()
{
 int ch;
 while(1)
 {
  cout<<"\n\n 1. Add"
	<<"\n 2. List"
	<<"\n 3. Delete"
	<<"\n 4. Exit"
	<<"\n Enter choice : ";
  cin>>ch;
  switch(ch)
  {
   case 1: myadd(); break;
   case 2: mylist(); break;
   case 3: mydel(); break;
   case 4: exit(1); break;
  }
 }
 return 0;
}
