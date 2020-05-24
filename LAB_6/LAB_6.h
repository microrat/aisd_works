#include<list>
using namespace std;
//--STACK--//
class my_stack
{
private:
	list<int> steck;
public:
	void add(int val)
	{steck.push_back(val);}
	bool del()
	{
		if (steck.empty()) {return false;}
		else {steck.pop_back(); return true;}
	}
	bool empty()
	{return steck.empty();}
};
//--QUEUE--//
class my_queue {
	list<int> queu;
public:
	void add(int val){queu.push_back(val);}
	bool del(){
	    	if (queu.empty()){return false;}
		    else { queu.pop_front(); return true; }
	}
	bool empty(){return queu.empty();}
};
//--DEQUE--//
class my_deque
{
private:
	list<int> deck;
public:
	void add_begin(int val){deck.push_front(val);}
	void add_end(int val){deck.push_back(val);}
	bool del_begin(){
		if (deck.empty()){return false;}
		else { deck.pop_front(); return true; }
	}
	bool del_end(){
		if (deck.empty()){return false;}
		else { deck.pop_back(); return true; }
	}
	bool empty(){return deck.empty();}
};
