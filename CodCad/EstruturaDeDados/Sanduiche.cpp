#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    
    int n = 0, d = 0;
    int aux = 0, sum = 0, count = 0;
    vector<int> vetor;
 
    cin >> n >> d;
 
    for(int i = 0; i < n; i++) {
        cin >> aux;
        vetor.push_back(aux);
    }
    aux = 0;
    for(int i = 0; i < n; i++) {
        while(sum < d) {
            sum += vetor[aux];
            if(aux < n-1) aux++;
            else aux = 0;
            if(aux == i) break;
        }
        count += sum == d;
        sum -= vetor[i];
    }
 
    cout << count << endl;

    return 0;
}
