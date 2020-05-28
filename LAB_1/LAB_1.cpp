#include <iostream>

using namespace std;

int fact1(int n) {
	if (n == 1) return 1;
	else {
		int c=1;
		for (int i = 2; i <= n; ++i)
			c *= i;
		return c;
	}
}

int fact2(int n) {
	if (n == 1) return 1;
	else return fact2(n - 1)*n;
}



int main(){
	int a = fact1(3);
	cout << a<<endl;
	int  b= fact2(3);
	cout << b<<endl;
	system("pause");
	return 0;
}
