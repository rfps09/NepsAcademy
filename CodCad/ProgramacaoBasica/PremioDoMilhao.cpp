    #include <iostream>
     
    using namespace std;
     
    int main () {
    	int i = 0, n = 0, soma = 0, aux = 0, count = 0;
     
    	cin >> n;
     
    	for(i = 0; i < n; i++) {
    		cin >> aux;
    		soma += aux;
    		count++;
    		if (soma >= 1000000) {
    			break;	
    		}
    	}
     
    	cout << count << endl;
     
    	return 0;
    }
