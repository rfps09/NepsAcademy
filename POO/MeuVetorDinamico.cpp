#include <stdio.h>

template <typename T>
class MeuVetorDinamico {
    T *memoria;
    int t_max; //Tamanho máximo que o vetor pode ter.
    int t; //Tamanho atual do vetor.

public:
    MeuVetorDinamico(int tamanho_maximo=2){
        this->memoria = new T[tamanho_maximo];
        this->t = 0;
        this->t_max = tamanho_maximo;
    }

    ~MeuVetorDinamico(){
        delete memoria;
    }    

    T operator [] (int indice){
        //TODO: retorne o valor da memória correspondente ao indice pedido no parâmetro da função.
        return memoria[indice];
    }

    void adicionar(T x){
        //TODO: adiciona o objeto x na memória do vetor e atualize seu tamanho (variável t).
        memoria[t] = x;
        t++;

        //Caso o vetor chegue ao seu tamanho máximo vamos duplicar a capacidade do vetor.
        if (t == t_max){

            this->t_max = 2*t_max;
            T *copy = new T[this->t_max];        

            for(int i=0;i<t;i++){
                copy[i] = this->memoria[i];
            }

            T* tmp = this->memoria;

            this->memoria = copy;

            delete tmp;
        }
    }

    //TODO: implemente a função que remove o último elemento do vetor.
    void remove_ultimo(){
        if(t) t--;
    }

    //TODO: implemente a função que retorna o tamanho atual do vetor.
    int tamanho(){
        return t;
    }
};

int main(){
    MeuVetorDinamico<int> vetor;

    int N, x;
    char op;
    scanf("%d", &N);

    for(int i=0;i<N;i++){
        scanf(" %c", &op);

        if(op == 'A'){
            scanf("%d", &x);
            vetor.adicionar(x);
        }else{
            vetor.remove_ultimo();
        }
        
    }

    for(int i=0;i<vetor.tamanho();i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");
    
}
