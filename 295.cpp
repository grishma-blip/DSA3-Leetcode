class MedianFinder {
public:
    priority_queue<int> left; // max heap

    priority_queue<int, vector<int>, greater<int>> right; // min heap

    MedianFinder() {

    }

    void addNum(int num) {

        left.push(num);

        right.push(left.top());
        left.pop();

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {

        if (left.size() > right.size())
            return left.top();

        return (left.top() + right.top()) / 2.0;
    }
};
