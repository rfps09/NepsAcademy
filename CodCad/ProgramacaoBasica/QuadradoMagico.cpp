    #include <iostream>
     
    using namespace std;
     
    int sumR[10], sumC[10], sumD[2];
     
    int main () {
    	int x = 0, n = 0, i = 0, j = 0;
     
    	cin >> n;
     
    	for(i = 0; i < n; i++) {
    		for(j = 0; j < n; j++) {
    			cin >> x;
    			sumR[i] += x;
    			sumC[j] += x;
    			if(i == j) {
    				sumD[0] += x;	
    			}
    			if( (n-1) - i == j ) {
    				sumD[1] += x;	
    			}
    		}
    		if (i > 0 && sumR[i] != sumR[i-1]) {
    			cout << "-1" << endl;
    			return 0;
    		}
    	}
     
    	if(sumD[0] != sumD[1] || sumD[0] != sumR[0] || sumR[0] != sumC[0]) {
    		cout << "-1" << endl;
    		return 0;
    	}
     
    	for(i = 0; i < n-1; i++) {
    		if(sumC[i] != sumC[i+1]) {
    			cout << "-1" << endl;
    			return 0;
    		}
    	}	
     
    	cout << sumD[1] << endl;
     
    	return 0;
    }
