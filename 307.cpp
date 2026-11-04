class NumArray {
public:
    vector<int> tree;
    int n;

    void build(vector<int>& nums, int node, int start, int end){
        if(start == end){
            tree[node] = nums[start];
            return;
        }

        int mid = (start + end) / 2;
        build(nums, 2*node+1, start, mid);
        build(nums, 2*node+2, mid+1, end);

        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    void updateTree(int node, int start, int end, int idx, int val){
        if(start == end){
            tree[node] = val;
            return ;
        }

        int mid = (start + end) / 2;

        if(idx <= mid)
            updateTree(2*node+1, start, mid, idx, val);
        else
            updateTree(2*node+2, mid+1, end, idx, val);

        tree[node] = tree[2*node+1]+tree[2*node+2];
    }

    int query(int node, int start, int end, int left, int right){
        if(right < start || left > end)
            return 0;
        if(left <= start && end <= right)
            return tree[node];

        int mid = (start+end) / 2;

        return query(2*node+1, start, mid, left, right) + query(2*node+2, mid+1, end, left, right);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4*n);
        build(nums, 0, 0, n-1);
    }
    
    void update(int index, int val) {
        updateTree(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
