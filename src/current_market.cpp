//
//  current_market.cpp
//  Finding NIMo
//
//  Created by jonathan sandberg on 12/21/15.
//  Copyright © 2015 jonathan sandberg. All rights reserved.
//

#include "../src/current_market.hpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>


using namespace std;

CurrentMarket::CurrentMarket() {

    	/* init the Symbols
    	1	Real GDP growth
    	2	Nominal GDP growth
    	3	Real disposable income growth
    	4	Nominal disposable income growth
    	5	Unemployment rate
    	6	CPI inflation rate
    	7	3-month Treasury rate
    	8	5-year Treasury yield
    	9	10-year Treasury yield
    	10	BBB corporate yield
    	11	Mortgage rate
    	12	Prime rate
    	13	Dow Jones Total Stock Market Index
    	14	House Price Index
    	15	Commercial Real Estate Price Index
    	16	Market Volatility Index (VIX)
    	17	Euro Area Real GDP Growth
    	18	Euro Area Inflation
    	19	Euro Area Bilateral Dollar Exchange Rate  (USD/Euro)
    	20	Developing Asia Real GDP Growth
    	21	Developing Asia Inflation
    	22	Developing Asia Bilateral Dollar Exchange Rate (F/USD, Index, Base = 2000 Q1)
    	23	Japan Real GDP Growth
    	24	Japan Inflation
    	25	Japan Bilateral Dollar Exchange Rate (Yen/USD)
    	26	UK Real GDP Growth
    	27	UK Inflation
    	28	UK Bilateral Dollar Exchange Rate (USD/Pound)
    	*/
    	strcpy(SymbolTable[0], "Real GDP growth");
    	strcpy(SymbolTable[1], "Nominal GDP growth");
    	strcpy(SymbolTable[2], "Real disposable income growth");
    	strcpy(SymbolTable[3], "Nominal disposable income growth");
    	strcpy(SymbolTable[4], "Unemployment rate");
    	strcpy(SymbolTable[5], "CPI inflation rate");
    	strcpy(SymbolTable[6], "3-month Treasury rate");
    	strcpy(SymbolTable[7], "5-year Treasury yield");
    	strcpy(SymbolTable[8], "10-year Treasury yield");
    	strcpy(SymbolTable[9], "BBB corporate yield");
    	strcpy(SymbolTable[10], "Mortgage rate");
    	strcpy(SymbolTable[11], "Prime rate");
    	strcpy(SymbolTable[12], "Dow Jones Total Stock Market Index");
    	strcpy(SymbolTable[13], "House Price Index");
    	strcpy(SymbolTable[14], "Commercial Real Estate Price Index");
    	strcpy(SymbolTable[15], "Market Volatility Index (VIX)");
    	strcpy(SymbolTable[16], "Euro Area Real GDP Growth");
    	strcpy(SymbolTable[17], "Euro Area Inflation");
    	strcpy(SymbolTable[18], "USD/Euro");
    	strcpy(SymbolTable[19], "Developing Asia Real GDP Growth");
    	strcpy(SymbolTable[20], "Developing Asia Inflation");
    	strcpy(SymbolTable[21], "F/USD");
    	strcpy(SymbolTable[22], "Japan Real GDP Growth");
    	strcpy(SymbolTable[23], "Japan Inflation");
    	strcpy(SymbolTable[24], "Real GDP growth");
    	strcpy(SymbolTable[25], "Yen/USD");
    	strcpy(SymbolTable[26], "UK Real GDP Growth");
    	strcpy(SymbolTable[27], "UK Inflation");
    	strcpy(SymbolTable[28], "USD/Pound");
    	strcpy(SymbolTable[29], "Test 1");
    	strcpy(SymbolTable[30], "Test 2");
    	strcpy(SymbolTable[31], "Test 3");

    	// init the data with constants for now - Go get the FED data later - this is ok for benchmarking
    	for( int i = 0; i < this->max_symbols; i++)
    		for(int j=0; j < this->max_data; j++)	SymbolData[i][j] = 1.00001;
    	return;
    }


