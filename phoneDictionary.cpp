#include <bits/stdc++.h>
using namespace std;
const int MAXN = 256;
const int poolsize = (int)1e6+9;
struct Node {
	vector<string> name;
	struct Node *CHILD[MAXN];
	int eof;
}pool[poolsize];

struct Node *getNode() {
	static int cnt = -1;
	struct Node *t = &pool[++cnt];
	for (int i = 0; i < MAXN; ++i) {
		t->CHILD[i] = nullptr;
	}
	t->eof = 0;
	t->name.clear();
	return t;
}


class Phone {
	private:
		//vector<string> name;
		//vector<string> phone;
		struct Node *root;
	public:
		Phone() {
			name.clear();
			phone.clear();
			delete root;
			root = getNode();
		}
    
		virtual ~Phone() {
			cnt = -1;
			delete root;
		}

		void insertTrie(string Number, string Name) {
			struct Node *ptr = root;
			for (int i = 0; i < Number.length(); ++i) {
				int index = Number[i];
				if(ptr->CHILD[index] == nullptr) {
					ptr->CHILD[index] = getNode();
				}
				ptr = ptr->CHILD[index];
			}
			ptr->eof = 1;
			ptr->name.push_back(Name);
			return ;
		}

		void insert(string Name, string Number) {
			//cout << "insert Called\n";
			//name.push_back(Name);
			//phone.push_back(Number);
			insertTrie(Number, Name);
		}

		vector<string> search(string number) {
			struct Node *ptr = root;
			for (int i = 0; i < number.length(); ++i) {
				int index = number[i];
				if(ptr->CHILD[index] == nullptr) {
					vector<string> r;
					r.clear();
					return r;
				}
				ptr = ptr->CHILD[index];
			}
			if(ptr->eof == 1 && ptr != nullptr)
				return ptr->name;
			else {
				vector<string> v;
				v.clear();
				return v;
			}
		}

		void getNamesFromNumber(string number) {
			vector<string> r = search(number);
			if((int)r.size() == 0) {
				cout << "number does not exist in the dictionary" << '\n';
			} else {
				cout << "names which are present into the dictionary" << '\n';
				for (auto &s: r) {
					cout << s << " ";
				}
// 				cout << '\n';
			}
		}
};

int main() {
	Phone p;
	p.insert("AJAY", "8445933880");
	p.getNamesFromNumber("8445933880");
	p.getNamesFromNumber("8445933881");
	return 0;
}
