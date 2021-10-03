    #include <iostream>
    #include <cmath>
     
    using namespace std;
     
    int fibonacci (int numSeq) {
        numSeq = (numSeq < 1) ? 1 : numSeq;
        return round(( pow( ( ( 1+sqrt(5) ) / 2 ), numSeq+1 ) + pow( ( ( 1-sqrt(5) ) / 2 ), numSeq+1 ) ) / sqrt(5));
    }
     
    int main () {
    	int n = 0;
     
    	cin >> n;
     
    	cout << fibonacci(n) << endl;
     
    	return 0;
    }
