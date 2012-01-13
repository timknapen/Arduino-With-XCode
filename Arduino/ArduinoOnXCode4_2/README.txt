*   Jan 13, 2012 — simplification


### This is the Arduino on XCode 4 help file ###

	The preferred place for help, discussion and suggestions is here:
	http://arduino.cc/forum/index.php/topic,49956.0.html


### General Structure

*   I get rid of ArduinoProgram.h successfully.
*
*   In main.cpp, change 
*       #include "ArduinoProgram.cpp"
*   for
*       #include "ArduinoProgram.cpp"
*
*   The only consequence is you need to define a function BEFORE calling it.
*   Declaring protoypes at the beginning of ArduinoProgram.cpp for all the functions is another solution.


###	Quickstart

	To build select target "Build Arduino" and press "Run"
	To build and upload select target "Build and Upload" and press "Run"
    
    Make sure you the right board setup before uploading:
    go to the Project Navigator (aka source tree) and click the project name at the top.
    In the middle window click on the project name under "Project"
    Click the "Info" tab (next to Build Settings)
    Under "Configuration" click the triangle next to "Release" to make it fold open. 
    Then fold open the project to see the "Build" and "Build and Upload" targets.
    Select your board in the "Based on Configuration File" next to each target.


###	LIBRARIES
	
	All the standard libraries included in Arduino.app (both C and C++) are already 
    included in the makefile. 
	You just need to #include them like you normally would.


###	To add another library:

*   If the library is in the <YourProjectName>/source folder, you only need step 1.: 
*   - drag the .h and .cpp files 
*   OR
*   - contect menu Add Files to <YourProjectName>


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


### Known Bugs and Missing Features

*   No console
*   No tooltips for user created items
*   No syntax colouring for user created items
*   No Xcode 4 template
*
*   I guess all the mentionned limitations are linked to Xcode configuration.
*   Help would be greatly appreciated.


### FEEDBACK
	Is this not clear enough? Should we include something else? Can you help us make this project better?
	Let us know at the Arduino Forum! 
	http://arduino.cc/forum/index.php/topic,49956.0.html
