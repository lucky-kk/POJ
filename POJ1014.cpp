#include<iostream>  
using namespace std;

int amount[7] = { 0 };
int half_value = 0;
int flag = 0;

void DFS(int value, int pre){

	if (value == half_value)
	{
		flag = 1;
		return;
	}

	if (flag == 1)
	{  //不可少的，感受其作用,让递归栈中所有DFS结束  
		return;
	}

	int i = 0;
	for (i = pre; i > 0; i--)
	{
		if (amount[i])
		{
			if (i + value <= half_value)
			{
				amount[i]--;
				DFS(i + value, i);

				if (flag == 1)
				{  //不可少的，感受其作用,让递归栈中所有DFS结束  
					return;
				}
			}
		}
	}
}


int main(){

	int testcase = 1;
	while (true)
	{
		flag = 0;
		int totalvalue = 0;
		int N = 6;
		int i = 1;
		while (i <= N)
		{
			cin >> amount[i];
			totalvalue += amount[i] * i;
			i++;
		}

		if (!amount[1] && !amount[2] && !amount[3] && !amount[4] && !amount[5] && !amount[6])
		{
			break;
		}

		printf("Collection #%d:\n", testcase++);
		if (totalvalue % 2 != 0)
		{
			cout << "Can't be divided." << endl << endl;
			continue;
		}

		half_value = totalvalue / 2;
		DFS(0, 6);

		if (flag)
		{
			cout << "Can be divided." << endl;
		}
		else 
		{
			cout << "Can't be divided." << endl;
		}
		cout << endl;
	}
	return 0;
}