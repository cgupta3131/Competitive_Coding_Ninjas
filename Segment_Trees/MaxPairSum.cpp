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
void buildTree(int *arr, pii *tree, int start, int end, int treeNode)
{

	if(start == end)
	{
		tree[treeNode].first = -1;
		tree[treeNode].second = arr[start];

		return;
	}

	int mid = (start+end)/2;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);

	int a = tree[2*treeNode].first;
	int b = tree[2*treeNode].second;
	int c = tree[2*treeNode+1].first;
	int d = tree[2*treeNode+1].second;

	tree[treeNode].first = max( max(a,c),min(b,d));
	tree[treeNode].second = max(b,d);

}

void update(int *arr, pii *tree, int start, int end, int treeNode, int idx, int value)
{
	if(start == end)
	{
		arr[idx] = value;
		tree[treeNode].first = -1;
		tree[treeNode].second = value;
		return;
	}


	int mid = (start+end)/2;
	if(idx > mid)
		update(arr,tree,mid+1,end,2*treeNode+1,idx,value);
	else
		update(arr,tree,start,mid,2*treeNode,idx,value);

	int a = tree[2*treeNode].first;
	int b = tree[2*treeNode].second;
	int c = tree[2*treeNode+1].first;
	int d = tree[2*treeNode+1].second;

	tree[treeNode].first = max( max(a,c),min(b,d));
	tree[treeNode].second = max(b,d);
}

pii query(pii *tree, int start, int end, int treeNode, int left, int right)
{

	if(end < left || start > right)
	{
		pii temp;
		temp.first = -1;
		temp.second = -1;
		return temp;
	}

	if(left <= start && right >= end)
	{
		return tree[treeNode];
	}

	int mid = (start+end)/2;
	pii ans1 = query(tree,start,mid,2*treeNode,left,right);
	pii ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);

	int a = ans1.first;
	int b = ans1.second;
	int c = ans2.first;
	int d = ans2.second;

	pii output;
	output.first = max( max(a,c),min(b,d));
	output.second = max(b,d);

	return output;

}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n;
    cin >> n;

    int *arr = new int[n];
   	for(int i=0;i<n;i++)
   		cin >> arr[i];

   	pii *tree = new pii[4*n];
   	//pair<second_max, max>
   	for(int i=0;i<4*n;i++)
   	{
   		tree[i].first = -1;
   		tree[i].second = -1;
   	}

   	buildTree(arr,tree,0,n-1,1);

   	int q;
   	cin >> q;

   	while(q--)
   	{
   		char ch;
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    	cin >> ch;

    	if(ch == 'Q')
    	{
    		int x,y;
    		cin >> x >> y;
    		pii output = query(tree,0,n-1,1,x-1,y-1);

    		cout << output.first + output.second << "\n";
    	}

    	else
    	{
    		int x,y;
    		cin >> x >> y;

    		update(arr,tree,0,n-1,1,x-1,y);
    	}


   	}


	return 0 ; 

}



