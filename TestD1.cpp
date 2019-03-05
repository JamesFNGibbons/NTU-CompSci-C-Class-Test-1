// TestD1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

/**
  * This is the counted number of
  * lawn mower models that the company sells.
*/
const int MOWERMODELS = 7;

/** 
  * This function is used to calculate the
  * price that the customer will pay based
  * on the price of the mower that they have
  * purchased.
*/
int CalculateDelivery(int price){
	if(price < 1100){
		return 45;
	}
	if(price > 2500){
		return 0;
	}
	if(price > 1100 && price < 2500){
		return 120;
	}
}

// The data structure for the mowers vector.
struct Mower {
	int num_sold;
	int price;
};

/** 
  * This is used to buld the vector arrays, using
  * the data that has been provided, for use with
  * the given structure.
*/
std::vector<Mower> build_mowers(){

	/**
	  * This array contains the number of lawn
	  * mower sales, and their prices. This data
	  * will be stored in the vector that we are
	  * building.
	*/
	int NumSold[MOWERMODELS] = { 30, 28, 5, 15, 10, 1, 3 };
	double MowerPrice[MOWERMODELS] = { 1089.50, 500.0, 3250.0, 1350.0, 1100.0, 4390.99, 1999.90};

	std::vector<Mower> the_mowers;
	for(int x = 0; x < MOWERMODELS; x++){
		Mower m; 
		m.num_sold = NumSold[x];
		m.price = MowerPrice[x]; 
	
		the_mowers.push_back(m);
	}

	return the_mowers;
}



int main()
{

	// The mowers vector with the structure.
	std::vector<Mower> mowers = build_mowers();

	float totalSales = 0;
	int totalDelivery = 0;

	/**
	  * Loop through the number of lawn mower models,
	  * and calculate the delivery prices.
	*/
	std::cout << "Count	   Total Sales  	   Delivery " << std::endl;
	for(Mower m : mowers){
		float totalSales = m.num_sold * m.price;
		int deliveryCost = CalculateDelivery(m.price) * m.num_sold;

		totalDelivery += deliveryCost;
		totalSales += totalSales;

		std::cout << m.num_sold << "	   " << totalSales << "		   " << deliveryCost << std::endl;
	}

	std::cout << "Total Sales = " << totalSales << "	Total Delivery = " << totalDelivery << std::endl;

	return 0;
}


