# Umzimba Movement
Umzimba Movement is a multiplayer game for people with autism. It uses the Microsoft Kinect V2 to track a players hands and allow them to express themselves visually.
The game contains one game with two minigames, a bubble popping game and a painting game.

## Downloading and Running the Game
### Dependencies
* [Microsoft Kinect SDK 2.0](https://www.microsoft.com/en-us/download/details.aspx?id=44561)

### Instructions
* Make sure the Kinect SDK is correctly installed
* Download the latest release from [here](https://github.com/Seanie96/KinectMultiplayerGame/releases)
* Unzip the download to a folder
* Run *KinectBodyIndex.exe*

## Building From Source
### Dependencies
* [Vistual Studio 2015](https://www.visualstudio.com/downloads/)
* [OpenFrameworks](https://github.com/openframeworks/openFrameworks)
* [Microsoft Kinect SDK 2.0](https://www.microsoft.com/en-us/download/details.aspx?id=44561)
* [ofxKinectForWindows2](https://github.com/elliotwoods/ofxKinectForWindows2)
** Fix for latest version [here](https://github.com/elliotwoods/ofxKinectForWindows2/issues/76)

### Building
* Clone the repo into *openframeworks/apps/myApps/*
* Clone ofxKinectForWindows2 into *openframeworks/addons/*
* Open the KinectBodyIndex Visual Studio Solution file located in *KinectMuliplayerGame/KinectBodyIndex/*
* Right click the KinectBodyIndex solution in Visual Studio and Add > Existing Project
* Add the ofxKinectForWindows2 project inside *openframeworks/addons/ofxKinectForWindows2/ofxKinectForWindows2Lib/*
* In Property Manager in Visual Studio click Add Existing Property Sheet and add the property sheet inside *openframeworks/addons/ofxKinectForWindows2/*
* In the KinectBodyIndex solution, right click References and Add Reference, tick *ofxKinectForWindows2Lib*
* In Visual Studio under *src/Games/BubbleGame/Resources/* right click on *pop_sound.mp3* > Properties and change item type to Media
* Under *src/Games/BubbleGame/Resources/Fonts* right click on *AYearWithoutRain.ttf* > Properties and change item type to Font
* Build and run the program
