/*
    example/example18.cpp -- Multiple inheritance support

    Copyright (c) 2016 Boris Schäling <boris@highscore.de>

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE file.
*/

#include "example.h"

struct MIClassA {
    virtual ~MIClassA() = default;
    virtual void funcA() { std::cout << "funcA\n"; }
};

struct MIClassB {
    virtual ~MIClassB() = default;
    virtual void funcB() { std::cout << "funcB\n"; }
};

struct MIClassC {
    virtual ~MIClassC() = default;
    virtual void funcC() { std::cout << "funcC\n"; }
};

struct MIClassD {
    virtual ~MIClassD() = default;
    virtual void funcD() { std::cout << "funcD\n"; }
};

struct MIClassAB : MIClassA, MIClassB {
    virtual ~MIClassAB() = default;
    virtual void funcAB() { std::cout << "funcAB\n"; }
};

struct MIClassCD : MIClassC, MIClassD {
    virtual ~MIClassCD() = default;
    virtual void funcCD() { std::cout << "funcCD\n"; }
};

struct MIClassABCD : MIClassAB, MIClassCD {
    virtual ~MIClassABCD() = default;
    virtual void funcABCD() { std::cout << "funcABCD\n"; }
};

void init_ex18(py::module &m) {
    py::class_<MIClassA>(m, "MIClassA")
        .def(py::init<>())
        .def("funcA", &MIClassA::funcA);

    py::class_<MIClassB>(m, "MIClassB")
        .def(py::init<>())
        .def("funcB", &MIClassB::funcB);

    py::class_<MIClassC>(m, "MIClassC")
        .def(py::init<>())
        .def("funcC", &MIClassC::funcC);

    py::class_<MIClassD>(m, "MIClassD")
        .def(py::init<>())
        .def("funcD", &MIClassD::funcD);

    py::class_<MIClassAB>(m, "MIClassAB", py::bases<MIClassA, MIClassB>())
        .def(py::init<>())
        .def("funcAB", &MIClassAB::funcAB);

    py::class_<MIClassCD>(m, "MIClassCD", py::bases<MIClassC, MIClassD>())
        .def(py::init<>())
        .def("funcCD", &MIClassCD::funcCD);

    py::class_<MIClassABCD>(m, "MIClassABCD", py::bases<MIClassAB, MIClassCD>())
        .def(py::init<>())
        .def("funcABCD", &MIClassABCD::funcABCD);
}
