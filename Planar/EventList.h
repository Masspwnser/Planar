#pragma once

#include "Event.h"
#include <QString>
#include <QListWidget>

using namespace std;

class EventList
{
private:
	list<Event> eventList;

public:
	void add(Event);
	void fillEventsList(QListWidget* listbox, const QDate date);
	void fillRandom(int);
};
