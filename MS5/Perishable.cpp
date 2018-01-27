////////////////////////////////////////////////////////////////////////////////////////
// Final Project Milestone 5
//
// Version 1.0
// Date  12/22/2017
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
// 
/////////////////////////////////////////////////////////////////////////
////////////////////////////////*Milestone5*////////////////////////////
///////////////////////////////////////////////////////////////////////
#include "Perishable.h"

using namespace std;
namespace sict {


	Perishable::Perishable(const char type) : NonPerishable('P')
	{

	

	}


	fstream & Perishable::store(std::fstream & file, bool newLine) const
	{

		NonPerishable::store(file, false);

		file << "," << expire_date;

		if (newLine) {

			file << '\n';
		}

		return file;

	}

	fstream & Perishable::load(std::fstream & file)
	{
		
		NonPerishable::load(file);
		
		expire_date.read(file);
		file.ignore();

		return file;

	}

	ostream & Perishable::write(std::ostream & os, bool linear) const
	{

		NonPerishable::write(os, linear);
		
		if (NonPerishable::isClear() && !NonPerishable::isEmpty()) {


			if (linear) {

				os << this->expire_date;
			}
			else
			{

				os << std::endl << "Expiry date: " << this->expire_date;
			}
		}
			return os;
	}

	istream & Perishable::read(std::istream & is)
	{

		NonPerishable::read(is);

		if (NonPerishable::isClear()) {

			cout << "Expiry date (YYYY/MM/DD): ";

			Date temp_ex_date;
			is >> temp_ex_date;


			if (temp_ex_date.errCode() != 0)
			{

				if (temp_ex_date.errCode() == CIN_FAILED)

					NonPerishable::message("Invalid Date Entry");

				else if (temp_ex_date.errCode() == YEAR_ERROR)

					NonPerishable::message("Invalid Year in Date Entry");

				else if (temp_ex_date.errCode() == MON_ERROR)

					NonPerishable::message("Invalid Month in Date Entry");

				else if (temp_ex_date.errCode() == DAY_ERROR)

					NonPerishable::message("Invalid Day in Date Entry");

				is.setstate(ios::failbit);
			}


			else if (!is.fail())
			{
				this->expire_date = temp_ex_date;
			}

			
		}
		return is;
	}

	const Date & Perishable::expiry() const
	{
		return this->expire_date;
	}

	Product * CreatePerishable()
	{
		Product * product = nullptr;
		product = new Perishable();
		return product;
	}

}


/////////////////////////////////////////////////////////////////////////
////////////////////////////*End of Milestone5*/////////////////////////
///////////////////////////////////////////////////////////////////////
