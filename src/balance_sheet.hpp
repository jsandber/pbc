//
//  balance_sheet.hpp
//  Finding NIMo
//
//  Created by jonathan sandberg on 12/15/15.
//  Copyright © 2015 jonathan sandberg. All rights reserved.
//

#ifndef balance_sheet_hpp
#define balance_sheet_hpp

#include <stdio.h>
#include "../src/security_master.hpp"
#include "../src/accrual_portfolio.hpp"

//#include "nimo_configuration.cpp"

class BalanceSheet {
public:
    BalanceSheet(int, int);
    ~BalanceSheet();
    
    int simulate_hold_flat(int, int, float *, float *);
    //float sample_balance();
    //float sample_rate();
    int full_regression_model_simulation(int, int, float *, float *, float *, float *, float *);
    // int distribute_simualated_security_master(SecurityMaster *);
    
    //build the full balance sheet simulation from the security simulationa and the accrual portfolio
    int build_ssnp2bs(AccrualSecurityMaster *, AccrualPortfolio *);
    
private:
    
    int acct_id;
    int num_rows = 512*1024;
    int num_cols = 64;
    float * balance;
    float * rate;
    
    
};

#endif /* balance_sheet_hpp */
