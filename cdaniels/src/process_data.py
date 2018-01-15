#!/usr/local/bin/python3
########10########20########30## DOCUMENTATION #50########60########70########80
#
#  OVERVIEW
#  ========
#  Process data given on stdin. Output results to stdout
#  
#  input lines are expected to be formatted as::
#    
#    n,M,m,L,l
#  
#  output lines are formatted as::
#  
#    T,lmb2,lmb,d,n,V,u,f,L,l,m,M
#    
#  NOTE: lmb stands for lambda
#  
########10########20########30#### LISCENSE ####50########60########70########80
# Copyright (c) 2016, Charles Daniels
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without 
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, 
# this list of conditions and the following disclaimer.
# 
# 2. Redistributions in binary form must reproduce the above copyright notice, 
# this list of conditions and the following disclaimer in the documentation 
# and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its 
# contributors may be used to endorse or promote products derived from this 
# software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
# POSSIBILITY OF SUCH DAMAGE.
########10########20########30########40########50########60########70########80

import sys
import csv
import numpy
import math 
import logging

logging.basicConfig(level=logging.DEBUG)

output_format = ['T','lmb2','lmb','d','n','V','u','f','L','l','m','M']
precision = 3
g = 9.81  # gravity constant

logging.info("output format is: {}".format(','.join(output_format)))

for line in sys.stdin:
  line = line.replace('\n', '')
  logging.debug("processing line: {}".format(line))
  line = [float(x) for x in line.split(',')]
  assert len(line) is 5
  n, M, m, L, l = line
  logging.debug("n, M, m, L, l = {}, {}, {}, {}, {}".format(n, M, m, L, l))

  # convert from grams to kg
  M *= 0.001
  m *= 0.001

  d = L/n
  T = M*g
  lmb = 2*d
  lmb2 = lmb * lmb
  u = m / l
  V = math.sqrt(T/u)
  f = V/lmb



  ns = locals()
  logging.debug("un-rounded output is: {}".format([ns[x] for x in output_format]))
  output = [str(round(ns[x], precision)) for x in output_format]
  logging.debug("generated output: {}".format(output))
  print(','.join(output))

