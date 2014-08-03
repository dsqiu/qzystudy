#!/usr/bin/env python
import threading
from time import sleep

def test_func(id):
    for i in range(0,5):
        sleep(1)
        print('thread %d is running %d\n' % (id,i))

threads = []
for i in range(0,3):
    t = threading.Thread(target=test_func, args=(i,))
    threads.append(t)

for t in threads:
    t.start()

for t in threads:
    t.join()
