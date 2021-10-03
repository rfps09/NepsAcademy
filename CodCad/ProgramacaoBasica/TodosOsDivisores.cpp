    #include <iostream>
     
    using namespace std;
     
    using ll = long long int;
     
    int main () {
    	ll x = 0, i = 0;
     
    	cin >> x;
     
    	cout << "1 ";
     
    	for(i = 2; i < x; i++) {
    		if (x % i == 0) {
    			cout << i << " ";
    		}
    	}
     
    	cout << x <<endl;
     
    	return 0;
    }
