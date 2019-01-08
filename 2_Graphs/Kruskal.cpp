#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007

//cin.ignore(numeric_limits<streamsize>::max(), '\n'); -> Clears the input buffer

class Edge{
public:
	int source;
	int destination;
	int weight;
};	

bool compare(Edge e1, Edge e2)
{
	return e1.weight < e2.weight;
}

int findParent(int v0, int *parent)
{
	if(parent[v0] == v0)
		return v0;

	return findParent(parent[v0],parent);
}


int main()
{
	
	int V;
	int E;
	cin >>	V >> E;

	Edge *input = new Edge[E];
	Edge *output = new Edge[V-1];

	for(int i=0;i<E;i++)
	{
		cin >> input[i].source;
		cin >> input[i].destination;
		cin >> input[i].weight;
	}

	sort(input,input+E,compare);

	/*  for(int i=0;i<E;i++)
		cout << input[i].weight << endl;  */

	int count = 0;
	int *parent = new int[V];

	for(int i=0;i<V;i++)
		parent[i] = i;

	for(int i=0;i<E;i++)
	{
		if(count == V-1)
			break;

		int v1 = input[i].source;
		int v2 = input[i].destination;
		int w = input[i].weight;

		int p1 = findParent(v1,parent);
		int p2 = findParent(v2,parent);

		if(p1 == p2) //Means that cycle has been detected
		{
			//cout << "Cycle Detection : ";
			//cout << v1 << " " << v2 << " " <<  w << endl;
			continue;
		}
		else
		{
			//Copying the contents to output array
			output[count] = input[i];

			//Updating the parents list
			parent[p1] = p2;
			count++;
		}
	}

	for(int i=0;i<V-1;i++)
	{
		int mini = min(output[i].source,output[i].destination );
		int maxi = max(output[i].source,output[i].destination );

		cout << mini << " " << maxi << " " << output[i].weight << endl;
	}


	return 0 ; 

}



