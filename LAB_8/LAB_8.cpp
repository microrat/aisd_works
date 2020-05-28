#include <fstream>
#include <windows.h>
#include <iostream>

using namespace std;

ofstream fout("output.txt");
ifstream fin("input.txt");

class Node {
public:
	int value;
	int height;
	int sum;
	Node* left;
	Node* right;
	Node(){}
	Node(int var){
		value = var;
		left = NULL;
		right = NULL;
	}
	void print(){
		cout << value << endl;
	}
};
bool flagRoot = false;
int maxx;
int maxfind(int a, int b) {
	if (a == b) return a;
	if (a > b) return a;
	if (b > a) return b;
}
class tree {
public:
	Node* root;
	tree(){root = NULL;}
	tree(int val){root = new Node(val);}

	void add(int val){
		if (root == NULL)
		{root = new Node(val);}
		Node* temp = root;
		Node* pred = NULL;
		int compare = 0;
		while (temp != NULL){
			pred = temp;
			compare = val - temp->value;
			if (compare > 0){temp = temp->right;}
			else if (compare < 0){temp = temp->left;}
			else if (compare == 0){return;}
		}
		if (compare > 0){pred->right = new Node(val);}
		else if (compare < 0){pred->left = new Node(val);}
	}

	void heightSum(){
		if (root != NULL){heightSum(root);}
		}

	void heightSum(Node* n){
		int heightLeft;
		int heightRight;

		if (n->right != NULL){
			heightSum(n->right);
			heightRight = n->right->height;
		}
		else heightRight = 0;
		if (n->left != NULL)		{
			heightSum(n->left);
			heightLeft = n->left->height;
		}
		else heightLeft = 0;

		n->height = (maxfind(heightRight, heightLeft) + 1);
		n->sum = heightRight + heightLeft;
		if (n->sum > maxx){maxx = n->sum;	}
	}

	void searchRoot(){
		if (root != NULL){searchRoot(root, NULL);}
	}

	void searchRoot(Node* n, Node* pred)	{
		if (n->left != NULL){searchRoot(n->left, n);}
		if (n->sum == maxx)	{
			if (flagRoot == false){
				Node* nodeRoot = NULL;
				nodeRoot = n;
				flagRoot = true;
				cout << nodeRoot->value << " deleted" << endl;
				delR(nodeRoot, pred);
			}

		}
		if (n->right != NULL){searchRoot(n->right, n);}
	}

	void delR(Node* n, Node* pred)
	{
		if (n == root){
			if (n->left == NULL){root = root->right;}
			if (n->right == NULL){root = root->left;}
		}
		if (n->left == NULL && pred != NULL)
		{
			if (pred->left == n){pred->left = n->right;}
			if (pred->right == n){pred->right = n->right;}
		}
		if (n->right == NULL && pred != NULL){
			if (pred->left == n){pred->left = n->left;}
			if (pred->right == n){pred->right = n->left;}
		}

		if ((n->right != NULL) && (n->left != NULL))
		{
			Node* tempNode = n->right;
			Node* tempPred = n;
			while (true){
				if (tempNode->left != NULL){
					tempPred = tempNode;
					tempNode = tempNode->left;}
				else break;
			}
			n->value = tempNode->value;
			if (tempNode->right != NULL)
			{
				if (tempPred != n){tempPred->left = tempNode->right;}
				else{tempPred->right = tempNode->right;}
			}
			else
			{
				if (tempPred != n){	tempPred->left = NULL;}
				else{tempPred->right = NULL;}
			}

		}
	}

};
//ВЫВОД ДЕРЕВА
void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}
void print(const string& str, Node* top, int temp) {
	string s;
	if (temp == -1) {
		s = "";
	}
	else
		if (temp == 1) {
			s = "L:";

		}
		else {
			s = "R:";

		}
	if (top)
	{
		cout << str;

		cout << "|_";
		if (s == "R:")
			SetColor(2, 0);
		else if (s == "L:")
			SetColor(13, 0);
		cout << s;
		SetColor(7, 0);
		cout << top->value << endl;

		for (int i = 1; i < 2; i++) {
			if (temp)      print(str + "|   ", top->left, 1);
			else           print(str + "    ", top->left, 1);
		}
		if (temp)      print(str + "|   ", top->right, 0);
		else           print(str + "    ", top->right, 0);
	}
}
//Прямой//
void straight(Node* top) {
	if (top) {
		cout<<top->value<<" ";
		straight(top->left);
		straight(top->right);
	}
}
//Симметричный//
void simmetr(Node* top) {
	if (top) {
		simmetr(top->left);
		cout<<top->value<<" ";
		simmetr(top->right);
	}
}
//Обратный//
void obrat(Node* top) {
	if (top) {
		obrat(top->left);
		obrat(top->right);
		cout<<top->value<<" ";
	}
}

int depth(Node* top, int level) {//глубина
	if (top == NULL)
		return level;
	return max(depth(top->left, level + 1), depth(top->right, level + 1));
}

int layer(int key, Node* top, int k) {//уровень узла
	while (top) {
		if (top->value == key){return k;}
		if (top->value > key){top = top->left;}
		else top = top->right;
		k++;
	}
	return -1;
}
int main() {
	tree MyTree = *(new tree());
	int value;
	while (fin.eof() != true)
	{
		fin >> value;
		MyTree.add(value);
	}
	print(" ",MyTree.root,-1);
	MyTree.heightSum();
	MyTree.searchRoot();
	cout <<"Min sum =  "<< maxx << endl;
	print(" ", MyTree.root, -1);
	obrat(MyTree.root);
	return 0;
}
