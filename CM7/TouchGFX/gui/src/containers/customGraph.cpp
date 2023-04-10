#include <gui/containers/customGraph.hpp>

customGraph::customGraph()
{

}

void customGraph::initialize()
{
    customGraphBase::initialize();
    customGraphBase::graph1.setGraphRangeX(0, 50);
}


void customGraph::addPoint(float y, float x)
{
	customGraphBase::graph1.addDataPoint(y, x);
//    customGraphBase::dynamicGraph1.addDataPoint(y);
//    customGraphBase::dynamicGraph1.setGraphRangeYAuto(true,5);
//    customGraphBase::dynamicGraph1.setGraphRangeX(0, 100);*/
}
