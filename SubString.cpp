#include <iostream>
#include <string>
#include <vector>
using namespace std;

int numberOfSubstrings(string s) {
    vector<int> cnt(3, 0);
    int left = 0;
    int ans = 0;
    int n = s.size();

    for (int right = 0; right < n; right++) {
        cnt[s[right] - 'a']++;

        while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
            ans += (n - right);
            cnt[s[left] - 'a']--;
            left++;
        }
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << numberOfSubstrings(s);

    return 0;
}