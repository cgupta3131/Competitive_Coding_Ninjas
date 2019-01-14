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

class triplet{

public:
	int a,b,c; //a denotes left side, b denotes the middle part and c denotes the right part

};	


void buildTree(int *arr, triplet *tree, int start, int end, int treeNode)
{
	if(start == end)
	{
		tree[treeNode].a = 0;
		tree[treeNode].b = arr[start];
		tree[treeNode].c = 0;

		return;
	}


	int mid =(start+end)/2;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);

	int a1 = tree[2*treeNode].a;
	int b1 = tree[2*treeNode].b;
	int c1 = tree[2*treeNode].c;
	int a2 = tree[2*treeNode+1].a;
	int b2 = tree[2*treeNode+1].b;
	int c2 = tree[2*treeNode+1].c;

	int maxi = max(max(b1,b2),b1+b2+c1+a2);

	if(maxi == b1)
	{	
		tree[treeNode].a = a1;
		tree[treeNode].b = b1;
		tree[treeNode].c = c1+a2+b2+c2;
	}

	else if(maxi == b2)
	{	
		tree[treeNode].a = a1+b1+c1+a2;
		tree[treeNode].b = b2;
		tree[treeNode].c = c2;
	}

	else
	{	
		tree[treeNode].a = a1;
		tree[treeNode].b = b1+c1+a2+b2;
		tree[treeNode].c = c2;
	}
}


triplet query(triplet *tree, int start, int end, int treeNode, int left, int right)
{

	if(left > end || right < start)
	{
		triplet temp;
		temp.a = 0;
		temp.b = 0;
		temp.c = 0;

		return temp;
	}

	if(left<=start && right>=end)
		return tree[treeNode];

	int mid = (start+end)/2;

	triplet first = query(tree,start,mid,2*treeNode,left,right);
	triplet second = query(tree,mid+1,end,2*treeNode+1,left,right);

	int a1 = first.a;
	int b1 = first.b;
	int c1 = first.c;
	int a2 = second.a;
	int b2 = second.b;
	int c2 = second.c;

	triplet output;

	int maxi = max(max(b1,b2),b1+b2+c1+a2);

	if(maxi == b1)
	{	
		output.a = a1;
		output.b = b1;
		output.c = c1+a2+b2+c2;
	}

	else if(maxi == b2)
	{	
		output.a = a1+b1+c1+a2;
		output.b = b2;
		output.c = c2;
	}

	else
	{	
		output.a = a1;
		output.b = b1+c1+a2+b2;
		output.c = c2;
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

    int *arr = new int[n];

    for(int i=0;i<n;i++)
    	cin >> arr[i];

    triplet *tree = new triplet[4*n];

    for(int i=0;i<4*n;i++)
    {
    	tree[i].a = 0;
    	tree[i].b = 0;
    	tree[i].c = 0;
    }

    buildTree(arr,tree,0,n-1,1);
   /*   for(int i=0;i<4*n;i++)
    {
    	if(tree[i].a == 0 && tree[i].b == 0 && tree[i].c == 0)
    		continue;
    	else
    		cout << tree[i].a << " " << tree[i].b << " " << tree[i].c << "\n";
    }  */

    

    int q;
    cin >> q;

    while(q--)
    {
    	int l,r;
    	cin >> l >> r;

    	triplet temp = query(tree,0,n-1,1,l-1,r-1);
    	cout << temp.b << "\n";

    }


    	
    
    
	
	return 0 ; 

}



