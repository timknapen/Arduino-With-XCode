
### This is the Arduino on XCode 4 help file ###

This is not a real "XCode Template". It is an empty project to start from. 
Just copy the whole folder, give it another name and start working with it this way.
    
This project is for Arduino.app version 0022 !!!
The 1.0 version has had a few changes internally that break the makefile included here (I think)

The preferred place for help, discussion and suggestions is here:
[http://arduino.cc/forum/index.php/topic,49956.0.html](http://arduino.cc/forum/index.php/topic,49956.0.html)


###	Quickstart

To build select target "Build Arduino" and press "Run"
To build and upload select target "Build and Upload" and press "Run"
    
Make sure you the right board setup before uploading:
go to the Project Navigator (aka source tree) and click the project name at the top.
In the middle window click on the project name under "Project"
Click the "Info" tab (next to Build Settings)
Under "Configuration" click the triangle next to "Release" to make it fold open. 
Then fold open the project to see the "Build" , "Clean" and "Build and Upload" targets.
Select your board in the "Based on Configuration File" next to each target.

WARNING it appears that you can't compile the .cpp files included in Arduino.app when it is inside /Applications/
I assume this is because Lion has new permissions for the Applications/ folder.
Suggested solution: move Arduino.app out of /Applications/ into a folder you have full read/write access to.
You will have to change the build setting called 'ARDUINO_APP_PATH' to the correct new path. 
Or you change the permissions of Arduino.app to allow everyone read/write access.
To do this, you can go to Arduino.app, right click > Show Package Contents,
Right click on Contents > Show Info. Then scroll down to "Sharing and Permissions" and set everybody's persmissions to Read & Write.
And choose "Apply to enclosing items" from the gear drop-down.

###	LIBRARIES
	
All the standard libraries included in Arduino.app are already included in the build settings.
    
    

###	To add another library: ###

1.	Drag the folder containing the library's .cpp and .h file onto XCode's project tree.
	A dialog pops up asking you about the way you want to add this folder.
	Uncheck "Copy items into destinations group's folder (if needed)".
	Click "Add"

2.	Get the absolute path to this folder
	
3.  Click on the project in the Project Navigater and open the tab "Build Settings"
	In the "value" field for "LIBRARY_PATHS", type Full path you just copied.
	LIBRARY_PATHS is a space separated list. At the moment the paths in this list can't contain spaces.
	Don't try to add quotes around those paths, it won't work... Make has horrible problems with paths that contain spaces :-(
	(see here for more about that nonsense: http://www.cmcrossroads.com/ask-mr-make/7859-gnu-make-meets-file-names-with-spaces-in-them )
	Are also not allowed: paths that have ~/yourFolder instead of /Users/myUserName/yourFolder
	Paths should NOT end with a slash.


### FEEDBACK ###

Is this not clear enough? Should we include something else? Can you help us make this project better?
Let us know at the Arduino Forum! 
http://arduino.cc/forum/index.php/topic,49956.0.html
