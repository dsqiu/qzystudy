#!/usr/bin/env python
class DistinctError(Exception):
    pass
class distinctdict(dict):
    def __setitem__(self,key,value):
        try:
            value_index = self.values().index(value)
            existing_key = self.keys()[value_index]
            if existing_key != key:
                raise DistinctError(("This value already "
                                     "exists for '%s'") % \
                                    str(self[existing_key]))
        except ValueError:
            pass
        super(distinctdict,self).__setitem__(key,value)
my = distinctdict()
my['key'] = 'value'
my['other_key'] = 'value'
my['other_key'] = 'value2'
def dump(d):
    print "aa %s" % d
print "===================="
[dump(my[i]) for i in my]

class folder(list):
    def __init__(self,name):
        self.name = name
    def dir(self):
        print 'I am the %s folder.' % self.name
        for element in self:
            print element
the = folder('secret')
the
the.append('pics')
the.append('videos')
the.dir()
