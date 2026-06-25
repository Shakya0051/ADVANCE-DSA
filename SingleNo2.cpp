#include <iostream>
using namespace std;

int singleNumber(int nums[], int n) {
    int ans = 0;

    for (int i = 0; i < 32; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if ((nums[j] >> i) & 1) {
                count++;
            }
        }

        if (count % 3) {
            ans |= (1 << i);
        }
    }

    return ans;
}

int main() {
    int nums[] = {2, 2, 3, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << singleNumber(nums, n);

    return 0;
}