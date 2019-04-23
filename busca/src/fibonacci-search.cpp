#include "../include/buscas.h"
#include "../include/utils.h"
#include <iterator>
#include <cmath>

// Fibonacci Search
const value_type *fibonacciSearch( const value_type* first, const value_type* last, value_type value )
{
        value_type *m_first = const_cast<value_type *>(first);
        value_type *m_last = const_cast<value_type *>(last);

        int fibm2 = 0, fibm1 = 1, fib3=0;

        fib3 = fibm1+fibm2;

        while(fib3 <= m_last - m_first)
        {
                fibm2= fibm1;
                fibm1 = fib3;
                fib3 = fibm2+fibm1;
        }

        int offset= -1;

        while(fib3>1)
        {
                int i = min(offset+fibm2,(m_last - m_first)-1);
                if( *(m_first+i) < value){
                        fib3 = fibm1;
                        fibm1 = fibm2;
                        fibm2 = fib3-fibm1;
                        offset = i;
                }
                else if(*(first+i) > value){
                        fib3= fibm2;
                        fibm1 = fibm1 - fibm2;
                        fibm2 = fib3 - fibm1;
                }

                else return m_first+i;
        }

        if(fibm1 && *(first+offset+1)==value) return first + offset+1;

        return last;
}
