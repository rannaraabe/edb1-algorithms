#include "buscas.h"

void preencherVetor(value_type* vet, value_type i ){
    for(value_type j = 0;j < i;j++){
        vet[j]=j;
    }
}

value_type min(value_type x, value_type y) { 
    return (x<=y)? x : y;
} 
