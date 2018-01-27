///////////////////////////////////////////////////////////////////////////////
// Final Project Milestone 4
//
// Version 1.0
// Date 12/18/2017
// Author: ALBERTO LAURENZI
// Milestone 4 - Completed
// email: 
// ID:
// Description
//  
// 
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////////////
////////////////////////////////*Milestone4*////////////////////////////
///////////////////////////////////////////////////////////////////////



#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "NonPerishable.h"

using namespace std;

namespace sict {

	// Member function that return true if the product is taxable.
	bool NonPerishable::isTaxed() const
	{
		return this->prod_tax;
	}

	// Function that allocate memory for the char* pointer and make deep copies
	void NonPerishable::name(const char* name) {

		if (name != nullptr) {
			int size = strlen(name);

			if (prod_name != nullptr) {
				delete[] prod_name;
				prod_name = nullptr;
			}
			prod_name = new char[size + 1];
			strncpy(prod_name, name, size);
			prod_name[size] = '\0';
		}
		else  if (prod_name != nullptr) {
			delete[] prod_name;
			prod_name = nullptr;
		}
	}

	// Member function that returns the name of the product
	const char* NonPerishable::name() const 
	{ 
		return this->prod_name; 
	}

	// Member functin that return that return the price with or without tax
	double NonPerishable::cost() const
	{
		return isTaxed() ? this->prod_price * tax : this->prod_price;
	}

	// Member function that store the error message in the ErrorMessage Object
	void NonPerishable::message(const char* message) 
	{ 
		error.message(message); 
	}

	// Member function that returns the message = nullptr
	bool NonPerishable::isClear() const
	{ 
		return error.isClear();
	}

	// Default construct 
	NonPerishable::NonPerishable() : error()
	{

		prod_type = '\0';
		prod_sku[0] = '\0';
		prod_name = nullptr;
		prod_sku[0] = '\0';
		prod_onHand = 0;
		prod_qtyNeed = 0;
		prod_price = 0.0;
		prod_tax = true;	
	}

	// Constructor with seven parameters
	NonPerishable::NonPerishable(const char* prodSku, const char* prodName, const char * prodUnit, int qtyOnHand,
		bool tax, double prodPriceBtax, int prodQtyNeed) 
	{
		this->prod_name = nullptr;
		if (prodSku != nullptr && prodName != nullptr && prodUnit != nullptr) {

			strcpy(this->prod_sku, prodSku);
			strcpy(this->prod_unit, prodUnit);
			this->prod_onHand = qtyOnHand;
			this->prod_qtyNeed = prodQtyNeed;
			this->prod_price = prodPriceBtax;
			this->prod_tax = tax;
			name(prodName);
		}
	}

	// Copy Costructor method Direct Call with the copy assignment operator
	NonPerishable::NonPerishable(const NonPerishable & obj)
	{
		this->prod_name = nullptr;
		*this = obj; // call the copy assignemt operator
	}

	// Copy Assignment operator
	NonPerishable & NonPerishable::operator=(const NonPerishable & obj)
	{
		if (this != &obj) { // self-check assignment

			// shallow copies
			prod_type = obj.prod_type;
			strcpy(prod_sku, obj.prod_sku);
			strcpy(prod_unit, obj.prod_unit);
			prod_onHand = obj.prod_onHand;
			prod_qtyNeed = obj.prod_qtyNeed;
			prod_price = obj.prod_price;
			prod_tax = obj.prod_tax;
			//Deep copies
			name(obj.prod_name);
		}

		return *this;
	}
	// Decostructor
	NonPerishable::~NonPerishable()
	{
		delete[] prod_name;
		prod_name = nullptr;
	}

	// Member function that write record in the file ms4.txt in two different format
	fstream & NonPerishable::store(fstream & file, bool newLine) const
	{
		file << prod_type << "," << prod_sku << "," << prod_name << "," << prod_unit
			<< "," << prod_onHand << "," << prod_qtyNeed << "," << prod_price;

		if (newLine) {
			file << endl;
		}

		return file;
	}

	// Member function that stores the record in the destination variable of  temporary object and  copies them into the current object
	fstream & NonPerishable::load(fstream & file)
	{
		NonPerishable tempProduct;

		file >> tempProduct.prod_type >> tempProduct.prod_sku >> tempProduct.prod_name >>
			tempProduct.prod_unit >> tempProduct.prod_onHand >> tempProduct.prod_qtyNeed >> tempProduct.prod_price;

		*this = tempProduct;

		return file;
	}

	// Ostream Member function that display the record in two different format dipending on the bool linear
	ostream & NonPerishable::write(ostream & os, bool linear) const
	{
		if (linear) {

			os << setw(max_sku_length) << prod_sku << '|' << setw(20) << prod_name << "|" << setw(7) << prod_price << "|" <<
				setw(4) << prod_onHand << "|" << setw(10) << prod_unit << setw(4) << prod_qtyNeed << endl;
		}
		else
		{
			os << "Sku:" << prod_sku << endl;
			os << "Name:" << name() << endl;
			os << "Price" << this->prod_price << endl;
			os << "Price after tax:";

			if (isTaxed()) {

				os << cost();
			}
			else 
			{
				os << "N/A";
			}
			os << endl;

			os << "Quantity On Hand:" << quantity() << endl;
			os << "Quantity Needed:" << qtyNeeded() << endl;
		}

		return os;
	}

	//Istream Member function that reads the alle records and store error message if the input from the user is incorrect
	std::istream & NonPerishable::read(std::istream & is)
	{
		char character;

		is >> this->prod_sku;
		is >> this->prod_name;
		is >> this->prod_unit;

		is >> character;
		if (character == 'y' || character == 'Y') {

			this->prod_tax = true;
		}
		else if ((character == 'n' || character == 'N')) {

			this->prod_tax = false;
		}
		else
		{
			is.setstate(std::ios::failbit);
			error.message("Only (Y)es or (N)o are acceptable");
		}

		is >> this->prod_price;
		if (is.fail()) {

			error.message("Invalid Price Entry");
		}

		is >> this->prod_onHand;
		if (is.fail()) {

			error.message("Invalid Quantity Entry");
		}
		is >> this->prod_qtyNeed;
		if (is.fail()) {

			error.message("Invalid Quantity Needed Entry");
		}

		return is;
	}

	// Binary Member function that compare the sku string with the string that receive as parameter and return tru if equals
	bool NonPerishable::operator==(const char* rhs) const 
	{
		return (strcmp(prod_sku, rhs) == 0);
	}

	// Member Function that calculate the cost of the products available including or excluding tax
	double NonPerishable::total_cost() const 
	{
		return this->prod_onHand * cost();
	}

	// Member function that reset the products available 
	void NonPerishable::quantity(int qty_prod_onHand) 
	{
		this->prod_onHand = qty_prod_onHand;
	}

	// Member Function that return true if the current object is an empty safe state
	bool NonPerishable::isEmpty() const {

		return  prod_sku[0] == '\0' && prod_name == nullptr &&
			prod_onHand == 0 && prod_qtyNeed == 0 && prod_price == 0;
	}

	// Member function that returns the quantity needed of the product
	int NonPerishable::qtyNeeded() const
	{
		return this->prod_qtyNeed;
	}

	// Member function that returns the quantity needed of the product
	int NonPerishable::quantity() const 
	{
		return this->prod_onHand;
	}

	// Member function that return true if the string's lenght received is longer  than the sku
	bool NonPerishable::operator>(const char* string) const 
	{
		return strcmp(string, this->prod_sku) > 0;
	}
	// Binary Member function that add units to the product already available if the units are > 0
	int NonPerishable::operator+=(int value)
	{
		return (value > 0) ? this->prod_onHand += value : this->prod_onHand;
	}

	// Member function that return true if the string's lenght  received of type Product is longer than the product name
	bool NonPerishable::operator>(const Product& name_obj) const
	{
		return  (strcmp(this->prod_name, name_obj.name()) > 0);
	}

	// Helper Function that store Product record in ostream obj
	std::ostream & operator<<(std::ostream& os, const Product& obj)
	{
		obj.write(os, true);
		return os;
	}
	// Helper Function that read Product records from ostream obj
	std::istream & operator>>(std::istream& is, Product& obj)
	{
		obj.read(is);
		return is;
	}
	// Helper Function that add the total cost of the Product obj to the double received
	double operator+=(double& cost, const Product& prod_)
	{
		cost += prod_.total_cost();
		return cost;
	}
	//// Helper Function that create a NonPerishable object in dynamic memory 
	Product * CreateProduct()
	{
		Product* item = nullptr;
		item = new NonPerishable();
		return item;
	}
} // !SICT_NONPERISHABLE_H

/////////////////////////////////////////////////////////////////////////
////////////////////////////*End of Milestone4*/////////////////////////
///////////////////////////////////////////////////////////////////////
