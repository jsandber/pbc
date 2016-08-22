//
//  security_master.hpp
//  Finding NIMo
//
//  Created by jonathan sandberg on 12/21/15.
//  Copyright © 2015 jonathan sandberg. All rights reserved.
//

#ifndef security_master_hpp
#define security_master_hpp

#include <stdio.h>
//#include "nimo_configuration.cpp"

#include "../src/accrual_portfolio.hpp"
#include "../src/current_market.hpp"



class AccrualSecurityMaster {
    
public:
    
    AccrualSecurityMaster(int, int);
    ~AccrualSecurityMaster();

    int simulate_security_master(int, int, float * , float *, float *);
    int set_balance_history();
    int set_rates_history();
    int set_credit_default_history();
    int calibrate_security_models(AccrualPortfolio *, CurrentMarket *);
    int set_simulated_balance();
    int full_regression_model_simulation(int, int, float *, float *, float *);
    
    int p2s_list(AccrualPortfolio *); // determines a security list using the user supplied accrual portfolio as input
    // simulate the designated security models against the current market
    int simulate_2_security_master(int, int, float * , float *, CurrentMarket *);

    // bind the rate and balance models together the simulation loop will project rates and balances together
    int deposit_model_1(int, float, float, float *, float *, float *);
    int cards_model_1(int, float, float, float *, float *, float *);
    int fed_funds_model_1(int, float, float, float *, float *, float *);

    int deposit_model_2(int, float, float, float *, float *, CurrentMarket *);
    int cards_model_2(int, float, float, float *, float *, CurrentMarket *);
    int fed_funds_model_2(int, float, float, float *, float *, CurrentMarket *);

private:
    
    long    sec_id;
    long    sec_model_id;
    int     as_of_date;
    long    scenario_id;
    // for the given security, model, as_of date, and scenario these are forward balance projections
    
    float historical_balance[3][60];
    double balance_parameter_calibration[3][60];
    float forward_balance[3][60];
 
    
    int num_deposit_rows = 1024;
    int num_cards_rows = 1024;
    int num_fed_funds_rows = 512*1024;
    int num_cols = (64);
    
    float * deposit_balance;
    float * deposit_rate;
    float * cards_balance;
    float * cards_rate;
    float * fed_funds_balance;
    float * fed_funds_rate;
    
    int * deposit_balance_model_assignment;
    int * deposit_rate_model_assignement;
    int * cards_balance_model_assignment;
    int * cards_rate_model_assignment;
    int * fed_funds_balance_model_assignment;
    int * fed_funds_rate_model_assignment;
    
    
};

#endif /* security_master_hpp */
