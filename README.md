#####

This repository contains all configuration files to generate Table I
of the paper "Under-Approximation Through Optimal Control".

# UTOPIC

## Required Software

* Matlab 2016 or higher
* VNODE-LP : http://www.cas.mcmaster.ca/~nedialk/vnodelp/

## Running the examples: Van der Pol

The configurations files are in the folder utopic/VanderPol/

* execute vanderPol_Pontryagin.m in Matlab
* compile vanderPol_VNODELP.cc and execute the binary

To run another model, replace vanderPol by the name of the desired model.

# CORA

## Required Software

* Matlab 2016 or higher
* CORA 2016: http://www.i6.in.tum.de/Main/SoftwareCORA

## Running the examples: Van der Pol 

The configuration file is in the folder CORA/VanderPol/

* set the correct path to CORA in the first line of vanderPol_reach_set.m file
* execute vanderPol_reach_set.m in Matlab

To run another model, replace vanderPol by the name of the desired model.

# FLOW*

## Required Software 

* Flow* 2.0.0 or higher

## Running the example: Van der Pol

The configuration files are in the folder Flowstar/VanderPol/

* set the correct path to flowstar in run.sh file
* execute run.sh

