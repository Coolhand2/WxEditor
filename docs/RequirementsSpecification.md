Requirements Specification
===
Introduction
---
This section introduces the requirement specification document for the wxEditor application. It provides the purpose and scope of the system. Any definitions and references are listed in this section as well as an overview of the remaining requirements specification document.

### Purpose
This requirements specification document describes the functions and requirements specified for this wxEditor application. This application is needed to allow uses to create, read, and update, simple text files. In order to make this possible, the system utilizes the basic file loading and saving utilities provided by WxWidgets, along with the GUI utilities also provided by WxWidgets.

### Scope
The application will allow users to quickly open, edit, and save both pre-existing and brand new simple text files.

### Definitions, Acronyms, Abbreviations

| Word | Description |
|-|-|
| None At this Time | |

### References
Michael Sherwood, Software Engineering
Michael Sherwood, Manager
Michael Sherwood, User

IEEE 830:1998 - IEEE Recommended Practice for Software Requirements Specifications

https://www.slideshare.net/indrisrozas/example-requirements-specification - Example Requirements Specification Document for Ambulance Dispatch Service.

### Overview
This document provides a high-level description of the wxEditor application. It identifies the involved users and helps explain their roles. The document then describes general software and hardware constraints as well as any assumptions and dependencies concerning the system. The majority of this document focuses on the specific requirements list. A master list of specific requirements is given first, followed by each requirement explained in detail in the next section. The external interfaces are addressed in the subsequent section. External interface requirements are requirements involved user hardware, software and communications interfaces. This requirements document concludes with general design constraints specified by the customer along with the business requirements this software must meet.

General Description
---
This section is used to provide a high-level description of the system, as well as identify the users involved and help explain their roles.

### System Functions
The wxEditor application shall help ensure text files are edited quickly and effectively in order to reduce file corruption and user confusion. To facilitate these needs, the system shall allow users to specify a file to open, even if that file does not exist. The system shall keep track of the file name and location, and utilize those faculties to ensure the file, upon save, is placed in the correct location on the file directory. If a new file is opened (specified as a text file that does not exist at time of action), the system will utilize the last-known save location of the current session, to set the first directory that the user will be offered to save to, but will leave the file name field blank in order for the user to specify it. The last-known save location will default to the user's home directory, if it is the first save of the applications session. The application will not save a file with an empty (string length = 0) or blank file name (a string with only white space or un-printable control characters.) 

### User Characteristics
There are two groups of user who will use the application. The first group of users are the System Administrators. They are concerned with editing system-related files that will affect either the entire Operating System, or a specific application running on the operating system.  This group has the highest computer skill set and is capable of maintaining a workstation. Their interaction with the application is not limited, and can ruin the workstation if this application is not used with caution.

Normal users make up the second group. These users do not have Administrator permissions on the workstation, and will not be allowed to edit documents they do not own. To enforce this, the application will not let users edit documents outside of their own home directory. Users in this group interacting with the application leaves the workstation in a safe position as they will not be able to accidentally edit any system-specific files.

General Constraints
---
### Software Limitations
- System shall need Windows 10 installed. 
- VisualStudio 2019 with the WxWidgets props file shall be used in the development of the application.

### Hardware Limitations
- Each user will need a workstation capable of running Microsoft Windows 10.

Assumptions and Dependencies
---
The application assumes that the users have adequate skill with using computers and computer software.

It is assumed that the customers have a sufficient number of workstations in quantity at least one per user.

Requirements Master List
---
This section contains the listing of all requirements for the wxEditor application. The list contains unique requirement numbers and names with a short description of each requirement. The following section describes these requirements in full detail.

**REQ 1:** Open an Existing Text File - Allows the user to select an existing text file to open for editing, closing the current one (if any)

**REQ 2:** Open a New Text File with no File Name specified - Allows the user to close the current file (if any) and start a new file with no name and no content.

**REQ 3:** Open a New Text File with a File Name specified - Allows the user to close the current file (if any) and start a new file with a specific name and no content.

**REQ 4:** Save Existing File under same File Name in the same Directory Location - Allows the user to save their changes to a file, without specifying a new name or new directory. Overwrites existing file with new contents.

**REQ 5:** Save Existing File under new File Name in the same Directory Location - Allows the user to save their changes to a file, while specifying a new name, but not a new directory. Overwrites existing file with new contents if necessary, and if given permission.

**REQ 6:** Save Existing File under same File Name in a new Directory Location - Allows the user to save their changes to a file, without specifying a new name, but with a new directory. Overwrites existing file with new contents if necessary, and if given permission.

**REQ 7:** Save Existing File under new File Name in a new Directory Location - Allows the user to save their changes to a file, while specifying a new name, and a new directory. Overwrites existing file with new contents if necessary, and if given permission.

**REQ 8:** Close an Unsaved File, Declining Prompt for Saving before Closure - Allows the user to discard their changes to a file when closing it.

**REQ 9:** Close an Unsaved File, Accepting Prompt for Saving before Closure - Allows the user to save their changes to a file when closing it.

**REQ 10:** Close a Saved File without a Prompt for Save - Allows the user to close their file without a prompt for saving due to it being unnecessary.

**REQ 11:** Open a Text-based file for Editing - Allows the user to open a text-based file for editing, but will not guarantee efficiency of editing or understanding for that file.

**REQ 12:** Default character encoding of UTF-8 - Allows the user to open a text-based file for editing in any language, and recieve support for the majority of symbols of many languages available around the world.

Requirements Detail
---

### REQ 1: Open an Existing Text File
#### Description
Allows the user to select an existing text file to open for editing, closing the current one (if any)

#### Input
The user shall use an "Open File" dialog box to browse the Windows File System Directory Structure to find a specific directory location, to be combined with a specified file name to complete an absolute path that the application will then use to read the file into memory and ready for display.

#### Display
The "Open File" dialog box provided by WxWidgets will be utilised to achieve the goal of selecting a file to open.

#### Application Processing
The application is considered idle during the process of selecting a file to open.

Once the user clicks the "Open" button, the system determines if the user has permissions to open the file they have specified. If the user has not selected an appropriate file, the application shall alert the users. The application shall display an error message stating that they are not allowed to open a file outside of their home directory. The user will then be able to select either the same, or a different file. The next file they select will repeat this process of checking until they have found a file that is within their home directory.

A user in the Administrative Users group will not be faced with this restriction.

Once the file selected passes the restriction criteria, if any are present, the contents of the file will be displayed to the screen in such a manner as to allow the user to edit it.

#### Application Output
The application will display an error whenever a user in the Normal Users group attempts to open a file outside of it's own home directory. 

Once the user has clicked the "Open" button, and the information is correct, the contents of that file will be extracted and displayed in the Text Area on screen, giving the user an ability to edit the contents of the file at their will.

#### Other
N/A

#### Constraints
For users in the Normal Users group, they will not be allowed to open any text-based files outside of their home directory.

For users in the Administrative Users group, they will not be restricted from opening any text-based file on the system.

#### Data Handling
The name specified for the file being opened will be saved for the Quick Save option specified in REQ 4.

The directory location for the file being opened will be saved for use in the following requirements: REQ 2, REQ 3, REQ 4, and REQ 5.

### REQ 2: Open a New Text File with no File Name specified
 - Allows the user to close the current file (if any) and start a new file with no name and no content.
#### Input


#### Display


#### Application Processing


#### Application Output


#### Other


#### Constraints


#### Data Handling


### REQ 3: Open a New Text File with a File Name specified
 - Allows the user to close the current file (if any) and start a new file with a specific name and no content.
#### Input


#### Display


#### Application Processing


#### Application Output


#### Other


#### Constraints


#### Data Handling


### REQ 4: Save Existing File under same File Name in the same Directory Location
 - Allows the user to save their changes to a file, without specifying a new name or new directory. Overwrites existing file with new contents.
#### Input


#### Display


#### Application Processing


#### Application Output


#### Other


#### Constraints


#### Data Handling


### REQ 5: Save Existing File under new File Name in the same Directory Location
 - Allows the user to save their changes to a file, while specifying a new name, but not a new directory. Overwrites existing file with new contents if necessary, and if given permission.
#### Input


#### Display


#### Application Processing


#### Application Output


#### Other


#### Constraints


#### Data Handling


### REQ 6: Save Existing File under same File Name in a new Directory Location
 - Allows the user to save their changes to a file, without specifying a new name, but with a new directory. Overwrites existing file with new contents if necessary, and if given permission.
#### Input


#### Display


#### Application Processing


#### Application Output


#### Other


#### Constraints


#### Data Handling


### REQ 7: Save Existing File under new File Name in a new Directory Location
 - Allows the user to save their changes to a file, while specifying a new name, and a new directory. Overwrites existing file with new contents if necessary, and if given permission.
#### Input


#### Display


#### Application Processing


#### Application Output


#### Other


#### Constraints


#### Data Handling


### REQ 8: Close an Unsaved File, Declining Prompt for Saving before Closure
 - Allows the user to discard their changes to a file when closing it.
#### Input


#### Display


#### Application Processing


#### Application Output


#### Other


#### Constraints


#### Data Handling


### REQ 9: Close an Unsaved File, Accepting Prompt for Saving before Closure
 - Allows the user to save their changes to a file when closing it.
#### Input


#### Display


#### Application Processing


#### Application Output


#### Other


#### Constraints


#### Data Handling


### REQ 10: Close a Saved File without a Prompt for Save
 - Allows the user to close their file without a prompt for saving due to it being unnecessary.
#### Input


#### Display


#### Application Processing


#### Application Output


#### Other


#### Constraints


#### Data Handling


### REQ 11: Open a Text-based file for Editing
 - Allows the user to open a text-based file for editing, but will not guarantee efficiency of editing or understanding for that file.
#### Input


#### Display


#### Application Processing


#### Application Output


#### Other


#### Constraints


#### Data Handling


### REQ 12: Default character encoding of UTF-8
 - Allows a user to open a text-based file for editing in any language, and recieve support for the majority of symbols of many languages available around the world.
#### Input


#### Display


#### Application Processing


#### Application Output


#### Other


#### Constraints


#### Data Handling


External Interface Requirements
---
This section shall describe the interface requirements for the wxEditor application. They specify the way the user shall interact with the system as well as define the necessary hardware interfaces and communication interfaces required by the application to store and retrieve data.

### User Interfaces
The user interface shall follow basic Windows style functionality conventions. The interface has a title bar as part of the window border, menu bar at the top of the window, and a status bar at the bottom. Scroll bars will appear on the right and bottom side as necessary to ensure overflow text outside of the current visible area can be made viewable.

The title bar will display the name of the currently open text file, or the text "Unnamed File" if an unnamed file has been opened. The title bar will also help communicate whether a file has been changed from it's originally loaded contents by displaying an asterisk (*) at the end of the file name once a change has been made to the contents, only to be removed upon a saving of the new content set.

In the menu bar, there will be one Menu with 6 options. The one menu will be titled "File".

The first option called "New" will close the current file (if any is currently open), emptying the text area of content, and clear out the last saved file name (if any is present), in accordance with REQ 2.

The second option, called "Open" will close the current file (if any is currently open), display the "Open File" dialog, and allow the user to navigate to a directory location and select either an existing file, in accordance with REQ 1, or specify a new file name to open, in accordance with REQ 3.

The third option, called "Save" will allow the user to save the contents of the currently open file in the same location in accordance with REQ 4.

The fourth option, called "Save As" will allow the user to save the contents of the currently open file in a new location in accordance with REQ 4, REQ 5, REQ 6, and REQ 7.


The fifth option, called "Close" will allow the user to close out the file, whilst giving them the option to save that file in accordance with REQ 8, REQ 9, and REQ 10.

The sixth option, called "Exit" will allow the user to close out of the application completely, whilst giving them the option to save any open file in accordance with REQ 8, REQ 9, and REQ 10.

The status bar at the bottom of the window will display two pieces of information: The current (X,Y) position of the cursor within the file, and the file encoding.

### Hardware Interfaces
The application can run on any hardware that can support Windows 10. The system must have a minimum of 100 Megabytes of free disk space to install the program. Between 100 Megabytes of Memory is required to load the application, but will require more depending on the size of file the user decides to open, as its contents will be loaded into memory. All file information is stored on the workstations hard drive.

### Software Interfaces
The system requires a properly configured version of Windows 10 to run the application.

### Communications Interfaces
None. This application will not communicate with any remote objects for any reason.

General Design Constraints
---
The customer requested an application that can open and edit text-based files. They have not specified graceful handling of non-text-based files. If a user attempts to open a binary file, the application will display the contents in a human readable format. We do not guarantee the human reading the file will be able to understand it on their own.

The customer also wishes to limit the users in the Normal Users group to help keep the contents of their workstation secure and free from meddling.

