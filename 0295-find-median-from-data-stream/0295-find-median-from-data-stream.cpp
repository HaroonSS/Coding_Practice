#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> lowerHalf; // Max-heap for the smaller half
    priority_queue<int, vector<int>, greater<int>> upperHalf; // Min-heap for the larger half

public:
    MedianFinder() {}

    void addNum(int num) {
        // Add to max-heap (lowerHalf)
        lowerHalf.push(num);

        // Balance by moving the largest from lowerHalf to upperHalf
        upperHalf.push(lowerHalf.top());
        lowerHalf.pop();

        // Ensure size difference between heaps is at most 1
        if (lowerHalf.size() < upperHalf.size()) {
            lowerHalf.push(upperHalf.top());
            upperHalf.pop();
        }
    }

    double findMedian() {
        if (lowerHalf.size() > upperHalf.size()) {
            // Odd number of elements
            return lowerHalf.top();
        } else {
            // Even number of elements
            return (lowerHalf.top() + upperHalf.top()) / 2.0;
        }
    }
};
