#define MAX_DAY_EVENTS 100 //max events in one day
#define MAX_EVENT_FILESIZE 50000
typedef struct // Event date definition
{
  unsigned day;
  unsigned month;
  unsigned year;
} EventDate;

typedef struct // Event time definition
{
  unsigned hour;
  unsigned minute;
  unsigned second;
} EventTime;

typedef struct // Defines what a calendar event contains
{
  unsigned category;
  unsigned daterange;
  EventDate startdate;
  EventDate enddate;
  unsigned dayofweek;
  unsigned repeat;
  unsigned timed; //full-day = 0, timed = 1
  EventTime starttime;
  EventTime endtime;
  unsigned char title[25]; //can't be 21, because otherwise somehow the location will replace the last chars of title
  unsigned char location[135]; //can't be 128, because otherwise somehow the description may flow into the location.
  unsigned char description[1030]; //orig 1024
} CalendarEvent;
// end of type definitions
extern CalendarEvent charToCalEvent(unsigned char *src,int leadingTwoBytes);
void calEventToChar(unsigned char *buf,CalendarEvent calEvent);
int atoi(const char *str);
void filenameFromDate(EventDate date, char* filename);
int AddSMEMEvent(CalendarEvent calEvent, const char* filename);
int RemoveSMEMEvent(EventDate startdate, int calEventPos, const char* folder);
int EditSMEMEvent(EventDate startdate, int calEventPos, const char* folder, CalendarEvent editedEvent);
int RemoveSMEMDay(EventDate date, const char* folder);
int GetSMEMeventsForDate(EventDate startdate, const char* folder, CalendarEvent calEvents[]);
int AddMCSEvent(CalendarEvent calEvent, const char* folder);
int RemoveMCSDay(EventDate date, const char* folder);
int GetMCSeventsForDate(EventDate startdate, const char* folder, CalendarEvent calEvents[]);
