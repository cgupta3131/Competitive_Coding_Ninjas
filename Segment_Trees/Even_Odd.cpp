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
		if(arr[start]%2 == 0) //means even number!
			tree[treeNode].first = 1;
		else
			tree[treeNode].second = 1;

		return;
	}

	int mid = (start+end)/2;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);

	tree[treeNode].first = tree[2*treeNode].first + tree[2*treeNode+1].first;
	tree[treeNode].second = tree[2*treeNode].second + tree[2*treeNode+1].second;

}

void update(int *arr, pii *tree, int start, int end, int treeNode, int idx, int value)
{
	if(start == end)
	{
		arr[idx] = value;
		if(value%2 == 0) 
		{
			tree[treeNode].first = 1;
			tree[treeNode].second = 0;
		}
		else
		{
			tree[treeNode].first = 0;
			tree[treeNode].second = 1;
		}

		return;
	}


	int mid = (start+end)/2;
	if(idx > mid)
		update(arr,tree,mid+1,end,2*treeNode+1,idx,value);
	else
		update(arr,tree,start,mid,2*treeNode,idx,value);

	tree[treeNode].first = tree[2*treeNode].first + tree[2*treeNode+1].first;
	tree[treeNode].second = tree[2*treeNode].second + tree[2*treeNode+1].second;
}


int query(pii *tree, int start, int end, int treeNode, int left, int right, int a)
{

	if(end < left || start > right)
		return 0;

	if(left <= start && right >= end)
	{
		if(a == 1)
			return tree[treeNode].first;
		else
			return tree[treeNode].second;
	}

	int mid = (start+end)/2;
	int ans1 = query(tree,start,mid,2*treeNode,left,right,a);
	int ans2 = query(tree,mid+1,end,2*treeNode+1,left,right,a);

	return ans1+ans2;
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
   	//pair<even,odd>
   	for(int i=0;i<4*n;i++)
   	{
   		tree[i].first = 0;
   		tree[i].second = 0;
   	}

   	buildTree(arr,tree,0,n-1,1);
   	

   	int q;
   	cin >> q;

   	while(q--)
   	{

   		int a,x,y;
   		cin >> a >> x >> y;

   		if(a == 0) //update the index arr[x-1] to y
   			update(arr,tree,0,n-1,1,x-1,y);
   		else
   			cout << query(tree,0,n-1,1,x-1,y-1,a) << "\n";

   	}
	
	return 0 ; 

}



