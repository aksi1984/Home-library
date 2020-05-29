#ifndef DATATOWIDGET_HPP
#define DATATOWIDGET_HPP

#include "value.hpp"

template<typename... Args>
struct Type;

template<typename T, typename... Args>
struct Type<T, Args...>
{
    using type = typename T::value_type;
};

///////////////////////////////////////////////////////////////////////////////////

template<typename... Args>
void putDataInWidget(const QVariantList& varList, Args... args)
{
    if constexpr((IsList<Args>{}, ...))
    {
        // This part of this function shoud be write better in future!

        for(int i = 0; i < varList.size(); ++i)
        {
            Value<typename Type<Args...>::type>::get((args[i], ...), varList[i]);
        }
    }
    else
    {
        if(!varList.isEmpty())
        {
            int count = 0;
            (Value<Args>::get(args, varList[count++]), ...);
        }
    }
};

#endif // DATATOWIDGET_HPP
