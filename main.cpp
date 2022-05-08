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

    using And_predicate_two = private_implementation_detail::And_predicate<
        Object, Is_p_positive<Object>, Is_x_even<Object>>;
    using And_predicate_three =
        private_implementation_detail::And_predicate<Object, And_predicate_two,
                                                     Is_y_odd<Object>>;
    const And_predicate_two   and_predicate_two{is_p_positive, is_x_even};
    const And_predicate_three and_predicate_three{and_predicate_two, is_y_odd};


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

                std::cout << (and_predicate_three(object) ? "[passed]"
                                                          : "[failed]")
                          << " output" << '\n';
                std::cout << "=======================================" << '\n';
            }
        }
    }

    return 0;
}