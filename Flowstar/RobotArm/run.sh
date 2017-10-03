#!/bin/bash 

$1/flowstar < RobotArm.model
gnuplot outputs/RobotArm.plt
