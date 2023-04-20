#ifndef CUSTOMGRAPH_HPP
#define CUSTOMGRAPH_HPP

#include <gui_generated/containers/customGraphBase.hpp>
#include <time.h>
#include <string.h>

class customGraph : public customGraphBase
{
public:
    customGraph();
    virtual ~customGraph() {}

    virtual void initialize();

    void addPoint(time_t x, float y);

    void setMaxPoint(int maxPoint);

    void setTimeRange(int hours);			// 1,8 or 24

    void  clearAllData();

    void  setYAxisLabel(const char* name);

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

    void convert_timeStampToDateTime(time_t * timestamp, struct tm * date_time)
    {
    	localtime_r(timestamp, date_time);
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
		if(value.dragEvent.getNewX() > value.dragEvent.getOldX() && scrollCounter>0.0){
			scrollCounter -= (customGraphTimeRange/float(2.0));

			if(timeLabel1.getX() + 16 >= graph1.getX() + graph1.getGraphAreaMarginLeft() + graph1.getGraphAreaWidth() - graph1.getGraphAreaMarginRight()){
				if(timeLabel1_pageCNTR > 0){
					timeLabel1_pageCNTR--;
					timeLabel1_time = timeLabel1_time - customGraphInterval*numberofGrid*60;
					convert_timeStampToDateTime(&timeLabel1_time, &timeLabel1_time_tm);
					updateTimeLabel(&timeLabel1, timeLabel1Buffer, &timeLabel1_time_tm);
				}
			}
			if(timeLabel2.getX() + 16 >= graph1.getX() + graph1.getGraphAreaMarginLeft() + graph1.getGraphAreaWidth() - graph1.getGraphAreaMarginRight()){
				if(timeLabel2_pageCNTR > 0){
					timeLabel2_pageCNTR--;
					timeLabel2_time = timeLabel2_time - customGraphInterval*numberofGrid*60;
					convert_timeStampToDateTime(&timeLabel2_time, &timeLabel2_time_tm);
					updateTimeLabel(&timeLabel2, timeLabel2Buffer, &timeLabel2_time_tm);
				}
			}
			if(timeLabel3.getX() + 16 >= graph1.getX() + graph1.getGraphAreaMarginLeft() + graph1.getGraphAreaWidth() - graph1.getGraphAreaMarginRight()){
				if(timeLabel3_pageCNTR > 0){
					timeLabel3_pageCNTR--;
					timeLabel3_time = timeLabel3_time - customGraphInterval*numberofGrid*60;
					convert_timeStampToDateTime(&timeLabel3_time, &timeLabel3_time_tm);
					updateTimeLabel(&timeLabel3, timeLabel3Buffer, &timeLabel3_time_tm);
				}
			}
			if(timeLabel4.getX() + 16 >= graph1.getX() + graph1.getGraphAreaMarginLeft() + graph1.getGraphAreaWidth() - graph1.getGraphAreaMarginRight()){
				if(timeLabel4_pageCNTR > 0){
					timeLabel4_pageCNTR--;
					timeLabel4_time = timeLabel4_time - customGraphInterval*numberofGrid*60;
					convert_timeStampToDateTime(&timeLabel4_time, &timeLabel4_time_tm);
					updateTimeLabel(&timeLabel3, timeLabel4Buffer, &timeLabel4_time_tm);
				}
			}
		}
		else if(value.dragEvent.getNewX() < value.dragEvent.getOldX() && (graph1.getGraphRangeXMaxAsInt()-customGraphInterval) < graph1.indexToDataPointXAsInt(graph1.getUsedCapacity()-1)){
			scrollCounter += (customGraphTimeRange/float(2.0));

			if(timeLabel1.getX() + 16 <= graph1.getX() + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight()){
				timeLabel1_pageCNTR++;
				timeLabel1_time = timeLabel1_time + customGraphInterval*numberofGrid*60;
				convert_timeStampToDateTime(&timeLabel1_time, &timeLabel1_time_tm);
				updateTimeLabel(&timeLabel1, timeLabel1Buffer, &timeLabel1_time_tm);
			}
			if(timeLabel2.getX() + 16 <= graph1.getX() + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight()){
				timeLabel2_pageCNTR++;
				timeLabel2_time = timeLabel2_time + customGraphInterval*numberofGrid*60;
				convert_timeStampToDateTime(&timeLabel2_time, &timeLabel2_time_tm);
				updateTimeLabel(&timeLabel2, timeLabel2Buffer, &timeLabel2_time_tm);
			}
			if(timeLabel3.getX() + 16 <= graph1.getX() + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight()){
				timeLabel3_pageCNTR++;
				timeLabel3_time = timeLabel3_time + customGraphInterval*numberofGrid*60;
				convert_timeStampToDateTime(&timeLabel3_time, &timeLabel3_time_tm);
				updateTimeLabel(&timeLabel3, timeLabel3Buffer, &timeLabel3_time_tm);
			}
			if(timeLabel4.getX() + 16 <= graph1.getX() + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight()){
				timeLabel4_pageCNTR++;
				timeLabel4_time = timeLabel4_time + customGraphInterval*numberofGrid*60;
				convert_timeStampToDateTime(&timeLabel4_time, &timeLabel4_time_tm);
				updateTimeLabel(&timeLabel4, timeLabel4Buffer, &timeLabel4_time_tm);
			}
		}

		graph1.setGraphRangeX(0 + int(scrollCounter), (graph1.getGraphRangeXMaxAsInt() - graph1.getGraphRangeXMinAsInt()) + int(scrollCounter));
		graph1.setGraphRangeYAuto(true,(graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/float(numberofGrid));
		graph1MajorYAxisLabel.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/float(numberofGrid));
		graph1MajorYAxisGrid.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/float(numberofGrid));

		timeLabel1_Pos = CWRUtil::muldiv_toQ5(((timeLabel1_pageCNTR*customGraphInterval*numberofGrid)+1*customGraphInterval) - graph1.getGraphRangeXMinScaled(), graph1.getGraphAreaWidth() - 1, graph1.getGraphRangeXMaxScaled() - graph1.getGraphRangeXMinScaled()) + CWRUtil::toQ5(graph1.getGraphAreaPaddingLeft());
		timeLabel2_Pos = CWRUtil::muldiv_toQ5(((timeLabel2_pageCNTR*customGraphInterval*numberofGrid)+2*customGraphInterval) - graph1.getGraphRangeXMinScaled(), graph1.getGraphAreaWidth() - 1, graph1.getGraphRangeXMaxScaled() - graph1.getGraphRangeXMinScaled()) + CWRUtil::toQ5(graph1.getGraphAreaPaddingLeft());
		timeLabel3_Pos = CWRUtil::muldiv_toQ5(((timeLabel3_pageCNTR*customGraphInterval*numberofGrid)+3*customGraphInterval) - graph1.getGraphRangeXMinScaled(), graph1.getGraphAreaWidth() - 1, graph1.getGraphRangeXMaxScaled() - graph1.getGraphRangeXMinScaled()) + CWRUtil::toQ5(graph1.getGraphAreaPaddingLeft());
		timeLabel4_Pos = CWRUtil::muldiv_toQ5(((timeLabel4_pageCNTR*customGraphInterval*numberofGrid)+4*customGraphInterval) - graph1.getGraphRangeXMinScaled(), graph1.getGraphAreaWidth() - 1, graph1.getGraphRangeXMaxScaled() - graph1.getGraphRangeXMinScaled()) + CWRUtil::toQ5(graph1.getGraphAreaPaddingLeft());

		timeLabel1.setX(graph1.getX() + timeLabel1_Pos.round()  + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
		timeLabel2.setX(graph1.getX() + timeLabel2_Pos.round()  + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
		timeLabel3.setX(graph1.getX() + timeLabel3_Pos.round()  + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
		timeLabel4.setX(graph1.getX() + timeLabel4_Pos.round()  + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);

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

			setYAxisLabel("qwer");
		}
		if(value.clickEvent.getType() == ClickEvent::RELEASED){

		}
	}

	CWRUtil::Q5 timeLabel1_Pos;
	CWRUtil::Q5 timeLabel2_Pos;
	CWRUtil::Q5 timeLabel3_Pos;
	CWRUtil::Q5 timeLabel4_Pos;

	float scrollCounter = 0.0;
	int timeLabel1_pageCNTR=0;
	int timeLabel2_pageCNTR=0;
	int timeLabel3_pageCNTR=0;
	int timeLabel4_pageCNTR=0;

	time_t firstDataTime;
	struct tm firstDataTime_tm;
	uint8_t firstDataTaken=0;

	time_t timeLabel1_time;
	struct tm timeLabel1_time_tm;
	time_t timeLabel2_time;
	struct tm timeLabel2_time_tm;
	time_t timeLabel3_time;
	struct tm timeLabel3_time_tm;
	time_t timeLabel4_time;
	struct tm timeLabel4_time_tm;

	short int customGraphMaxPoint  = 500;
	int customGraphTimeRange = 24;
	int customGraphInterval = 125;
	int numberofGrid = 4;
};

#endif // CUSTOMGRAPH_HPP
