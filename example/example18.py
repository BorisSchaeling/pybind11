#!/usr/bin/env python
from example import MIChild1

c = MIChild1()
c.virtualParent1()
c.nonvirtualParent1()
c.virtualParent2()
c.nonvirtualParent2()
c.child1()
c.virtualOverride()
