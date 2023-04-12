#include <gui/containers/customGraph.hpp>

customGraph::customGraph()
{

}

void customGraph::initialize()
{
    customGraphBase::initialize();
    customGraphBase::graph1.setGraphRangeX(0, 100);
    customGraphBase::graph1MajorXAxisLabel.setInterval((graph1.getGraphRangeXMaxAsInt() - graph1.getGraphRangeXMinAsInt())/4);
    customGraphBase::graph1MajorXAxisGrid.setInterval((graph1.getGraphRangeXMaxAsInt() - graph1.getGraphRangeXMinAsInt())/4);
    customGraphBase::graph1.setGraphRangeYAutoScaled(true,30);
    customGraphBase::graph1MajorYAxisLabel.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/4);
    customGraphBase::graph1MajorYAxisGrid.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/4);
    customGraphBase::timeLabel1.setXY(graph1.indexToScreenX(findTimeLabelCoordinate(25))  + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight(), 180);
    customGraphBase::timeLabel2.setXY(graph1.indexToScreenX(findTimeLabelCoordinate(50))  + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight(), 180);
    customGraphBase::timeLabel3.setXY(graph1.indexToScreenX(findTimeLabelCoordinate(75))  + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight(), 180);
    customGraphBase::timeLabel4.setXY(graph1.indexToScreenX(findTimeLabelCoordinate(100)) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight(), 180);
}


void customGraph::addPoint(float y, float x)
{
	customGraphBase::graph1.addDataPoint(y, x);
}
