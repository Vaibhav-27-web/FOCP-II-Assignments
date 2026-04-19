#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

  
    set<int> s(a.begin(), a.end());

    
    vector<int> v(s.begin(), s.end());
    sort(v.rbegin(), v.rend());

    long long alex = 0, bob = 0;

   
    for(int i = 0; i < v.size(); i++) {
        if(i % 2 == 0) alex += v[i];
        else bob += v[i];
    }

 
    if(alex > bob) cout << "Alex\n";
    else cout << "Bob\n";

    return 0;
}
