#ifndef IS_Y_ODD_HPP
#define IS_Y_ODD_HPP

#include "predicate.hpp"

template <class Object_type> class Is_y_odd : public Predicate<Object_type>
{
public:
    bool operator()(const Object_type& object) const override
    {
        const bool result = object.y % 2 == 1;
        std::cout << (result ? "[passed]" : "[failed]") << " Is_y_odd with "
                  << object.y << '\n';
        return result;
    }
};

#endif