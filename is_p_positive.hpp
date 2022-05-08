#ifndef IS_P_POSITIVE_HPP
#define IS_P_POSITIVE_HPP

#include "iostream"
#include "predicate.hpp"

template <class Object_type> class Is_p_positive : public Predicate<Object_type>
{
public:
    bool operator()(const Object_type& object) const override
    {
        const bool result = object.p > 0;
        std::cout << (result ? "[passed]" : "[failed]")
                  << " Is_p_positive with " << object.p << '\n';
        return result;
    }
};

#endif