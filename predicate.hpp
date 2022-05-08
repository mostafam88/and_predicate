#ifndef PREDICATE_HPP
#define PREDICATE_HPP

template <class Object_type> class Predicate
{
public:
    virtual bool operator()(const Object_type& object) const = 0;
};

#endif