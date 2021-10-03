    #include <iostream>
     
    using namespace std;
     
    int main () {
    	int i = 0, n = 0, a = 0, b = 0, aux = 0, count = 0, record = 0;
     
    	cin >> n;
     
    	cin >> a >> b;
    	for(i = 0; i < n-1; i++) {
    		if (a == b) {
    			count++;
    		}
    		else {
    		    count = 0;
    		}
    		if (count > record) {
    			record = count;	
    		}
    		cin >> aux;
    		a = b;
    		b = aux;
    	}
     
    	cout << record + 1 << endl;
     
    	return 0;
    }
