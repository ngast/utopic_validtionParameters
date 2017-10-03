#!/bin/bash 

$1/flowstar < helicopter.model
gnuplot outputs/helicopter.plt
