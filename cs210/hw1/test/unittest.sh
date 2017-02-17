#!/bin/bash

../bin/hw1 samp1.ccx > out1
../bin/hw1 samp2.ccx > out2
../bin/hw1 samp3.ccx > out3

diff -s out1 good1
diff -s out2 good2
diff -s out3 good3
