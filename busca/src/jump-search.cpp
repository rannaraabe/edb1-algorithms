#include "../include/buscas.h"
#include "../include/utils.h"
#include <iterator>
#include <cmath>

// Jump Search
const value_type * jumpSearch( const value_type* first, const value_type* last, value_type value )
{
        int tamanho = std::distance(first,last);
        int step = sqrt(tamanho);
        int prox = 0;
        
	while(*(first + min(step, tamanho)-1) < value)
        {
                prox = step;
                step += (int) sqrt(tamanho);
                if(prox >= value)
                        return last;
        }

        while(*(first+prox) < value)
        {
                prox++;
                if(prox == min(step, tamanho))
                        return last;
        }

        if(*(first + prox) == value)
                return first + prox;

        return last;
}
