    #include <iostream>
     
    using namespace std;
     
    int main () {
    	int i = 0, n = 0, aux = 0, count1 = 0, count2 = 0;
     
    	cin >> n;
     
    	for (i = 0; i < n; i++) {
    		cin >> aux;
     
    		switch(aux) {
    			case 1: 
    				count1++;
    			break;
     
    			case 2: 
    				count2++;
    			break;
    		}
    	}
     
    	cout << (count1 + count2) % 2 << endl;
    	cout << count2 % 2 << endl;
     
    	return 0;
    }
