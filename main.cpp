#include "iostream"

#include "and_predicate.hpp"
#include "is_p_positive.hpp"
#include "is_x_even.hpp"
#include "is_y_odd.hpp"
#include "object.hpp"

int main()
{
    const Is_p_positive<Object> is_p_positive{};
    const Is_x_even<Object>     is_x_even{};
    const Is_y_odd<Object>      is_y_odd{};

    const auto and_predicate =
        make_and_predicate<Object>(is_p_positive, is_x_even, is_y_odd);

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

                std::cout << (and_predicate(object) ? "[passed]" : "[failed]")
                          << " output" << '\n';
                std::cout << "=======================================" << '\n';
            }
        }
    }

    return 0;
}