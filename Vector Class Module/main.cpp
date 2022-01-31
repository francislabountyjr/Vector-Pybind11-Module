#include <pybind11/operators.h>
#include <pybind11/functional.h>

#include "vec3.h"

namespace py = pybind11;

PYBIND11_MODULE(vector_ops, m) {
	py::class_<Vec3<float>>(m, "Vec3")
		.def(py::init<float, float, float>())
		.def(py::self += py::self)
		.def(py::self -= py::self)
		.def(py::self *= py::self)
		.def(py::self /= py::self)
		.def(py::self += float())
		.def(py::self -= float())
		.def(py::self *= float())
		.def(py::self /= float())
		.def(py::self + py::self)
		.def(py::self - py::self)
		.def(py::self * py::self)
		.def(py::self / py::self)
		.def(py::self + float())
		.def(py::self - float())
		.def(py::self * float())
		.def(py::self / float())
		.def(float() + py::self)
		.def(float() - py::self)
		.def(float() * py::self)
		.def(float() / py::self)
		.def(-py::self)
		.def(py::self == py::self)
		.def(py::self != py::self)
		.def("__abs__", &Vec3<float>::absolute)
		.def("__str__", &Vec3<float>::toString)
		.def("__repr__", &Vec3<float>::toString)
		.def("dot", &Vec3<float>::dot)
		.def("cross", &Vec3<float>::cross)
		.def("magnitude", &Vec3<float>::magnitude)
		.def("angle", &Vec3<float>::angle)
		.def("direction", &Vec3<float>::direction)
		.def("project", &Vec3<float>::project)
		.def_readwrite("x", &Vec3<float>::x)
		.def_readwrite("y", &Vec3<float>::y)
		.def_readwrite("z", &Vec3<float>::z);
}