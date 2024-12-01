class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> s; // To store previously seen elements
        
        for (int x : arr) {
            // Check if 2 * x or x / 2 (if x is even) exists in the set
            if (s.find(2 * x) != s.end() || (x % 2 == 0 && s.find(x / 2) != s.end())) {
                return true;
            }
            s.insert(x); // Add current element to the set
        }
        
        return false; // No such pair found
    }
};