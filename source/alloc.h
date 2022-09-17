#pragma once

#if 0
    #include <new>
    #define THROW_BAD_ALLOC throw std::bad_alloc
#elif !defined THROW_BAD_ALLOC
    #include<iostream>
    #define THROW_BAD_ALLOC std::cerr<<"out of memory!"<<std::endl;exit(1)
#endif
#include <stdexcept>


class malloc_alloc
{
public:
    static void* oom_malloc(size_t size)
    {
        void(*my_malloc_realloc_oom_handler)()=nullptr;
        void* result=nullptr;
        for(;;)
        {
            my_malloc_realloc_oom_handler=malloc_alloc_oom_handler;
            if(my_malloc_realloc_oom_handler==nullptr) {THROW_BAD_ALLOC;}
            (*my_malloc_realloc_oom_handler)();
            result=malloc(size);
            if(result) return result;
        }
    }
    static void* oom_realloc(void* p, size_t size)
    {
        void (*my_malloc_realloc_oom_handler)() = nullptr;
        void* result = nullptr;
        for (;;)
        {
            my_malloc_realloc_oom_handler = malloc_alloc_oom_handler;
            if (!my_malloc_realloc_oom_handler){THROW_BAD_ALLOC;}
            (*my_malloc_realloc_oom_handler)();
            result = realloc(p,size);
            if (result) return result;
        }
    }
    static void* allocate(size_t n)
    {
        void* result=malloc(n);
        if(!result) result=oom_malloc(n);
        return result;
    }
    static void* reallocate(void* p,size_t old_size,size_t new_size)
    {
        void* result=realloc(p,new_size);
        if(!result) result=oom_realloc(p,new_size);
        return result;
    }
    static void deallocate(void* p,size_t size)
    {
        free(p);
    }
    static void(*set_oom_handler(void(*f)()))()
    {
        auto old=malloc_alloc_oom_handler;
        malloc_alloc_oom_handler=f;
        return old;
    }
protected:
    static void(* malloc_alloc_oom_handler)()=nullptr;
};
