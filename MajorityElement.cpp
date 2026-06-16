#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for (int num : nums) {
        if (count == 0)
            candidate = num;

        if (num == candidate)
            count++;
        else
            count--;
    }

    return candidate;
}

int main() {
    vector<int> nums = {4, 4, 2, 2, 2, 4, 4};

    cout << "Majority Element: "
         << majorityElement(nums) << endl;

    return 0;
}