    #include <iostream>
     
    using namespace std;
     
    int main() {
        int n = 0, a = 0, b = 0, c = 0, aux = 0;
     
        cin >> n;
        if (n > 2) {
            cin >> a >> b >> c;
            cout << a + b << endl;
            for(int i = 0; i < n-2; i++) {
                cout << a + b + c << endl;
                if (i < n-3) {
                    cin >> aux;
                    a = b;
                    b = c;
                    c = aux;
                }
            }
     
            cout << b + c << endl;
        }
        else {
            cin >> a >> b;
            cout << a + b;
        }
        return 0;
    }
