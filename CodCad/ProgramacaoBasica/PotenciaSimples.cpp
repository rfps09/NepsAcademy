    #include <iostream>
    #include <cmath>
    #include <iomanip>
     
    using namespace std;
     
    int main () {
    	double x, y;
     
    	cin >> x >> y;
     
    	cout << setprecision(4) << fixed << pow(x,y) << endl;
     
    	return 0;
    }
