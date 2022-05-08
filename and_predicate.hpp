#ifndef AND_PREDICATE_HPP
#define AND_PREDICATE_HPP

#include "predicate.hpp"

namespace private_implementation_detail
{

template <class Object_type, class First_predicate_type,
          class Second_predicate_type>
class And_predicate : public Predicate<Object_type>
{
public:
    And_predicate(const First_predicate_type&  first_predicate_,
                  const Second_predicate_type& second_predicate_)
      : first_predicate{&first_predicate_}
      , second_predicate{&second_predicate_}
    {
    }

    bool operator()(const Object_type& object) const override
    {
        const bool result = first_predicate-> operator()(object) &&
                            second_predicate->operator()(object);
        return result;
    }

private:
    const First_predicate_type*  first_predicate;
    const Second_predicate_type* second_predicate;
};

} // namespace private_implementation_detail

#endif