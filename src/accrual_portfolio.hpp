//
//  accrual_portfolio.hpp
//  Finding NIMo
//
//  Created by jonathan sandberg on 12/21/15.
//  Copyright © 2015 jonathan sandberg. All rights reserved.
//

#ifndef accrual_portfolio_hpp
#define accrual_portfolio_hpp

#include <stdio.h>


struct Position  {
    long posn_id;   // key - anything the user wants
    long as_of;     // key - constraint is it must be the number of days since 1-Jan-2016
    long acct_id;   // portfolio of securities for each account - anything the user wants
    long sec_id;	// must be one of the current securities with a product model even if the user is overriding
    				// the NIMo product model. THe zero product is the  user override.
    double usd_face_amount; // notional face amount in USD at COB on as_of date
    double rate; // return rate in percentage on COB as_of date
    int currency=0;	// local currency to start always USD so currency = 0
   };

class AccrualPortfolio {
public:
    AccrualPortfolio(); // dynamically allocate the portfolio size based on the user input
    //statically allocated to start

    ~AccrualPortfolio(); // free up the allocated memory for the  accrual portfolio
    
    double * getAccrualPorfolio();
    int set_accrual_portfolio(long, long , long, long, long, double, double, int);
    int get_balance_sheet(float *, float *);
    
private:

    // maps security portfolios to balance sheet accounts
    // and simulated portfolios to account in balance sheet simulations
    int					number_of_positions;
    int					max_positions = 128;
    struct 	Position  	p[128];
    
    
};

#endif /* accrual_portfolio_hpp */
