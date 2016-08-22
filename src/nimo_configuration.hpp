//
//  nimo_configuration.hpp
//  Finding NIMo
//
//  Created by jonathan sandberg on 12/21/15.
//  Copyright © 2015 jonathan sandberg. All rights reserved.
//

#ifndef nimo_configuration_hpp
#define nimo_configuration_hpp

#include <stdio.h>
#include <iostream>
#include <string>


enum CodeOptimizationLevel {REFERENCE, AVX2};
enum ScenarioModel {BASE, PARSHIFT, STOCHASTIC};
enum PostSimulationOptimizationLevel {NONE, OPTIMIZE_CAPITAL_PLAN};
enum CurrencyLimits {USD, MULTI};
enum BalanceSheetSize {SMALL, BIG};
enum MonteCarloSimulationConfiguration {NOMC, COMPLETE};
enum BalanceSheetSimulation {HOLD_FLAT, FULL_BS};


class Nimo {
    
public:
 
    // global limits
    int max_acct_id = (4);
    int max_horizon_months = (4); // code assumes max 64  in various places
    int max_securities = (4);
    
    std::string get_Nimo(){return("\thello from NIMo\n");};

    void print_Nimo(){
        std::cout << "max_acct_id = " << max_acct_id << "\n";
        std::cout << "max_horizon_months = " << max_horizon_months << "\n";
        std::cout << "max_securities = " << max_securities << "\n";
        std::cout << "opt_level = " << opt_level << "\n";
        std::cout << "scen_mdl = " << scen_mdl << "\n";
        std::cout << "ps_opt_level = " << ps_opt_level << "\n";
        std::cout << "ccy_limit = " << ccy_limit << "\n";
        std::cout << "bs_size = " << bs_size << "\n";
        std::cout << "mc_config = " << mc_config << "\n";
        std::cout << "bs_sim = " << bs_sim << "\n";
        return;
    };

  
    int get_max_acct_id(){return(this->max_acct_id);};
    int get_max_horizon_months(){return(this->max_horizon_months);};
    int get_max_securities(){return(this->max_securities);};
    int set_max_acct_id(int i) {max_acct_id = i;return(0);};
    int set_max_horizon_months(int i) {max_horizon_months = i;return(0);};
    int set_max_securities(int i){max_securities = i;return(0);};
    int set_opt_level (enum CodeOptimizationLevel i){opt_level = i;return(0);};
    int set_scen_mdl (enum ScenarioModel i){scen_mdl = i;return(0);};
    int set_ps_opt_level(enum PostSimulationOptimizationLevel i){ps_opt_level = i;return(0);};
    int set_ccy_limit(enum CurrencyLimits i){ccy_limit = i;return(0);};
    int set_bs_size(enum BalanceSheetSize i) {bs_size = i;return(0);};
    int set_mc_config(enum MonteCarloSimulationConfiguration i) {mc_config = i;return(0);};
    int set_bs_sim(enum BalanceSheetSimulation i) {bs_sim = i;return(0);};
    
private:
    
    
    enum CodeOptimizationLevel opt_level = REFERENCE;
    enum ScenarioModel  scen_mdl = BASE;
    enum PostSimulationOptimizationLevel ps_opt_level = NONE;
    enum CurrencyLimits ccy_limit = USD;
    enum BalanceSheetSize bs_size = SMALL;
    enum MonteCarloSimulationConfiguration mc_config = NOMC;
    enum BalanceSheetSimulation bs_sim = HOLD_FLAT;
    
    
};

#endif /* nimo_configuration_hpp */