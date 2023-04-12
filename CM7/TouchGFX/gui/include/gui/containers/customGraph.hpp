#ifndef CUSTOMGRAPH_HPP
#define CUSTOMGRAPH_HPP

#include <gui_generated/containers/customGraphBase.hpp>

class customGraph : public customGraphBase
{
public:
    customGraph();
    virtual ~customGraph() {}

    virtual void initialize();

    void addPoint(float y, float x);

protected:

    int findTimeLabelCoordinate(int targetX_Val)
	{
		int16_t targetXIndex;
		int16_t i;

		targetXIndex = targetX_Val;
		if(targetXIndex > graph1.getUsedCapacity())
			targetXIndex = graph1.getUsedCapacity()-1;
		for(i=0; i<100; i++){
			if(graph1.indexToDataPointXAsInt(targetXIndex) > targetX_Val ){
				targetXIndex -= 1;
			}
			else{
				break;
			}
		}
		return targetXIndex;
	}

    virtual void graph1Dragged(AbstractDataGraph::GraphDragEvent value)
	{

		// Override and implement this function in customGraph
		if(value.dragEvent.getNewX() > value.dragEvent.getOldX() && Counter>0){
			Counter -= 1;
			graph1.setGraphRangeX(0 + Counter, (graph1.getGraphRangeXMaxAsInt() - graph1.getGraphRangeXMinAsInt()) + Counter);
			graph1.setGraphRangeYAutoScaled(true,30);
			graph1MajorYAxisLabel.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/4);
			graph1MajorYAxisGrid.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/4);

			if(timeLabel1.getX() >= graph1.getX() + graph1.getGraphAreaMarginLeft() + graph1.getGraphAreaWidth() - graph1.getGraphAreaMarginRight())
				if(label1_pageCNTR > 0)
					label1_pageCNTR--;
			if(timeLabel2.getX() >= graph1.getX() + graph1.getGraphAreaMarginLeft() + graph1.getGraphAreaWidth() - graph1.getGraphAreaMarginRight())
				if(label2_pageCNTR > 0)
					label2_pageCNTR--;
			if(timeLabel3.getX() >= graph1.getX() + graph1.getGraphAreaMarginLeft() + graph1.getGraphAreaWidth() - graph1.getGraphAreaMarginRight())
				if(label3_pageCNTR > 0)
					label3_pageCNTR--;
			if(timeLabel4.getX() >= graph1.getX() + graph1.getGraphAreaMarginLeft() + graph1.getGraphAreaWidth() - graph1.getGraphAreaMarginRight())
				if(label4_pageCNTR > 0)
					label4_pageCNTR--;
		}
		else if(value.dragEvent.getNewX() < value.dragEvent.getOldX() && (graph1.getGraphRangeXMaxAsInt() - graph1.getGraphRangeXMinAsInt())+Counter<500){
			Counter += 1;
			graph1.setGraphRangeX(0 + Counter, (graph1.getGraphRangeXMaxAsInt() - graph1.getGraphRangeXMinAsInt()) + Counter);
			graph1.setGraphRangeYAutoScaled(true,30);
			graph1MajorYAxisLabel.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/4);
			graph1MajorYAxisGrid.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/4);

			if(timeLabel1.getX() <= graph1.getX() + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight())
				label1_pageCNTR++;
			if(timeLabel2.getX() <= graph1.getX() + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight())
				label2_pageCNTR++;
			if(timeLabel3.getX() <= graph1.getX() + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight())
				label3_pageCNTR++;
			if(timeLabel4.getX() <= graph1.getX() + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight())
				label4_pageCNTR++;
		}
		timeLabel1.moveTo(graph1.getX() + graph1.indexToScreenX(findTimeLabelCoordinate((label1_pageCNTR*100)+25))  + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight(), 180);
		timeLabel2.moveTo(graph1.getX() + graph1.indexToScreenX(findTimeLabelCoordinate((label2_pageCNTR*100)+50))  + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight(), 180);
		timeLabel3.moveTo(graph1.getX() + graph1.indexToScreenX(findTimeLabelCoordinate((label3_pageCNTR*100)+75))  + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight(), 180);
		timeLabel4.moveTo(graph1.getX() + graph1.indexToScreenX(findTimeLabelCoordinate((label4_pageCNTR*100)+100)) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight(), 180);
	}

	virtual void graph1clicked(AbstractDataGraph::GraphClickEvent value)
	{
		// Override and implement this function in customGraph
		if(value.clickEvent.getType() == ClickEvent::PRESSED){
			Unicode::snprintf(debugTextBuffer, DEBUGTEXT_SIZE, "%d", value.index);
			debugText.setWildcard(debugTextBuffer);
			debugText.invalidate();
			debugText.resizeToCurrentText();
			debugText.invalidate();
		}
		if(value.clickEvent.getType() == ClickEvent::RELEASED){

		}
	}

	int Counter = 0;
	int label1_pageCNTR=0;
	int label2_pageCNTR=0;
	int label3_pageCNTR=0;
	int label4_pageCNTR=0;
};

#endif // CUSTOMGRAPH_HPP
