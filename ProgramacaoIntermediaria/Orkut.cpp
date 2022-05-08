#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n=0,m=0, teste=0;
    string nome;

    while(cin >> n && n) {
        teste++;
        
        int count=0;
        map<string,int> friends;
        map<int,string> numbers;
        map<string,int>::iterator it;
        
        int ot[n];
        vector<int>grafinho[n];
        
        for(int i=0; i<n; i++) {
            cin >> nome;
            friends[nome] = 0;
            ot[i] = 0;
        }
        
        for(it = friends.begin(); it != friends.end(); it++) {
            it->second = count;
            numbers[count] = it->first;
            count++;
        }
        
        for(int i=0; i<n; i++) {
            cin >> nome;
            cin >> m;
            
            int x = friends[nome];
            for(int j=0; j<m; j++) {
                cin >> nome;
                int y = friends[nome];
                grafinho[y].push_back(x);
                ot[x]++;
            }
        }
        
        queue<int> fila;
        vector<int> ans;
        
        for(int i=0; i<n; i++) {
            if(!ot[i]) fila.push(i);
        }
    
        while(!fila.empty()) {
            int atual = fila.front();
            ans.push_back(atual);
            
            for(int i=0; i<grafinho[atual].size(); i++) {
                int v = grafinho[atual][i];
                ot[v]--;
                if(!ot[v]) fila.push(v);
            }
            
            fila.pop();
        }
        
        cout << "Teste " << teste << "\n";
    
        if(ans.size() < n) cout << "impossivel\n\n";
        else {
            for(int i=0; i<n; i++) {
                cout << numbers[ans[i]] << " ";
            }
            cout << "\n\n";
        }
    }

    return 0;
}