#include <stdio.h>

class Pontos {
public:
	int x,y;
    Pontos() {
        x = 0;
        y = 0;
    }
    Pontos(int X,int Y) {
        x = X;
        y = Y;
    }
};

class Retangulo {
	Pontos superior_esquerdo;
	Pontos inferior_direito;
	
public:
	void set_pontos(int x1,int y1,int x2,int y2){
		superior_esquerdo = Pontos(x1,y1);
        inferior_direito = Pontos(x2,y2);
	}

    int area() {
        return (inferior_direito.x - superior_esquerdo.x) * (superior_esquerdo.y - inferior_direito.y);
    }
};

int main(){

    Retangulo retangulo;
    int N;

    scanf("%d", &N);

    for(int i=0;i<N;i++){
        int x1, y1, x2, y2;
        char operacao;

        scanf(" %c", &operacao);

        if(operacao == 'R'){ //Redimensionar
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            retangulo.set_pontos(x1, y1, x2, y2);
        }else if(operacao == 'A'){ //Imprimir a área
            printf("%d\n", retangulo.area());
        }
    }
}