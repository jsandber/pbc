//
//  current_market.hpp
//  Finding NIMo
//
//  Created by jonathan sandberg on 12/21/15.
//  Copyright © 2015 jonathan sandberg. All rights reserved.
//

#ifndef current_market_hpp
#define current_market_hpp

#include <stdio.h>

// start with statically allocated symbol table and data
// the product model functions in security master can look up the data directly
// since the user supplies all the data the Server has no idea if it scenario or real data.
// Here are the sybols from the FED   http://www.federalreserve.gov/bankinforeg/ccar.htm these are the 2015 cut
// the FED gives them as quarterly data and we need monthly. We will do some interpolation to get this going
// but in general the user does all the interpolation so there is no issue if we are chossing the correct
// interpolation method - we do not choose anything - we just take data from the user.

/*
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

// we are going to trim these names down to the first 31 chars, convert to simple FX ratea as well




class CurrentMarket {
public:

	CurrentMarket();

	// construct/Write the SymbolTable and Data
    int set_SymbolTable(int i, char symbol[32]) { for(int j= 0; j < max_symbols; j++)	SymbolTable[i][j] = symbol[j]; return(0);}

    int set_SymbolData(int i, float d[128]) {for(int j= 0; j < max_data; j++)	SymbolData[i][j] = d[j]; return(0);}

    // Read the valid data parameters, SymbolTable, and SymbolData
    int 	get_number_of_symbols () { 	return(number_of_symbols);}
    int 	get_max_data() { 			return(max_data);}
    int 	get_max_symbols() {			return(max_symbols);}

    char  * get_SymbolTable(int i) { return((char *)&SymbolTable[i][0]);}
    float *	get_SymbolData(int i){ return(&SymbolData[i][0]);}
    
    
private:
    
    int		as_of=31;  // as of date for current market days since 1-Jan-2016?
    int		number_of_symbols = 28; // increment when symbol is in SymbolTable and data is in SymbolData
    int		max_data = 128;
    int		max_symbols = 32;
    int		max_symbol_length = 32;
    char	SymbolTable[32][32];	// zero terminated symbol strings max length 31
    float 	SymbolData[32][128];	// historical and forecasted valaues for each of the symbols in the SymbolTable
};

#endif /* current_market_hpp */




