/*
class SynthBox {
public:
    SynthBox(int sampleRate);
    void addSynth(Synth* input);
    std::vector<double> getBuffer();


private:
    std::vector<Synths> synths;

};
*/

#include "BuildingBox.h"

SynthBox::SynthBox(int sampleRate, int bufferSize) {
    this->sampleRate = sampleRate;
    this->bufferSize = bufferSize;
}

void SynthBox::addSynth(Synth& input) {
    this->synths.push_back(dynamic_cast<Synth*>(&input));
}

std::vector<double> SynthBox::getBuffer() {
    std::vector<double> out;
    for(int i = 0; i <= this->bufferSize; i++) {
        double currSample = 0;
        for(auto s : this->synths) {
            currSample += s->getSample();
        }
        out.push_back(currSample);
    }
    return out;
}
