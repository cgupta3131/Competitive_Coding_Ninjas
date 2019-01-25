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

class Point
{
public:
	double x,y;
};

class Polygon{
public:
	Point *points;
	Polygon(int npoints)
	{
		points = new Point[npoints];
	}

};


double area(Polygon p, int n)
{
	double fArea = 0;

	for(int i=1;i<n-1;i++)
	{
		double x1 = p.points[i].x - p.points[0].x;
		double y1 = p.points[i].y - p.points[0].y;

		double x2 = p.points[i+1].x - p.points[0].x;
		double y2 = p.points[i+1].y - p.points[0].y;

		double cross_product = x1*y2 - x2*y1;

		fArea += cross_product/2;
	}

	return abs(fArea);

}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << "Enter the number of points for the polygon" << endl;
    int n;
    cin >> n;

    Polygon p(n);
    cout << "Enter the coordinates for polygon" << endl;

    for(int i=0;i<n;i++)
    	cin >> p.points[i].x >> p.points[i].y;
    
    cout << "Area of Polygon is : " << area(p,n) << endl;
	
	return 0 ; 

}



