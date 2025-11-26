#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int a[100];
    int size;

    PriorityQueue() { size = 0; }

    void insert(int x) {
        a[size] = x;
        int i = size;
        size++;

        while(i > 0 && a[(i-1)/2] < a[i]) {
            swap(a[(i-1)/2], a[i]);
            i = (i-1)/2;
        }
    }

    int extractMax() {
        if(size == 0) return -1;

        int root = a[0];
        a[0] = a[size-1];
        size--;

        heapify(0);
        return root;
    }

    void heapify(int i) {
        int largest = i;
        int l = 2*i+1, r = 2*i+2;

        if(l < size && a[l] > a[largest]) largest = l;
        if(r < size && a[r] > a[largest]) largest = r;

        if(largest != i) {
            swap(a[i], a[largest]);
            heapify(largest);
        }
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(30);
    pq.insert(10);
    pq.insert(50);

    cout << pq.extractMax() << endl; // 50
}

