#ifndef PREDICATE_HPP
#define PREDICATE_HPP

template <class Object_type_> class Predicate
{
public:
    using Object_type = Object_type_;

    virtual bool operator()(const Object_type& object) const = 0;
};

#endif