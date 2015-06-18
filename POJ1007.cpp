#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,m;
	char DNA[100][50];
	int num[100],QQ[100];
	int temp,tmp;
	cin>>n>>m;
	for (int i=0;i<m;i++)
	{
		num[i]=0;
		for (int j=0;j<n;j++)
		{
			cin>>DNA[i][j];
		}
//		cout<<DNA[0][1]<<DNA[0][2]<<endl;
		for (int k=0;k<n;k++)
		{
			for (int l=k+1;l<n;l++)
			{
				if (DNA[i][k]>DNA[i][l])
				{
					num[i]++;
				}
			}
		}
		cout<<num[i]<<endl;
	}
	for (int Q=0;Q<m;Q++)
	{
		QQ[Q] = Q;
	}
	for (int I=0;I<m;I++)
	{
		for (int J=0;J<m-1-I;J++)
		{
			if (num[J]>num[J+1])
			{
				temp = num[J];
				num[J] = num[J+1];
				num[J+1] = temp;

				tmp = QQ[J];
				QQ[J] = QQ[J+1];
				QQ[J+1] = tmp;
			}
		}
	}
	for (int JJ=0;JJ<m;JJ++)
	{
		for(int II=0;II<n;II++)
		{
			cout<<DNA[QQ[JJ]][II];
		}
		cout<<endl;
	}
	return 0;
}
