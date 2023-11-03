g++ -shared -fPIC $(/home/stenh/mainvenv/bin/python -m pybind11 --includes) wrapper.cpp Synths.cpp BuildingBox.cpp -o Synths.cpython-311-x86_64-linux-gnu.so
