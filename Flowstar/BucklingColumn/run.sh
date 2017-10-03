#!/bin/bash 

$1/flowstar < BucklingColumn.model
gnuplot outputs/BucklingColumn.plt
