#include "../include/buscas.h"
#include "../include/utils.h"
#include <iterator>

// Binary Search
const value_type *binarySearch( const value_type *first, const value_type *last, value_type value )
{
        const value_type* templast = last;
        int meio = std::distance(first,last)/2;
 
        while(first <= templast)
        {
                meio = std::distance(first, templast)/2;

                if(value == *(first+meio)){
                        return first+meio;
                }
                else if(value>*(first+meio)){
                        first = first+meio+1;
                }
                else{
                        templast = first+meio-1;
                }
        }

        return last;
}

// Recursive Binary Search
const value_type *rbinarySearch( const value_type *first, const value_type *last, value_type value )
{
        const value_type* templast = const_cast<value_type *>(last);
        int meio = std::distance(first,last)/2;

        if(first>=last){
		return last;
	}

        if(value == *(first+meio)){
		return first+meio;
	}
	else if(value>*(first+meio)){
                return  rbinarySearch(first+meio+1,templast,value);
	}
	else{
                return rbinarySearch(first,first+meio-1,value);
	}

        return last;
}

