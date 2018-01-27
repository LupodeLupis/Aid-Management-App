////////////////////////////////////////////////////////////////////////////////////////
// Final Project Milestone 4
//
// Version 1.0
// Date 28/11/2017
// Author ALBERTO LAURENZI
// Milestone 4 - Completed
// email: alaurenzi@myseneca.com
// ID:150954162
// Description
//  - Explicit keyword for memeber function
//  - Virtual Function
//  - Copies prohibited
// 
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////////////
////////////////////////////////*Milestone4*////////////////////////////
///////////////////////////////////////////////////////////////////////


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "ErrorMessage.h"
using namespace std;
using namespace sict;


	// Explicit ErrorMessage function ( do not permit to call the currect object implicitly)
	ErrorMessage::ErrorMessage(const char * errorMessage)
	{
		if (nullptr == errorMessage) {

			this->p_message = nullptr;
		}
		else {

			this->p_message = new char[strlen(errorMessage) + 1];
			strncpy(this->p_message, errorMessage, strlen(errorMessage));
			this->p_message[strlen(errorMessage)] = '\0';
		}
	}

	// Virtual Deconstructor definition 
	ErrorMessage::~ErrorMessage() {

		delete[] this->p_message;
		this->p_message = nullptr;

	}

	// Clear Function defintion
	void ErrorMessage::clear() {

		if (this->p_message != nullptr) {

			delete[] this->p_message;
			this->p_message = nullptr;
		}
	}

	// isClear Function definition
	bool ErrorMessage::isClear() const {

		return (this->p_message == nullptr);

	}

	// message Function definition
	void ErrorMessage::message(const char* str) {

		if (nullptr != str) {

			delete[] this->p_message;

			this->p_message = new char[strlen(str) + 1];

			strncpy(this->p_message, str, strlen(str));
			this->p_message[strlen(str)] = '\0';
		}
	}

	// query message const Function definition
	const char* ErrorMessage::message()const { return this->p_message; }

	// ostream << operator definition
	std::ostream& sict::operator<<(ostream& os, const ErrorMessage& obj) {

		if (!obj.isClear()) {
			os << obj.message();
		}	
		return os;
	}

/////////////////////////////////////////////////////////////////////////
////////////////////////////*End of Milestone2*/////////////////////////
///////////////////////////////////////////////////////////////////////
