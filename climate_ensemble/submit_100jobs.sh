#!/bin/bash

count=0
total_jobs=3

for (( label=1; label<=total_jobs; label++ ))
do
    results='climate_ensemble/'${label}'/'
    sed 's/namehere/'$label'/' climate_ensemble/sbatch_single_longleaf.sh > climate_ensemble/manyrun/sbatch_single_longleaf_${label}.sh
    sed -i 's/outhere/out_'$label'.txt/' climate_ensemble/manyrun/sbatch_single_longleaf_${label}.sh
    sed -i 's/errhere/err_'$label'.txt/' climate_ensemble/manyrun/sbatch_single_longleaf_${label}.sh

    if [ $count -eq 0 ]
    then
      jobid=$(sbatch --parsable climate_ensemble/manyrun/sbatch_single_longleaf_${label}.sh $label $results)
    else
      jobid=$(sbatch --parsable --dependency=after:$jobid+1 climate_ensemble/manyrun/sbatch_single_longleaf_${label}.sh $label $results)
    fi

    count=$(( $count + 1 ))
done