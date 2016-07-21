# -*- coding: utf-8 -*-
"""
Created on Wed Jun 22 07:30:00 2016

@author: ok
"""

#silver
from math import log 
while True:
    n=int(input())
    if n==0:
        break
    print(int(log(n,2)))