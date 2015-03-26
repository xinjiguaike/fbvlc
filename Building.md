# Building fbVLC #
This guide is for building under Windows with Visual Studio Express 2010.  This should work with the full version of Visual Studio as well.

# Requirements #


All these must be installed _before_ proceeding to the build instructions.

**CMake** version 2.8.7 or later: http://www.cmake.org/cmake/resources/software.html
Make sure to grab the Binary distribution (cmake-ver-win32-x86.exe)
When asked, tell the installer to add cmake to your system path

**Visual Studio** 2005, 2008, or 2010 (full or express versions)

**WDK** 7.1 or later from Microsoft: http://www.microsoft.com/en-us/download/details.aspx?id=11800
> Select the "Build Environments" option
> This will install the ATL and MFC header and lib files. ATL is a requirement for FireBreath on windows. Make sure to install this in the default location so that FireBreath can find it

**Git** (if you want to check out from source): http://git-scm.com/
http://code.google.com/p/gitextensions/Git is a fantastic Git GUI for windows that comes with Git binaries

**WiX** (creates the .msi file): http://wix.codeplex.com/downloads/get/204417

**VLC** (Windows installer, not the source): www.videolan.org

**FireBreath source:** http://www.firebreath.org/display/documentation/Download

**fbVLC source:** https://code.google.com/p/fbvlc/source/checkout

**Correct VLC library:** http://code.google.com/p/vc-libvlc/downloads/list
Get the version which matches your VLC version.  After you install VLC, replace /sdk/lib/libvlc.lib in the VLC install directory with this version.

# Build Procedure #
I'll assume you installed the FireBreath sources to c:\src\firebreath.  Substitute whatever path you used.  Substute your VLC install path for <vlc install dir>.


Add the VLC install directory to your system Path variable.

Copy the fbVLC source directory to your FireBreath source directory.  We'll use c:\src\firebreath\fbvlc\ for example.

If you want to include VLC in the fbVLC installer, copy the VLC install folder to c:\src\firebreath\fbvlc\Win\WiX\vlc-2.0.3 (assuming you grabbed VLC 2.0.3).

In c:\src\firebreath run _prep2010.cmd fbvlc fbbuild_.  This creates a whole bunch of files in c:\src\firebreath\fbbuild.
> Note: you must have WiX installed before this step

Open c:\src\firebreath\fbbuild\FireBreath.sln.  You should have the following projects (among others): FBVLC, FBVLC\_WITH\_VLC\_WiXInstall (only if you coped the VLC folder into Wix/ in the step above), and FBVLC\_WiXInstall.

Right-click on the FBVLC project and add <vlc install dir>/sdk/include directory to _C/C++ -> Additional Include Directories_.  Add <vlc install dir>/sdk/lib directory to _Linker -> Additional Library Directories_

Build the ALL\_BUILD project.

If everything worked you should have two .msi files in c:\src\firebreath\fbbuild\bin\FBVLC\Release: one for just the fbVLC install and one which includes portions of VLC.