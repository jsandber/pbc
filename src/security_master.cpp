//
//  security_master.cpp
//  Finding NIMo
//
//  Created by jonathan sandberg on 12/21/15.
//  Copyright © 2015 jonathan sandberg. All rights reserved.
//

#include "../src/security_master.hpp"
#include "../src/accrual_portfolio.hpp"


#include <stdlib.h>

AccrualSecurityMaster::AccrualSecurityMaster(int r, int c) {
 
    void * ptr;
    
    ptr = (void *)malloc(r * c * sizeof(float));
    if (ptr == NULL) exit(-1);
    else this->deposit_balance = (float *) ptr;
   
    ptr = (void *)malloc(r * c * sizeof(float));
    if (ptr == NULL) exit(-1);
    else this->deposit_rate = (float *) ptr;

    ptr = (void *)malloc(r * c * sizeof(float));
    if (ptr == NULL) exit(-1);
    else this->cards_balance = (float *) ptr;
    
    ptr = (void *)malloc(r * c * sizeof(float));
    if (ptr == NULL) exit(-1);
    else this->cards_rate = (float *) ptr;
    
    ptr = (void *)malloc(r * c * sizeof(float));
    if (ptr == NULL) exit(-1);
    else this->fed_funds_balance = (float *) ptr;

    ptr = (void *)malloc(r * c * sizeof(float));
    if (ptr == NULL) exit(-1);
    else this->fed_funds_rate = (float *) ptr;
    
    
    //this->deposit_balance = (float *)malloc(r * c * sizeof(float));
    //this->deposit_rate = (float *)malloc(r * c * sizeof(float));
    //this->cards_balance = (float *)malloc(r * c * sizeof(float));
    //this->cards_rate = (float *)malloc(r * c * sizeof(float));
    //this->fed_funds_balance = (float *)malloc(r * c * sizeof(float));
    //this->fed_funds_rate = (float *)malloc(r * c * sizeof(float));
    return;
}

AccrualSecurityMaster::~AccrualSecurityMaster() {
    
    free(this->deposit_balance);
    free(this->deposit_rate);
    free(this->cards_balance);
    free(this->cards_rate);
    free(this->fed_funds_balance);
    free(this->fed_funds_rate);
    return;
}

// place holder benchmark to get up and running
int AccrualSecurityMaster::full_regression_model_simulation(int max_sec, int max_periods, float * balance, float *rate, float *mkt1) {

    for (int i = 0; i < max_sec; i++ )
        for (int j = 0; j < max_periods; j++ ) {
            *(this->deposit_balance + i*this->num_cols  + j)= balance[i];
        }
    
    for (int i = 0; i < max_sec; i++ )
        for (int j = 0; j < max_periods; j++ ) {
            *(this->deposit_rate + i*this->num_cols + j)= rate[i];
        }
    
    return(0);
}

int AccrualSecurityMaster::deposit_model_1(int max_periods, float initial_balance, float initial_rate, float * balance, float * rate, float * mkt1) {
    
    float c1=1.0001, c2=1.0002, c3=1.0002, c4=1.0004;
    
    balance [0] = initial_balance;
    rate[0] = initial_rate;
    for (int i = 1; i < max_periods; i++) {
        balance[i] = balance[i-1] * mkt1[i] * c1 + c2;
        rate[i] = rate[i-1] *mkt1[i]*c3 + c4;
    }
    
    return(0);
}
int AccrualSecurityMaster::cards_model_1(int max_periods, float initial_balance, float initial_rate, float *balance, float * rate, float * mkt1){
    
    float c1=1.0001, c2=1.0002, c3=1.0002, c4=1.0004;
    
    balance [0] = initial_balance;
    rate[0] = initial_rate;
    for (int i = 1; i < max_periods; i++) {
        balance[i] = balance[i-1] * mkt1[i] * c1 + c2;
        rate[i] = rate[i-1] *mkt1[i]*c3 + c4;
    }
    
    
    return(0);
}

int AccrualSecurityMaster::fed_funds_model_1(int max_periods, float initial_balance, float initial_rate, float *balance, float * rate, float *mkt1){
    
    float c1=1.0001, c2=1.0002, c3=1.0002, c4=1.0004;
    
    balance [0] = initial_balance;
    rate[0] = initial_rate;
    for (int i = 1; i < max_periods; i++) {
        balance[i] = balance[i-1] * mkt1[i] * c1 + c2;
        rate[i] = rate[i-1] * mkt1[i]*c3 + c4;
    }
    
    return(0);
}

int AccrualSecurityMaster::simulate_security_master(int max_sec, int max_periods, float * balance, float *rate, float *mkt1) {
   
     // Simulate all deposits
    for (int i = 0; i < max_sec; i++ ) {
        deposit_model_1(max_periods, balance[i], rate[i], this->deposit_balance + i*this->num_cols, this->deposit_rate + i*this->num_cols, mkt1);
    }
    // Simulate all cards
    for (int i = 0; i < max_sec; i++ ) {
        cards_model_1(max_periods, balance[i], rate[i], this->cards_balance + i*this->num_cols, this->cards_rate + i*this->num_cols, mkt1);
    }
    // simulate all cash/fed fund0 securities
    for (int i = 0; i < max_sec; i++ ) {
        fed_funds_model_1(max_periods, balance[i], rate[i], this->fed_funds_balance + i*this->num_cols, this->fed_funds_rate + i*this->num_cols, mkt1);
    }
    return(0);
}

int AccrualSecurityMaster::deposit_model_2(int max_periods, float initial_balance, float initial_rate, float * balance, float * rate, CurrentMarket * m) {

    float c1=1.0001, c2=1.0002, c3=1.0002, c4=1.0004; 	// ultimately these coeffs get pulled from security master post market calibration

    float * mkt1 = m->get_SymbolData(1);   	// pull mkt1 from CurrentMarket

    balance [0] = initial_balance;
    rate[0] = initial_rate;
    for (int i = 1; i < max_periods; i++) {
        balance[i] = balance[i-1] * mkt1[i] * c1 + c2;
        rate[i] = rate[i-1] *mkt1[i]*c3 + c4;
    }

    return(0);
}
int AccrualSecurityMaster::cards_model_2(int max_periods, float initial_balance, float initial_rate, float *balance, float * rate, CurrentMarket * m){

    float c1=1.0001, c2=1.0002, c3=1.0002, c4=1.0004;	// ultimately these coeffs get pulled from security master post market calibration

    float * mkt1 = m->get_SymbolData(1);  	// pull mkt1 from CurrentMarket

    balance [0] = initial_balance;
    rate[0] = initial_rate;
    for (int i = 1; i < max_periods; i++) {
        balance[i] = balance[i-1] * mkt1[i] * c1 + c2;
        rate[i] = rate[i-1] *mkt1[i]*c3 + c4;
    }


    return(0);
}


int AccrualSecurityMaster::fed_funds_model_2(int max_periods, float initial_balance, float initial_rate, float *balance, float * rate, CurrentMarket *m){

    float c1=1.0001, c2=1.0002, c3=1.0002, c4=1.0004; // ultimately these coeffs get pulled from security master post market calibration
    float * mkt1 = m->get_SymbolData(1);    // pull mkt1 from CurrentMarket

    balance [0] = initial_balance;
    rate[0] = initial_rate;
    for (int i = 1; i < max_periods; i++) {
        balance[i] = balance[i-1] * mkt1[i] * c1 + c2;
        rate[i] = rate[i-1] * mkt1[i]*c3 + c4;
    }

    return(0);
}
int AccrualSecurityMaster::simulate_2_security_master(int max_sec, int max_periods, float * balance, float *rate, CurrentMarket *m) {

     // Simulate all deposits
    for (int i = 0; i < max_sec; i++ ) {
        deposit_model_2(max_periods, balance[i], rate[i], this->deposit_balance + i*this->num_cols, this->deposit_rate + i*this->num_cols, m);
    }
    // Simulate all cards
    for (int i = 0; i < max_sec; i++ ) {
        cards_model_2(max_periods, balance[i], rate[i], this->cards_balance + i*this->num_cols, this->cards_rate + i*this->num_cols, m);
    }
    // simulate all cash/fed fund0 securities
    for (int i = 0; i < max_sec; i++ ) {
        fed_funds_model_2(max_periods, balance[i], rate[i], this->fed_funds_balance + i*this->num_cols, this->fed_funds_rate + i*this->num_cols, m);
    }
    return(0);
}

int AccrualSecurityMaster::p2s_list(AccrualPortfolio * p) {

	// create an list of securities to be simulated
	// initially we just put all the securities on the list.


	return(0);
}
