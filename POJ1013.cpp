#include<iostream>
using namespace std;
struct ALL_COIN
{
	char left[15];
	char right[15];
	char state[10];
};
void update_state(char num, bool state[12])
{
	if (num == 'A')
	{
		state[0] = true;
	}
	else if (num == 'B')
	{
		state[1] = true;
	}
	else if (num == 'C')
	{
		state[2] = true;
	}
	else if (num == 'D')
	{
		state[3] = true;
	}
	else if (num == 'E')
	{
		state[4] = true;
	}
	else if (num == 'F')
	{
		state[5] = true;
	}
	else if (num == 'G')
	{
		state[6] = true;
	}
	else if (num == 'H')
	{
		state[7] = true;
	}
	else if (num == 'I')
	{
		state[8] = true;
	}
	else if (num == 'J')
	{
		state[9] = true;
	}
	else if (num == 'K')
	{
		state[10] = true;
	}
	else if (num == 'L')
	{
		state[11] = true;
	}
}

bool compare_state(char num, bool state[12])
{
	if (num == 'A')
	{
		if (state[0])
		{
			return true;
		}
	}
	else if (num == 'B')
	{
		if (state[1])
		{
			return true;
		}
	}
	else if (num == 'C')
	{
		if (state[2])
		{
			return true;
		}
	}
	else if (num == 'D')
	{
		if (state[3])
		{
			return true;
		}
	}
	else if (num == 'E')
	{
		if (state[4])
		{
			return true;
		}
	}
	else if (num == 'F')
	{
		if (state[5])
		{
			return true;
		}
	}
	else if (num == 'G')
	{
		if (state[6])
		{
			return true;
		}
	}
	else if (num == 'H')
	{
		if (state[7])
		{
			return true;
		}
	}
	else if (num == 'I')
	{
		if (state[8])
		{
			return true;
		}
	}
	else if (num == 'J')
	{
		if (state[9])
		{
			return true;
		}
	}
	else if (num == 'K')
	{
		if (state[10])
		{
			return true;
		}
	}
	else if (num == 'L')
	{
		if (state[11])
		{
			return true;
		}
	}
	return false;
}
int main()
{
	ALL_COIN *coin = new ALL_COIN[3];
	int i = 0;
	bool state[12];
	for (int s = 0; s < 12; s++)
	{
		state[s] = false;
	}
	while (1)
	{
		cout << "ÇëÊäÈë×óÓÒºÍÆ«Ïò:" << endl;
		cin >> coin[i].left >> coin[i].right >> coin[i].state;
		i++;
		if (i == 3)
		{
			break;
		}
	}
	for (int j = 0; j < 3; j++)
	{
		if (strcmp(coin[j].state, "even") == 0)
		{
			for (unsigned int k = 0; k < strlen(coin[j].left); k++)
			{
				update_state(coin[j].left[k], state);
			}
			for (unsigned int x = 0; x < strlen(coin[j].right); x++)
			{
				update_state(coin[j].right[x], state);
			}
		}
	}
	for (int l = 0; l < 3; l++)
	{
		if (strcmp(coin[l].state, "up") == 0)
		{
			for (unsigned int y = 0; y < strlen(coin[l].left); y++)
			{
				if (!compare_state(coin[l].left[y], state))
				{
					cout << coin[l].left[y] << " is the counterfeit coin and it is heavy " << endl;
				}
			}
			for (unsigned int z = 0; z < strlen(coin[l].right); z++)
			{
				if (!compare_state(coin[l].right[z], state))
				{
					cout << coin[l].right[z] << " is the counterfeit coin and it is light " << endl;
				}
			}
		}
		else if (strcmp(coin[l].state, "down") == 0)
		{
			for (unsigned int y = 0; y < strlen(coin[l].left); y++)
			{
				if (!compare_state(coin[l].left[y], state))
				{
					cout << coin[l].left[y] << " is the counterfeit coin and it is light " << endl;
				}
			}
			for (unsigned int z = 0; z < strlen(coin[l].right); z++)
			{
				if (!compare_state(coin[l].right[z], state))
				{
					cout << coin[l].right[z] << " is the counterfeit coin and it is heavy " << endl;
				}
			}
		}
	}
	system("pause");
	return 0;
}