#include <iostream>
#include <algorithm>

using namespace std;

int x[1000000];
int aux[1000];
int resultado[1000];

int main() {
    int n = 0, c = 0, p = 0, i = 0;
    int j = 0, k = 0, count = 0, total = 0, validacao = 0;

    cin >> n >> c;

    for(j = 0; j < c; j++) {
        cin >> p >> i;
        aux[j] = p;
        for(k = total; k < total+i; k++) {
            cin >> x[k];
        }

        total += i;
    }

    for(j = 0; j < c; j++) {
        for(k = 0; k < total; k++) {
            if(x[k] == aux[j]) {
                validacao = 1;
                break;
            }
        }

        if(validacao == 0) {
            resultado[count] = aux[j];
            count++;
        }

        validacao = 0;
    }

    sort(resultado, resultado+count);

    for(j = 0; j < count; j++) {
        cout << resultado[j] << endl;
    }

  return 0;
}
