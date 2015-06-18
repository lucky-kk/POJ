#include <iostream>
using namespace std;
void init(int a[4])
{
	for (int i=0;i<4;i++)
	{
		a[i]=0;
	}
}
int kind_num(int a1,int a2,int a3,int a4,int max_num)
{
	if (a1==0)
	{
		max_num--;
	}
	if (a2==0)
	{
		max_num--;
	}
	if (a3==0)
	{
		max_num--;
	}
	if (a4==0)
	{
		max_num--;
	}
	if ((a1==a2)&&(a1!=0))
	{
		max_num--;
	}
	if ((a1==a3)&&(a1!=0))
	{
		max_num--;
	}
	if ((a1==a4)&&(a1!=0))
	{
		max_num--;
	}
	if ((a2==a3)&&(a2!=0))
	{
		max_num--;
	}
	if ((a2==a4)&&(a2!=0))
	{
		max_num--;
	}
	if ((a3==a4)&&(a3!=0))
	{
		max_num--;
	}
	return max_num;
}
int num_stamps(int b1,int b2,int b3,int b4)
{
	int num = 4;
	if (b1==0)
	{
		num--;
	}
	if (b2==0)
	{
		num--;
	}
	if (b3==0)
	{
		num--;
	}
	if (b4==0)
	{
		num--;
	}
	return num;
}
void sort_temp(int a[4])
{
	int A;
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<3-i;j++)
		{
			if (a[j]>a[j+1])
			{
				A=a[j+1];
				a[j+1]=a[j];
				a[j]=A;
			}
		}
	}
}
int main()
{
	int kinds,a;
    int stamps[25];
	int temp[4];
	int max_stamp;
	int customer[100];
	int max_customer;
	stamps[0]=0;
	int num1,num2;
	int A_a[4];
	for (int i=1;i<25;i++)
	{
		cin>>kinds;
		if (kinds != 0)
		{
			stamps[i]=kinds;
		}
		else
		{
			max_stamp=i;
			break;
		}
	}
	for (int j=0;j<100;j++)
	{
		cin>>a;
		if (a != 0)
		{
			customer[j]=a;
		}
		else
		{
			max_customer=j;
			break;
		}
	}
//	cout<<max_stamp<<" "<<max_customer<<endl;
	for (int kk=0;kk<max_customer;kk++)
	{
		init(temp);          //初始化临时数组
		init(A_a);
        int falg1=0,falg2=0;
        int max1=-1,max2;
		int kinds_temp=0;
        int kinds_stamps=0;
		for (int a1=0;a1<max_stamp;a1++)
		{
			for (int a2=0;a2<max_stamp;a2++)
			{
				for (int a3=0;a3<max_stamp;a3++)
				{
					for (int a4=0;a4<max_stamp;a4++)
					{
						if (stamps[a4]+stamps[a3]+stamps[a2]+stamps[a1] == customer[kk])
						{
							falg1++;
							kinds_stamps=kind_num(a1,a2,a3,a4,max_stamp);
							num1=num_stamps(stamps[a4],stamps[a3],stamps[a2],stamps[a1]);
							int A_aa[4];
							A_aa[0]=a1;A_aa[1]=a2;A_aa[2]=a3;A_aa[3]=a4;
							sort_temp(A_aa);
							if (stamps[a4]>max1)
							{
								max1=stamps[a4];
							}
							if (stamps[a3]>max1)
							{
								max1=stamps[a3];
							}
							if (stamps[a2]>max1)
							{
								max1=stamps[a2];
							}
							if (stamps[a1]>max1)
							{
								max1=stamps[a1];
							}
							if (kinds_stamps>kinds_temp)
							{
								kinds_temp=kinds_stamps;
								temp[0]=stamps[a4];
								temp[1]=stamps[a3];
								temp[2]=stamps[a2];
								temp[3]=stamps[a1];
								sort_temp(temp);
								for (int x1=0;x1<4;x1++)
								{
									A_a[x1]=A_aa[x1];
								}
								max2=max1;
								num2=num1;
								falg2=0;
								max1=-1;
								num1=0;
							}
							else if(kinds_stamps==kinds_temp)
							{
								if (num1<num2)
								{
									kinds_temp=kinds_stamps;
									temp[0]=stamps[a4];
									temp[1]=stamps[a3];
									temp[2]=stamps[a2];
									temp[3]=stamps[a1];
									sort_temp(temp);
									for (int x2=0;x2<4;x2++)
									{
										A_a[x2]=A_aa[x2];
									}
									max2=max1;
							    	num2=num1;
									falg2=0;
									max1=-1;
									num1=0;
								}
								else if(num1==num2)
								{
									if (max1>max2)
									{
										kinds_temp=kinds_stamps;
										temp[0]=stamps[a4];
										temp[1]=stamps[a3];
										temp[2]=stamps[a2];
										temp[3]=stamps[a1];
										sort_temp(temp);
										for (int x3=0;x3<4;x3++)
										{
											A_a[x3]=A_aa[x3];
										}
										max2=max1;
							         	num2=num1;
										falg2=0;
										max1=-1;
										num1=0;
									}
									else if (max1==max2)
									{
										int b[4];
										b[0]=stamps[a4];
										b[1]=stamps[a3];
										b[2]=stamps[a2];
										b[3]=stamps[a1];
										sort_temp(b);
										if ((temp[0]==b[0])&&(temp[1]==b[1])&&(temp[2]==b[2])&&(temp[3]==b[3]))
										{
										//	falg2=0;
											if ((A_a[0]==A_aa[0])&&(A_a[1]==A_aa[1])&&(A_a[2]==A_aa[2])&&(A_a[3]==A_aa[3]))
											{
												continue;
											}
											else
											{
												falg2++;
											}
											max1=-1;
											num1=0;
										}
										else
										{
											falg2++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (falg1==0)
		{
			cout<<"none"<<endl;
		}
		else
		{
		if (falg2!=0)
		{
			cout<<"tie"<<endl;
		}
		else
		{
		for (int k=0;k<4;k++)
		{
			if (temp[k]!=0)
			{
				cout<<temp[k]<<" ";
			}
		}
		cout<<endl;
		}
		}
	}
	return 0;
}