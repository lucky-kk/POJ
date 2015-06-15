#include<iostream>
#include<string>
#include<vector>
#include<strstream>
using namespace std;

vector<string>ALL;
vector<string>ONE;

string new_string(string in)
{
	string new_s;
	for (int i = 0; i < 10; i++)
	{
		int num = 0;
		string temp,temp_s;
		strstream ss;
		ss << i;
		ss >> temp;

		for (int j = 0; j < in.length(); j++)
		{
			temp_s = in[j];
			if (temp == temp_s)
			{
				num++;
			}
		}
		if (num != 0)
		{
			string temp1;
			strstream s_n;
			s_n << num;
			s_n >> temp1;
			new_s = new_s + temp1 + temp;
		}
	}
	return new_s;
}
int main()
{
	while (1)
	{
		string input;
		cin >> input;
		if (input == "-1")
		{
			break;
		}
		else
		{
			ALL.push_back(input);
		}
	}
	vector<string>::iterator iter = ALL.begin();
	for (; iter != ALL.end(); iter++)
	{
		string in = *iter;
		int one_num = 0;
		while (1)
		{
			string new_s = new_string(in);
//			cout << new_s << endl;
			if ((new_s == *iter)&&(one_num == 0))
			{
				cout << *iter << " is self-inventorying " << endl;
				break;
			}
			else if ((new_s == in) && one_num)
			{
				cout << *iter <<" is self-inventorying after " << one_num << " steps " << endl;
				break;
			}
			else
			{
				one_num++;
				int flag = 0;
				vector<string>::iterator iter_one = ONE.begin();
				for (; iter_one != ONE.end(); iter_one++)
				{
					flag++;
					if (new_s == *iter_one)
					{
						cout << *iter << " enters an inventory loop of length " << flag << endl;
						break;
					}
				}
				ONE.push_back(new_s);
			}

			if (one_num == 15)
			{
				cout << *iter <<" can not be classified after 15 iterations " << endl;
				break;
			}
			in = new_s;
		}
		vector<string>::iterator iter_clear = ONE.begin();
		for (; iter_clear != ONE.end(); )
		{
			iter_clear = ONE.erase(iter_clear);
		}
	}
	return 0;
}