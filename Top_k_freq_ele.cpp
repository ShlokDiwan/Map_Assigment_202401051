#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;

    priority_queue<pair<int, int>> pq;
    for (auto& [num, count] : freq) pq.push({count, num});

    vector<int> result;
    while (k-- && !pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}

int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cin >> k;

    vector<int> result = topKFrequent(nums, k);
    for (int num : result) cout << num << " ";
    cout << endl;
}
