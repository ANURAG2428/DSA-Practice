class MedianFinder {
public:
    // step 1 : create max-heap pq1 and min-heap pq2
    priority_queue<int> pq1; // Max-heap Pq

    priority_queue<int, vector<int>, greater<int>> pq2;

    MedianFinder() {}

    void addNum(int num) {
        pq1.push(num);       // max-heap mein daalo
        pq2.push(pq1.top()); // max-heap ka max min-heap mein
        pq1.pop();

        if (pq2.size() > pq1.size()) { // balance
            pq1.push(pq2.top());
            pq2.pop();
        }
    }

    double findMedian() {
        // step 4 : now whenever asked to get the median , firsly check size of
        // pq1.size() and pq2.size()
        if (pq1.size() > pq2.size())
            return pq1.top();
        return (pq1.top() + pq2.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */