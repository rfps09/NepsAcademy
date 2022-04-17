#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 25;

int memo[MAXN][MAXN];

int editDistance(string &a, string &b, int A, int B) {
    if(A==-1 || B==-1) return abs((A+1)-(B+1));

    if(memo[A][B] != -1) return memo[A][B];

    int ans=0;

    if(a[A] != b[B]) {
        int temp;
        ans = editDistance(a,b,A-1,B-1) + 1;
        temp = editDistance(a,b,A-1,B) + 1;
        if(ans > temp) ans = temp;
        temp = editDistance(a,b,A,B-1) + 1;
        if(ans > temp) ans = temp;
    } else ans = editDistance(a,b,A-1,B-1);
    
    return memo[A][B] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n=0, m=0;
    string palavra;
    vector<string> dic;

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> palavra;
        dic.push_back(palavra);
    }

    for(int i=0; i<m; i++) {
        cin >> palavra;

        string words;

        for(int j=0; j<n; j++) {
            int len1 = dic[j].length();
            int len2 = palavra.length();
            int diff = len1-len2;

            for(int k=0;k<=len1;k++)
            for(int l=0;l<=len2;l++)
            memo[k][l] = -1;

            if(abs(diff) <= 2) {
                if(editDistance(dic[j],palavra,len1,len2) <= 2) {
                    words+= dic[j];
                    words+= " ";
                }
            }
        }
        int end = (int) words.length();

        if(end) {
            words[end-1] = '\n';
            cout << words;
        } else cout << "\n";
    }

    return 0;
}