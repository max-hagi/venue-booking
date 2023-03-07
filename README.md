# venue-booking
Provides users and businesses a lightweight interface to manage reservations

Running the Project:

	1. Find the path QT is installed on your computer
	2.  Go to “qt/6.3.2/lib/QtWidgets.framework/Versions/A/Headers“ and copy the pathname (use “find” in command line)
	3. Type “qmake -project” in the command line of the project
	4. Go into the .pro file that was generated and put the copied pathname after INCLUDEPATH +=
	5. Add “QT += widgets” and “LIBS += -lsqlite3” after the INCLUDEPATH
	6. Ensure that all the headers and cpp files are all in their respective sections of the .pro file (headers/sources)
	7. In the project command line type "qmake" then “make”
	8. An executable will be generated and have the same name as the .pro file

**NOTE** When logging in as a user, the credentials username:abcd and password:1234 work
**NOTE** When logging in as a business account, the credentials username: ben and password:1 work 
