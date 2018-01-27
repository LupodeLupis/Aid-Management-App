///////////////////////////////////////////////////////////////////////////////
// Final Project Milestone 4
//
// Version 1.0
// Date 12/18/2017
// Author 
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



#ifndef SICT_NONPERISHABLE_H
#define SICT_NONPERISHABLE_H
#include "Product.h"
#include "ErrorMessage.h"

namespace sict {

	const short int max_sku_length = 7;
	const short int max_unit = 10;
	const short int max_name_length = 75;
	const double tax = 1.13;

	class NonPerishable : public Product {

		char prod_type ;  // indicates the type of product  
		char prod_sku[max_sku_length + 1]; // array that holds the product’s sku 
		char* prod_name; // holds the name of the product
		char prod_unit[max_unit + 1]; // array that holds the unit for the product 
		int prod_onHand; // holds the current quantity on hand of the product
		int prod_qtyNeed; // holds the quantity needed of the product
		double prod_price; // holds the price of the product before taxes
		bool prod_tax; // true if the product is taxable
		ErrorMessage error; // hold the error state of the current object
		bool isTaxed() const; 
		

	protected:
		void name(const char* name_prod);
		const char* name() const;
		double cost() const;
		void message(const char* message);
		bool isClear() const;
		

	public:

		NonPerishable();
		NonPerishable(const char* sku_prod, const char* name_prod, const char* unit_prod,
			int qty_onHand = 0, bool tax = true, double price_btax = 0, int qty_prod = 0);
		NonPerishable(const NonPerishable& obj);
		NonPerishable& operator = (const NonPerishable& obj);
		~NonPerishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char* rhs) const;
		double total_cost() const;
		void quantity(int); 
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		int operator+=(int);
		bool operator>(const Product&) const;
		
	};
	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
	Product* CreateProduct();
} 
#endif // !SICT_NONPERISHABLE_H

  /////////////////////////////////////////////////////////////////////////
  ////////////////////////////*End of Milestone4*/////////////////////////
  ///////////////////////////////////////////////////////////////////////
