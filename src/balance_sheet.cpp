//
//  balance_sheet.cpp
//  Finding NIMo
//
//  Created by jonathan sandberg on 12/15/15.
//  Copyright © 2015 jonathan sandberg. All rights reserved.
//

#include "../src/balance_sheet.hpp"

#include <stdlib.h>
#include <math.h>
#include "../src/security_master.hpp"
#include "../src/accrual_portfolio.hpp"


BalanceSheet::BalanceSheet(int r, int c) {
    
    void * ptr;
    
    ptr = (void *)malloc(r * c * sizeof(float));
    if (ptr == NULL) exit(-1);
    else this->balance = (float *) ptr;
    
    ptr = (void *)malloc(r * c * sizeof(float));
    if (ptr == NULL) exit(-1);
    else this->rate = (float *) ptr;
    
    //this->balance = (float *)malloc(r * c * sizeof(float));
    //this->rate = (float *)malloc(r * c * sizeof(float));
    return;
    }

BalanceSheet::~BalanceSheet() {
    free(this->balance);
    free(this->rate);
    return;
}


int BalanceSheet::simulate_hold_flat(int max_acct, int max_periods, float * balance, float * rate) {
    
    for (int i = 0; i < max_acct; i++ )
        for (int j = 0; j < max_periods; j++ ) {
            *(this->balance + i*this->num_cols  + j)= balance[i];
        }
    for (int i = 0; i < max_acct; i++ )
        for (int j = 0; j < max_periods; j++ ) {
            *(this->rate + i*this->num_cols + j)= rate[i];
        }
    return(0);
}

int BalanceSheet::full_regression_model_simulation(int max_acct, int max_periods, float * balance, float * rate, float *coeff, float *mkt, float *c) {
    

    for (int i = 0; i < max_acct; i++ ) {
        this->balance[0] = balance[i];
        for (int j = 1; j < max_periods; j++ ) {
            *(this->balance + i*this->num_cols  + j)=  *(this->balance + i*this->num_cols  + j-1)* coeff[j] * log(mkt[j]/mkt[j-1]) + exp(c[j]) * mkt[j-1];
        }
    }
    for (int i = 0; i < max_acct; i++ ){
        this->rate[0] = rate[i];
        for (int j = 1; j < max_periods; j++ ) {
            *(this->rate + i*this->num_cols  + j)=  pow(*(this->rate + i*this->num_cols  + j-1), 0.99);
        }
    }
    return(0);
}

int BalanceSheet::build_ssnp2bs(AccrualSecurityMaster *, AccrualPortfolio *) {

	 // build the full balance sheet simulation from the security simulation and the accrual portfolio



	return(0);
}




    /*
int BalanceSheet::distribute_simualated_security_master(AccrualSecurityMaster s) {
    
    return(0);
};
*/
