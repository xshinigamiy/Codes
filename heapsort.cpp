#include <bits/stdc++.h>
using namespace std;

class Heap {
	private:
	vector<int> a;
	int size;

	public:
	Heap(int SIZE){
		this->size = 0;
		a.resize(SIZE);
		for (int i = 0; i < SIZE; ++i)
			a[i] = 0;
	}

	void insert(int x) {
		// if()
		// a.push_back(x);
		if(this->size >= a.size())
			return ;
		a[this->size] = x;
		++(this->size);
	}

	void heapify(int i) {
		int largest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;

		if(l < size && a[l] > a[largest])
			largest = l;

		if(r < size && a[r] > a[largest])
			largest = r;

		if(largest != i){
			// swap(a[i], a[largest]);
			int t = a[i];
			a[i] = a[largest];
			a[largest] = t;
			heapify(largest);
		}
	}

	void build_heap() {
		for(int i = this->size/2; i >= 0; --i)
			heapify(i);
	}

	void heapsort() {
		build_heap();
		int tmp = this->size;
		for (int i = this->size - 1; i >= 0; --i) {
			// swap(a[0], a[i]);
			int t = a[0];
			a[0] = a[i];
			a[i] = t;
			--(this->size);
			heapify(0);
		}
		this->size = tmp;
	}

	void print() {
		// for (int i = 0; i < a.size(); ++i)
		for (int i = 0; i < this->size; ++i) {
			cout << a[i] << " ";
		}
		cout << '\n';
	}
};

int main() {
	// int a[] = {12, 1, 78, 90, 57, 89, 56};
	// int n = sizeof(a)/ sizeof(a[0]), k = 3;
	// // findMax(a, n, k);
	// Quicksort(a, 0, n - 1);
	// for (const int &x: a) {
	// 	cout << x << " ";
	// }
	// cout << '\n';
	Heap h(10);
	h.insert(1);
	h.insert(13);
	h.insert(2);
	h.insert(564);
	h.insert(1231);
	h.insert(123);
	h.heapsort();
	h.print();
	return 0;
}
