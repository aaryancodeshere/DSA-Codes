class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr = nums;
        for(int i=1; i<arr.size(); i++){
            arr[i]+=arr[i-1];
        }

    }
    
    int sumRange(int left, int right) {
        
        int sum = left!=0 ? (arr[right] - arr[left - 1]) : arr[right];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */