#!/usr/bin/python

class Base:
    def method(self):
        print('Base::method')


class Child(Base):
    pass


c = Child()
c.method()
