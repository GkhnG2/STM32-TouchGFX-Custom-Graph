#ifndef CUSTOMGRAPH_HPP
#define CUSTOMGRAPH_HPP

#include <gui_generated/containers/customGraphBase.hpp>
#include <time.h>

class customGraph : public customGraphBase
{
public:
    customGraph();
    virtual ~customGraph() {}

    virtual void initialize();

    void addPoint(float y, float x);

    void setMaxPoint(int maxPoint);

    void setTimeRange(int hours);			// 1,8 or 24

    void  clearAllData();

    void  setYAxisLabel();

    void  cleanUp();

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

    void convertTimeStampToDate_time(time_t * timestamp, struct tm * date_time)
    {
    	//localtime_r(timestamp, date_time);
    }

    void updateTimeLabel(touchgfx::TextAreaWithOneWildcard * timelabel, touchgfx::Unicode::UnicodeChar * timeLabelBuf, struct tm * time)
    {
    	Unicode::snprintf(timeLabelBuf, 10, "%02dc%02d",time->tm_hour, time->tm_min);
    	timelabel->setWildcard(timeLabelBuf);
    	timelabel->invalidate();
    	timelabel->resizeToCurrentText();
    	timelabel->invalidate();
    }


    virtual void graph1Dragged(AbstractDataGraph::GraphDragEvent value)
	{
		// Override and implement this function in customGraph
		if(value.dragEvent.getNewX() > value.dragEvent.getOldX() && scrollCounter>0){
			scrollCounter -= 1;
			graph1.setGraphRangeX(0 + scrollCounter, (graph1.getGraphRangeXMaxAsInt() - graph1.getGraphRangeXMinAsInt()) + scrollCounter);
			graph1.setGraphRangeYAutoScaled(true,30);
			graph1MajorYAxisLabel.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/3);
			graph1MajorYAxisGrid.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/3);

			if(timeLabel1.getX() + 16 >= graph1.getX() + graph1.getGraphAreaMarginLeft() + graph1.getGraphAreaWidth() - graph1.getGraphAreaMarginRight()){
				if(timeLabel1_pageCNTR > 0){
					timeLabel1_pageCNTR--;
					timeLabel1_time = timeLabel1_time - 4800;
					convertTimeStampToDate_time(&timeLabel1_time, &timeLabel1_time_tm);
					updateTimeLabel(&timeLabel1, timeLabel1Buffer, &timeLabel1_time_tm);
				}
			}
			if(timeLabel2.getX() + 16 >= graph1.getX() + graph1.getGraphAreaMarginLeft() + graph1.getGraphAreaWidth() - graph1.getGraphAreaMarginRight()){
				if(timeLabel2_pageCNTR > 0){
					timeLabel2_pageCNTR--;
					timeLabel2_time = timeLabel2_time - 4800;
					convertTimeStampToDate_time(&timeLabel2_time, &timeLabel2_time_tm);
					updateTimeLabel(&timeLabel2, timeLabel2Buffer, &timeLabel2_time_tm);
				}
			}
			if(timeLabel3.getX() + 16 >= graph1.getX() + graph1.getGraphAreaMarginLeft() + graph1.getGraphAreaWidth() - graph1.getGraphAreaMarginRight()){
				if(timeLabel3_pageCNTR > 0){
					timeLabel3_pageCNTR--;
					timeLabel3_time = timeLabel3_time - 4800;
					convertTimeStampToDate_time(&timeLabel3_time, &timeLabel3_time_tm);
					updateTimeLabel(&timeLabel3, timeLabel3Buffer, &timeLabel3_time_tm);
				}
			}
		}
		else if(value.dragEvent.getNewX() < value.dragEvent.getOldX()/* && (graph1.getGraphRangeXMaxAsInt() - graph1.getGraphRangeXMinAsInt())+scrollCounter<graph1.getUsedCapacity()*/){
			scrollCounter += 1;
			graph1.setGraphRangeX(0 + scrollCounter, (graph1.getGraphRangeXMaxAsInt() - graph1.getGraphRangeXMinAsInt()) + scrollCounter);
			graph1.setGraphRangeYAutoScaled(true,30);
			graph1MajorYAxisLabel.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/3);
			graph1MajorYAxisGrid.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/3);

			if(timeLabel1.getX() + 16 <= graph1.getX() + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight()){
				timeLabel1_pageCNTR++;
				timeLabel1_time = timeLabel1_time + 4800;
				convertTimeStampToDate_time(&timeLabel1_time, &timeLabel1_time_tm);
				updateTimeLabel(&timeLabel1, timeLabel1Buffer, &timeLabel1_time_tm);
			}
			if(timeLabel2.getX() + 16 <= graph1.getX() + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight()){
				timeLabel2_pageCNTR++;
				timeLabel2_time = timeLabel2_time + 4800;
				convertTimeStampToDate_time(&timeLabel2_time, &timeLabel2_time_tm);
				updateTimeLabel(&timeLabel2, timeLabel2Buffer, &timeLabel2_time_tm);
			}
			if(timeLabel3.getX() + 16 <= graph1.getX() + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight()){
				timeLabel3_pageCNTR++;
				timeLabel3_time = timeLabel3_time + 4800;
				convertTimeStampToDate_time(&timeLabel3_time, &timeLabel3_time_tm);
				updateTimeLabel(&timeLabel3, timeLabel3Buffer, &timeLabel3_time_tm);
			}
		}
		timeLabel1_Pos = CWRUtil::muldiv_toQ5(((timeLabel1_pageCNTR*customGraphInterval*3)+1*customGraphInterval) - graph1.getGraphRangeXMinScaled(), graph1.getGraphAreaWidth() - 1, graph1.getGraphRangeXMaxScaled() - graph1.getGraphRangeXMinScaled()) + CWRUtil::toQ5(graph1.getGraphAreaPaddingLeft());
		timeLabel2_Pos = CWRUtil::muldiv_toQ5(((timeLabel2_pageCNTR*customGraphInterval*3)+2*customGraphInterval) - graph1.getGraphRangeXMinScaled(), graph1.getGraphAreaWidth() - 1, graph1.getGraphRangeXMaxScaled() - graph1.getGraphRangeXMinScaled()) + CWRUtil::toQ5(graph1.getGraphAreaPaddingLeft());
		timeLabel3_Pos = CWRUtil::muldiv_toQ5(((timeLabel3_pageCNTR*customGraphInterval*3)+3*customGraphInterval) - graph1.getGraphRangeXMinScaled(), graph1.getGraphAreaWidth() - 1, graph1.getGraphRangeXMaxScaled() - graph1.getGraphRangeXMinScaled()) + CWRUtil::toQ5(graph1.getGraphAreaPaddingLeft());
		/*timeLabel1.setX(graph1.getX() + graph1.indexToScreenX(findTimeLabelCoordinate((timeLabel1_pageCNTR*customGraphInterval*3)+customGraphInterval))  + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 16);
		timeLabel2.setX(graph1.getX() + graph1.indexToScreenX(findTimeLabelCoordinate((timeLabel2_pageCNTR*customGraphInterval*3)+customGraphInterval*2))  + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 16);
		timeLabel3.setX(graph1.getX() + graph1.indexToScreenX(findTimeLabelCoordinate((timeLabel3_pageCNTR*customGraphInterval*3)+customGraphInterval*3))  + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 16);
		*/

		timeLabel1.setX(graph1.getX() + timeLabel1_Pos.round()  + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
		timeLabel2.setX(graph1.getX() + timeLabel2_Pos.round()  + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
		timeLabel3.setX(graph1.getX() + timeLabel3_Pos.round()  + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);

	}

	virtual void graph1clicked(AbstractDataGraph::GraphClickEvent value)
	{
		CWRUtil::Q5 test;
		//int x;
		// Override and implement this function in customGraph
		if(value.clickEvent.getType() == ClickEvent::PRESSED){
			//Unicode::snprintf(debugTextBuffer, 10, "%d", graph1.getUsedCapacity());
			//x = graph1.int2scaledX(value.index);
			test = CWRUtil::muldiv_toQ5(12 - graph1.getGraphRangeXMinScaled(), graph1.getGraphAreaWidth() - 1, graph1.getGraphRangeXMaxScaled() - graph1.getGraphRangeXMinScaled()) + CWRUtil::toQ5(graph1.getGraphAreaPaddingLeft());
			Unicode::snprintf(debugTextBuffer, 10, "%d", test.round());
			//Unicode::snprintf(debugTextBuffer, 10, "%d", graph1.indexToScreenX(value.index));
			//Unicode::snprintf(debugTextBuffer, 10, "%d", graph1.getGraphRangeXMaxScaled() - graph1.getGraphRangeXMinScaled());
			//Unicode::snprintf(debugTextBuffer, 10, "%d", graph1.getGraphAreaPaddingLeft());
			debugText.setWildcard(debugTextBuffer);
			debugText.invalidate();
			debugText.resizeToCurrentText();
			debugText.invalidate();
		}
		if(value.clickEvent.getType() == ClickEvent::RELEASED){

		}
	}

	CWRUtil::Q5 timeLabel1_Pos;
	CWRUtil::Q5 timeLabel2_Pos;
	CWRUtil::Q5 timeLabel3_Pos;

	int scrollCounter = 0;
	int timeLabel1_pageCNTR=0;
	int timeLabel2_pageCNTR=0;
	int timeLabel3_pageCNTR=0;

	time_t firstDataTime;
	struct tm firstDataTime_tm;

	time_t timeLabel1_time;
	struct tm timeLabel1_time_tm;
	time_t timeLabel2_time;
	struct tm timeLabel2_time_tm;
	time_t timeLabel3_time;
	struct tm timeLabel3_time_tm;

	short int customGraphMaxPoint  = 500;
	int customGraphTimeRange = 24;
	int customGraphInterval = 125;
};

#endif // CUSTOMGRAPH_HPP
