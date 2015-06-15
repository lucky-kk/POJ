#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
struct score
{
	int defendant;          //±ç·½
	int prosecution;        //¿Ø·½
};
vector<score>add_all;

int main()
{
	int n, m;
	cin >> n >> m;
	score *SC = new score[n];
	int i = 0;
	while (1)
	{
		int N, M;
		cin >> N >> M;
		if ((N == 0) && (M == 0))
		{
			break;
		}
		else
		{
			SC[i].defendant = N;
			SC[i].prosecution = M;
			i++;
		}
	}
	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < n - j - 1; k++)
		{
			int a1 = SC[k].defendant - SC[k].prosecution;
			int a2 = SC[k + 1].defendant - SC[k + 1].prosecution;
			if (abs(a1)>abs(a2))
			{
				int temp1 = SC[k].defendant;
				SC[k].defendant = SC[k + 1].defendant;
				SC[k + 1].defendant = temp1;

				int temp2 = SC[k].prosecution;
				SC[k].prosecution = SC[k + 1].prosecution;
				SC[k + 1].prosecution = temp2;
			}
		}
	}
	int add_num = 0;
	int temp = abs(SC[0].defendant - SC[0].prosecution);
	add_all.push_back(SC[0]);
	for (int x = 1; x < n; x++)
	{
		int temp_s = abs(SC[x].defendant - SC[x].prosecution);
		if (temp == temp_s)
		{
			add_all.push_back(SC[x]);
			add_num++;
		}
		else
		{
			break;
		}
	}
	vector<score>::iterator its = add_all.begin();
	int add1 = its->defendant;
	int add2 = its->prosecution;
	int add_n = add1 + add2;
	while( its != add_all.end())
	{
		its++;
		if (its != add_all.end())
		{
			if (add_n < (its->defendant + its->prosecution))
			{
				add1 = its->defendant;
				add2 = its->prosecution;
				add_n = add1 + add2;
			}
		}
	}
	cout << add1 << ":" << add2 << endl;
//	system("pause");
	return 0;
}