#include <iostream>
#include <set>

using namespace std;

int main () {
	ios::sync_with_stdio(0);
	int n = 0, aux = 0;
	set<int> s;
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> aux;
		s.insert(aux);
	}

	cout << s.size() << "\n";
	
	return 0;
}
