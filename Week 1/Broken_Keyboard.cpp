#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		bool a[26]{0};
		for(int i = 0; i < s.size(); i++)
		{
			int cnt = 1;
			while(i != s.size()-1 and s[i] == s[i+1])
			{
				i++;
				cnt++;
			}
			if(cnt % 2 == 1)	a[s[i] - 'a'] = true;	
		}

		for(int i = 0; i < 26; i++)
		{
			if(a[i])
			{
				char ch = i + 'a';
				cout<<ch;
			}
		}
		cout<<endl;
	}
	



	return 0;
}