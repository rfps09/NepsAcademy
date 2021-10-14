#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int p = 0, s = 0, count = 0;
    vector<pair<int, int>> sorveteiro;
    vector<pair<int, int>> aux;
    pair<int, int> area;

    cin >> p >> s;

    for(int i = 0; i < s; i++) {
        cin >> area.first >> area.second;
        sorveteiro.push_back(area);
    }

    sort(sorveteiro.begin(), sorveteiro.end());

    aux.push_back(sorveteiro[0]);

    for(int i = 1; i < s; i++) {
        if(sorveteiro[i].first <= aux[count].second && sorveteiro[i].second >= aux[count].second) {
			aux[count].second = sorveteiro[i].second;
		}
		else if(sorveteiro[i].first > aux[count].second) {
			aux.push_back(sorveteiro[i]);
			count++;
		}
    }
    
    for(int i = 0; i < count+1; i++) {
        cout << aux[i].first << " " << aux[i].second << endl;
    }

    return 0;
}
