#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cassert>
#include<numeric>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<deque>
#include<stack>
using namespace std; 
vector<int> arr;
void solve(int n) {
    int val = n;
    for (int i = 0; i <= n; i++) {
	   for (int j = 2; j <= n; j++) {
		  if (val%j == 0) { arr[j]++; val /= j; break; }
	   }
	   if (val == 1) { break; }
    }
}
void solve2(int n) {
    for (int i = 2; i <= n; i++) {
	   solve(i);
    }
}
int main() {
   
    int N;
    cin >> N;
    for (int i = 0; i < N + 10; i++) { arr.push_back(0); }
    solve2(N);
    string s = "";
    for (int i = 0; i < N+10; i++) {
	   int a = i;
	   int b;
	   if (arr[i] != 0) { b = arr[i]; }
	   if (arr[i] == 0) { continue; }
	   stringstream ss;
	   ss << a;
	   s += ss.str();
	   s += '^';
	   stringstream ss2;
	   ss2 << b;
	   s += ss2.str();
	   s += '*';
    }
    for (int i = 0; i < s.length() - 1; i++) {
	   cout << s[i];
    }
    cout << endl;
    system("pause");
}