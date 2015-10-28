###############################################################################
## Copyright (C), 2015, dploop
## FileName: p8.py
## Author: dploop
## Date: 2015/10/28
## Description: http://www.pythontip.com/coding/code_oj_case/8
###############################################################################

L.sort(); n = len(L)
ds = L[(n-1)//2] + L[n//2]
if ds % 2:
	print ds / 2.0
else:
	print ds // 2

