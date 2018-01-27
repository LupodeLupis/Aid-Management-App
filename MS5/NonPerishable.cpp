///////////////////////////////////////////////////////////////////////////////
// Final Project Milestone 5
//
// Version 1.0
// Date  12/22/2017
// Author ALBERTO LAURENZI
// Milestone  1 - 2 - 3 - 4 - 5 - Completed
// email: alaurenzi@myseneca.com
// ID:150954162
// Description
//  
// 
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Alberto Laurenzi  22/12/2017        implementation Load/Write/function
/////////////////////////////////////////////////////////////////////////
////////////////////////////////*Milestone4*////////////////////////////
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include "NonPerishable.h"


using namespace std;

namespace sict {

	// Function that allocate memory for the char* pointer and make deep copies
	void NonPerishable::name(const char* name) {

		if (name != nullptr)
		{
			if (this->prod_name != nullptr)
			{
				delete[] this->prod_name;
				this->prod_name = nullptr;

			}

			int size = strlen(name);
			prod_name = new char[size + 1];
			strncpy(prod_name, name, size);
			prod_name[size] = '\0';
		}
		else {
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
		return  prod_tax ? this->prod_price * tax : this->prod_price;
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
	NonPerishable::NonPerishable(char type)
	{
		prod_sku[0] = '\0';
		prod_name = nullptr;
		prod_unit[0] = '\0';
		prod_onHand = 0;
		prod_qtyNeed = 0;
		prod_price = 0.0;
		prod_tax = true;
		prod_type = type;
		error.clear();

	}

	// Constructor with seven parameters
	NonPerishable::NonPerishable(const char* prodSku, const char* prodName, const char * prodUnit, int qtyOnHand,
		bool tax, double prodPriceBtax, int prodQtyNeed)
	{

		if (prodSku != nullptr && prodName != nullptr && prodUnit != nullptr && qtyOnHand
			!= 0 && prodPriceBtax != 0 && prodQtyNeed != 0)
		{

			strcpy(this->prod_sku, prodSku);
			strcpy(this->prod_unit, prodUnit);
			this->prod_onHand = qtyOnHand;
			this->prod_qtyNeed = prodQtyNeed;
			this->prod_price = prodPriceBtax;
			this->prod_tax = tax;
			name(prodName);
		}

		else {

			*this = NonPerishable();
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
		file << prod_type << "," << prod_sku << "," << prod_name << "," << prod_price << "," << prod_tax
			<< "," << prod_onHand << "," << prod_unit << "," << prod_qtyNeed;

		if (newLine) {
			file << endl;
		}

		return file;
	}

	// Member function that stores the record in the destination variable of  temporary object and  copies them into the current object
	fstream & NonPerishable::load(fstream & file)
	{
		//NonPerishable tempProduct;


		string temp_prod_sku;
		string temp_prod_name;
		string temp_prod_unit;
		bool temp_prod_tax;
		double temp_prod_price;
		int temp_prod_onHand;
		int temp_prod_qytNeed;


		if (file) {
			char c;
			getline(file, temp_prod_sku, ',');
			getline(file, temp_prod_name, ',');
			file >> temp_prod_price;
			file >> c;
			file >> temp_prod_tax;
			file >> c;
			file >> temp_prod_onHand;
			file >> c;
			getline(file, temp_prod_unit, ',');
			file >> temp_prod_qytNeed;
			file >> c;

			if (!file.fail())
			{
				strcpy(prod_sku, temp_prod_sku.c_str());
				name(temp_prod_name.c_str());
				strcpy(this->prod_unit, temp_prod_unit.c_str());
				this->prod_price = temp_prod_price;
				this->prod_onHand = temp_prod_onHand;
				this->prod_qtyNeed = temp_prod_qytNeed;
				this->prod_tax = temp_prod_tax;
			}
			
		}
		return file;
	}

	// Ostream Member function that display the record in two different format dipending on the bool linear
	ostream & NonPerishable::write(ostream & os, bool linear) const
	{

		if (error.isClear())
		{


			if (linear) {

				os.setf(ios::fixed);
				os.precision(2);
				os.fill(' ');
				os << left;
				os << setw(max_sku_length);
				os << prod_sku;
				os << '|';
				os << left;
				os << setw(20);
				os << prod_name;
				os << right;
				os << "|";
				os << setw(7);
				os << cost();
				os << right;
				os << "|";
				os << setw(4);
				os << quantity();
				os << left;
				os << "|";
				os << setw(10);
				os << prod_unit;
				os << right;
				os << "|";
				os << setw(4);
				os << prod_qtyNeed;
				os << "|";
			}
			else
			{
				os << "Sku: " << prod_sku << endl;
				os << "Name: " << name() << endl;
				os << "Price: " << this->prod_price << endl;
				os << "Price after tax: ";

				if (this->prod_tax) {

					os << total_cost();
				}
				else
				{
					os << "N/A";
				}
				os << endl;

				os << "Quantity On Hand: " << quantity() << " " << this->prod_unit <<  endl;
				os << "Quantity Needed: " << qtyNeeded();
			}
		}
		else
		{
			os << error.message();
		}

		return os;
	}

	//Istream Member function that reads the alle records and store error message if the input from the user is incorrect
	std::istream & NonPerishable::read(std::istream & is)
	{



		char temp_prod_sku[max_sku_length + 1];
		char temp_prod_name[max_name_length];
		char temp_prod_unit[max_unit + 1];
		char temp_prod_tax;
		double temp_prod_price;
		int temp_prod_onHand;
		int temp_prod_qytNeed;


		cout << " Sku: ";
		is >> temp_prod_sku;

		if (!is.fail()) {

			strcpy(prod_sku, temp_prod_sku);
		}


		cout << " Name: ";
		is >> temp_prod_name;

		if (!is.fail()) {

			name(temp_prod_name);
		}

		cout << " Unit: ";
		is >> temp_prod_unit;

		if (!is.fail()) {

			strcpy(prod_unit, temp_prod_unit);
		}

		cout << " Taxed? (y/n): ";
		is >> temp_prod_tax;

		if (!is.fail())
		{
			if (temp_prod_tax == 'N' || temp_prod_tax == 'n') {


				prod_tax = false;

			}

			else if (temp_prod_tax == 'Y' || temp_prod_tax == 'y')

			{

				prod_tax = true;

			}
			else

			{
				error.message("Only (Y)es or (N)o are acceptable");
				is.setstate(ios::failbit);

			}
		}


		if (!is.fail()) {
			cout << " Price: ";
			is >> temp_prod_price;
			prod_price = temp_prod_price;
			if (is.fail()) {

				error.message("Invalid Price Entry");
			}
		}


		if (!is.fail()) {
			cout << "Quantity On hand: ";
			is >> temp_prod_onHand;
			prod_onHand = temp_prod_onHand;
			if (is.fail()) {

				error.message("Invalid Quantity Entry");
			}

		}


		if (!is.fail()) {
			cout << "Quantity Needed: ";
			is >> temp_prod_qytNeed;
			prod_qtyNeed = temp_prod_qytNeed;

			if (is.fail()) {

				error.message("Invalid Quantity Needed Entry");
			}

		}

		if (!is.fail()) {

			error.clear();
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
