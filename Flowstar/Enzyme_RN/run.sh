#!/bin/bash 

# define the path to flowstar
flowstar_path=~/Desktop/flowstar/flowstar-2.0.0

$flowstar_path/flowstar < Enzyme_RN.model
gnuplot outputs/Enzyme_RN.plt
