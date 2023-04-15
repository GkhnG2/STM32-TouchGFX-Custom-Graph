#include <gui/containers/customGraph.hpp>

customGraph::customGraph()
{

}

void customGraph::initialize()
{
    customGraphBase::initialize();
    setTimeRange(24);

    firstDataTime = 1681492804;			// 1681492804 --> 14 April 2023 17:20			//firstDataTime = time(NULL);
    convertTimeStampToDate_time(&firstDataTime, &firstDataTime_tm);

    timeLabel1_time = firstDataTime + 300 + 1200;
    convertTimeStampToDate_time(&timeLabel1_time, &timeLabel1_time_tm);

    timeLabel2_time = timeLabel1_time + 1200;
    convertTimeStampToDate_time(&timeLabel2_time, &timeLabel2_time_tm);

    timeLabel3_time = timeLabel2_time + 1200;
    convertTimeStampToDate_time(&timeLabel3_time, &timeLabel3_time_tm);


	updateTimeLabel(&dateLabel, dateLabelBuffer, &firstDataTime_tm);

	updateTimeLabel(&timeLabel1, timeLabel1Buffer, &timeLabel1_time_tm);
	updateTimeLabel(&timeLabel2, timeLabel2Buffer, &timeLabel2_time_tm);
	updateTimeLabel(&timeLabel3, timeLabel3Buffer, &timeLabel3_time_tm);
}


void customGraph::addPoint(float y, float x)
{
	customGraphBase::graph1.addDataPoint(y, x);
}


void customGraph::setMaxPoint(int maxPoint)
{
	customGraphMaxPoint = maxPoint;
}


void customGraph::setTimeRange(int hours)
{
	int success = 0;

	switch(hours){
		case 1:
			customGraphTimeRange = 1;
			customGraphInterval = (customGraphMaxPoint/(24/customGraphTimeRange))/3;
			customGraphBase::graph1.setGraphRangeX(0, customGraphMaxPoint/(24/customGraphTimeRange));
			customGraphBase::graph1MajorXAxisLabel.setInterval(customGraphInterval);
			customGraphBase::graph1MajorXAxisGrid.setInterval(customGraphInterval);
			customGraphBase::graph1.setGraphRangeYAutoScaled(true,30);
			customGraphBase::graph1MajorYAxisLabel.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/3);
			customGraphBase::graph1MajorYAxisGrid.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/3);

			customGraphBase::timeLabel1.setX(graph1.getX() + (graph1.getGraphAreaWidth()*1/3) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
			customGraphBase::timeLabel2.setX(graph1.getX() + (graph1.getGraphAreaWidth()*2/3) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
			customGraphBase::timeLabel3.setX(graph1.getX() + (graph1.getGraphAreaWidth()*3/3) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
			break;
		case 8:
			customGraphTimeRange = 8;
			customGraphInterval = (customGraphMaxPoint/(24/customGraphTimeRange))/3;
			customGraphBase::graph1.setGraphRangeX(0, customGraphMaxPoint/(24/customGraphTimeRange));
			customGraphBase::graph1MajorXAxisLabel.setInterval(customGraphInterval);
			customGraphBase::graph1MajorXAxisGrid.setInterval(customGraphInterval);
			customGraphBase::graph1.setGraphRangeYAutoScaled(true,30);
			customGraphBase::graph1MajorYAxisLabel.setInterval(customGraphInterval);
			customGraphBase::graph1MajorYAxisGrid.setInterval(customGraphInterval);

			customGraphBase::timeLabel1.setX(graph1.getX() + (graph1.getGraphAreaWidth()*1/3) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
			customGraphBase::timeLabel2.setX(graph1.getX() + (graph1.getGraphAreaWidth()*2/3) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
			customGraphBase::timeLabel3.setX(graph1.getX() + (graph1.getGraphAreaWidth()*3/3) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
			break;
		case 24:
			customGraphTimeRange = 24;
			customGraphInterval = (customGraphMaxPoint/(24/customGraphTimeRange))/3;
			customGraphBase::graph1.setGraphRangeX(0, customGraphMaxPoint/(24/customGraphTimeRange));
			customGraphBase::graph1MajorXAxisLabel.setInterval(customGraphInterval);
			customGraphBase::graph1MajorXAxisGrid.setInterval(customGraphInterval);
			customGraphBase::graph1.setGraphRangeYAutoScaled(true,30);
			customGraphBase::graph1MajorYAxisLabel.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/3);
			customGraphBase::graph1MajorYAxisGrid.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/3);

			customGraphBase::timeLabel1.setX(graph1.getX() + (graph1.getGraphAreaWidth()*1/3) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
			customGraphBase::timeLabel2.setX(graph1.getX() + (graph1.getGraphAreaWidth()*2/3) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
			customGraphBase::timeLabel3.setX(graph1.getX() + (graph1.getGraphAreaWidth()*3/3) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
			break;
		default:
			break;

		if(success)
		{
			success = 0;


		}
	}
}
