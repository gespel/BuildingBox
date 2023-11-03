import Synths
import pyaudio
import array
import ctypes

sb = Synths.SynthBox(48000, 1024)
s1 = Synths.SineSynth(440, 48000)

sb.addSynth(s1)

while True:
    print(sb.getBuffer())