    #include <iostream>
     
    using namespace std;
     
    const int TAM = 10;
    int contagem[TAM];
     
    int main () {
    	int n = 0, i = 0, j = 0;
    	string aux;
     
    	cin >> n;
     
    	for(i = 0; i < n; i++) {
    		cin >> aux;
     
    		for(j = 0; j < aux.length(); j++) 
    			contagem[aux[j]-'0']++;
    	}
     
    	for(i = 0; i < TAM; i++)
    		cout << i << " - " << contagem[i] << endl;
     
    	return 0;
    }
