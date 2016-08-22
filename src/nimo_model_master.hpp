//
//  nimo_model_master.hpp
//  Finding NIMo
//
//  Created by jonathan sandberg on 12/21/15.
//  Copyright © 2015 jonathan sandberg. All rights reserved.
//

#ifndef nimo_model_master_hpp
#define nimo_model_master_hpp

#include <stdio.h>


class nimo_model_master {
public:
 
    
    double * getnimo();
    int setnimo(double *);
    
    
private:
    
    long max_acct_id;
    int mac_horizon_month=60;
    int max_securities = 10*(1024);
    
    
};

#endif /* nimo_model_master_hpp */
