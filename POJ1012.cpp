#include<iostream>
using namespace std;
struct NUMBER{
	int change;
	int num;
	bool state;
};

bool main_state;

int main()
{
	while (1)
	{
		main_state = true;
		int m = 1;
		cout << "ÇëÊäÈëkÖµ:" << endl;
		int k;
		cin >> k;
		if (k == 0)
		{
			break;
		}
		else
		{
			struct NUMBER *ALL = new struct NUMBER[2 * k];
			for (int i = 0; i < 2 * k; i++)
			{
				ALL[i].change = i + 1;
				ALL[i].num = i + 1;
				ALL[i].state = false;
			}
			int t = 2 * k;
			while (main_state)
			{
				int out = m % t;
				if (out == 0)
				{
					out = t;
				}
				//cout << "out = " << out << endl;
				for (int j = 0; j < 2*k; j++)
				{
					if (ALL[j].change == out && (!ALL[j].state))
					{
						ALL[j].state = true;
						int num_live = 0;
						for (int x = k; x < 2 * k; x++)
						{
							if (ALL[x].state)
							{
								num_live++;
							}
						}
						if (num_live == k)
						{
							cout << "m = " << m << endl;
							main_state = false;
							for (int i = 0; i < 2 * k; i++)
							{
								ALL[i].change = i + 1;
								ALL[i].num = i + 1;
								ALL[i].state = false;
							}
							break;
						}
						if (ALL[j].num <= k)
						{
							m++;
							t = 2 * k;
							for (int i = 0; i < 2 * k; i++)
							{
								ALL[i].change = i + 1;
								ALL[i].num = i + 1;
								ALL[i].state = false;
							}
							break;
						}
						else
						{
							int a = 1;
							for (int y = ALL[j].num; y < 2 * k; y++)
							{
								if (!ALL[y].state)
								{
									ALL[y].change = a;
									a++;
								}
							}
							for (int z = 0; z < ALL[j].num - 1; z++)
							{
								if (!ALL[z].state)
								{
									ALL[z].change = a;
									a++;
								}
							}
						}
						t = t - 1;
						break;
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}