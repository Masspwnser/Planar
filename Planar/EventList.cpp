#include "EventList.h"

#include <list>
#include <algorithm>
#include <QDateTime>
#include <QDebug>

// Predicate for the insert position, based off exact dateTime
bool predDate(const Event& lhs, const Event& rhs)
{
	return lhs.getDate() < rhs.getDate();
}
// Predicate for the date selection, based off the whole day
// Make more like this to modify the event display window
bool predTime(const Event& lhs, const Event& rhs)
{
	return lhs.getDateTime() < rhs.getDateTime();
}

// Inserts an event into the list in sorted order
void EventList::add(Event e)
{
	auto insertPos = lower_bound(eventList.begin(), eventList.end(), e, predTime);
	eventList.insert(insertPos, e);
}

// Takes a list widget and a date
// Fills the widget with all of the events on that date
void EventList::fillEventsList(QListWidget* listbox, const QDate date)
{
	auto bounds = equal_range(eventList.begin(), eventList.end(), Event(date), predDate);

	for_each(bounds.first, bounds.second, [listbox](Event e)
		{
			listbox->addItem(e.getDateTime().toString());
		});
}

// Fill the list with n events with dates set by days and seconds
void EventList::fillRandom(int n)
{
	int days = 5;
	int seconds = 1200;
	srand(time(nullptr));
	for (int i = 0; i < n; i++)
	{
		Event e(QDateTime::currentDateTime() + chrono::days(rand() % days) + chrono::seconds(rand() % seconds));
		add(e);
	}
}
