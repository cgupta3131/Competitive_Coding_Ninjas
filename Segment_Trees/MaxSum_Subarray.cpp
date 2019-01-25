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
	int maxPrefixSum;
	int maxSuffixSum;
	int totalSum;
	int maxSubarraySum;

	Node()
	{
		maxPrefixSum = maxSuffixSum = maxSubarraySum = totalSum = -100000;

	}
};	

int max_value(int a,int b, int c, int d, int e)
{
	return max(a,max (b, max (c,max(d,e) ) ) );
}

void buildTree(int *arr, Node *tree, int start, int end, int treeNode)
{
	if(start == end)
	{
		//cout << "Start : " << start << endl;
		//cout << "treeNode : " << treeNode << endl;
		tree[treeNode].maxPrefixSum = arr[start];
		tree[treeNode].maxSuffixSum = arr[start];
		tree[treeNode].totalSum = arr[start];
		tree[treeNode].maxSubarraySum = arr[start];

		return;
	}


	int mid =(start+end)/2;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);

	tree[treeNode].maxPrefixSum = max(tree[2*treeNode].maxPrefixSum, 
							tree[2*treeNode].totalSum + tree[2*treeNode+1].maxPrefixSum);

	tree[treeNode].maxSuffixSum = max(tree[2*treeNode+1].maxSuffixSum, 
							tree[2*treeNode+1].totalSum + tree[2*treeNode].maxSuffixSum);

	tree[treeNode].totalSum = tree[2*treeNode].totalSum + tree[2*treeNode+1].totalSum;

	tree[treeNode].maxSubarraySum = max_value(tree[2*treeNode].maxSubarraySum, 
									tree[2*treeNode+1].maxSubarraySum, 
									tree[2*treeNode].maxSuffixSum + 
									tree[2*treeNode+1].maxPrefixSum, 
									tree[treeNode].maxPrefixSum,
									tree[treeNode].maxSuffixSum);
}


Node query(Node *tree, int start, int end, int treeNode, int left, int right)
{

	if(left > end || right < start)
	{
		Node temp;
		return temp;
	}

	if(left<=start && right>=end)
		return tree[treeNode];

	int mid = (start+end)/2;


	Node first = query(tree,start,mid,2*treeNode,left,right);
	Node second = query(tree,mid+1,end,2*treeNode+1,left,right);

	Node output;

	output.maxPrefixSum = max(first.maxPrefixSum, first.totalSum + second.maxPrefixSum);
	output.maxSuffixSum = max(second.maxSuffixSum, second.totalSum + first.maxSuffixSum);
	output.totalSum = first.totalSum + second.totalSum;
	output.maxSubarraySum = max_value(first.maxSubarraySum, second.maxSubarraySum, 
									first.maxSuffixSum + second.maxPrefixSum,
									output.maxPrefixSum, output.maxSuffixSum);

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

    Node *tree = new Node[4*n];

    buildTree(arr,tree,0,n-1,1);
    /*  for(int i=0;i<4*n;i++)
    {
    	cout << i << " " << tree[i].maxSubarraySum << endl;
    }  */    

    //cout << endl;
    int q;
    cin >> q;
    //cout << "QUERIES " << endl;
    while(q--)
    {
    	int l,r;
    	cin >> l >> r;

    	Node temp = query(tree,0,n-1,1,l-1,r-1);
    	cout << temp.maxSubarraySum << endl;

    }  


    	
    
    
	
	return 0 ; 

}



