#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<string>  
#include<cmath>  
#include<algorithm>  
  
using namespace std;  
  
#define pi acos(-1.0)  
int n;  
double x,y;  
double r,s;  
int ans;  
  
int main()  
{  
    scanf("%d",&n);  
    for(int i=1;i<=n;i++)  
    {  
        scanf("%lf%lf",&x,&y);  
        r=x*x+y*y;  
        s=pi*r/2;  
        ans=ceil(s/50);  
        printf("Property %d: This property will begin eroding in year %d.\n",i,ans);  
    }  
    printf("END OF OUTPUT.\n");  
    return 0;  
}  