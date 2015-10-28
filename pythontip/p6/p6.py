###############################################################################
## Copyright (C), 2015, dploop
## FileName: p6.py
## Author: dploop
## Date: 2015/10/28
## Description: http://www.pythontip.com/coding/code_oj_case/6
###############################################################################

print "2 3 5 7 " + " ".join([str(n) for n in \
xrange(10, 100) if n%2 and n%3 and n%5 and n%7])

