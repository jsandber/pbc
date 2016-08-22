//
//  scenario_master.hpp
//  Finding NIMo
//
//  Created by jonathan sandberg on 12/21/15.
//  Copyright © 2015 jonathan sandberg. All rights reserved.
//

#ifndef scenario_master_hpp
#define scenario_master_hpp

#include <stdio.h>

#endif /* scenario_master_hpp */
class ScenarioMaster {
public:
    ScenarioMaster();
    ~ScenarioMaster();
    
    double * getScenarioMaster();
    int setScenarioMaster(double *);
    
    
private:
    
    
    int     scenario_id;
    int     as_of_date;
    double  Swap10Y[60];
    double  CPI[60];

};