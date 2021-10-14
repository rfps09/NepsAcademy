#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int n = 0;
    string linha;
    stack<char> pilha;
    
    cin >> n;
    cin.get();

    for(int i = 0; i < n; i ++) {
        getline(cin, linha);
        for(int j = 0; j < linha.length(); j++) {
            if(linha[j] == '{') {
                pilha.push('{');
            }
            else if (linha[j] == '}' && !pilha.empty()) {
                pilha.pop();
            }
            else if (linha[j] == '}' && pilha.empty()) {
                cout << "N" << endl;
                return 0;
            }
        }
    }

    if(pilha.empty()) {
        cout << "S" << endl;
    }
    else {
        cout << "N" << endl;
    }
    
    return 0;
}
