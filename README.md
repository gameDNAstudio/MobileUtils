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
At /Source/MobileUtils/MobileUtils_APL.xml,
Add your tested java code:

* At <gameActivityImportAdditions>
		<insert>,
		insert your import(s) (check first if they do not exist on the GameActivity, at the actual engine).
* At <gameActivityClassAdditions>
		 <insert>,
		 insert your new methods. They should have the prefix "AndroidThunkJava_".

At /Source/MobileUtils/Private/Android/MobileUtilsPlatform.h,
Start integrating your code into the plugin:

* Declare your jmethodID(s) as well as function(s) with the appropriate names.

At /Source/MobileUtils/Private/Android/MobileUtilsPlatform.cpp,
Continue your integration:
* On the constructor, initialize that jmethodID you specified with FindMethod.
* Add your previously specified function along with the implementation like the other functions on that file.

And now, some extra intel. Do not be afraid to open up the source of Unreal and look into the Android related parts of the system as well as pull requests that add features to the android part. You can find more information about JNI method signatures [here!](http://www.rgagnon.com/javadetails/java-0286.html)

##For iOS
//todo
