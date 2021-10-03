    #include <iostream>
     
    using namespace std;
     
    int main () {
    	int p1, c1, p2, c2, produto1, produto2;
     
    	cin >> p1 >> c1 >> p2 >> c2;
     
    	produto1 = p1 * c1;
    	produto2 = p2 * c2;
     
    	if (produto1 > produto2) {
    		cout << "-1\n";
    	}
    	else if (produto2 > produto1) {
    		cout << "1\n";
    	}
    	else {
    		cout << "0\n";
    	}
     
    	return 0;
    }
