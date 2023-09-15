#pragma once
#include <iostream>
#include <ctime>


class clsDate
{

private:

    short Day;
    short Month;
    short Year;


public :


    clsDate()
    {
       time_t T = time(0);
       tm* Now = localtime(&T);
       Day = Now->tm_mday;
       Month = Now->tm_mon + 1;
       Year = Now->tm_year + 1900;

    }

    clsDate(string Date)
    {
        *this = StringToDate(Date);
    }

    clsDate(short Day, short Month, short Year)
    {
       this->Day = Day;
       this->Month = Month;
       this->Year = Year;
    }

    clsDate(short Days,short Year)
    {
      *this = GetDateFromDayOredeInYear(Days,Year);
    }

    void SetDay(short Day)
    {
        this->Day = Day;
    }

    short GetDay()
    {
        return Day;
    }

    void SetMonth(short Month)
    {
        this->Month = Month;
    }

    short GetMonth()
    {
        return Month;
    }

    void SetYear(short Year)
    {
      this->Year = Year;
    }

    short GetYear()
    {
        return Year;
    }

    void Print ()
    {
        cout <<  GetDate() << endl;
    }

static bool IsLeapYear(short Year)
{
 return (Year % 4 ==0 && Year % 100 != 0) || (Year % 400 ==0);
}

bool IsLeapYear()
{
    return IsLeapYear(Year);
}

static short NumberOfDaysInYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfDaysInYear()
{
    return NumberOfDaysInYear(Year);
}

static short NumberOfHourInYear(short Year)
{
    return NumberOfDaysInYear(Year) * 24;
}

short NumberOfHourInYear()
{
    return NumberOfHourInYear(Year);
}

static int NumberOfMinuteInYear(short Year)
{
    return NumberOfHourInYear(Year) * 60;
}

int NumberOfMinuteInYear()
{
    return NumberOfMinuteInYear(Year);
}

static int NumberOfSecondsInYear(short Year)
{
    return NumberOfMinuteInYear(Year) * 60;
}

int NumberOfSecondsInYear()
{
    return NumberOfSecondsInYear(Year);
}

static int NumberOfDaysInMonth(short Month ,short Year)
{
    if(Month < 1 || Month > 12)
        return 0;

     int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};

     return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

int NumberOfDaysInMonth()
{
    return NumberOfDaysInMonth(Month,Year);
}

static int NumberOfHourInMonth(short Month ,short Year)
{
    return NumberOfDaysInMonth(Month,Year) * 24;
}

int NumberOfHourInMonth()
{
    return NumberOfHourInMonth(Month,Year);
}

static int NumberOfMinuteInMonth(short Month ,short Year)
{
    return NumberOfHourInMonth(Month,Year) * 60;
}

int NumberOfMinuteInMonth()
{
    return NumberOfMinuteInMonth(Month,Year);
}

static int NumberOfSecondsInMonth(short Month ,short Year)
{
    return NumberOfMinuteInMonth(Month,Year) *60;
}

int NumberOfSecondsInMonth()
{
    return NumberOfSecondsInMonth(Month,Year);
}

static short ReadYear()
 {
     cout << "\nPlease Enter a Year to check ";
     int Year;
     cin >> Year;
     return Year;
 }

static short ReadMonth()
 {
     cout << "\nPlease Enter a Month to check ";
     int Month;
     cin >> Month;
     return Month;
 }

static short DayOfWeekOrder(short Year , short Month, short Day)
{
    short a , y ,m ;

    a = (14 -Month) / 12;
    y = Year - a;
    m = Month + 12 * a - 2;
    // Gregorian:
    //0:Sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y/4)-(y/100) + (y/400) + ((31 * m) /12)) % 7;

}

static short DayOfWeekOrder(clsDate Date)
{
    return DayOfWeekOrder(Date.Year,Date.Month,Date.Day);
}

short DayOfWeekOrder()
{
    return DayOfWeekOrder(*this);
}

static string DayShortName(short DayOfWeekOrder)
{
    string arrDays[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    return arrDays[DayOfWeekOrder];
}

string DayShortName()
{
    return DayShortName(Day);
}

static short ReadDay()
 {
     cout << "\nPlease Enter a Day  ";
     int Day;
     cin >> Day;
     return Day;
 }

static  string MonthShortName(short MonthOfYear)
{
    string MonthOfYearName[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    return MonthOfYearName[MonthOfYear-1];
}

string MonthShortName()
{
    return MonthShortName(Month);
}

static void PrintMonthCalendar(short Year , short Month)
{
    short NumberOfDays;

    // index of day from 0 to 6
    short current = DayOfWeekOrder(Year,Month,1);

    NumberOfDays = NumberOfDaysInMonth(Month,Year);

    // print the current month name
    printf("\n_________________%s_______________\n\n",MonthShortName(Month).c_str());

    // print the columns
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    short i;
    for(i =0; i < current; i++)
        printf("     ");

    for(short j =1; j <= NumberOfDays; j++)
    {
        printf("%5d",j);

        if(++i == 7)
        {
            i =0;
            printf("\n");
        }

    }
        printf("\n___________________________________\n");

}

void PrintMonthCalendar()
{
    PrintMonthCalendar(Year,Month);
}

static void PrintYearCalendar(short Year)
{
         printf("\n___________________________________\n\n");
         printf("         Year Calendar - %d",Year);
         printf("\n___________________________________\n");

         for(short i =1; i <= 12; i++)
         {
             PrintMonthCalendar(Year,i);
         }

  return;

}

void PrintYearCalendar()
{
    PrintYearCalendar(Year);
}

static short NumberOfDaysFromTheBiginingTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for(short i =1; i <= Month -1; i++)
    {
        TotalDays += NumberOfDaysInMonth(i,Year);
    }
    TotalDays += Day;

    return TotalDays;
}

short NumberOfDaysFromTheBiginingTheYear()
{
    return NumberOfDaysFromTheBiginingTheYear(Day,Month,Year);
}

static clsDate DateAddDays(short Days, clsDate Date)
{
    short RemainingDays = Days + NumberOfDaysFromTheBiginingTheYear(Date.Day,Date.Month,Date.Year);
    short MonthDays = 0;

    Date.Month =1;

    while(true)
    {
        MonthDays = NumberOfDaysInMonth(Date.Month,Date.Year);

        if(RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;

            if(Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date;

}

clsDate DateAddDays(short Days, short Year)
{
    return DateAddDays(Days,*this);
}

static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
{
 return (Date1.Year < Date2.Year)? true : ((Date1.Year == Date2.Year)? (Date1.Month < Date2.Month)? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false) :false);
}

bool IsDateBeforeDate2(clsDate Date2)
{
   return IsDate1BeforeDate2(*this,Date2);
}

static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
{
    return (Date1.Year == Date2.Year)? (Date1.Month == Date2.Month)? (Date1.Day == Date2.Day)? true : false :false : false;
}

bool IsDateEqualDate2(clsDate Date2)
{
    return IsDate1EqualDate2(*this,Date2);
}

static bool IsDate1AfterDate2(clsDate Date1 , clsDate Date2)
{
    return (!IsDate1BeforeDate2(Date1,Date2) && !IsDate1EqualDate2(Date1,Date2));
}

bool IsDateAfterDate2(clsDate Date2)
{
    return IsDate1AfterDate2(*this,Date2);
}

static bool IsLastDayInMonth(clsDate Date)
{
    return (Date.Day == NumberOfDaysInMonth(Date.Month,Date.Year));
}

bool IsLastDayInMonth()
{
   return IsLastDayInMonth(*this);
}

static bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

bool IsLastMonthInYear()
{
    return IsLastMonthInYear(Month);
}

static clsDate DecreaseDateByOneDay(clsDate& Date)
{
    if(Date.Day == 1)
    {
        if(Date.Month == 1)
        {
            Date.Day = 31;
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInMonth(Date.Month,Date.Year);
        }

    }
    else
    {
        Date.Day--;
    }

    return Date;

}

void DecreaseDateByOneDay()
{
    DecreaseDateByOneDay(*this);
}

static clsDate DecreaseDateByXDays(clsDate& Date ,short Days)
{
    for(short i = 1; i <= Days; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

void DecreaseDateByXDays(short Days)
{
    DecreaseDateByXDays(*this,Days);
}

static clsDate DecreaseDateByOneWeek(clsDate& Date)
{
    for(short i=1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;

}

void  DecreaseDateByOneWeek()
{
    DecreaseDateByOneWeek(*this);
}

static clsDate DecreaseDateByXWeeks(clsDate& Date , short Weeks)
{
    for(short i =1; i <= Weeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }

    return Date;
}

void DecreaseDateByXWeeks(short Weeks)
{
    DecreaseDateByXWeeks(*this,Weeks);
}

static clsDate DecreaseDateByOneMonth(clsDate& Date)
{
    if(Date.Month == 1)
    {
        Date.Year--;
        Date.Month = 12;
    }
    else
    {
      Date.Month--;
    }

    ///last check day in date should not exceed max days in the current month
    /// example if daate is 31/3/2022 decreasing one month should not be 31/2/2022
    /// it is should be 28/2/2022
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month,Date.Year);

    if(Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

void DecreaseDateByOneMonth()
{
    DecreaseDateByOneMonth(*this);
}

static clsDate DecreaseDateByXMonths(clsDate& Date, short Months)
{
    for(short i = 1; i <= Months; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;

}

void DecreaseDateByXMonths(short Months)
{
    DecreaseDateByXMonths(*this,Months);
}

static clsDate DecreaseDateByOneYear(clsDate& Date)
{
    Date.Year--;
    return Date;
}

void DecreaseDateByOneYear()
{
    DecreaseDateByOneYear(*this);
}

static clsDate DecreaseDateByXYears(clsDate& Date, short YearsToAdd)
{
    Date.Year -= YearsToAdd;
    return Date;
}

void DecreaseDateByXYears(short YearsToAdd)
{
    DecreaseDateByXYears(*this,YearsToAdd);
}

static clsDate DecreaseDateByOneDecade(clsDate& Date)
{
    ///Period of 10 years
    Date.Year -= 10;
    return Date;
}

void DecreaseDateByOneDecade()
{
    DecreaseDateByOneDecade(*this);
}

static clsDate DecreaseDateByXDecades(clsDate& Date , short Decade)
{
    Date.Year -= Decade * 10;
    return Date;
}

void DecreaseDateByXDecades(short Decades)
{
   DecreaseDateByXDecades(*this,Decades);
}

static clsDate DecreaseDateByOneCentury(clsDate& Date)
{
    ///Period of 100 years
    Date.Year -= 100;
    return Date;
}

void DecreaseDateByOneCentury()
{
    DecreaseDateByOneCentury(*this);
}

static clsDate DecreaseDateByOneMillennium(clsDate& Date)
{
    ///Period of 1000 years
    Date.Year -= 1000;
    return Date;
}

void DecreaseDateByOneMillennium()
{
   DecreaseDateByOneMillennium(*this);
}

static clsDate AddOneDay(clsDate Date)
{
    if(IsLastDayInMonth(Date))
    {
        if(IsLastMonthInYear(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }

    }
    else
    {
        Date.Day++;
    }

    return Date;

}

void AddOneDay()
{
    *this = AddOneDay(*this);
}

static clsDate IncreaseDateByXDays(clsDate& Date ,short Days)
{
    for(short i = 1; i <= Days; i++)
    {
        Date = AddOneDay(Date);
    }
    return Date;
}

void IncreaseDateByXDays(short Days )
{
    IncreaseDateByXDays(*this,Days);
}

static clsDate IncreaseDateByOneWeek(clsDate& Date)
{
    for(short i=1; i <= 7; i++)
    {
        Date = AddOneDay(Date);
    }
    return Date;

}

void IncreaseDateByOneWeek()
{
    IncreaseDateByOneWeek(*this);
}

static clsDate IncreaseDateByXWeeks(clsDate& Date , short Weeks)
{
    for(short i =1; i <= Weeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }

    return Date;
}

void IncreaseDateByXWeeks(short Weeks)
{
    IncreaseDateByXWeeks(*this,Weeks);
}

static clsDate IncreaseDateByOneMonth(clsDate& Date)
{
    if(Date.Month == 12)
    {
        Date.Year++;
        Date.Month = 1;
    }
    else
    {
      Date.Month++;
    }

    ///last check day in date should not exceed max days in the current month
    /// example if daate is 31/1/2022 increasing one month should not be 31/2/2022
    /// it is should be 28/2/2022
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month,Date.Year);

    if(Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

void IncreaseDateByOneMonth()
{
    IncreaseDateByOneMonth(*this);
}

static clsDate IncreaseDateByXMonths(clsDate& Date, short Months)
{
    for(short i = 1; i <= Months; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;

}

void IncreaseDateByXMonths(short Months)
{
    IncreaseDateByXMonths(*this,Months);
}

static clsDate IncreaseDateByOneYear(clsDate& Date)
{
    Date.Year++;
    return Date;
}

void  IncreaseDateByOneYear()
{
    IncreaseDateByOneYear(*this);
}

static clsDate IncreaseDateByXYears(clsDate& Date, short YearsToAdd)
{
    Date.Year += YearsToAdd;
    return Date;
}

void IncreaseDateByXYears(short Years)
{
    IncreaseDateByXYears(*this,Years);
}

static clsDate IncreaseDateByOneDecade(clsDate& Date)
{
    ///Period of 10 years
    Date.Year += 10;
    return Date;
}

void IncreaseDateByOneDecade()
{
    IncreaseDateByOneDecade(*this);
}

static clsDate IncreaseDateByXDecades(clsDate& Date, short Decade)
{
    Date.Year += Decade * 10;
    return Date;
}

void  IncreaseDateByXDecades(short Decades)
{
    IncreaseDateByXDecades(*this,Decades);
}

static clsDate IncreaseDateByOneCentury(clsDate& Date)
{
    ///Period of 100 years
    Date.Year += 100;
    return Date;
}

void IncreaseDateByOneCentury()
{
    IncreaseDateByOneCentury(*this);
}

static clsDate IncreaseDateByOneMillennium(clsDate& Date)
{
    ///Period of 1000 years
    Date.Year += 1000;
    return Date;
}

void IncreaseDateByOneMillennium()
{
    IncreaseDateByOneMillennium(*this);
}

static bool IsValidDate(clsDate Date)
{
    if(Date.Day < 1 || Date.Day > 31)
        return false;

    if(Date.Month < 1 || Date.Month > 12)
        return false;

    if(Date.Month == 2)
    {
        if(IsLeapYear(Date.Year))
        {
            if(Date.Day > 29)
                return false;
        }
        else
        {
            if(Date.Day > 28)
                return false;
        }
    }

    short DaysInMonth = NumberOfDaysInMonth(Date.Month,Date.Year);

    if(Date.Day > DaysInMonth)
        return false;

        return true;

}

bool IsValid()
{
    return IsValidDate(*this);
}

static string DateToString(clsDate Date)
{
    return (to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year));
}

static clsDate StringToDate(string DateString)
{
    vector<string> vString = clsString::Split(DateString,"/");
    clsDate Date;

    Date.Day   = stoi(vString[0]);
    Date.Month = stoi(vString[1]);
    Date.Year  = stoi(vString[2]);

    return Date;

}

static clsDate GetSystemDate()
{
    clsDate Date;
    time_t T = time(0);
    tm* now = localtime(&T);

    Date.Day = now->tm_mday;
    Date.Month = now->tm_mon +1;
    Date.Year = now->tm_year + 1900;

    return Date;

}


static string  GetSystemDateTimeString()
{
    time_t T = time(0);
    tm* now = localtime(&T);
    string  DateTimeLine ="";

    DateTimeLine += to_string(now->tm_mday) + "/" ;
    DateTimeLine += to_string(now->tm_mon +1)+ "/";
    DateTimeLine += to_string(now->tm_year + 1900) + " - ";
    DateTimeLine += to_string(now->tm_hour) + ":";
    DateTimeLine += to_string(now->tm_min)  + ":";
    DateTimeLine += to_string(now->tm_sec) ;
    return DateTimeLine;

}

static string FormatDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormattedDateString = "";

    FormattedDateString = clsString::ReplaceWord(DateFormat,"dd",to_string(Date.Day));
    FormattedDateString = clsString::ReplaceWord(FormattedDateString,"mm",to_string(Date.Month));
    FormattedDateString = clsString::ReplaceWord(FormattedDateString,"yyyy",to_string(Date.Year));

    return FormattedDateString;
}

string FormatDate(string DateFormat = "dd/mm/yyyy")
{
  ///  return FormatDate(*this,FormatDate);
}

static short GetDiffrenceInDays(clsDate Date1 , clsDate Date2, bool IncludeEndDay = false)
{
    short Days =0;

    while(IsDate1BeforeDate2(Date1,Date2))
    {
         Days++;
      ///   Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days : Days;
}

short GetDiffrenceInDays(clsDate Date2, bool IncludeEndDay = false)
{
    return GetDiffrenceInDays(*this,Date2,IncludeEndDay);
}

static string GetDate(clsDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

string GetDate()
{
    return GetDate(*this);
}


static clsDate GetDateFromDayOredeInYear(short DateOrderInYear, short Year)
{
    clsDate Date;
    short RemaingDays = DateOrderInYear;
    short MonthDays = 0;

    Date.Year = Year;
    Date.Month = 1;

    while(true)
    {
        MonthDays = NumberOfDaysInMonth(Date.Month,Year);

        if(RemaingDays > MonthDays)
        {
            RemaingDays -= MonthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = RemaingDays;
            break;
        }
    }

    return Date;
}

static void SwapDates(clsDate& Date1,clsDate& Date2)
{
    clsDate TempDate;
    TempDate = Date1;
    Date1 = Date2;
    Date2 = TempDate;

}


static bool IsEndOfWeek(clsDate Date)
{
   return DayOfWeekOrder(Date) == 6;
}

bool IsEndOfWeek()
{
    return IsEndOfWeek(*this);
}

static bool IsWeekEnd(clsDate Date)
{
    /// weekends is Fri and Sat
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6);
}

bool IsWeekEnd()
{
    return IsWeekEnd(*this);
}

static bool IsBusinessDay(clsDate Date)
{

 /*short DayIndex = DayOfWeekOrder(Date);
 return (DayIndex >= 1 && DayIndex <= 4);
 */

 /// shorter method is to invert the IsWeekEnd: this will save updating code.
 return !IsWeekEnd(Date);
}

bool IsBusinessDay()
{
    return IsBusinessDay(*this);
}

static short DayUntilEndOfWeek(clsDate Date)
{
    return 6 - DayOfWeekOrder(Date);
}

short DayUntilEndOfWeek()
{
    return DayUntilEndOfWeek(*this);
}

static short DayUntilEndMonth(clsDate Date)
{
 clsDate EndOfMonthDate;
 EndOfMonthDate.Day = NumberOfDaysInMonth(Date.Month,Date.Year);
 EndOfMonthDate.Month = Date.Month;
 EndOfMonthDate.Year = Date.Year;

 return GetDiffrenceInDays(Date,EndOfMonthDate,true);

}

short DayUntilEndMonth()
{
    return DayUntilEndMonth(*this);
}

static short DayUntilEndYear(clsDate Date)
{
 clsDate EndOfYearDate;
 EndOfYearDate.Day = 31;
 EndOfYearDate.Month = 12;
 EndOfYearDate.Year = Date.Year;

 return GetDiffrenceInDays(Date,EndOfYearDate,true);

}

short DayUntilEndYear()
{
    return DayUntilEndYear(*this);
}

static short CalculateVacationDays(clsDate Date1, clsDate Date2)
{
    short DaysCount = 0;
    while(IsDate1BeforeDate2(Date1,Date2))
    {
        if(IsBusinessDay(Date1))
            DaysCount++;

        Date1 = AddOneDay(Date1);
    }

    return DaysCount;

}

static clsDate CalculateVacationReturnDate(clsDate VacationStart , short VacationDays)
{
    short WeekEndCounter =0;

    //in case the date is weekend keep adding one day until you reach business day
    //we get rid of all weekends before the first business day
    while(IsWeekEnd(VacationStart))
    {
        VacationStart = AddOneDay(VacationStart);
    }

    //here we increase the vacation dates to add all weekends to it.

    for(short i =1; i <= VacationDays + WeekEndCounter; i++)
    {
        if(IsWeekEnd(VacationStart))
            WeekEndCounter++;

        VacationStart = AddOneDay(VacationStart);
    }

    //in case the return date is week end keep adding one day until you reach business day
    while(IsWeekEnd(VacationStart))
    {
        VacationStart = AddOneDay(VacationStart);
    }

    return VacationStart;
}

static short ReadVacationDays()
{
    cout << "\nPlease enter Vacation days? ";
    short VacationDays;
    cin >> VacationDays;
    return VacationDays;
}

enum enDateCompare{ Before = -1, Equal = 0, After = 1};

static enDateCompare CompareDates(clsDate Date1 , clsDate Date2)
{
    if(IsDate1BeforeDate2(Date1,Date2))
        return enDateCompare::Before;

    if(IsDate1EqualDate2(Date1,Date2))
        return enDateCompare::Equal;

    return enDateCompare::After;
}

enDateCompare CompareDates(clsDate Date2)
{
    return CompareDates(*this,Date2);
}


};
