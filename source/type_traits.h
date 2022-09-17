#pragma once

namespace sl
{

    struct false_type{};
    struct true_type{};
    
    template<typename T>
    struct type_traits
    {
        using has_trivial_destructor=false_type ; 
    };
    template<>
    struct type_traits<int>{using has_trivial_destructor=true_type;};
    template<>
    struct type_traits<unsigned int>{using has_trivial_destructor=true_type;};
    template<>
    struct type_traits<long>{using has_trivial_destructor=true_type;};
    template<>
    struct type_traits<long long>{using has_trivial_destructor=true_type;};
    template<>
    struct type_traits<float>{using has_trivial_destructor=true_type;};
    template<>
    struct type_traits<bool>{using has_trivial_destructor=true_type;};
    template<>
    struct type_traits<double>{using has_trivial_destructor=true_type;};
    
}