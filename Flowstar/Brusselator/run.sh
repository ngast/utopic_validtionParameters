#!/bin/bash 

$1/flowstar < Brusselator.model
gnuplot outputs/Brusselator.plt
