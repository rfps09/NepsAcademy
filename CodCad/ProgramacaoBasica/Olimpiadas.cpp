    #include <iostream>
    #include <algorithm>
     
    using namespace std;
     
    typedef struct {
    	int MedOuro = 0;
    	int MedPrata = 0;
    	int MedBronze = 0;
    	int index = 0;
    }TIME;
     
    int comparer(TIME a, TIME b) {
    	if(a.MedOuro != b.MedOuro) {
    		return a.MedOuro > b.MedOuro;
    	}
    	else if(a.MedPrata != b.MedPrata) {
    		return a.MedPrata > b.MedPrata;
    	}
    	else if(a.MedBronze != b.MedBronze) {
    		return a.MedBronze > b.MedBronze;
    	}
     
    	return a.index < b.index;
    }
     
    int main() {
    	int n = 0, m = 0, i = 0;
    	int o = 0, p = 0, b = 0;
    	TIME time[100];
     
    	cin >> n >> m;
     
    	for(i = 0; i < n; i++) {
    		time[i].index = i + 1;
    	}
     
    	for(i = 0; i < m; i++) {
    		cin >> o >> p >> b;
     
    		time[o-1].MedOuro++;
    		time[p-1].MedPrata++;
    		time[b-1].MedBronze++;
    	}
     
    	sort(time, time+n, comparer);
     
    	for(i = 0; i < n-1; i++) {
    		cout << time[i].index <<  " ";
    	}
     
    	cout << time[n-1].index << endl;
     
    	return 0;
    }
