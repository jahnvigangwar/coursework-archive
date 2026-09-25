# pip3 install SpeechRecognition
# pip3 install pyttsx3
# pip3 install playsound

# https://stackoverflow.com/questions/73268630/error-could-not-build-wheels-for-pyaudio-which-is-required-to-install-pyprojec
# brew install portaudio
# brew link portaudio
# brew --prefix portaudio
# sudo nano $HOME/.pydistutils.cfg
# [build_ext]
# include_dirs=/usr/local/opt/portaudio/include/
# library_dirs=/usr/local/opt/portaudio/lib/
# pip3 install pyaudio
 
# pip3 install virtualenv

import speech_recognition as sr
import pyttsx3
import pyaudio

r = sr.Recognizer()
def speak(cmd):
    engine = pyttsx3.init()
    engine.say(cmd)
    engine.runAndWait()

with sr.Microphone() as source2:
    r.adjust_for_ambient_noise(source2,duration=0.1)
    print("speak now")
    audio2 = r.listen(source2)
    MyText = r.recognise_google(audio2)
    print("recording done")
    MyText = MyText.upper()
    print("you said " + MyText)
    speak(MyText)


    # app kholna hai 

    # signals to digital with features conversion 
    # graphs 
