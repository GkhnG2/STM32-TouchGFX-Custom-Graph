#ifndef CUSTOMGRAPH_HPP
#define CUSTOMGRAPH_HPP

#include <gui_generated/containers/customGraphBase.hpp>

class customGraph : public customGraphBase
{
public:
    customGraph();
    virtual ~customGraph() {}

    virtual void initialize();

    virtual void graph1Dragged(AbstractDataGraph::GraphDragEvent value)
	{
		// Override and implement this function in customGraph
    	// Override and implement this function in customGraph
		if(value.dragEvent.getNewX() > value.dragEvent.getOldX() && Counter>-100){
			Counter -= 1;
			graph1.setGraphRangeX(0 + Counter, 50 + Counter);
		}
		else if(value.dragEvent.getNewX() < value.dragEvent.getOldX() && 50+Counter<100){
			Counter += 1;
			graph1.setGraphRangeX(0 + Counter, 50 + Counter);
		}
	}

    void addPoint(float y, float x);
protected:
    int Counter = 0;
};

#endif // CUSTOMGRAPH_HPP
