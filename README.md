# SOFT20091-SDI

___Built on QT Framework V5.14.1 so may need to install v5.12 or later to build properly___
	**Update: 11.03.20:- May no longer build on v5.1.0 due to mouse events if the mouse needs to be handled directly: https://doc.qt.io/qt-5/qmouseevent.html#QMouseEvent-3**

___The Project may run into linking errors and not build correctly in Visual Studio without the QT VS Tools addon___

# todo 
 * __Fix Layout to be more faithful to the GUI mockup__ -_(Progress: 60%)_
 * __Add treeView dialog for img file browsing and access__ -_(Progress: 80%)_
	* add native methods of sorting and organising ItemModels without relying on explorer
 * __Add Framebuffer for image rendering/drawing for backend OpenCV functionality__
 * __Add versioning__
 * __Add documentation__
 	* Code Style and Contribution guides
 * __Add Ci and unit testing integration__
 	* An easily accesible CI tool for begginers such as CircleCi may be a good fit
 * __Split MainWindow betwen various SubWidgets__ _(QSplitter Class may be usefull for this)

 * __Allow portable binaries to be compiled with seperate .Dll dependancies to allow execution without a Qt Installation__ *
 # Secondary
	Add theme support for improved Aesthetics?
	Fix project structure
	Display modes for FileSystem
	
	
# .Misc
	Build tests for other platforms (OSX, Linux e.g.)
	Configuration options
	WidgetTabs 