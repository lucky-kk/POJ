#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<string>  
#include<cmath>  
#include<algorithm>  

using namespace std;  

#define eps  1e-8  


double l,s,tag;  
int cnt,ans[1100];  

int sig(double k)  
{  
    if(fabs(k)<eps)  
        return 0;  
    return (k>0)?1:-1;  
}  

int main()  
{  
    s=0;  
    memset(ans,-1,sizeof(ans));  
    for(int i=1;i<=520;i++)  
    {  
        cnt=1,s=0.5,tag=(i*1.0)/100;  
        for(;;)  
        {  
            if(sig(s-tag)>=0)  
            {  
                ans[i]=cnt;  
                break;  
            }  
            cnt++;  
            s+=1.0/(cnt+1);  
        }  
    }  
    while(~scanf("%lf",&l))  
    {  
        if(sig(l-0)==0)  
            break;  
        printf("%d card(s)\n",ans[(int)(l*100)]);  
		
    }  
	
    return 0;  
}  