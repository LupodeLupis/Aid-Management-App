////////////////////////////////////////////////////////////////////////////////////////
// Final Project Milestone 5
//
// Version 1.0
// Date  12/22/2017
// Author: ALBERTO LAURENZI 
// Milestone  1 - 2 - 3 - 4 - 5 - Completed
// email: 
// ID:
// Description
//
// Declaration and defintion of Class and member function including 
// default Construct and Construct with arguments.
// Declaration and definition of Input and Output stream
// Declaration and definition of Helper as global function
// Test over binary operator and error state (day , month, year)
//	
// Provided private member function in order to optimaze the code
// and avoid repeating the logic.
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//                 24/11/2017           Ok from professor to use Optional Private Function*
///////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////
////////////////////////////////*Milestone5*////////////////////////////
///////////////////////////////////////////////////////////////////////

#include "Date.h"

namespace sict {

	// number of days in month mon_ and year year_
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));

	}

	// Definition private Member Function errCode
	void Date::errCode(int errorCode) {

		error = 0;
	}

	// Definition optional private Member Function isValid ( It optimazes and avoid the repetition of coding)
	// The function set the appropriate error if values are invalid and exit
	void Date::isValid() {

		if (year < min_year || year > max_year)
		{
			setEmpty();
			error = YEAR_ERROR;

		}
		else if (month < 1 || month > 12)
		{
			setEmpty();
			error = MON_ERROR;

		}
		else if (day < 0 || day > mdays(month, year))
		{
			setEmpty();
			error = DAY_ERROR;

		}
		else {

			error = NO_ERROR;

		}
	}

	// Definition optional private Member Function setEmpty
	void Date::setEmpty() {

		day = 0;
		year = 0;
		month = 0;
		comparator = 0;
		error = NO_ERROR;

	}

	// Definition optional query private Member Function calcCompartor
	int Date::calcComparator() const {

		return (year * 372 + month * 13 + day);
	}

	// Definition Default Constructor
	Date::Date() {

		setEmpty();
	}

	// Definition three arguments Constructor
	Date::Date(const int& yearOne, const int& monthOne, const int& dayOne) {

		this->day = dayOne;
		this->month = monthOne;
		this->year = yearOne;
		comparator = calcComparator();
		isValid();

	}
	// Definition operator ==
	bool Date::operator==(const Date& rhs) const {

		return (this->comparator == rhs.comparator) && (this->comparator != 0 && rhs.comparator != 0);

	}
	// Definition operator !=
	bool Date::operator!=(const Date& rhs) const {

		return !(*this == rhs);

	}
	// Definition operator<
	bool Date::operator<(const Date& rhs) const {

		return (this->comparator < rhs.comparator);

	}
	// Definition operator>
	bool Date::operator>(const Date& rhs) const {

		return !(*this < rhs);

	}
	// Definition operator <=
	bool Date::operator<=(const Date& rhs) const {

		return (this->comparator <= rhs.comparator);

	}
	// Definition operator >=
	bool Date::operator>=(const Date& rhs) const {

		return (this->comparator >= rhs.comparator);

	}

	// Definition query function errCode 
	int Date::errCode() const {

		return error;
	}

	// Definition query function bad
	bool Date::bad() const {

		return (error != NO_ERROR);
	}

	// Definition Input Member Function
	std::istream& Date::read(std::istream& istr) {

		char delimiter;

		istr >> year;
		istr >> delimiter;
		if (delimiter != '/' && delimiter != '-') {
			error = CIN_FAILED;
			return istr;
		}

		istr >> month;
		istr >> delimiter;

		if (delimiter != '/' && delimiter != '-') {
			error = CIN_FAILED;
			return istr;
		}

		istr >> day;
		if (istr.fail())

			error = CIN_FAILED;

		else
		{
			isValid();
		}

		comparator = calcComparator();
		return istr;

	}

	// Definition Output Member Function
	std::ostream& Date::write(std::ostream& ostr)const {

		ostr.width(1);
		ostr.fill('0');
		ostr << year << '/';

		ostr.width(2);
		ostr << month << '/';

		ostr.width(2);
		ostr << day;

		return ostr;

	}

	// Declaration Helper global function
	std::ostream& operator<<(std::ostream& ostr, const Date& obj) { return obj.write(ostr); }
	std::istream& operator>>(std::istream& istr, Date& obj) { return obj.read(istr); }

}// sict namespace

/////////////////////////////////////////////////////////////////////////
////////////////////////////*End of Milestone5*/////////////////////////
///////////////////////////////////////////////////////////////////////
