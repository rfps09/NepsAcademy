    #include <iostream>
     
    using namespace std;
     
    int main () {
    	float a = 0, b = 0, media = 0;
     
    	cin >> a >> b;
     
    	media = (a+b)/2;
     
    	if(media < 4) {
    		cout << "Reprovado" << endl;
    	}
    	else if (media >= 4 && media < 7) {
    		cout << "Recuperacao" << endl;
    	}
    	else {
    		cout << "Aprovado" << endl;
    	}
     
    	return 0;
    }
