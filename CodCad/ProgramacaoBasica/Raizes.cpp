    #include <iostream>
    #include <cmath>
    #include <iomanip>
     
    using namespace std;
     
    int main () {
    	int n;
    	double x;
     
    	cin >> n;
     
    	for(int i = 0; i < n; i++) {
    		cin >> x;
    		cout << setprecision(4) << fixed << sqrt(x) << endl; 
    	}
     
    	return 0;
    }
