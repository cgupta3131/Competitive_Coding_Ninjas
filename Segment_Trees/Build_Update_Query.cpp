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

	tree[treeNode] = tree[2*treeNode]+tree[2*treeNode+1]; 
}

void updateTree(int *arr, int *tree, int start, int end, int treeNode, int idx, int value)
{
	if(start == end)
	{
		arr[idx] = value;
		tree[treeNode] = value; 
		return;
	}

	int mid = (start+end)/2;
	if(idx > mid) //go towards Right
		updateTree(arr,tree,mid+1,end,2*treeNode+1,idx,value);
	else //go towards Left
		updateTree(arr,tree,start,mid,2*treeNode,idx,value);

	tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];

}

int query(int *tree, int start, int end, int treeNode, int left, int right)
{

	//Completely outside the given range

	if(start > right || end < left)
		return 0;

	//Completely inside the given range

	if(start >=left && end <= right)
		return tree[treeNode];

	//Partialy inside and partially outside;

	int mid = (start+end)/2;
	int ans1 = query(tree,start,mid,2*treeNode,left,right);
	int ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);

	return ans1 + ans2;



}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int arr[] = {1,2,3,4,5};
	int *tree = new int[10];

	buildTree(arr,tree,0,4,1);

	/*  for(int i=1;i<10;i++)
		cout << tree[i] << "\n";
	cout << "\n";  */

	updateTree(arr, tree, 0, 4, 1, 2, 10);

	for(int i=1;i<10;i++)
		cout << tree[i] << "\n";
	cout << "\n";

	int ans = query(tree,0,4,1,2,4);
	cout << "Sum between the indices 2 and 4 is " << ans << "\n";

	return 0 ; 

}



