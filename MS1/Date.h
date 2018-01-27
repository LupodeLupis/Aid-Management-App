////////////////////////////////////////////////////////////////////////////////////////
// Final Project Milestone 1
//
// Version 1.0
// Date 30/10/2017
// Author ALBERTO LAURENZI
// Milestone 1 - Completed
// email: alaurenzi@myseneca.com
// ID:150954162
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
// Alberto Laurenzi   24/11/2017           Ok from professor to use Optional Private Function*
///////////////////////////////////////////////////////////////////////////////////////



#ifndef SICT_DATE_H
#define SICT_DATE_H

#include <iostream>
	
	#define NO_ERROR 0
	#define CIN_FAILED 1  
	#define YEAR_ERROR 2
	#define MON_ERROR  3 
	#define DAY_ERROR  4 

namespace sict {

	const int min_year = 2000;
	const int max_year = 2030;

  class Date {

	  // Data Members - Milestone 1 
	  int day;
	  int year;
	  int month;
	  int comparator;
	  int error;

	  // Member Function - Milestone 1
      int mdays(int mon, int year)const;
	  void errCode(int errorCode);

	  // *Optional Private Member Function  - Milestone 1 (Check with the Prof. OK - Check Revison History)
	  void isValid();
	  void setEmpty();
	  int calcComparator() const;
	 
  public:

	  // Constructors - Milestone 1 
	  Date();
	  Date(const int& yearOne, const int& monthOne, const int& dayOne);

	  // Operators overloaded - Milestone 1
	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;

	  // Queries and Mutator Public Member function - Milestone 1
	  int errCode() const;
	  bool bad() const;
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr) const;


  };

  // Helper global function  - Milestone 1 
  std::ostream&	operator<<(std::ostream& ostr, const Date& obj);
  std::istream& operator>>(std::istream& istr, Date& obj);
}
#endif