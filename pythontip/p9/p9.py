###############################################################################
## Copyright (C), 2015, dploop
## FileName: p9.py
## Author: dploop
## Date: 2015/10/28
## Description: http://www.pythontip.com/coding/code_oj_case/9
###############################################################################

def gcd(a, b):
    return gcd(b, a%b) if b else a

print gcd(a, b)
