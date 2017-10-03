#!/bin/bash 

$1/flowstar < jetEngine.model
gnuplot outputs/JetEngine.plt
