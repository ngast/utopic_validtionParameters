#!/bin/bash 

$1/flowstar < Aging.model
gnuplot outputs/Aging.plt
