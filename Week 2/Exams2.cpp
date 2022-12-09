#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second < p2.second;
}

int check(vector<pair<int, int>> &l, vector<int> e, vector<int> &prep, int m, int n)
{
	for(pair<int, int> p : l)
	{
		int exam = p.first;
		cout<<exam<<" ";
		int last = p.second;
		int days = prep[exam-1];
		int i = 0;
		for(; i < e.size(), days > 0; i++)
		{
			if(e[i] != -1)
			{
				e[i] = -1;
				days--;
				if(days == 0)	break;
			}
		}
		if(i == e.size() and days > 0)	return -1;
		for(; i < e.size(); i++)
		{
			if(e[i] == exam)
			{
				e[i] = -1;
				cout<<"EXAM ON "<<i<<endl;
				break;
			}
		}
		if(i == e.size())	return -1;
	}
	cout<<endl;
	int pos = 0;
	for(int i = 0; i < e.size(); i++)
	{
		cout<<i<<" "<<e[i]<<endl;
		if(e[i] == -1) pos = i;	
	}

	return pos+1;
}

int main()
{
	int m, n;	cin >> n >> m;
	vector<int> exams(n, 0);
	for(int i = 0; i < n; i++)	cin >> exams[i];
	vector<int> prep(m, 0);
	for(int i = 0; i < m; i++)	cin >> prep[i];
	vector<int> last(m+1, 0);
	for(int i = 0; i < n; i++)
	{
		// if(last[exams[i]] == 0)
			last[exams[i]] = i+1;
	}	
	vector<pair<int, int>> lasts;
	for(int i = 1; i < last.size(); i++)
	{
		if(last[i])
		lasts.push_back(make_pair(i, last[i]));
	} 
	sort(lasts.begin(), lasts.end(), compare);
	for(pair<int, int> p : lasts)
	{
		cout<<p.first<<" "<<p.second<<endl;
	}
	cout<<endl;
	cout<<check(lasts, exams, prep, m, n);


	return 0;
}