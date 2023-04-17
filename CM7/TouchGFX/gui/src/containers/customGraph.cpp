#include <gui/containers/customGraph.hpp>

customGraph::customGraph()
{

}

void customGraph::initialize()
{
    customGraphBase::initialize();

    firstDataTime = 1681492804;			// 1681492804 --> 14 April 2023 17:20			//firstDataTime = time(NULL);
    convert_timeStampToDateTime(&firstDataTime, &firstDataTime_tm);

    addPoint(firstDataTime, float(1.0));
	addPoint(firstDataTime + 1200, float(1.3));
	addPoint(firstDataTime + 1200, float(1.8));
	addPoint(firstDataTime + 2400, float(2.0));

	setTimeRange(24);
}


void customGraph::addPoint(time_t x, float y)
{
	struct tm x_tm;
	float x_axisVal;

	if(firstDataTaken == 0)
	{
		firstDataTaken = 1;
		firstDataTime = x;
		convert_timeStampToDateTime(&firstDataTime, &firstDataTime_tm);
		customGraphBase::graph1.addDataPoint(float(0.0), y);
	}
	else
	{
		convert_timeStampToDateTime(&x, &x_tm);
		if(x_tm.tm_year == firstDataTime_tm.tm_year && x_tm.tm_mon == firstDataTime_tm.tm_mon && (x_tm.tm_mday - firstDataTime_tm.tm_mday) < 2)
		{
			x_axisVal = ((x_tm.tm_mday - firstDataTime_tm.tm_mday)*24*60) + ((x_tm.tm_hour - firstDataTime_tm.tm_hour)*60) + (x_tm.tm_min - firstDataTime_tm.tm_min);
			customGraphBase::graph1.addDataPoint(float(x_axisVal), y);
		}
	}
}


void customGraph::setMaxPoint(int maxPoint)
{
	customGraphMaxPoint = maxPoint;
}


void customGraph::setTimeRange(int hours)
{

	if(hours == 1 || hours ==8 || hours == 24)
	{
		customGraphTimeRange = hours;
		customGraphInterval = (hours*60)/4;
		customGraphBase::graph1.setGraphRangeX(0, hours*60);
		customGraphBase::graph1MajorXAxisLabel.setInterval(customGraphInterval);
		customGraphBase::graph1MajorXAxisGrid.setInterval(customGraphInterval);
		customGraphBase::graph1.setGraphRangeYAutoScaled(true,1);
		customGraphBase::graph1MajorYAxisLabel.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/4);
		customGraphBase::graph1MajorYAxisGrid.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/4);

		customGraphBase::graph1MajorYAxisLabel.setInterval(1);
		customGraphBase::graph1MajorYAxisGrid.setInterval(1);

		timeLabel1_time = firstDataTime + customGraphInterval*60;
		convert_timeStampToDateTime(&timeLabel1_time, &timeLabel1_time_tm);

		timeLabel2_time = timeLabel1_time + customGraphInterval*60;
		convert_timeStampToDateTime(&timeLabel2_time, &timeLabel2_time_tm);

		timeLabel3_time = timeLabel2_time + customGraphInterval*60;
		convert_timeStampToDateTime(&timeLabel3_time, &timeLabel3_time_tm);

		timeLabel4_time = timeLabel3_time + customGraphInterval*60;
		convert_timeStampToDateTime(&timeLabel4_time, &timeLabel4_time_tm);

		Unicode::snprintf(dateLabelBuffer, 10, "%02d-%02d-%02d",firstDataTime_tm.tm_mday, firstDataTime_tm.tm_mon, firstDataTime_tm.tm_year-100);
		dateLabel.setWildcard(dateLabelBuffer);
		dateLabel.invalidate();
		dateLabel.resizeToCurrentText();
		dateLabel.invalidate();

		updateTimeLabel(&timeLabel1, timeLabel1Buffer, &timeLabel1_time_tm);
		updateTimeLabel(&timeLabel2, timeLabel2Buffer, &timeLabel2_time_tm);
		updateTimeLabel(&timeLabel3, timeLabel3Buffer, &timeLabel3_time_tm);
		updateTimeLabel(&timeLabel4, timeLabel4Buffer, &timeLabel4_time_tm);

		customGraphBase::timeLabel1.setX(graph1.getX() + (graph1.getGraphAreaWidth()*1/4) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
		customGraphBase::timeLabel2.setX(graph1.getX() + (graph1.getGraphAreaWidth()*2/4) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
		customGraphBase::timeLabel3.setX(graph1.getX() + (graph1.getGraphAreaWidth()*3/4) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);
		customGraphBase::timeLabel4.setX(graph1.getX() + (graph1.getGraphAreaWidth()*4/4) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - 22);

		scrollCounter = 0;
	}
}
