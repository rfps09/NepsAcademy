    #include <iostream>
     
    using namespace std;
     
    int main() {
        int n = 0, count = 0, a = 0, b = 0, c = 0, aux = 0;
     
        cin >> n;
     
        cin >> a >> b >> c;
     
        for(int i = 0; i < n-2; i++) {
            if(a == 1 && b == 0 && c == 0) {
                count++;
            }
            cin >> aux;
            a = b;
            b = c;
            c = aux;
        }
     
        cout << count << endl;
     
        return 0;
    }
