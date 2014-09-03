#!/usr/bin/env python
class FirstClass(object):
    def _get_price(self):
        return '$500'
    price = property(_get_price)
class SecondClass(FirstClass):
    def _get_price(self):
        return '$20'
plane_ticket = SecondClass()
print plane_ticket.price


class FirstClass1(object):
    def _get_price(self):
        return '$500'
    def _get_the_price(self):
        return self._get_price()
    price = property(_get_the_price)
class SecondClass1(FirstClass1):
    def _get_price(self):
        return '$20'
plane_ticket = SecondClass1()
print plane_ticket.price
                
class FirstClass2(object):
    def _get_price(self):
        return '$500'
    price = property(_get_price)
class SecondClass2(FirstClass2):
    def _cheap_price(self):
        return '$20'
    price = property(_cheap_price)
plane_ticket = SecondClass2()
print plane_ticket.price
