#!/usr/bin/env python
import os  
filenames=os.listdir(os.getcwd())  
for name in filenames:
    print name
    print filenames.index(name)
    print name[:-3]
