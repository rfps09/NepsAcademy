    #include <iostream>
    #include <algorithm>
     
    using namespace std;
     
    int vetor[100000];
    int vetorAux[100000];
    int vetorDesor[100000];
     
    int main () {
    	int n = 0, i = 0, count = 0;
     
    	cin >> n;
     
    	for(i = 0; i < n; i++) {
    		cin >> vetor[i];
    		vetorAux[i] = vetor[i];
    	}
     
    	sort(vetor, vetor+n);
     
    	for(i = 0; i < n; i++) {
    		if(vetorAux[i] != vetor[i]) {
    			vetorDesor[count] = vetorAux[i];
    			count++;
    		}
    	}
     
    	sort(vetorDesor, vetorDesor+count);
     
    	cout << count << endl;
    	for(i = 0; i < count; i++) cout << vetorDesor[i] << " ";
    	cout << endl;
     
    	return 0;
    }
