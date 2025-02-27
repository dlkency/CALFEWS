C Copyright (C) 2005, 2009 International Business Machines and others.
C All Rights Reserved.
C This code is published under the Common Public License.
C
C    $Id: IpReturnCodes.inc 1435 2009-04-24 17:09:05Z andreasw $
C
C Author:   Andreas Waechter    IBM      2005-08-11
C
      INTEGER IP_SOLVE_SUCCEEDED
      PARAMETER( IP_SOLVE_SUCCEEDED = 0 )

      INTEGER IP_ACCEPTABLE_LEVEL
      PARAMETER( IP_ACCEPTABLE_LEVEL = 1 )

      INTEGER IP_INFEASIBLE_PROBLEM
      PARAMETER( IP_INFEASIBLE_PROBLEM = 2 )

      INTEGER IP_SEARCH_DIRECTION_TOO_SMALL
      PARAMETER( IP_SEARCH_DIRECTION_TOO_SMALL = 3 )

      INTEGER IP_DIVERGING_ITERATES
      PARAMETER( IP_DIVERGING_ITERATES = 4 )

      INTEGER IP_USER_REQUESTED_STOP
      PARAMETER( IP_USER_REQUESTED_STOP = 5 )

      INTEGER IP_FEASIBLE_POINT_FOUND
      PARAMETER( IP_FEASIBLE_POINT_FOUND = 6 )

      INTEGER IP_ITERATION_EXCEEDED
      PARAMETER( IP_ITERATION_EXCEEDED = -1 )

      INTEGER IP_RESTORATION_FAILED
      PARAMETER( IP_RESTORATION_FAILED = -2 )

      INTEGER IP_ERROR_IN_STEP_COMPUTATION
      PARAMETER( IP_ERROR_IN_STEP_COMPUTATION = -3 )

      INTEGER IP_CPUTIME_EXCEEDED
      PARAMETER( IP_CPUTIME_EXCEEDED = -4 )

      INTEGER IP_NOT_ENOUGH_DEGREES_OF_FRE
      PARAMETER( IP_NOT_ENOUGH_DEGREES_OF_FRE = -10 )

      INTEGER IP_INVALID_PROBLEM_DEFINITION
      PARAMETER( IP_INVALID_PROBLEM_DEFINITION = -11)

      INTEGER IP_INVALID_OPTION
      PARAMETER( IP_INVALID_OPTION = -12 )

      INTEGER IP_INVALID_NUMBER_DETECTED
      PARAMETER( IP_INVALID_NUMBER_DETECTED = -13 )

      INTEGER IP_UNRECOVERABLE_EXCEPTION
      PARAMETER( IP_UNRECOVERABLE_EXCEPTION = -100 )

      INTEGER IP_NON_IPOPT_EXCEPTION
      PARAMETER( IP_NON_IPOPT_EXCEPTION = -101 )

      INTEGER IP_INSUFFICIENT_MEMORY
      PARAMETER( IP_INSUFFICIENT_MEMORY = -102 )

      INTEGER IP_INTERNAL_ERROR
      PARAMETER( IP_INTERNAL_ERROR = -199 )

      INTEGER IP_REGULAR_MODE
      PARAMETER( IP_REGULAR_MODE = 0 )

      INTEGER IP_RESTORATION_PHASE_MODE
      PARAMETER( IP_RESTORATION_PHASE_MODE = 1 )
