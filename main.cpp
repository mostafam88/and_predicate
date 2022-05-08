#include "iostream"

#include "is_p_positive.hpp"
#include "is_x_even.hpp"
#include "is_y_odd.hpp"
#include "object.hpp"

int main()
{
    const Is_p_positive<Object> is_p_positive{};
    const Is_x_even<Object>     is_x_even{};
    const Is_y_odd<Object>      is_y_odd{};

    for (const auto p : {3.14, -1.4142})
    {
        for (const auto x : {42, 13})
        {
            for (const auto y : {8, 55})
            {
                Object object{};
                object.p = p;
                object.x = x;
                object.y = y;

                const bool result = is_p_positive(object) &&
                                    is_x_even(object) && is_y_odd(object);

                std::cout << (result ? "[passed]" : "[failed]")
                          << " and_predicate" << '\n';
                std::cout << "=======================================" << '\n';
            }
        }
    }

    return 0;
}