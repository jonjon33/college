#!/bin/bash
hw1dir=/home/jon/Code/college/cs210/hw1/

$hw1dir/bin/hw1 $hw1dir/test/samp1.ccx > $hw1dir/test/out1

diff -s $hw1dir/test/out1 $hw1dir/test/good1
