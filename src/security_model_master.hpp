//
//  security_model_master.hpp
//  Finding NIMo
//
//  Created by jonathan sandberg on 12/21/15.
//  Copyright © 2015 jonathan sandberg. All rights reserved.
//

#ifndef security_model_master_hpp
#define security_model_master_hpp

#include <stdio.h>
#include "../src/account_balance.hpp"

#endif /* security_model_master_hpp */
class SecurityModelMaster {
public:
    SecurityModelMaster();
    ~SecurityModelMaster();
    
    double * getSecurityModelMaster();
    int setSecurityModelMaster(double *);
    
    
private:
    
    long    sec_id;
    long    sec_model_id;
    int     as_of_date;
    long    scenario_id; // for the given security, model, as_of date, and scenario these are the historical balance levels for the regrssion fit.
    AccountBalance Previous_ab[60];
  
    
};