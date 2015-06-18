#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b )
{
    return a>b;
}

int sticks[100];
bool used[100];
int n, StickLen, len;

bool dfs(int i,int l,int t)
//i为当前试取的棍子序号,l为要拼成一根完整的棍子还需要的长度,t初值为所有棍子总长度
{
    if(l==0) {
        t-=len;
        if(t==0)return true;
        for(i=0; used[i]; ++i);
        //剪枝1：搜索下一根大棍子的时候，找到第一个还没有使用的小棍子开始
        used[i]=1;
        //由于排序过，找到的第一根肯定最长，也肯定要使用，所以从下一根开始搜索
        if(dfs(i+1,len-sticks[i],t))return true;
        used[i]=0;
        t+=len;
    } else {
        for(int j=i; j<n; ++j) {
            if(j>0&&(sticks[j]==sticks[j-1]&&!used[j-1]))
            //剪枝2：前后两根长度相等时，如果前面那根没被使用，
            //也就是由前面那根开始搜索不到正确结果，那么再从这根开始也肯定搜索不出正确结果，此剪枝威力较大
                continue;
            if(!used[j]&&l>=sticks[j]) {
            //剪枝3：最简单的剪枝，要拼成一根大棍子还需要的长度L>=当前小棍子长度，才能选用
                l-=sticks[j];
                used[j]=1;
                if(dfs(j,l,t))return true;
                l+=sticks[j];
                used[j]=0;
                if(sticks[j]==l)
                //剪枝4：威力巨大的剪枝，程序要运行到此处说明往下的搜索失败，
                //若本次的小棍长度刚好填满剩下长度，但是后面的搜索失败，则应该返回上一层
                    break;
            }
        }
    }
    return false;
}
int main()
{
    int i, totalLen;
    bool flag;
    while(scanf("%d",&n),n) {
        totalLen = 0;
        for(i=0; i<n; ++i) {
            scanf("%d",&sticks[i]);
            totalLen += sticks[i];
        }
        sort(sticks, sticks+n, cmp);
        memset(used, 0, sizeof used );
        flag = false;
        for(StickLen = sticks[0]; StickLen <=totalLen/2; ++StickLen) {
            len = StickLen;
            if(totalLen % StickLen == 0)
                if(dfs(0, StickLen, totalLen) ) {
                    flag= true;
                    printf("%d\n",StickLen);
                    break;
                }
        }
        if(!flag) {
            printf("%d\n",totalLen);
        }
    }
    return 0;
}