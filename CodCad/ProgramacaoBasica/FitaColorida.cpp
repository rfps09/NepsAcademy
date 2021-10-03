    #include <iostream>
     
    using namespace std;
     
    int main() {
        int n = 0, aux = 0, x[10000], count = 0, carry = 0, JgDiff = 0, i = 0,  j = 0;
        bool firts = true;
     
        cin >> n;
     
        for(i = 0; i < n; i++) {
            cin >> aux;
     
            if (aux == 0 && firts == true) {
                x[i] = aux;
     
                if (i > 9) {
                    count = 9;
                } 
                else {
                    count = i;
                }
     
                for(j = 0; j < i; j++) {
                    if (i - j > 9) {
                        x[j] = 9;
                    }
                    else {
                        x[j] = count;
                        count--;
                    }
                }
     
                firts = false;
                carry = i;
            }
            else if (aux == 0 && firts == false) {
                x[i] = aux;
     
                JgDiff = i - carry - 1;
     
                if (JgDiff % 2 == 1) {
                    JgDiff = JgDiff / 2 + 1;
                }
                else {
                    JgDiff /= 2;
                }
     
                for(j = carry + 1; j <= carry + JgDiff; j++) {
                    if (j - carry > 9) {
                        x[j] = 9;
                    }
                    else {
                        x[j] = j - carry;
                    }
                }
     
                if (i - j - 1 <= 8) {
                    count = i - j;
                }
                else {
                    count = 9;
                }
     
                for(j = carry + JgDiff + 1; j < i; j++) {
                    if(i - j > 9) {
                        x[j] = 9;
                    }
                    else {
                        x[j] = count;
                        count--;
                    }
                }
     
                carry = i;
            }
        }
     
        if(carry+1 < n) {
            for(j = carry + 1; j < n; j++) {
                if(j - carry > 9) {
                    x[j] = 9;
                }
                else {
                    count = j;
                    x[j] = j - carry;
                }
            }
        }
     
        for(i = 0; i < n-1; i++) {
            cout << x[i] << " ";
        }
     
        cout << x[n-1] << endl;
     
        return 0;
    }
