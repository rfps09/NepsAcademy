#include <stdio.h>

class Horario{
public:
    int horas, minutos, segundos;

    Horario(){}

    Horario(int horas, int minutos, int segundos ){
        this->horas = horas;
        this->minutos = minutos;
        this->segundos = segundos;
    }

    //TODO: Implementar o operador de adição.
    Horario operator + (Horario b){
        int carry = 0;

        int S = segundos + b.segundos;
        if(S >= 60) {
            S -= 60;
            carry = 1;
        }

        int M = minutos + b.minutos + carry;
        if(M >= 60) {
            M -= 60;
            carry = 1;
        } else carry = 0;

        int H = horas + b.horas + carry;
        H = H >= 24 ? H-24 : H;
        
        return Horario(H,M,S);
    }

    //TODO: Implementar o operador de subtração.
    Horario operator - (Horario b){
        int carry = 0;

        int S = segundos - b.segundos;
        if(S < 0) {
            carry = 1;
            S += 60;
        }

        int M = minutos - b.minutos - carry;
        if(M < 0) {
            carry = 1;
            M += 60;
        } else carry = 0;
        
        int H = horas - b.horas - carry;
        H = H < 0 ? 24 + H : H;

        return Horario(H,M,S);
    }

};

int main(){
    Horario a, b, c;
    char op;

    scanf("%d:%d:%d", &a.horas, &a.minutos, &a.segundos);
    scanf("%d:%d:%d", &b.horas, &b.minutos, &b.segundos);
    scanf(" %c", &op);

    if(op == 'A'){
        c = a + b;
    } else if(op == 'S'){
        c = a - b;
    }

    printf("%02d:%02d:%02d\n", c.horas, c.minutos, c.segundos);
}
