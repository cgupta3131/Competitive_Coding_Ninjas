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

class Node{
public:
	int maxA;
	int minB;
	int index;

	Node()
	{
		maxA = minB = index = -1;
	}
};

void buildTree(int *A, int *B, Node *tree, int start, int end, int treeNode) 
{
	
	if(start == end)
	{	
		//cout << "TreeNode : " << treeNode << endl;
		//cout << start << " " << end << " " << A[start] << " " << B[start] << endl;
		tree[treeNode].maxA = A[start];
		tree[treeNode].minB = B[start];
		tree[treeNode].index = start;

		return;
	}

	int mid = (start+end)/2;
	buildTree(A,B,tree,start,mid,2*treeNode);
	buildTree(A,B,tree,mid+1,end,2*treeNode+1);

	int left = 2*treeNode;
	int right = 2*treeNode+1;

	Node first = tree[left];
	Node second = tree[right];
	Node &output = tree[treeNode];

	if(first.maxA > second.maxA)
	{
		output.maxA = first.maxA;
		output.minB = first.minB;
		output.index = first.index;
	}

	else if(first.maxA < second.maxA)
	{
		output.maxA = second.maxA;
		output.minB = second.minB;
		output.index = second.index;
	}

	else
	{
		if(first.minB > second.minB)
		{
			output.maxA = second.maxA;
			output.minB = second.minB;
			output.index = second.index;
		}

		else if(first.minB < second.minB)
		{
			output.maxA = first.maxA;
			output.minB = first.minB;
			output.index = first.index;
		}

		else
		{
			output.maxA = first.maxA;
			output.minB = first.minB;
			output.index = first.index;
		}
	}
}


Node query(Node *tree, int start, int end, int treeNode, int l, int r)
{


	if(l > end || r < start)
	{
		Node temp;
		return temp;
	}

	if(l<=start && r>=end)
		return tree[treeNode];

	int mid = (start+end)/2;
	Node first = query(tree,start,mid,2*treeNode,l,r);
	Node second = query(tree,mid+1,end,2*treeNode+1,l,r);

	int left = 2*treeNode;
	int right = 2*treeNode+1;
	Node output = tree[treeNode];

	if(first.maxA > second.maxA)
	{
		output.maxA = first.maxA;
		output.minB = first.minB;
		output.index = first.index;
	}

	else if(first.maxA < second.maxA)
	{
		output.maxA = second.maxA;
		output.minB = second.minB;
		output.index = second.index;
	}

	else
	{
		if(first.minB > second.minB)
		{
			output.maxA = second.maxA;
			output.minB = second.minB;
			output.index = second.index;
		}

		else if(first.minB < second.minB)
		{
			output.maxA = first.maxA;
			output.minB = first.minB;
			output.index = first.index;
		}

		else
		{
			output.maxA = first.maxA;
			output.minB = first.minB;
			output.index = first.index;
		}
	}

	return output;
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int *A = new int[n];
    int *B = new int[n];

    for(int i=0;i<n;i++)
    	cin >> A[i];
     for(int i=0;i<n;i++)
    	cin >> B[i];

    Node *tree = new Node[4*n];
	buildTree(A,B,tree,0,n-1,1); 

	int q;
	cin >> q;
	while(q--)
	{
		int l,r;
		cin >> l >> r;

		Node temp = query(tree,0,n-1,1,l-1,r-1);
		cout << temp.index + 1 << endl;
	}   
	
	return 0 ; 

}



