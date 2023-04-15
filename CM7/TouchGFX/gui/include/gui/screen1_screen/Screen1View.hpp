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


    void handleTickEvent();

protected:
    int tickCounter;
    int tickCounter2;
    int Counter = 0;
    int Counter2 = 0;
};

#endif // SCREEN1VIEW_HPP
