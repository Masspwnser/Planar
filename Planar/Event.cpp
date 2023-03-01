#include "Event.h"

// Defaults to current time
Event::Event()
{
	dateTime = QDateTime::currentDateTime();
}

Event::Event(QDate d)
{
	dateTime = QDateTime(d, QTime());
}

Event::Event(QDateTime d)
{
	dateTime = d;
}

QDateTime Event::getDateTime() const
{
	return dateTime;
}

QDate Event::getDate() const
{
	return dateTime.date();
}

QTime Event::getTime() const
{
	return dateTime.time();
}
