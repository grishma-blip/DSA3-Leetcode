class Solution {
public:
    vector<int> ans;

    void mergeSort(vector<pair<int,int>>& v, int l, int r) {
        if (l >= r) return;

        int mid = (l + r) / 2;

        mergeSort(v, l, mid);
        mergeSort(v, mid + 1, r);

        vector<pair<int,int>> temp;

        int i = l;
        int j = mid + 1;

        int rightCount = 0;

        while (i <= mid && j <= r) {

            if (v[j].first < v[i].first) {
                rightCount++;
                temp.push_back(v[j++]);
            }
            else {
                ans[v[i].second] += rightCount;
                temp.push_back(v[i++]);
            }
        }

        while (i <= mid) {
            ans[v[i].second] += rightCount;
            temp.push_back(v[i++]);
        }

        while (j <= r) {
            temp.push_back(v[j++]);
        }

        for (int k = l; k <= r; k++) {
            v[k] = temp[k - l];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        ans.assign(n, 0);

        vector<pair<int,int>> v;

        for (int i = 0; i < n; i++)
            v.push_back({nums[i], i});

        mergeSort(v, 0, n - 1);

        return ans;
    }
};
