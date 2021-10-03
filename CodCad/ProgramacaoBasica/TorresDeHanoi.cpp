    #include <iostream>
    #include <cmath>
     
    using namespace std;
     
    int res (int n) {
    	return pow(2,n) - 1;
    }
     
    int main () {
    	int n = 0, count = 1;
     
    	while(cin >> n && n) {
    		cout << "Teste " << count << endl;
    		cout << res(n) << endl << endl;
    		count++;
    	}
     
    	return 0;
    }
