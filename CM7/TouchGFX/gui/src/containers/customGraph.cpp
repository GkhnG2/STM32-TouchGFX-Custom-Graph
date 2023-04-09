#include <gui/containers/customGraph.hpp>

customGraph::customGraph()
{

}

void customGraph::initialize()
{
    customGraphBase::initialize();
}


void customGraph::addPoint(float y)
{
    customGraphBase::dynamicGraph1.addDataPoint(y);
    customGraphBase::dynamicGraph1.setGraphRangeYAuto(true,5);
}
