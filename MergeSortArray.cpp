#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int idx = m + n - 1;

    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] >= nums2[p2]) {
            nums1[idx] = nums1[p1];
            p1--;
        } else {
            nums1[idx] = nums2[p2];
            p2--;
        }
        idx--;
    }

    while (p2 >= 0) {
        nums1[idx] = nums2[p2];
        p2--;
        idx--;
    }
}

int main() {
    vector<int> nums1 = {2, 4, 6, 0, 0, 0};
    vector<int> nums2 = {4, 10, 12};

    int m = 3;
    int n = 3;

    merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int x : nums1) {
        cout << x << " ";
    }

    return 0;
}