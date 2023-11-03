#include <vector>
#include "Synths.h"


class SynthBox {
public:
    SynthBox(int sampleRate, int bufferSize);
    void addSynth(Synth& input);
    std::vector<double> getBuffer();


private:
    std::vector<Synth*> synths;
    int sampleRate;
    int bufferSize;
};