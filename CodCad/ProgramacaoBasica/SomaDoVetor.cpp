#include <iostream>
 
using namespace std;
 
void soma_vetor(int somaVetor){
	cout << somaVetor << "\n";
}
 
int main(){
	int soma = 0, aux = 0, n = 0;
 
	cin >> n;
 
	for(int i=0;i<n;i++) {
		cin >> aux;
		soma += aux;
	}
 
	soma_vetor(soma);
  
  return 0;
}
