#include <pybind11/pybind11.h>
#include "Synths.h"
#include "BuildingBox.h"

namespace py = pybind11;

/*
public:
    SynthBox(int sampleRate, int bufferSize);
    void addSynth(Synth* input);
    std::vector<double> getBuffer();


private:
    std::vector<Synth*> synths;
    int sampleRate;
    int bufferSize;
};
*/


PYBIND11_MODULE(Synths, m) {
    py::class_<SineSynth>(m, "SineSynth")
        .def(py::init<double, double>())
        .def("getSample", &SineSynth::getSample)
        .def("setFrequency", &SineSynth::setFrequency, py::arg("double"));

    py::class_<SawtoothSynth>(m, "SawtoothSynth")
        .def(py::init<double, double>())
        .def("getSample", &SawtoothSynth::getSample)
        .def("setFrequency", &SawtoothSynth::setFrequency, py::arg("double"));

    py::class_<SquareSynth>(m, "SquareSynth")
        .def(py::init<double, double>())
        .def("getSample", &SquareSynth::getSample)
        .def("setFrequency", &SquareSynth::setFrequency, py::arg("double"));
    py::class_<WavetableSynth>(m, "WavetableSynth")
		.def(py::init<double, double, int>())
		.def("getSample", &WavetableSynth::getSample)
		.def("setFrequency", &WavetableSynth::setFrequency, py::arg("double"))
		.def("setWavetable", &WavetableSynth::setWavetable)
		.def("generateRandomWavetable", &WavetableSynth::generateRandomWavetable);
    py::class_<SynthBox>(m, "SynthBox")
        .def(py::init<int, int>())
        .def("addSynth", &SynthBox::addSynth)
        .def("getBuffer", &SynthBox::getBuffer);




}