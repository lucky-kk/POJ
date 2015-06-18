#include<iostream>  
#include<iomanip>  
using namespace std;  
int main()  
{  
    float c,num=0;  
    while(cin>>c)  
    {  
        num+=c;  
    }  
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<'$'<<num/12<<endl;  
    return 0;  
}  