#include <iostream>
#include <cstdlib>
#include <string.h>
#include <string>
#include <ctype.h>
using namespace std;
int countt=0;
typedef struct BSTNode
{
char phoneName[9];
int times;
struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

 

void InsertBST(BSTree &t,char name[])
{
BSTree p,f;
p=t;
while(p)
 {
  if(strcmp(name,p->phoneName)==0)//hints that the tree have this point,not
   //need to insert
  {
  p->times++;
  countt=1;
  return ;//alerady have this point ,return to main.
  }//if
  f=p;
  p=(strcmp(name,p->phoneName)<0) ? p->lchild:p->rchild;//if name<phoneName,turn to left child,otherwise,
  //turn to right child
 }//while

p=(BSTree)malloc(sizeof(BSTNode));
strcpy(p->phoneName,name);
p->lchild=p->rchild=NULL;
p->times=1;

if(t==NULL) t=p;
else if(strcmp(name,f->phoneName)<0)
 f->lchild=p;
else f->rchild=p;
}

void InOrderTraverse(BSTree t) //
{
if(t!=NULL)
 {
  InOrderTraverse(t->lchild);
  if(t->times>1)
   cout<<t->phoneName<<" "<<t->times<<endl;
  InOrderTraverse(t->rchild);
 }
}

int main()
{
int n,j,i;
char str[20];
//string str;
char ch;
BSTree t=NULL;
cin>>n;
countt=0;
for(i=0;i<n;i++)
{
j=0;
while((ch=getchar())!='\n')
 {
  if(isdigit(ch)) //to judge the ch is a num
   str[j++]=ch;
  else 
   if(isupper(ch)) //to check the ch if a captial character
   {
   switch(ch)
    {
     case'A':
  case'B':
  case'C':ch='2';break;
     case'D':
  case'E':
  case'F':ch='3';break;
     case'G':
  case'H':
  case'I':ch='4';break;
     case'J':
     case'K':
     case'L':ch='5';break;
     case'M':
     case'N':
  case'O':ch='6';break;
     case'P':
     case'R':
     case'S':ch='7';break;
  case'T':
  case'U':
  case'V':ch='8';break;
  case'W':
  case'X':
  case'Y':ch='9';break;
    }//switch
   str[j++]=ch;
    }//if
   else continue;
   if(j==3) str[j++]='-';
 }//while
str[j]='\0';
InsertBST(t,str);
}
if(countt) InOrderTraverse(t);
else cout<<"No duplicates."<<endl;
return 0; 
}