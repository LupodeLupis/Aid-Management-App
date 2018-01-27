// Final Project Milestone 3 - Product Interface
// Version 2.0
// Date	2017-12-02
// Authors	Fardad Soleimanloo, Chris Szalwinski
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2017-07-11           corrected compile safegaurds
// Chris              2017-12-02           Streamable -> Product
/////////////////////////////////////////////////////////////////
#ifndef SICT_MYPRODUCT_H__
#define SICT_MYPRODUCT_H__
#include "Product.h"
#include "Product.h"
#include "Product.h" // Product.h is included three times on purpose.

namespace sict {
  class MyProduct : public Product {
    char text_[10000];
	const char* sku = "sku";
	char name_[20];
	int value = 0;
  public:
    MyProduct(const char* name);
    std::fstream& store(std::fstream& file, bool addNewLine)const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear)const;
    std::istream& read(std::istream& is);
	bool operator==(const char*) const;
	double total_cost() const;
	const char* name() const;
	void quantity(int);
	int qtyNeeded() const;
	int quantity() const;
	int operator+=(int);
	bool operator>(const Product&) const;
  };
}
#endif