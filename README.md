![Splash](Resources/Splash.png)

# Mobile Utils

The **Mobile Utils** plugin lets you integrate out-of-the-box mobile utitilites for iOS & Android into your [Unreal Engine 4](http://www.unrealengine.com) project.

* **Current version:** 1.0
* **Binaries compiled for:** Unreal Engine 4.12.2
* **Required Unreal Engine 4.12 or above.**

## Features
* Checking internet connection availability
* Checking Google Play Services availability
* Works with dev & shipping builds
* Out-of-the-box for iOS & Android
* Additional SDK included
* Works with Blueprint-only & source code projects
* Works with Launcher & GitHub UE4 versions

Plugin icon designed by _Freepik_.

#Recommended PR pipeline
* Write java and/or Obj-C code in Android Studio or XCode depending on the platform(s) you wish to add functionality to
* Test your code with a very simple app setup on your Android or iPhone
* Integrate your code to the plugin **without** creating an interface to blueprints
* Create a new sample project and test your code on a packaged project, at your desired device and platform
* If everything works correctly, perform a Pull Request
* 
The reason that we prohibit you from creating a new blueprint node is to ensure cross platform compatibility as well as a uniform look and feel throughout the codebase. After your PR gets merged we will make sure that a new blueprint node is created if needed. We recommend trying to integrate your changes to the actual engine's master branch first and if your PR doesn't get merged, then resort to adding functionality to this plugin.

#Integration to the plugin
Here you will find the steps you need to take in order to add new functionality to this plugin.
##For Android
//todo
##For iOS
//todo
