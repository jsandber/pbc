//
//  accrual_portfolio.cpp
//  Finding NIMo
//
//  Created by jonathan sandberg on 12/21/15.
//  Copyright © 2015 jonathan sandberg. All rights reserved.
//

#include "../src/accrual_portfolio.hpp"
#include <math.h>
#include <stdlib.h>




AccrualPortfolio::AccrualPortfolio() {
    
	number_of_positions = 0;

    return;
}

AccrualPortfolio::~AccrualPortfolio() {
    
    return;
}

int AccrualPortfolio::set_accrual_portfolio(
		long i,
		long posn_id,
		long as_of,
		long acct_id,
		long sec_id,
		double usd_face_amount,
		double rate,
		int currency) {

	if( i < 0 or i > max_positions) return(-1);
	if( sec_id < 0 or sec_id > 4)	return(-1);
	if( currency != 0) return(-1);

	p[i].posn_id = posn_id;
	p[i].as_of = as_of;
	p[i].acct_id = acct_id;
	p[i].sec_id = sec_id;
	p[i].usd_face_amount = usd_face_amount;
	p[i].rate = rate;
	number_of_positions = i+1;
	return(0);
}


int AccrualPortfolio::get_balance_sheet(float * balance, float * rate) {

	// initialize the balance sheet for the given as_of data parameterized as a balance vector and a rate vector

	// get the max number of securities from SecurityMaster parse of the user entered AccrualPortfolio
	int max_sec = 4;

	if(number_of_positions > max_sec) return(-1);
	// determine the balance and rate from the user entered AccrualPortfolio
	// assume to start up the positions come in sequentially in the AccrualPortfolio
	for (int i = 0; i < number_of_positions; i++) {
		balance[i] = p[i].usd_face_amount;
		rate[i] = p[i].rate;
	}

	// return the balance sheet to the caller in vectors balance and rate
	return(0);
}

