/*
    example/example18.cpp -- Multiple inheritance support

    Copyright (c) 2016 Boris Schäling <boris@highscore.de>

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE file.
*/

#include "example.h"

struct MIParent1 {
    virtual ~MIParent1() = default;

    virtual void virtualParent1() {
        std::cout << "virtual parent1\n";
    }

    void nonvirtualParent1() {
        std::cout << "nonvirtual parent1\n";
    }

    virtual void virtualOverride() {
    }
};

struct MIParent2 {
    virtual ~MIParent2() = default;

    virtual void virtualParent2() {
        std::cout << "virtual parent2\n";
    }

    void nonvirtualParent2() {
        std::cout << "nonvirtual parent2\n";
    }
};

struct MIChild1 : MIParent1, MIParent2 {
    void child1() {
        std::cout << "child1\n";
    }

    void virtualOverride() override {
        std::cout << "override\n";
    }
};

void init_ex18(py::module &m) {
    py::class_<MIParent1>(m, "MIParent1")
        .def("virtualParent1", &MIParent1::virtualParent1)
        .def("nonvirtualParent1", &MIParent1::nonvirtualParent1)
        .def("virtualOverride", &MIParent1::virtualOverride);

    py::class_<MIParent2>(m, "MIParent2")
        .def("virtualParent2", &MIParent2::virtualParent2)
        .def("nonvirtualParent2", &MIParent2::nonvirtualParent2);

    py::class_<MIChild1>(m, "MIChild1", py::bases<MIParent1, MIParent2>())
        .def(py::init<>())
        .def("child1", &MIChild1::child1)
        .def("virtualOverride", &MIChild1::virtualOverride);
}
