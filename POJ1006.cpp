#include <iostream>
using namespace std;
const int lcm=21252;//23,28,33的最小公倍数
int main()
{
    int p,e,i,d,ans,case_i=1;
    while(cin>>p>>e>>i>>d,p!=-1)
    {
        ans=0;
        if(p>=23) p=p-(p/23)*23;
        if(e>=28) e=e-(e/28)*28;
        if(i>=33) i=i-(i/33)*33;
        for(int j=0;;j++)
        {
            ans=j*33+i;
            if(ans%23==p && ans%28==e)
                break;
        }
        if(ans<=d)
        {
            ans+=(d-ans)/lcm*lcm+lcm;
			
        }
        if(ans>d ) ans-=d;
        if(ans>21252) ans=21252;
        cout<<"Case "<<case_i++<<": the next triple peak occurs in "<<ans<<" days."<<endl;
    }
    return 0;
}