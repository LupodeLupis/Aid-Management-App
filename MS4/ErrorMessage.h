///////////////////////////////////////////////////////////////////////////////
// Final Project Milestone 4
//
// Version 1.0
// Date 12/18/2017
// Author ALBERTO LAURENZI
// Milestone 4 - Completed
// email: alaurenzi@myseneca.com
// ID:150954162
// Description
//  
// 
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////////////
////////////////////////////////*Milestone4*////////////////////////////
///////////////////////////////////////////////////////////////////////

#ifndef SICT_ERRORMESSAGE_H
#define SICT_ERRORMESSAGE_H
#include <iostream>


namespace sict {

	class ErrorMessage {

		// Data Members
		char* p_message;

	public:

		// Member Function
		explicit ErrorMessage(const char* errorMessage = nullptr);
		ErrorMessage(const ErrorMessage& em) = delete; // copies prohibited
		ErrorMessage& operator=(const ErrorMessage& em) = delete; // copies prohibited
		virtual ~ErrorMessage();
		void clear();
		void message(const char* str);
		bool isClear() const;
		const char* message()const;

	};

	// Helper global function 
	std::ostream& operator<<(std::ostream&, const ErrorMessage&);

}
#endif // !SICT_ERRORMESSAGE_H

/////////////////////////////////////////////////////////////////////////
////////////////////////////*End of Milestone4*/////////////////////////
///////////////////////////////////////////////////////////////////////


