    #include <iostream>
    #include <algorithm>
     
    using namespace std;
     
    int vetor[100000];
     
    int main () {
    	int n = 0, i = 0;
     
    	cin >> n;
     
    	for(i = 0; i < n; i++) {
    		cin >> vetor[i];	
    	}
     
    	sort(vetor, vetor+n);
    	n--;
     
    	for(i = 0; i < n; i++) {
    		cout << vetor[i] << " ";
    	}
     
    	cout << vetor[n] << endl;
     
    	return 0;
    }
