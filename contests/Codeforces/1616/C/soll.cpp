
// C++ program to find the minimum number
// of changes required to make the given
// array an AP with common difference d
#include <bits/stdc++.h>
using namespace std;
 
// Function to find the minimum number
// of changes required to make the given
// array an AP with common difference d
int minimumChanges(vector<int> arr, int n, int d)
{
    int maxFreq = INT_MIN;
 
    // Map to store frequency of a0
    unordered_map<int, int> freq;
 
    // storing frequency of a0 for all possible
    // values of a[i] and finding the maximum
    // frequency
    for (int i = 0; i < n; ++i) {
        int a0 = arr[i] - (i)*d;
 
        // increment frequency by 1
        if (freq.find(a0) != freq.end()) {
            freq[a0]++;
        }
        else
            freq.insert(make_pair(a0, 1));
 
        // finds count of most frequent number
        if (freq[a0] > maxFreq)
            maxFreq = freq[a0];
    }
 
    // minimum number of elements needed to
    // be changed is: n - (maximum frequency of a0)
    return (n - maxFreq);
}
 
// Driver Program
int main()
{
	int N; cin >> N;
	vector<int> A(N); for(auto &x : A) cin >> x;
 
    cout << minimumChanges(A, N, d);
 
    return 0;
}
