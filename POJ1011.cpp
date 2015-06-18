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
//iΪ��ǰ��ȡ�Ĺ������,lΪҪƴ��һ�������Ĺ��ӻ���Ҫ�ĳ���,t��ֵΪ���й����ܳ���
{
    if(l==0) {
        t-=len;
        if(t==0)return true;
        for(i=0; used[i]; ++i);
        //��֦1��������һ������ӵ�ʱ���ҵ���һ����û��ʹ�õ�С���ӿ�ʼ
        used[i]=1;
        //������������ҵ��ĵ�һ���϶����Ҳ�϶�Ҫʹ�ã����Դ���һ����ʼ����
        if(dfs(i+1,len-sticks[i],t))return true;
        used[i]=0;
        t+=len;
    } else {
        for(int j=i; j<n; ++j) {
            if(j>0&&(sticks[j]==sticks[j-1]&&!used[j-1]))
            //��֦2��ǰ�������������ʱ�����ǰ���Ǹ�û��ʹ�ã�
            //Ҳ������ǰ���Ǹ���ʼ����������ȷ�������ô�ٴ������ʼҲ�϶�����������ȷ������˼�֦�����ϴ�
                continue;
            if(!used[j]&&l>=sticks[j]) {
            //��֦3����򵥵ļ�֦��Ҫƴ��һ������ӻ���Ҫ�ĳ���L>=��ǰС���ӳ��ȣ�����ѡ��
                l-=sticks[j];
                used[j]=1;
                if(dfs(j,l,t))return true;
                l+=sticks[j];
                used[j]=0;
                if(sticks[j]==l)
                //��֦4�������޴�ļ�֦������Ҫ���е��˴�˵�����µ�����ʧ�ܣ�
                //�����ε�С�����ȸպ�����ʣ�³��ȣ����Ǻ��������ʧ�ܣ���Ӧ�÷�����һ��
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