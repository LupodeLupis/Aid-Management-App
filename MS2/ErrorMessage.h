////////////////////////////////////////////////////////////////////////////////////////
// Final Project Milestone 2
//
// Version 1.0
// Date 28/11/2017
// Author
// Milestone 2 - Completed
// email:
// ID:150954162
// Description
//  - Explicit keyword for memeber function
//  - Virtual Function
//  - Copies prohibited (prevent the client code to copies or 
//	  copies assigning any instance of a class)
//  
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
///////////////////////////////////////////////////////////////////////////////////////

#ifndef SICT_ERRORMESSAGE_H
#define SICT_ERRORMESSAGE_H
#include <iostream>


namespace sict {

	class ErrorMessage {

		// Data Members - Milestone 2 
		char* p_message;

	public:

		// Member Function - Milestone 2
		explicit ErrorMessage(const char* errorMessage = nullptr); 
		ErrorMessage(const ErrorMessage& em) = delete; // copies prohibited
		ErrorMessage& operator=(const ErrorMessage& em) = delete; // copies prohibited
		virtual ~ErrorMessage();
		void clear();
		void message(const char* str);
		bool isClear() const;
	 	const char* message()const;

	};

	// Helper global function  - Milestone 2 
	std::ostream& operator<<(std::ostream&, const ErrorMessage&);

}
#endif // !SICT_ERRORMESSAGE_H

