#ifndef AND_PREDICATE_HPP
#define AND_PREDICATE_HPP

#include "predicate.hpp"

namespace private_implementation_detail
{

template <class... Predicate_types> class And_predicate;

template <class Predicate_type>
class And_predicate<Predicate_type>
  : Predicate<typename Predicate_type::Object_type>
{
public:
    And_predicate(const Predicate_type& predicate_)
      : predicate{&predicate_}
    {
    }

    bool operator()(
        const typename Predicate_type::Object_type& object) const override
    {
        return predicate->operator()(object);
    }

private:
    const Predicate_type* predicate;
};

template <class Predicate_type, class... Rest_predicate_types>
class And_predicate<Predicate_type, Rest_predicate_types...>
  : public And_predicate<Rest_predicate_types...>
{
public:
    using Base_class_type = And_predicate<Rest_predicate_types...>;

    And_predicate(const Predicate_type& predicate_,
                  const Rest_predicate_types&... rest_predicates_)
      : Base_class_type{rest_predicates_...}
      , predicate{&predicate_}
    {
    }

    bool operator()(
        const typename Predicate_type::Object_type& object) const override
    {
        return predicate->      operator()(object) &&
               Base_class_type::operator()(object);
    }

private:
    const Predicate_type* predicate;
};

} // namespace private_implementation_detail

template <class First_predicate_type, class Second_predicate_type>
private_implementation_detail::And_predicate<First_predicate_type,
                                             Second_predicate_type>
make_and_predicate(const First_predicate_type&  first_predicate,
                   const Second_predicate_type& second_predicate)
{
    using Return_type =
        private_implementation_detail::And_predicate<First_predicate_type,
                                                     Second_predicate_type>;
    return Return_type{first_predicate, second_predicate};
}

template <class First_predicate_type, class Second_predicate_type,
          class... Rest_predicate_types>
private_implementation_detail::And_predicate<
    First_predicate_type, Second_predicate_type, Rest_predicate_types...>
make_and_predicate(const First_predicate_type&  first_predicate,
                   const Second_predicate_type& second_predicate,
                   const Rest_predicate_types&... rest_predicates)
{
    using Return_type = private_implementation_detail::And_predicate<
        First_predicate_type, Second_predicate_type, Rest_predicate_types...>;
    return Return_type{first_predicate, second_predicate, rest_predicates...};
}

#endif