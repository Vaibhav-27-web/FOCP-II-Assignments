#include <iostream>
using namespace std;


bool possible(string &s, int n, int m, int k) {
    int ops = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ops++;           
            if (ops > m) return false;

            i += k - 1;         
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int low = 1, high = n;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (possible(s, n, m, mid)) {
            ans = mid;          
            high = mid - 1;     
        } else {
            low = mid + 1;      
        }
    }

    cout << ans;
    return 0;
}
