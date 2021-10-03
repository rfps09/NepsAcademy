    #include <iostream>
     
    using namespace std;
     
    int main () {
    	int bino, cino, soma;
     
    	cin >> bino >> cino;
     
    	soma = (bino + cino) % 2;
     
    	if (soma == 0) {
    		cout << "Bino\n";
    	}
    	else {
    		cout << "Cino\n";	
    	}
     
    	return 0;
    }
