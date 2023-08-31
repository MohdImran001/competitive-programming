// https://leetcode.com/problems/k-diff-pairs-in-an-array/
// 532. K - diff Pairs in an Array

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution
{
public:
    int findPairs(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        set<int> Set;

        int n = arr.size();
        for (int i = 0; i < n - 1; ++i)
        {
            int idx = lower_bound(arr.begin() + i + 1, arr.end(), arr[i] + k) - arr.begin();
            if (arr[idx] - arr[i] == k)
                Set.insert(arr[idx]);
        }

        return Set.size();
    }
};
