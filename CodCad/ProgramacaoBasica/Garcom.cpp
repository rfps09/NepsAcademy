    #include <iostream>
     
    using namespace std;
     
    int main () {
    	int i = 0, n = 0, l = 0, c = 0, cq = 0;
     
    	cin >> n;
     
    	for(i = 0; i < n; i++) {
    		cin >> l >> c;
     
    		if (l > c) {
    			cq += c;
    		}
    	}
     
    	cout << cq << endl;
     
    	return 0;
    }
