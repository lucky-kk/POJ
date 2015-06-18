#include <iostream>
#include <math.h>
using namespace std;
int max_n(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8);
int main()
{
	int a[1000],b[1000],row,col,I,num=0;
	cin>>col;
	int falg=1;
	while(falg)
	{
		for (int i=0;i<1000;i++)
		{
			cin>>a[i]>>b[i];
			if (b[i] == 0)
			{
				I=i;
				falg = 0;
			}
			if (falg == 0)
			{
				break;
			}
		}
	}
	for (int j=0;j<I;j++)
	{
		num = num + b[j];
	}
	row = num/col;

    int** arr = new int*[row];    //原始矩阵
	for (int k=0;k<row;k++)
	{
		arr[k] = new int[col];
	}

	int** new_arr = new int*[row];     //修改后的矩阵
	for (int new_k=0;new_k<row;new_k++)
	{
		new_arr[new_k] = new int[col];
	}

	int a_row = 0,a_col = 0;

	for (int l=0;l<I;l++)
	{
		while(b[l] != 0)
		{
			arr[a_row][a_col] = a[l];
			a_col++;
			if (a_col == col)
			{
				a_col=0;
				a_row++;
			}
			b[l]--;
		}
	}
	for (int m=0;m<row;m++)
	{
		for (int n=0;n<col;n++)
		{
			cout<<arr[m][n]<<" ";
		}
		cout<<endl;
	} 
	for (int o=0;o<row;o++)
	{
		for (int p=0;p<col;p++)
		{
			int a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0;
			if ((o-1 >= 0)&&(p-1 >= 0))
			{
				a1 = abs(arr[o][p]-arr[o-1][p-1]);
//				cout<<"a1="<<a1<<" ";
			}
			if (( o-1 >= 0)&&(p >= 0))
			{
				a2 = abs(arr[o][p]-arr[o-1][p]);
//                cout<<"a2="<<a2<<" ";
			}
			if (( o-1 >= 0)&&( p+1 < col))
			{
				a3 = abs(arr[o][p]-arr[o-1][p+1]);
//                cout<<"a3="<<a3<<" ";
			}
			if ((o >= 0)&&(p-1 >= 0))
			{
				a4 = abs(arr[o][p]-arr[o][p-1]);
//                cout<<"a4="<<a4<<" ";
			}
			if ((o >= 0)&&(p+1 < col))
			{
				a5 = abs(arr[o][p]-arr[o][p+1]);
//				cout<<"a5="<<a5<<" ";
			}
			if ((o+1 < row)&&(p-1 >= 0))
			{
				a6 = abs(arr[o][p]-arr[o+1][p-1]);
//				cout<<"a6="<<a6<<" ";
			}
			if ((o+1 < row)&&(p>=0))
			{
				a7 = abs(arr[o][p]-arr[o+1][p]);
//				cout<<"a7="<<a7<<" ";
			}
			if ((o+1 < row)&&(p+1 <col))
			{
				a8 = abs(arr[o][p]-arr[o+1][p+1]);
//				cout<<"a8="<<a8<<" ";
			}
//			cout<<endl;
			new_arr[o][p] = max_n(a1,a2,a3,a4,a5,a6,a7,a8);
		}
	}
	cout<<endl;
	for (int mm=0;mm<row;mm++)
	{
		for (int nn=0;nn<col;nn++)
		{
			cout<<new_arr[mm][nn]<<" ";
		}
		cout<<endl;
	} 
	int num_arr=1;
	cout<<col<<endl;
	for (int s=0;s<row;s++)
	{
		for (int t=0;t<col;t++)
		{
			if ((t+1) == col)
			{
				if((s+1) == row)
				{
					cout<<new_arr[s][t]<<" "<<num_arr<<endl;
					cout<<"0"<<" "<<"0"<<endl;
					break;
				}
				if(new_arr[s][t] == new_arr[s+1][0])
				{
					num_arr++;
				}
				else
				{
				    cout<<new_arr[s][t]<<" "<<num_arr<<endl;
			    	num_arr=1;
				}
			}
			else
			{
				if (new_arr[s][t] == new_arr[s][t+1])
				{
					num_arr++;
				}
				else
				{
					cout<<new_arr[s][t]<<" "<<num_arr<<endl;
					num_arr=1;
				}
			}
		}
	}
	return 0;
}
int max_n(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8)
{
	int a[8],i;
	a[0]=a1;a[1]=a2;a[2]=a3;a[3]=a4;a[4]=a5;a[5]=a6;a[6]=a7;a[7]=a8;
	for (i=0;i<7;i++)
	{
		if (a[i]>a[i+1])
		{
			a[i+1]=a[i];
		}
	}
	return a[7];
}