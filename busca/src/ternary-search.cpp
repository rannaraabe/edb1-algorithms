#include "../include/buscas.h"
#include "../include/utils.h"
#include <iterator>

// Ternary Search
const value_type *ternarySearch( const value_type* first, const value_type* last, const value_type value )
{
        value_type *m_first = const_cast<value_type *>(first);
        value_type *m_last = const_cast<value_type *>(last);

        value_type *m_pivo, *m_pivo1;

        while(m_first < m_last)
        {
                m_pivo = m_first + (m_last - m_first)/3;
                m_pivo1 = m_pivo + (m_last - m_first)/3;

                if(*(m_pivo) == value){
                        return m_pivo;
                }
                else if(*(m_pivo) > value){
                        m_last = m_pivo - 1;
                }
                else if(*(m_pivo) < value){
                        if(*(m_pivo1) == value){
                                return m_pivo1;
                        }
                        else if(*(m_pivo1) > value){
                                m_first = m_pivo + 1;
                                m_last = m_pivo1;
                        }
                        else{
                                m_first = m_pivo1 + 1;
                        }
                }
        }

        return last;
}

// Recursive Ternary Search
const value_type *rternarySearch( const value_type* first, const value_type* last, const value_type value )
{
        value_type *m_first = const_cast<value_type *>(first);
        value_type *m_last = const_cast<value_type *>(last);

        value_type *m_pivo, *m_pivo1;

        m_pivo = m_first + (m_last - m_first)/3;
        m_pivo1 = m_pivo + (m_last - m_first)/3;

        if(m_first>=m_last){
                return last;
        }

        if(*(m_pivo) == value){
                return m_pivo;
        }
        else if( *(m_pivo) > value){
                return rternarySearch(first,m_pivo - 1,value);
        }
        else if(*(m_pivo) < value){
                if(*(m_pivo1) == value){
                        return m_pivo1;
                }
                else if(*(m_pivo1) > value){
                        return rternarySearch(m_pivo + 1,m_pivo1,value);
                }
                else{
                        return rternarySearch(m_pivo1 + 1,last,value);
                }
        }

        return last;
}
