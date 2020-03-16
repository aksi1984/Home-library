#ifndef ACTIONSRANGE_HPP
#define ACTIONSRANGE_HPP

#include <QAction>


inline QList<QAction*> actionsInRange(int begin, int end, QList<QAction*> source)
{
    QList<QAction*> actions;

    for(int i = begin; i < end; ++i)
    {
        actions.insert(i, source[i]);
    }

    return  actions;
}

#endif // ACTIONSRANGE_HPP
