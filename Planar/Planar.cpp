#include "Planar.h"
#include "EventList.h"

EventList eventList;

Planar::Planar(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Read info from file here
    eventList.fillRandom(20);

    // Connect the calendar selection to displaySelected
    Planar::connect(ui.calendarWidget, &QCalendarWidget::selectionChanged, this, &Planar::displaySelected);
}

Planar::~Planar()
{}

// Called when the calendar selection is changed
void Planar::displaySelected()
{
    ui.listWidget->clear();
    QDate selectedDate = ui.calendarWidget->selectedDate();
   
    eventList.fillEventsList(ui.listWidget, selectedDate);

}