    #include <iostream>
     
    using namespace std;
     
    int main () {
    	char op;
    	int x = 0, y = 0,z = 0;
     
    	cin >> z >> x >> op >> y;
     
    	switch(op) {
    		case '+':
    			if(z-y < x) {
    				cout << "OVERFLOW" << endl;
     
    				return 0;
    			}
    		break;
     
    		case '*':
    			if(z/y < x) {
    				cout << "OVERFLOW" << endl;
     
    				return 0;
    			}
    		break;
    	}
     
    	cout << "OK" << endl;
     
    	return 0;
    }
