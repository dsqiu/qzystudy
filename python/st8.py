#!/usr/bin/env python
def psychologist():
    print 'Please tell me your problems'
    while True:
        answer = (yield)
        if answer is not None:
            if answer.endswith('?'):
               print "Don't ask yourself too much questions"
            elif 'good' in answer:
                print "A that's good, go on"
            elif 'bad' in answer:
                print "Don't be so negative"
                
