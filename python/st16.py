#!/usr/bin/env python
import logging
from __future__ import with_statement
from contextlib import contextmanager
@contextmanager
def logged(klass,logger):
    def _log(f):
        def __log(*args,**kw):
            logger(f,args,kw)
            return f(arfs,kw)
        return __log
        for attribute in dir(klass):
            if attribute.startswith('-'):
                continue
            element = getattr(klass,attribute)
            setattr(klass,'__logger_%s' % attribute,element)
            setattr(klass,attribute,_log(element))
        yield _log

        for attribute in dir(klass):
            if not attribute.startswith('__logger__'):
                continue
            element = getattr(klass,attribute)
            setattr(klass,attribute[len('__logger__'):],element)
            delattr(klass,attribute)
class One(object):
    def _private(self):
        pass
    def one(self,other):
        self.two()
        other.thing(self)
        self._private()
    def two(self):
        pass
class Two(object):
    def thing(self,other):
        other.two()
calls = []
def called(meth,args,kw):
    calls.append(meth.im_func.func_name)
with logged(One,called):
    one = One()
    two = Two()
    one.one(two)
calls

