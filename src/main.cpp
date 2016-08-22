
//
//  main.cpp
//  Finding NIMo
//
//  Created by jonathan sandberg on 12/21/15.
//  Copyright © 2015 jonathan sandberg. All rights reserved.
//
//
//•	Select the as of date
//•	Set the simulation horizon to 60 monthly periods from the as of date. (default)
//•	Get 60 forward monthly 10Y swap rates and CPI levels for user selected market/scenario.
//•	Get max sec_id – determine the number of different securities in the accrual portfolio – allocate memory.
//•	Get max acct_id – determine the size of the balance sheet.
//•	Get the mapping of securities to accounts in the accrual portfolio.
//•	Set SecurityModelMaster( scenario_id, as-of_date)  so we fit regressions to the historical product data to obtain regression coefficients.
//•	Simulate securities id’d in step 2 forward 60 months from the as of date according to the scenario/market selected in step 1.
//•	Assign abd aggregate in the balance sheet per the accrual portfolio mapping selected in step 4.
//•	Return the simulated Balance sheet.

#include "../src/main.hpp"

#include <iostream>
#include <string>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include "../src/balance_sheet.hpp"
#include "../src/nimo_configuration.hpp"
#include "../src/security_master.hpp"
#include "../src/current_market.hpp"
#include "../src/accrual_portfolio.hpp"

#define MAX_HORIZON_MONTHS (128)

using namespace std;


int hold_flat(int max_acct, int max_periods, float *b ,float *r, BalanceSheet *bs) {
    
    // initialize the balance sheet for the as_of date
    // populate balance and rate
    for (int i = 0; i < max_acct; i++) {
        b[i] = 200 + rand() * 0.1;
        r[i] = 0.4 + rand() * 0.1;
    }
    
    // set up timing loop
    struct timeval tS, tS2; struct timezone tZ;
    tS.tv_sec = 0;
    tS.tv_usec = 0;
    gettimeofday(&tS, &tZ);
    
    // simulate hold flat balance sheet simulation
    bs->simulate_hold_flat(max_acct, max_periods, b, r);
    
    //sleep(1);
    
    //terminate timing loop
    gettimeofday(&tS2, &tZ);
    
    //verify hold flat
    
    //report timing results for hold flat balance sheet simulation
    cout << "Time taken is: " << tS2.tv_sec - tS.tv_sec << " " << tS2.tv_usec - tS.tv_usec << endl;
    
    return(0);
    
}

int full_balance_sheet_simulation(int max_acct, int max_periods, float *b ,float *r, BalanceSheet *bs) {
    
    
    float coeff[MAX_HORIZON_MONTHS];
    float mkt[MAX_HORIZON_MONTHS];
    float c[MAX_HORIZON_MONTHS];
    
    if(max_periods > MAX_HORIZON_MONTHS) return(1);
    
    // initialize the balance sheet for the as_of date
    // populate balance and rate
    for (int i = 0; i < max_acct; i++) {
        b[i] = 200 + rand() * 0.1;
        r[i] = 0.4 + rand() * 0.1;
    }
    
    for (int i = 0; i < max_periods; i++) {
        coeff[i] = 200 + rand() * 0.1;
        mkt[i] = 0.4 + rand() * 0.1;
        c[i] = 2.0 + rand()* 0.3;
    }
    
    // set up timing loop
    struct timeval tS, tS2; struct timezone tZ;
    tS.tv_sec = 0;
    tS.tv_usec = 0;
    gettimeofday(&tS, &tZ);
    
    // simulate hold flat balance sheet simulation
    bs->full_regression_model_simulation(max_acct, max_periods, b, r, coeff, mkt, c);
    
    // sleep(1);
    
    //terminate timing loop
    gettimeofday(&tS2, &tZ);
    
    //verify
     
    //report timing results for hold flat balance sheet simulation
    cout << "Time taken is: " << tS2.tv_sec - tS.tv_sec << " " << tS2.tv_usec - tS.tv_usec << endl;
    
    return(0);
    
}

int full_accrual_security_master_simulation(int max_sec, int max_periods, float *b ,float *r, AccrualSecurityMaster *s) {


    // max_acct = max_sec for this bemnchmark
    
    float mkt1[MAX_HORIZON_MONTHS];
    float mkt2[MAX_HORIZON_MONTHS];
    float mkt3[MAX_HORIZON_MONTHS];
    
    if(max_periods > MAX_HORIZON_MONTHS) return(1);
    
    // initialize the balance sheet for the as_of date
    // populate balance and rate
    for (int i = 0; i < max_sec; i++) {
        b[i] = 200 + rand() * 0.1;
        r[i] = 0.4 + rand() * 0.1;
    }
    
    for (int i = 0; i < max_periods; i++) {
        mkt1[i] = 6.0 + rand() * 0.1;
        mkt2[i] = 0.4 + rand() * 0.1;
        mkt3[i] = 2.0 + rand()* 0.3;
    }
    
    // set up timing loop
    struct timeval tS, tS2; struct timezone tZ;
    tS.tv_sec = 0;
    tS.tv_usec = 0;
    gettimeofday(&tS, &tZ);
    
    // simulate all the contracts in the security master table for a fixed set of randomly set market varliabbles
    s->full_regression_model_simulation(max_sec, max_periods, b, r, mkt1); // placeholder
    
    //sleep(1);
    
    //terminate timing loop
    gettimeofday(&tS2, &tZ);
    
    //verify
    
    //report timing results for hold flat balance sheet simulation
    cout << "Time taken is: " << tS2.tv_sec - tS.tv_sec << " " << tS2.tv_usec - tS.tv_usec << endl;
    
 
    return(0);
}

int full_accrual_2_security_master_simulation(int max_sec, int max_periods, float *b ,float *r, AccrualSecurityMaster *s, CurrentMarket *cm) {
    
    // max_acct = max_sec for this bemnchmark
    
    float mkt1[MAX_HORIZON_MONTHS];
    float mkt2[MAX_HORIZON_MONTHS];
    float mkt3[MAX_HORIZON_MONTHS];
    
    if(max_periods > MAX_HORIZON_MONTHS) return(1);
    
    // initialize the balance sheet for the as_of date
    // populate balance and rate
    for (int i = 0; i < max_sec; i++) {
        b[i] = 200 + rand() * 0.1;
        r[i] = 0.4 + rand() * 0.1;
    }
    
    for (int i = 0; i < max_periods; i++) {
        mkt1[i] = (float)(cm->get_SymbolData(1))[i];
        mkt2[i] = (float)(cm->get_SymbolData(2))[i];
        mkt3[i] = (float)(cm->get_SymbolData(3))[i];
    }
    
    // set up timing loop
    struct timeval tS, tS2; struct timezone tZ;
    tS.tv_sec = 0;
    tS.tv_usec = 0;
    gettimeofday(&tS, &tZ);
    
    // simulate all the contracts in the security master table for a fixed set of randomly set market varliabbles
    s->simulate_security_master(max_sec, max_periods, b, r, mkt1);
    
    //sleep(1);
    
    //terminate timing loop
    gettimeofday(&tS2, &tZ);
    
    //verify
    
    //report timing results for hold flat balance sheet simulation
    cout << "Time taken is: " << tS2.tv_sec - tS.tv_sec << " " << tS2.tv_usec - tS.tv_usec << endl;
    return(0);
}



int full_accrual_2_balance_sheet_simulation(int max_sec, int max_periods, float * balance, float * rate,
		AccrualPortfolio * p,
		BalanceSheet * bs,
		AccrualSecurityMaster * s,
		CurrentMarket * cm) {

    // max_acct = max_sec for this benchmark
    // make an accrual portfolio and send it to class accrual portfolio
	// time in aggregate the following benchmark steps
	// time - build a list of securities to be statically simulated in security master
	// time statically simulate those securities - in security master
	// time build the fully simulated balance sheet from the accrual portfolio (above) and the simulated securities
	// time function - build simulated balance sheet given accrual portfolio  and simualtion in security master
	// time return the fully simulated balance sheet.

    float mkt1[MAX_HORIZON_MONTHS]; // kill these at some point and just have the models access the current market directly
    float mkt2[MAX_HORIZON_MONTHS];
    float mkt3[MAX_HORIZON_MONTHS];
    // use the memory allocated in main() for now
    // we would like to switch to Accrual portfolio Allocated memory eventually
    // so we do not have memory off the stack dependency - save as later optimization
    if(max_periods > MAX_HORIZON_MONTHS) return(-1);

    // here is a portfolio of each of the three positions currently modeled
    // sec_id = 0 is the test security
    p->set_accrual_portfolio (0,1,31,1,1,100.0, 0.033,0);
    p->set_accrual_portfolio (1,1,31,1,2,100.0, 0.023,0);
    p->set_accrual_portfolio (2,1,31,1,3,100.0, 0.011,0);


    // initialize the balance sheet for the as_of date
    // populate balance and rate from the accrual portfolio - we want a class function based on the user supplied
    // accrual portfolio to compute the initial balance and rate of return
    p->get_balance_sheet(balance, rate);


    for (int i = 0; i < max_periods; i++) {
        mkt1[i] = (float)(cm->get_SymbolData(1))[i];
        mkt2[i] = (float)(cm->get_SymbolData(2))[i];
        mkt3[i] = (float)(cm->get_SymbolData(3))[i];
    }


    // set up timing loop
    struct timeval tS, tS2; struct timezone tZ;
    tS.tv_sec = 0;
    tS.tv_usec = 0;
    gettimeofday(&tS, &tZ);

	// time - build a list of securities to be statically simulated in security master
	s->p2s_list(p); //to start we are going to simulate all the products so this just initializes current balance sheet

    // time statically simulate those securities - in security master
    // simulate all the contracts in the security master table for a fixed set of randomly set market variables
    s->simulate_security_master(max_sec, max_periods, balance, rate, mkt1); // use the old function to get started

    // time building the fully simulated balance sheet from the accrual portfolio (above) and the simulated securities
    bs->build_ssnp2bs(s, p);

	// time return the fully simulated balance sheet.

    sleep(1);

    //terminate timing loop
    gettimeofday(&tS2, &tZ);

    //verify

    //report timing results for hold flat balance sheet simulation
    cout << "Time taken is: " << tS2.tv_sec - tS.tv_sec << " " << tS2.tv_usec - tS.tv_usec << endl;
    return(0);
}

int main(int argc, char * argv[]) {
    
    int test = 1; // select the benchmark test
    Nimo nimo;
    //set the size of the balance sheet and security master
    nimo.set_max_acct_id(8*1024);
    nimo.set_max_horizon_months(64);
    
    int max_acct = nimo.get_max_acct_id();
    int max_periods = nimo.get_max_horizon_months();
    int max_sec  = max_acct;
    
    float balance[max_acct];
    float rate[max_acct];
    
    cout << nimo.get_Nimo();
    nimo.print_Nimo();
    std::cout << "test = " << test << "\n";

    
    AccrualPortfolio p;
    CurrentMarket cm;
    BalanceSheet bs(max_acct, max_periods); // allocate a balance sheet for benchmarking
    AccrualSecurityMaster s(max_sec, max_periods);   // allocate a security master per product for benchmarking
    
    switch(test) {
        case 1:
            // Performance Benchmark: hold flat USD balance sheet simulation 5Y - just balance and rate models for baseline
  
            // DK the market or the accrual portfolio - it is all hold flat so does not matter.
            hold_flat(max_acct, max_periods, balance, rate, &bs);
            break;

        case 2:
            // Performance Benchmark: full balance sheet simulation out 5Y - synthetic placeholder regression balance and rate models
            // generate performance benchmark for unoptimized reference server.
            
            full_balance_sheet_simulation(max_acct, max_periods, balance, rate, &bs);
            break;
        
        case 3:
            // Performance Benchmark: simulate securities rather than Balance Sheet accounts containing securities
            // use this benchmark to get an estimate on how much the inline function call to the regression equation function will cost
            // assume all the rows in Accrual Security Master get simulated out 5 years
            // we can make that a user selectable parameter later
            
            // slight semantic shift in what is being modeled securities rather than accounts
            // the initial balance and rate are per security here rather than per account
            full_accrual_security_master_simulation(max_sec, max_periods, balance, rate, &s);
            break;
            
        case 4:
            // slight semantic shift in what is being modeled securities rather than accounts
            // the initial balance and rate are per security here rather than per account
            // push the current market into the product model valuation
            full_accrual_2_security_master_simulation(max_sec, max_periods, balance, rate, &s, &cm);
            break;
            
        case 5:
            // make an accrual portfolio and send it to class accrual portfolio
        	// build a list of securities to be statically simulated in security master
        	// statically simulate those securities - in security master
        	// build the fully simulated balance sheet from the accrual portfolio (above) and the simulated securities
        	// function - build simulated balance sheet given accrual portfolio  and simualtion in security master
        	// return the fully simulated balance sheet.
        	full_accrual_2_balance_sheet_simulation(max_sec, max_periods, balance, rate, &p, &bs, &s, &cm);
            break;
            
        case 6:
            // full USD balance sheet Monte Carlo simulation with LMM market model 5Y
            
            break;
            
        case 7:
            // full USD balance sheet MC simulation with NLP optimized capital allocation plan
            
            break;
            
    }
    
    return(0);
    
}
    

