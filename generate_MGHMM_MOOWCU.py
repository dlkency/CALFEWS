import numpy as np
import pandas as pd
import h5py
from calfews_src.util import MGHMM_generate_trace,  regularize_covariance 
import sys
from datetime import datetime

start_time = datetime.now()

### results folder and number of MC samples & DU samples from command line
MGHMMdir = 'calfews_src/data/MGHMM_synthetic/'
filestart = 'DailyQ_s'
annualfilestart = 'AnnualQ_s'
fileend = '.csv'
numMC = 100

### uncertainties. these are all set to baseline value for MOO/WCU experiment (as opposed to DU experiment to come in next paper)
udict = {'dry_state_mean_multiplier': 1, 'wet_state_mean_multiplier': 1,\
         'covariance_matrix_dry_multiplier': 1, 'covariance_matrix_wet_multiplier': 1, \
         'transition_drydry_addition': 0, 'transition_wetwet_addition': 0}
#### number of years for synthetic generation. Note this is one more than we will simulate, since this does calendar year but calfews cuts to water year.
nYears = 4
all_states = []
closest_yr = []
### loop over MC samples & create a new synthetic trace for each, using MC number as seed
for mc in range(numMC):
  udict['synth_gen_seed'] = mc
  annual, df, binary_states, closest_year  = MGHMM_generate_trace(nYears, udict, drop_date=False)
  df.to_csv(MGHMMdir + filestart + str(mc) + fileend, index=False)
  np.savetxt(MGHMMdir + annualfilestart + str(mc) + fileend, annual, delimiter=',')
  all_states.append({
            'MC_Sample': mc,
            'Year1_State': binary_states[0],
            'Year2_State': binary_states[1] if nYears >=2 else np.nan,
            'Year3_State': binary_states[2] if nYears >=3 else np.nan
            # Add more years if nYears >3
        })
  closest_yr.append({
            'MC_Sample': mc,
            'Year1_State': closest_year[0],
            'Year2_State': closest_year[1] if nYears >=2 else np.nan,
            'Year3_State': closest_year[2] if nYears >=3 else np.nan
            # Add more years if nYears >3
        })
  
states_df = pd.DataFrame(all_states)
states_filename = f"{MGHMMdir}All_States_summary.csv"
states_df.to_csv(states_filename, index=False)
closest_year_df = pd.DataFrame(closest_yr)
states_filename = f"{MGHMMdir}closest_year_df_summary.csv"
closest_year_df.to_csv(states_filename, index=False)