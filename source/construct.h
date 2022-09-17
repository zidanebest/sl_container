#pragma once
#include "type_traits.h"

namespace sl
{
    
    template<typename T1,typename T2>
    inline void construct(T1* p,const T2& value)
    {
        new(p) T1(value);
    }

    template<typename T>
    inline void destroy(T* p)
    {
        p->~T();
    }

    template<typename ForwardIterator>
    inline void destroy(ForwardIterator first,ForwardIterator last)
    {
        _destroy(first,last,value_type(first));
    }

    template<typename ForwardIterator,typename T>
    inline void _destroy(ForwardIterator first,ForwardIterator last,T* t)
    {
        using trivial_destructor=typename type_traits<T>::has_trivial_destructor ;
        destroy_aux(first,last,trivial_destructor());
    }

    template<typename ForwardIterator>
    inline void destroy_aux(ForwardIterator first,ForwardIterator last, true_type){}
    template<typename ForwardIterator>
    inline void destroy_aux(ForwardIterator first,ForwardIterator last,false_type)
    {
        for(;first<last;++first)
        {
            destroy(&*first);
        }
    }
}
