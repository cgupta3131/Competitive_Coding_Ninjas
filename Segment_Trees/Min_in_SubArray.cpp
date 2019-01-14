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

void buildTree(int *arr, int *tree, int start, int end, int treeNode)
{

	if(start == end)
	{
		tree[treeNode] = arr[start];
		return;
	}

	int mid = (start+end)/2;

	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);

	tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);
}	

int query(int *tree, int start, int end, int treeNode, int left, int right)
{

	if(left > end || right < start)
		return INT_MAX;

	if(left <= start && right >= end)
		return tree[treeNode];

	int mid = (start+end)/2;

	int ans1 = query(tree,start,mid,2*treeNode,left,right);
	int ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);

	return min(ans1,ans2);
}


void update(int *arr, int *tree, int start, int end, int treeNode, int idx, int value)
{
	if(start == end)
	{
		arr[idx] = value;
		tree[treeNode] = value;
		return;
	}

	int mid = (start+end)/2;

	if(idx <= mid)
		update(arr,tree,start,mid,2*treeNode,idx,value);
	else
		update(arr,tree,mid+1,end,2*treeNode+1,idx,value);

	tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);

}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,q;
    cin >> n >> q;

    int *arr = new int[n];
    for(int i=0;i<n;i++)
    	cin >> arr[i];

    int *tree = new int[4*n];
    for(int i=0;i<4*n;i++)
    	tree[i] = -1;

    buildTree(arr, tree, 0, n-1, 1);


    for(int i=0;i<q;i++)
    {
    	char ch;
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    	cin >> ch;

    	if(ch == 'q')
    	{
    		int l,r;
    		cin >> l >> r;
    		cout << query(tree,0,n-1,1,l-1,r-1) << endl;
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



