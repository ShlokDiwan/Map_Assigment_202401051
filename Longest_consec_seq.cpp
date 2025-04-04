#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;

    for (int num : nums) {
        if (!numSet.count(num - 1)) {
            int currentNum = num, count = 1;
            while (numSet.count(currentNum + 1)) {
                currentNum++;
                count++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << longestConsecutive(nums) << endl;
}
