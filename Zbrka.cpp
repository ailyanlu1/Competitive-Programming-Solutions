#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 10010
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

/* 
 * DP works like this: Value for each row increases up until N = C, when this happens, the row then decreases
 * DP[0][i] = value if previous element is LESS THAN OR EQUAL TO the current element, with confusion of i
 * DP[1][i] = value if previous element is GREATER THAN the current element, with confusion of i
 */

int N, C;
ll DP[2][MAXN];

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> C;
	DP[1][0] = 1;
	for (int i=2; i<=N; i++) {
		for (int j=0; j<=C; j++) {
			DP[i & 1][j] = (((j ? DP[i & 1][j - 1] : 0) + (DP[(i & 1) ^ 1][j]) - (j >= i ? DP[(i & 1) ^ 1][j - i] : 0)) + MOD) % MOD;
		}
	}
	cout << (DP[N & 1][C] + MOD) % MOD << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */