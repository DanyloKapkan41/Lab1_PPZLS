

#include <iostream>
#include <string>
using namespace std;


struct Node {
	int data;
	Node* next;
};

Node* swapPairs(Node* head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	Node* newHead = head->next;
	head->next = swapPairs(newHead->next);
	newHead->next = head;
	return newHead;
}
Node* appendNode(Node* head, int value) {
	Node* newNode = new Node();
	newNode->data = value;
	newNode->next = head;
	return newNode;
}

void printList(Node* head) {

	if (head != nullptr) {
		Node* temp = head->next;
		cout << head->data << " ";
		printList(temp);
	}
}
/*void Second_Functi(Node* head, int n)
{
	if (n > 0)
	{
		int x;
		n--;
		cout << "Enter data to new node: ";
		cin >> x;
		appendNode(head, x);
		Second_Functi(head, n);
	}
	else return;
}*/
void First_Functi(string n, int i)
{
	if (i >= 0)
	{
		cout << n[i];
		i--;
		First_Functi(n, i);
	}
	else return;
}
void Third_Functi(int choose, int i, int Fib1, int Fib2)
{
	if (i % 2)
	{
		Fib1 = Fib1 + Fib2;
	}
	else {

		Fib2 = Fib2 + Fib1;
	}
	i++;
	if (i <= choose)
		Third_Functi(choose, i, Fib1, Fib2);
	else {
		if (i % 2)cout << "Result: " << Fib1;
		else cout << "Result: " << Fib2;
	}
}
int Fourth_Functi(int n)
{
	{
		if (n == 0) return 0;
		if (n == 1) return 1;
		int ways = Fourth_Functi(n - 1) + Fourth_Functi(n - 2);
		return ways;
	}
}
void Fifth_Functi(int n, double x, double res)
{
	if (n > 0 && res < 1e4)
	{
		n--;
		res = x * res;
		Fifth_Functi(n, x, res);
	}
	else if (n < 0 && res > -1e4)
	{
		n++;
		res = res / x;
		Fifth_Functi(n, x, res);
	}
	else if (res > -1e4 && res < 1e4) cout << "Result: " << res;
	else if (res > -1e4) { cout << "Result: >10000"; }
	else cout << "Result: <-10000";
}
void First_Ex()
{
	string Tiger;
	cout << " Enter string: ";
	cin >> Tiger;
	cout << " Vasha nadpis`: ";
	First_Functi(Tiger, Tiger.length());
}
void Second_Ex()
{
	Node* head = nullptr;
	/*int n;
	cout << "Enter n: ";
	cin >> n; */
	head = appendNode(head, 5);
	head = appendNode(head, 4);
	head = appendNode(head, 3);
	head = appendNode(head, 2);
	head = appendNode(head, 1);

	cout << "Original: ";
	printList(head);

	head = swapPairs(head);

	cout << "After functi: ";
	printList(head);

	// Звільнення виділеної пам'яті
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}
void Third_Ex()
{
	int choose;
	cout << "Choose n: ";
	cin >> choose;
	Third_Functi(choose, 0, 0, 1);

}
void Fourth_Ex()
{
	int Count;
	cout << "Enter the count of stairs: ";
	cin >> Count;
	Count++;
	if (Count <= 45 && Count >= -1)
		cout << "Result: " << Fourth_Functi(Count);
	else return;
}
void Fifth_Ex()
{
	double x;
	int n;
	cout << "\nEnter x (100 <= x <= 100, x!=0): ";
	cin >> x;
	if (x > 100 || x < -100 || x == 0)
	{
		cout << "Try again, but next time follow the rules.";
		return;
	}
	cout << "\nEnter n ";
	cin >> n;
	Fifth_Functi(n, x, 1);
}
void Choosing()
{
	int Check;
	cout << "\nChoose an action 1 - 6: ";
	cin >> Check;
	switch (Check)
	{
	case (1):First_Ex(); break;
	case (2):Second_Ex(); break;
	case (3):Third_Ex(); break;
	case (4):Fourth_Ex(); break;
	case (5):Fifth_Ex(); break;
	case (6):return; break;
	default:cout << "Enter only numbers 1 - 6";; break;
	}
	Choosing();
}
int main()
{
	cout << "1. First ex\n2. Second ex\n3. Third ex\n4. Fourth ex\n5. Fifth ex\n6.Exit";
	Choosing();
	return 0;
}

