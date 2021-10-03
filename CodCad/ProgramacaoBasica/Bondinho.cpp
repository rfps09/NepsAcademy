    #include <iostream>
     
    using namespace std;
     
    int main () {
    	int a, b, soma;
     
    	cin >> a >> b ;
     
    	soma = a + b;
     
    	if (soma > 50) {
    		cout << "N\n";
    	}
    	else {
    		cout << "S\n";
    	}
     
    	return 0;
    }
