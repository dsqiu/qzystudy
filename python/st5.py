#!/usr/bin/env python
def _treatment(pos,element):
    return '%d:%s' % (pos,element)
seq = ["one","two","three"]
[_treatment(i,el) for i,el in enumerate(seq)]
