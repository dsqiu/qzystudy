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
        yield klass

        for attribute in dir(klass):
            if not attribute.startswith('__logger__'):
                continue
            element = getattr(klass,attribute)
            setattr(klass,attribute[len('__logger__'):],element)
            delattr(klass,attribute)

        
