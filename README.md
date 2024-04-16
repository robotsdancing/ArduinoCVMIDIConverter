# ArduinoCVMIDIConverter
This is a MIDI/CV converter I made using an Arduino for synthesizers using Hz/V. It uses callbacksin the Arduino MIDI library to then generate a tone and voltage(using tone() and FastPWMDac) to trigger notes on a synthesizer as well as tell the synthesizer what notes to play. Be warned that this only works with synthesizers that trigger notes via external audio input and this does not comply to Yamaha's standard for CV/Gate on the Yamaha CS-5(which is the synthesizer this was tested with/originally made for) 


How to Use:
1. Download the Hairless MIDI bridge, and a virtual MIDI port(I used loopMIDI, which is recommended by Hairless).
  Hairless MIDI site:http://projectgus.github.io/hairless-midiserial/
  loopMIDI site: https://www.tobias-erichsen.de/software/loopmidi.html
2. Upload arduino code(CVMIDIConverter.ino) to arduino, and attach 1/4"("Guitar cable") mono jacks for tone output and CV output.
  The tone output I have set up with a 100 Ohm 5% resistor, you can toy around with different resistor values if you so choose, it might affect the trigger levels on a synthesizer though. The resistor I soldered in line with the wire for the output pin(pin 6).
  The jack for CV output is a bit more complicated of a circuit, which is described here(http://bit.ly/2v6xoc7) for the most part but I made some changes(most noteably to have two grounds, one of them is the ground for the 1/4" mono jack and the other is the ground for the capacitor, photos will be uploaded to reference my somewhat dubious quality soldering/circuit skills).
3. Set up MIDI output in favorite DAW to the virtual MIDI port you used, run Hairless MIDI bridge, and connect the audio output to the audio input of the synthesizer, and the CV output of the Arduino to the CV input of the synthesizer.
4. Adjust the input trigger settings.
  For my synthesizer(a Yamaha CS-5) notes can be triggered via external audio input, as well as on some other synthesizers. For a Yamaha CS-5 it requires the trigger level to be dropped down pretty low(about between 0 and 1 out of 10) for it to trigger reliably. This triggering may be different based on different synthesizers and if one chooses to use a different resistor for the tone output.

Ideas for changes:
1. Usage with other synthesizers:
  Since this was originally designed for use with a Yamaha CS-5 it may not work entirely the same with other synthesizers that use Hz/V(such as the Korg MS-20,Korg MS-10 or any duophonic functionality that the Yamaha CS-15 and CS-30/30L have) and I recommend that if anyone is intending to use this with a different Hz/V synthesizer to branch the project and change things so that they are more functional with your specific synthesizer.
2. Testing different resistor values for the tone output:
  The tone output is not very loud, or as some people refer to "hot", as other sources of audio, so I will test different resistors in the tone circuit, first with headphones to make sure that it isn't loud enough to cause issues, and then with the synthesizer to find a happy medium of amplitude for the triggering audio without causing distortion of the source audio.
3. Changing DAC circuitry:
   The DAC circuitry may also be changed if I can find anything that will have a smaller amount of delay and higher resolution.
