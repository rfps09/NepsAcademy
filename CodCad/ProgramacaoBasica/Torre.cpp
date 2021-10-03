    #include <iostream>
     
    using namespace std;
     
    const int MAX = 1000;
     
    int num[MAX][MAX], x[MAX], y[MAX];
     
    int maior(int num[][MAX], int x[], int y[], int n) {
        int i = 0, j = 0, tallest = 0, ans = 0;
     
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                ans = x[i] + y[j] - 2*num[i][j];
                if(ans > tallest) tallest = ans;
            }
        }
     
        return tallest;
    }
     
    int main () {
        int n = 0, i = 0, j = 0, aux = 0, TheTallest = 0;
     
        cin >> n;
     
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                cin >> aux;
                num[i][j] = aux;
                x[i] += aux;
                y[j] += aux;
            }
        }
     
        TheTallest = maior(num, x, y, n);
     
        cout << TheTallest << endl;
     
        return 0;
    }
