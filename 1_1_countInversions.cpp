#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std; 

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define VECD(path,size)   for (int i = 0 ; i < size; ++i)  cout << path[i] << ' ';
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////

long long Merge(vector<long long>& A, ll low, ll mid, ll high)
{
	vector<long long> sorted_A;
	ll leftStart  = low;
	ll rightStart = mid;
	ll invertCount = 0;
	while(leftStart < mid && rightStart < high)
	{
		if(A[leftStart] <= A[rightStart])
	        {
		    sorted_A.push_back(A[leftStart++]); 
		}
		else
		{
		    invertCount += (mid - leftStart);
		    sorted_A.push_back(A[rightStart++]);
		}	
	}
	copy(A.begin() + leftStart, A.begin() + mid, back_inserter(sorted_A));
	copy(A.begin() + rightStart,A.begin() + high,back_inserter(sorted_A));
	copy(sorted_A.begin(),sorted_A.end(), A.begin() + low);
//	DEBUG(low);
//	DEBUG(high);
//	DEBUG(mid);
//	DEBUG(leftStart);
//	DEBUG(rightStart);
//	VECD(sorted_A,sorted_A.size());
//	cout <<"sorted array" << endl;
//	VECD(A,A.size());
//	cout << "original array " << endl;
//	cout << invertCount << endl;
	return invertCount;
}
long long countInversions(vector<long long>& A,ll low,ll high)
{
	if((high - low) <= 1) return 0;
	ll mid = low + ((high - low)/2);
//	cout << mid << endl;
	return countInversions(A,low,mid) + countInversions(A,mid,high) + Merge(A,low,mid,high);
}

int main()
{
    vector<long long> A;
    ll N;
    freopen("IntegerArray.txt","rb",stdin);
    while(cin >> N)
    {
//	    cout << N << ' ';
	    A.push_back(N);
    }
//    cout << A.size()  << endl;
    cout << countInversions(A,0,A.size()) << endl;
    return 0;
}
