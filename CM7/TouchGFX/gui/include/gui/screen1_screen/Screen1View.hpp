#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

	virtual void graph2Dragged(AbstractDataGraph::GraphDragEvent value)
	{
		// Override and implement this function in Screen1
		if(value.dragEvent.getNewX() > value.dragEvent.getOldX()){
			Counter2 -= 1;
			graph2.setGraphRangeX(0 + Counter2, 100 + Counter2);
		}
		else if(value.dragEvent.getNewX() < value.dragEvent.getOldX()){
			Counter2 += 1;
			graph2.setGraphRangeX(0 + Counter2, 100 + Counter2);
		}
	}

    void handleTickEvent();

protected:
    int tickCounter;
    int tickCounter2;
    int Counter = 0;
    int Counter2 = 0;
};

#endif // SCREEN1VIEW_HPP
