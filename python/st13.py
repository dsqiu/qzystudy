#!/usr/bin/env python
from __future__ import with_statement

hosts = file('/etc/hosts')
try:
    for line in hosts:        
        if line.startswith('#'):
            continue
        print line
finally:
    hosts.close()


with file('/etc/hosts') as hosts:
    for line in hosts:
        if line.startswith('#'):
            continue
        print line

