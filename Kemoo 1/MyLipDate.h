#pragma once

#include <iostream>
#include <String>
#include <vector>
#include <ctime> 
#include <iomanip>

using namespace std;

namespace MyLipDate
{


	struct stDate
	{
		int Year;
		int Month;
		int Day;
	};

	bool isLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
			Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
				Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}

	short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;
		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
			days[Month - 1];
	}

	bool IsLastDayInMonth(stDate Date)
	{
		return (Date.Day == NumberOfDaysInAMonth(Date.Month,
			Date.Year));
	}

	bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	stDate IncreaseDateByOneDay(stDate& Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Month = 1;
				Date.Day = 1;
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

	void Swap2Dates(stDate& date1, stDate& date2)
	{
		stDate TempDate;
		TempDate.Day = date1.Day;
		TempDate.Month = date1.Month;
		TempDate.Year = date1.Year;

		date1.Day = date2.Day;
		date1.Month = date2.Month;
		date1.Year = date2.Year;

		date2.Day = TempDate.Day;
		date2.Month = TempDate.Month;
		date2.Year = TempDate.Year;

	}

	int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		short swapevidence = 1;
		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			Swap2Dates(Date1, Date2);
			swapevidence = -1;
		}


		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);

		}

		return IncludeEndDay ? ++Days * swapevidence : Days * swapevidence;
	}

	short ReadDay()
	{
		short Day;
		cout << "\nPlease enter a Day? ";
		cin >> Day;
		return Day;
	}

	short ReadMonth()
	{
		short Month;
		cout << "Please enter a Month? ";
		cin >> Month;
		return Month;
	}

	short ReadYear()
	{
		short Year;
		cout << "Please enter a Year? ";
		cin >> Year;
		return Year;
	}

	stDate ReadFullDate()
	{
		stDate Date;
		Date.Day = ReadDay();
		Date.Month = ReadMonth();
		Date.Year = ReadYear();
		return Date;
	}

	stDate GetSystemDate()
	{
		stDate Date;
		time_t t = time(0);
		struct tm now;
		localtime_s(&now, &t);
		Date.Year = now.tm_year + 1900;
		Date.Month = now.tm_mon + 1;
		Date.Day = now.tm_mday;
		return Date;
	}

	short NumberDaysInMonth(short year, short month)
	{
		if (month < 1 || month > 12)
			return 0;
		short ArrMon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return (month == 2) ? (isLeapYear(year) ? 29 : 28) : ArrMon[month - 1];
	}

	void AddingXdays(stDate& date, short X)
	{
		for (int i = 0; i < X; i++)
		{
			IncreaseDateByOneDay(date);
		}

	}

	stDate AddingXdays2(stDate date, short X)
	{
		for (int i = 0; i < X; i++)
		{
			IncreaseDateByOneDay(date);
		}
		return date;

	}

	void AddingOneWeek(stDate& date)
	{
		for (int i = 0; i < 7; i++)
		{
			IncreaseDateByOneDay(date);
		}

	}

	void AddingXweeks(stDate& date, short x)
	{
		for (int i = 0; i < x; i++)
		{
			AddingOneWeek(date);
		}

	}

	void AddingOneMonth(stDate& Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}



		short NumberOfDaysInCurrentMonth = NumberDaysInMonth(Date.Year,
			Date.Month);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}


	}

	void AddingXmonths(stDate& date, short x)
	{
		for (int i = 0; i < x; i++)
		{
			AddingOneMonth(date);
		}

	}

	void AddingOneYear(stDate& date)
	{
		for (int i = 0; i < 12; i++)
		{
			AddingOneMonth(date);
		}

	}

	void AddingXyears(stDate& date, short x)
	{
		for (int i = 0; i < x; i++)
		{
			AddingOneYear(date);
		}

	}

	void AddingXyearsFaster(stDate& date, short x)
	{
		date.Year += x;

	}

	void AddingOneDecade(stDate& date)
	{
		date.Year += 10;

	}

	void AddingXdecades(stDate& date, short x)
	{
		for (int i = 0; i < x; i++)
		{
			AddingOneDecade(date);
		}

	}

	void AddingXdecadesFaster(stDate& date, short x)
	{
		date.Year += (x * 10);
	}

	void AddingOneCentury(stDate& date)
	{

		date.Year += 100;

	}

	void AddingOneMillennium(stDate& date)
	{

		date.Year += 1000;
	}

	void DecreaseDateByOneDay(stDate& date)
	{
		if (date.Day == 1)
		{
			if (date.Month == 1)
			{
				date.Month = 12;
				date.Day = 31;
				date.Year--;
			}
			else
			{
				date.Day = NumberOfDaysInAMonth(date.Month - 1, date.Year);;
				date.Month--;
			}
		}
		else
		{
			date.Day--;
		}

	}

	void DecreaseXdays(stDate& date, short X)
	{
		for (int i = 0; i < X; i++)
		{
			DecreaseDateByOneDay(date);
		}

	}

	void DecreaseOneWeek(stDate& date)
	{
		for (int i = 0; i < 7; i++)
		{
			DecreaseDateByOneDay(date);
		}

	}

	void DecreaseXweeks(stDate& date, short x)
	{
		for (int i = 0; i < x; i++)
		{
			DecreaseOneWeek(date);
		}

	}

	void DecreaseOneMonth(stDate& Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}



		short NumberOfDaysInCurrentMonth = NumberDaysInMonth(Date.Year, Date.Month);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}


	}

	void DecreaseXmonths(stDate& date, short x)
	{
		for (int i = 0; i < x; i++)
		{
			DecreaseOneMonth(date);
		}

	}

	void DecreaseOneYear(stDate& date)
	{
		if (isLeapYear(date.Year))
		{
			if (date.Month == 2 && date.Day == 29)
			{
				date.Day = 28;
			}
		}
		date.Year--;


	}

	void DecreaseXyears(stDate& date, short x)
	{
		for (int i = 0; i < x; i++)
		{
			DecreaseOneYear(date);
		}

	}

	void DecreaseXyearsFaster(stDate& date, short x)
	{
		date.Year -= x;

	}

	void DecreaseOneDecade(stDate& date)
	{
		date.Year -= 10;

	}

	void DecreaseXdecades(stDate& date, short x)
	{
		for (int i = 0; i < x; i++)
		{
			DecreaseOneDecade(date);
		}

	}

	void DecreaseXdecadesFaster(stDate& date, short x)
	{
		date.Year -= (x * 10);
	}

	void DecreaseOneCentury(stDate& date)
	{

		date.Year -= 100;

	}

	void DecreaseOneMillennium(stDate& date)
	{

		date.Year -= 1000;
	}

	short OrderOfDay(short Year, short Month, short Day)
	{
		short a, y, m;
		a = ((14 - Month) / 12);
		y = Year - a;
		m = Month + (12 * a) - 2;
		// Greforian:
		// The value of d is 0 for a Sunday, 1 for a Monday, 2 for a Tuesday etc..
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short OrderOfDay(stDate date)
	{
		short a, y, m;
		a = ((14 - date.Month) / 12);
		y = date.Year - a;
		m = date.Month + (12 * a) - 2;
		// Greforian:
		// The value of d is 0 for a Sunday, 1 for a Monday, 2 for a Tuesday etc..
		return (date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	void PrintDate(stDate date)
	{
		cout << date.Day << " / " << date.Month << " / " << date.Year << endl;
	}

	enum DaysInWeek { sun = 0, mon, tue, wed, thur, fri, sat };

	void PrintDay(stDate date)
	{
		switch (OrderOfDay(date))
		{
		case sun: cout << "Sunday";                break;
		case mon: cout << "Monday";                break;
		case tue: cout << "Tueday";                break;
		case wed: cout << "Wednsday";              break;
		case thur:cout << "Thursday";              break;
		case fri: cout << "Friday";                break;
		case sat: cout << "Saturday";              break;
		default:  cout << "Error in define day.\n";  break;
		}
	}

	bool IsItTheEndOfWeek(stDate date)
	{
		return (OrderOfDay(date) == fri) ? true : false;
	}

	bool IsItTheWeekend(stDate date)
	{
		return (OrderOfDay(date) == 6 || OrderOfDay(date) == 0) ? true : false;
	}

	bool IsItBusinessDay(stDate date)
	{
		return !IsItTheWeekend(date);
	}

	short DaysUntilTheEndOfWeek(stDate date)
	{

		return 6 - (OrderOfDay(date));
	}

	short DaysUntilTheEndOfMonth(stDate date)
	{
		return ((NumberOfDaysInAMonth(date.Month, date.Year)) - (date.Day));
	}

	short DaysUntilTheEndOfYear(stDate date)
	{
		short days = 0;
		days += DaysUntilTheEndOfMonth(date);
		date.Month++;
		date.Day = 1;

		while (date.Month <= 12)
		{
			days += NumberOfDaysInAMonth(date.Month, date.Year);
			date.Month++;

		}
		return days;
	}

	bool Equal2Dates(stDate date1, stDate date2)
	{
		return (date1.Year == date2.Year) ? (date1.Month == date2.Month) ? (date1.Day == date2.Day) : false : false;
	}

	bool IsDate1AfterDate2(stDate date1, stDate date2)
	{
		return (!IsDate1BeforeDate2(date1, date2) && (!Equal2Dates(date1, date2)));
	}

	enum enCompareDates { before = -1, Equal = 0, after = 1 };

	enCompareDates Compare2Dates(stDate date1, stDate date2)
	{
		if (IsDate1BeforeDate2(date1, date2))
		{
			return before;
		}
		else if (Equal2Dates(date1, date2))
		{
			return Equal;
		}
		else
		{
			return after;
		}
	}

	struct stPeriod
	{
		stDate StartDate;
		stDate EndDate;
	};

	stPeriod ReadPeriod()
	{
		stPeriod Period;

		cout << "\nEnter Start Date:\n";
		Period.StartDate = ReadFullDate();

		cout << "\nEnter End Date:\n";
		Period.EndDate = ReadFullDate();

		return Period;
	}

	bool IsOverlap(stPeriod period1, stPeriod period2)
	{
		if ((Compare2Dates(period1.EndDate, period2.StartDate) == before) || (Compare2Dates(period1.StartDate, period2.EndDate) == after))
		{
			return false;
		}
		return true;

	}

	bool IsOverlapDateInPeriod(stPeriod period , stDate date)
	{
		if ((Compare2Dates(period.EndDate, date) == before) || (Compare2Dates(period.StartDate,date) == after))
		{
			return false;
		}
		return true;

	}

	short PeriodLength(stPeriod period, bool includeEnd = false)
	{
		return GetDifferenceInDays(period.StartDate, period.EndDate, includeEnd);
	}

	short CountOverLapDays(stPeriod period1, stPeriod period2)
	{
		short period1Length = PeriodLength(period1, true);
		short period2Length = PeriodLength(period2, true);
		short OverlapedDays = 0;

		if (!IsOverlap(period1, period2))
			return 0;

		if (period1Length < period2Length)
		{
			while (IsDate1BeforeDate2(period1.StartDate, period1.EndDate))
			{
				if (IsOverlapDateInPeriod(period2, period1.StartDate))
					OverlapedDays++;
				period1.StartDate = IncreaseDateByOneDay(period1.StartDate);
			}
		}
		else
		{
			while (IsDate1BeforeDate2(period2.StartDate, period2.EndDate))
			{
				if (IsOverlapDateInPeriod(period1, period2.StartDate))
					OverlapedDays++;
				period2.StartDate = IncreaseDateByOneDay(period2.StartDate);
			}
		}
		return OverlapedDays;
	}

	bool ValidateDate(stDate date)
	{
		if (date.Month >= 1 && date.Month <= 12)
		{
			return (date.Day <= NumberOfDaysInAMonth(date.Month, date.Year) && date.Day > 0) ? true : false;

		}
		return false;

	}

	vector <string> SplitString(string text, string separator="/")
	{
		vector <string> vString;
		short pos = 0;
		string temp;

		while ((pos = text.find(separator)) != std::string::npos)
		{
			temp = text.substr(0, pos);
			if (temp != "")
			{
				vString.push_back(temp);
			}
			text.erase(0, pos + separator.length());

		}	 

		if (text != "")
		{

			vString.push_back(text);
		}

		return vString;
	}
	string ReadString(string message)
	{
		string text;
		cout << message << endl;
		getline(cin, text);
		return text;
	}

	stDate ConvertStringToDate(string text, string separator = "/")
	{
		stDate date;
		vector<string> vstring = SplitString(text, separator);

		date.Day = stoi(vstring[0]);
		date.Month = stoi(vstring[1]);
		date.Year = stoi(vstring[2]);
		return date;

	}

	string ConvertDateToString(stDate date, string separator = "/")
	{
		string line = "";
		line += to_string(date.Day) + separator;
		line += to_string(date.Month) + separator;
		line += to_string(date.Year);
		return line;
	}

	string ReplaceWordInString(string text, string ToReplace,
		string RepalceTo)
	{
		short pos = text.find(ToReplace);
		while (pos != std::string::npos)
		{
			text = text.replace(pos, ToReplace.length(),
				RepalceTo);
			pos = text.find(ToReplace);
		}
		return text;
	}

	string FormateDate(stDate Date, string Formate = "dd/mm/yyyy")
	{
		string NewFormate = Formate;
		NewFormate = ReplaceWordInString(NewFormate, "dd", to_string(Date.Day));
		NewFormate = ReplaceWordInString(NewFormate, "mm", to_string(Date.Month));
		NewFormate = ReplaceWordInString(NewFormate, "yyyy", to_string(Date.Year));
		return NewFormate;
	}
}