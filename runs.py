#!/usr/bin/python

import subprocess
import random

size = 4096 
rseed = 1
thresh = 64
outfile = 'outrseed.txt'

random.seed()
with open(outfile, 'w') as ofile:
    ofile.write("--------------------------------------------\n")
    for rseed in random.sample(xrange(2**31), 50):
        ofile.write("Size: " + str(size) + "\tSeed: " + str(rseed) + "\t Thresh: " + str(thresh) + "\n")
        command = "time ./strassen " + str(size) + " " + str(rseed) + " " + str(thresh)
        p = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True, executable='/bin/zsh')
        ofile.write(p.stdout.read())
        ofile.write(p.stderr.read())
        ofile.write("--------------------------------------------\n")
