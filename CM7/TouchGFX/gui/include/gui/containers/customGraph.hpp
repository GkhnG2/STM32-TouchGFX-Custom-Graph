#ifndef CUSTOMGRAPH_HPP
#define CUSTOMGRAPH_HPP

#include <gui_generated/containers/customGraphBase.hpp>

class customGraph : public customGraphBase
{
public:
    customGraph();
    virtual ~customGraph() {}

    virtual void initialize();
    void addData(int y);
protected:
};

#endif // CUSTOMGRAPH_HPP
