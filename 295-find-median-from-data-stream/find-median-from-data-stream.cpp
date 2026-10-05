class MedianFinder {
public:
    // step 1 : create max-heap pq1 and min-heap pq2
    priority_queue<int> pq1; // Max-heap Pq

    priority_queue<int, vector<int>, greater<int>> pq2;

    MedianFinder() {}

    void addNum(int num) {
        // step 1 : will always add new element to pq1 (always)
        pq1.push(num);
        // step 2 : now push top most (max-element) of pq1 in pq2 
        pq2.push(pq1.top());
        // step 3 : now remove the top-most element from pq1
        pq1.pop();

        // Now if pq1.size() < pq2.size() -> so here itself in addNum will adjust the 2 pq's => where pq1.size() should be 1 more than pq2.size()
        if(pq1.size() < pq2.size()){
            // do below 2 steps
            pq1.push(pq2.top());
            pq2.pop();
        }

    }

    double findMedian() {
        // Now we have to return median , so addnum() method is taking care of both pq's to mantain the req no of elements such that in case of even or odd no of arrays they return correct median
        
        // if odd no of elemets in total
        if(pq1.size() > pq2.size()) return pq1.top();

        // for even no of elements will return ((sum of both pq's top) /2)
        else return ((pq1.top() + pq2.top())/2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */