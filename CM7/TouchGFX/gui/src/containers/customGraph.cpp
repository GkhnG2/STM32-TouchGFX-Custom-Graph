#include <gui/containers/customGraph.hpp>

customGraph::customGraph()
{

}

void customGraph::initialize()
{
    customGraphBase::initialize();
}


void customGraph::addData(int y)
{
    customGraphBase::dynamicGraph1.addDataPoint(y);
}
