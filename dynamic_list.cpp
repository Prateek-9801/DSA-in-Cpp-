#include<iostream>
#include<cstdlib>
using namespace std;
int *a, n;
int i = -1;
void myrealloc()
{
 int t;
 cout<<"\n How many numbers : ";
 cin>>t;
 a= (int *)realloc(a,(n+t)*sizeof(int));
 n += t;
}
void myadd()
{
 if(i==n-1)
  myrealloc();
 cout<<"\n Enter data: ";
 cin>>a[++i];
}
void mylist()
{
 if(i==-1)
 {
  cout<<"\n List is empty!";
  return;
 }
 cout<<"\n Data in list  is : ";
 for(int j=0; j<=i; j++)
  cout<<" "<<a[j];
}
void mydelete()
{
 int j, key, F=0;
 cout<<"\n Enter number to search: ";
 cin>>key;
 for(j=0;j<=i;j++)
 {
  if(a[j]==key)
  {
   F=1;
   break;
  }
 }
 if(F==1)
 {
  for( ; j<i; j++)
   a[j]=a[j+1];
  i--;
 }
 else
  cout<<"\n Number not found";
}
void myinsert()
{
 if(i==n-1)
  myrealloc();
 int j, key, F=0, ch, k;
 cout<<"\n Enter number to search: ";
 cin>>key;
 for(j=0;j<=i;j++)
 {
  if(a[j]==key)
  {
   F=1;
   break;
  }
 }
 if(F==1)
 {
  cout<<"\n Where to insert? "<<"\n 1.Before"<<"\n 2.After"<<"\n Enter choice: ";
  cin>>ch;
  switch(ch)
  {
   case 1: k = j; break;
   case 2: k = j+1; break;
  }
  for(j=i ; j>=k; j--)
   a[j+1]=a[j];
  i++;
  cout<<"\n Enter number: ";
  cin>>a[k];
 }
 else
  cout<<"\n Number not found";
}
int main()
{
 int ch;
 cout<<"\n How many numbers : ";
 cin>>n;
 a=new int[n];
 while(1)
 {
  cout<<"\n 1.Add"
      <<"\n 2.List"
      <<"\n 3.Delete"
      <<"\n 4.Insert"
      <<"\n 5.Exit"
      <<"\n Enter choice : ";
  cin>>ch;
  switch(ch)
  {
   case 1: myadd(); break;
   case 2: mylist(); break;
   case 3: mydelete(); break;
   case 4: myinsert(); break;
   case 5: exit(1); break;
  }
 }
 return 0;
}
