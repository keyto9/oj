# -*- coding:utf-8 -*-
import os
import json

def attr(fname):
    ret = {}
    fin = open(fname, 'r')
    try:
        foo = fin.read()
        bar = json.loads(foo)
        ret = bar
    finally:
        fin.close()
    return ret

def sols(dname):
    ret = []
    flst = [x for x in os.listdir(dname)]
    exts = [os.path.splitext(x)[1] \
                            for x in flst]
    if '.cpp' in exts:
        ret.append('C++')
    if '.java' in exts:
        ret.append('Java')
    if '.py' in exts:
        ret.append('Python')
    return ','.join(ret)

def func(dname):
    t = dname.split('. ')
    index, title = int(t[0]), t[1]
    fname = dname + '/attr.json'
    url = attr(fname).get('url', '')
    title = '['+title+']( '+url+' )'
    solution = '['+sols(dname)+']( ' \
        +dname.replace(' ', '%20')+' )'
    return (index,title,solution)

def output(tb):
    fout = open('README.md', 'w')
    fout.write('# leetcode solution\n\n')
    fout.write('| Index | Problem | Solution |\n')
    fout.write('| :---: | :---- | :------: |\n')
    for tpl in tb:
        fout.write('| %d | %s | %s |\n' % tpl)

dlst = [x for x in os.listdir('.')  \
            if os.path.isdir(x)  \
            and x not in ['.git']]
output(sorted(map(func, dlst)))

