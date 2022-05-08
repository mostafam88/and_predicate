#ifndef IS_X_EVEN_HPP
#define IS_X_EVEN_HPP

#include "predicate.hpp"

template <class Object_type> class Is_x_even : public Predicate<Object_type>
{
public:
    bool operator()(const Object_type& object) const override
    {
        const bool result = object.x % 2 == 0;
        std::cout << (result ? "[passed]" : "[failed]") << " Is_x_even with "
                  << object.x << '\n';
        return result;
    }
};

#endif