#####

This repository contains all configuration files to generate Table I
of the paper "Under-Approximation Through Optimal Control".

# ALGO-vnode

## Required Software

* Matlab 2016 or higher

## Installation

* Download VNODE-LP : http://www.cas.mcmaster.ca/~nedialk/vnodelp/

## Running the examples

First, we compile the vnode file of each example (putting the binary in the same folder as the source file and keeping the same name). Then, in the run_all.m file of the ALGO-vnode folder, we set the correct path to Matlab. 

We execute the following commands in a terminal:

* cd ALGO-vnode
* ./run_all.sh

In each example, the obtained under-approximation of the reachable set can be seen in the terminal.

# CORA

## Required Software

* Matlab 2016 or higher

## Installation

* Download CORA 2016: http://www.i6.in.tum.de/Main/SoftwareCORA

## Running the examples:

First, in the run_all.m file of the CORA folder, we set the correct path to CORA. Then, we execute the following commands in a terminal (note that, in the first command, we must put the correct path to Matlab binaries):

* PATH=$PATH:/usr/local/MATLAB/R2016b/bin 
* cd CORA 
* matlab -nodesktop -r run_all

In each example, the obtained over-approximation of the reachable set can be seen in the terminal. The examples with timeout have been commented out.

# FLOW*

## Installation

* Download Flow* 2.0.0 or higher

## Configuration

* In the run_all.sh file in the Flowstar folder, set the correct path to flowstar

## Running the examples

First, in the run_all.m file of the CORA folder, we set the correct path to flowstar. Then, we execute the following commands in a terminal:

* cd Flowstar 
* ./run_all.sh

In each example, an image with the obtained over-approximation of the reachable set can be seen in the images folder and the output of the program in the outputs folder.
