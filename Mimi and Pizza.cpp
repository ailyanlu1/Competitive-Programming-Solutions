#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int B, P;
string s;
bool flag;

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> B >> P >> s;
    if (s == "Y") {
    	if (P * 5 <= B) {
    		cout << "B" << endl;
    		return 0;
    	}
    	if (P * 2 <= B) {
    		cout << "D" << endl;
    		return 0;
    	}
    }
    else if (s == "N") {
    	if (P * 5 <= B) {
    		cout << "A" << endl;
    		return 0;
    	}
    	if (P * 2 <= B) {
    		cout << "C" << endl;
    		return 0;
    	}
    }
    cout << "NO PIZZA" << endl;
    return 0;
}