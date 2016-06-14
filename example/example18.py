#!/usr/bin/env python
from example import MIClassA, MIClassB, MIClassC, MIClassD, MIClassAB, MIClassCD, MIClassABCD

a = MIClassA()
a.funcA()

b = MIClassB()
b.funcB()

c = MIClassC()
c.funcC()

d = MIClassD()
d.funcD()

ab = MIClassAB()
ab.funcA()
ab.funcB()
ab.funcAB()

cd = MIClassCD()
cd.funcC()
cd.funcD()
cd.funcCD()

abcd = MIClassABCD()
abcd.funcA()
abcd.funcB()
abcd.funcAB()
abcd.funcC()
abcd.funcD()
abcd.funcCD()
abcd.funcABCD()
