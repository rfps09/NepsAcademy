    #include <iostream>
    #include <iomanip>
     
    using namespace std;
     
    int main () {
    	char op;
    	double a = 0, b = 0;
     
    	cin >> op;
    	cin >> a >> b;
     
    	switch(op) {
    		case 'M':
    			cout << setprecision(2) << fixed << a*b << endl;
    		break;
    		case 'D':
    			cout << setprecision(2) << fixed << a/b << endl;
    		break;
    	}
     
    	return 0;
    }
