//#include <iostream>;
//using namespace std;
//
//int population_size = 200;
//float p_crossover = 0.9;
//float p_mutation = 0.1;
//int max_generations = 50;
//
//
//struct Node {
//	int val[2];
//	Node* next;
//
//	Node()
//	{
//		val[0] = 0;
//		val[1] = 0;
//		next = nullptr;
//	}
//	Node(int _val, int pod)
//	{
//		val[0] = _val;
//		val[1] = pod;
//		next = nullptr;
//	}
//};
//
//struct list {
//	Node* first;
//	Node* last;
//
//	list() : first(nullptr), last(nullptr) {}
//
//	bool is_empty() {
//		return first == nullptr;
//	}
//
//	void push_back(string _val, string pod) {
//		Node* p = new Node(_val, pod);
//		if (is_empty()) {
//			first = p;
//			last = p;
//			return;
//		}
//		last->next = p;
//		last = p;
//	}
//
//	Node* find(string _val) {
//		Node* p = first;
//		while (p && p->val[0] != _val) p = p->next;
//		cout << p->val[1] << endl;
//		return (p && p->val[0] == _val) ? p : nullptr;
//	}
//
//	void remove_first() {
//		if (is_empty()) return;
//		Node* p = first;
//		first = p->next;
//		delete p;
//	}
//
//	void remove_last() {
//		if (is_empty()) return;
//		if (first == last) {
//			remove_first();
//			return;
//		}
//		Node* p = first;
//		while (p->next != last) p = p->next;
//		p->next = nullptr;
//		delete last;
//		last = p;
//	}
//
//	void remove(string _val) {
//		if (is_empty()) return;
//		if (first->val[0] == _val) {
//			remove_first();
//			return;
//		}
//		else if (last->val[0] == _val) {
//			remove_last();
//			return;
//		}
//		Node* slow = first;
//		Node* fast = first->next;
//		while (fast && fast->val[0] != _val) {
//			fast = fast->next;
//			slow = slow->next;
//		}
//		if (!fast) {
//			cout << "not exist" << endl;
//			return;
//		}
//		slow->next = fast->next;
//		delete fast;
//	}
//
//	//void replace(list l, string _val1, string _val2)
//	//{
//	//	string temp;
//	//	temp = l.find(_val2)->val;
//	//	l.find(_val2)->val = l.find(_val1)->val;
//	//	l.find(_val1)->val = temp;
//	//}
//
//	Node* operator[] (const int index) {
//		if (is_empty()) return nullptr;
//		Node* p = first;
//		for (int i = 0; i < index; i++) {
//			p = p->next;
//			if (!p) return nullptr;
//		}
//		return p;
//	}
//
//	void print() {
//		if (is_empty()) return;
//		Node* p = first;
//		while (p) {
//			cout << p->val[0] << ":" << p->val[1];
//			p = p->next;
//		}
//		cout << endl;
//	}
//
//};
//
//int FitnessMax()
//{
//	int values = 0;
//	return values;
//};
//
//class individual
//{
//private:
//	list* ind;
//public:
//
//	int fitness = 0;
//	individual(int n)
//	{
//		ind = new list[n];
//		this->fitness = FitnessMax();
//	}
//
//
//};
//
//int oneMaxFitness(individual a,int n)
//{
//	for(int i = 0;i < n;i++)
//	{
//
//	}
//}
//
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	cout << "Введите количество предметов: ";
//	int n;
//	cin >> n;
//	Node *predmet=new Node[n];
//	//int one_max_length = n;
//	for (int i = 0;i < n;i++)
//	{
//		cout << "Вес " << i << " предмета: ";
//		cin >> predmet[i].val[0];
//		cout << "Значимость " << i << " предмета: ";
//		cin >> predmet[i].val[1];
//	}
//
//
//	system("PAUSE");
//	return 0;
//}