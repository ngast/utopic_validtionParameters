#!/bin/bash 

# define the path to flowstar
flowstar_path=~/Desktop/flowstar/flowstar-2.0.0

$flowstar_path/flowstar < replicatedBindingSite4Asymm.model
gnuplot outputs/replicatedBindingSite4Asymm.plt


