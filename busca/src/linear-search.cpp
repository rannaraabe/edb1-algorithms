#include "../include/buscas.h"

// Linear Search
const value_type *lsearch( const value_type *first, const value_type *last, value_type value )
{
        while(first!=last)
        {
                if(*(first)==value){
                        return first;
                }
                else{
                        first++;
                }
        }

        return last;
}

