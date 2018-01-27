////////////////////////////////////////////////////////////////////////////////////////
// Final Project Milestone 5
//
// Version 1.0
// Date 12/22/2017
// Author ALBERTO LAURENZI
// Milestone  1 - 2 - 3 - 4 - 5 - Completed
// email: 
// ID:
// Description
//  - Virtual pure functions
// 
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////////////
////////////////////////////////*Milestone5*////////////////////////////
///////////////////////////////////////////////////////////////////////


#ifndef SICT_PERISHABLE_H
#define SICT_PERISHABLE_H
#include "NonPerishable.h"
#include "Date.h"

namespace sict {

	
	class Perishable : public NonPerishable {

		Date expire_date;

	public:

		Perishable(const char type = 'P');
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;

	};

	Product* CreatePerishable();

}
#endif // !SICT_PERISHABLE_H


/////////////////////////////////////////////////////////////////////////
////////////////////////////*End of Milestone5*/////////////////////////
///////////////////////////////////////////////////////////////////////


