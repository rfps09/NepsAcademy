#include <iostream>
#include <set>

using namespace std;

int main() {
    int c = 0, aux = 0, tam = 0, count = 0;
    set<int> s;
    set<int>::iterator it;

    cin >> c;
    
    for(int i = 0; i < c; i++) {
        cin >> aux;
        if(!s.empty()) {
            it=s.find(aux);
            if(it != s.end()) {
                s.erase (it);
                tam = s.size();
            }
            else {
                s.insert(aux);
                count+=2;
            }
            
        }else {
            s.insert(aux);
            count+=2;
        }
    }
    
    cout << count << "\n";
    
    return 0;
}
