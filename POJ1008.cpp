#include <iostream>
#include <string>
using namespace std;
int main()
{
	string Haab[20]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu"};
	string Tzolkin[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
	int n;
	int time,year,m;
	string month;
	int num;
	cin>>n;
	cout<<n<<endl;
	for (int i=0;i<n;i++)
	{
		cin>>time>>month>>year;
		for (int j=0;j<20;j++)
		{
			if(month.compare(Haab[j]) == 0)
			{
				m=j;
				break;
			}
		}
		num = time + m*20 + year*365;
		cout<<num%13+1<<" "<<Tzolkin[num%20]<<" "<<num/260<<endl;
	}
	return 0;
}