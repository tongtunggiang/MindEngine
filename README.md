# MindEngine
The mind engine for non playable characters (NPCs). It allows these characters to think, to consider choices based on their current view of the world.

# Installation
> Note
> - Doxygen and LaTeX tool should be installed to get the documentation.

For Windows
- Pull the repo to your own local machine.
~~- Use Cmake GUI tool for generating project files with your choice of IDE (Visual Studio recommended).~~
- Open the MindEngine.sln solution file.

For Linux
- Pull the repo to your own local machine.
- Use Cmake-supported IDE for opening the CMakeLists.txt project (QTCreator, Kdevelop, CodeLite,..)

# Build instruction
In order to get full documentation (which is generated automatically with Doxygen), these build steps are needed:
- Build all C++ code files in the project (with Cmake).
- Clean the Docs folder then run doxygen command to generate HTML and LaTeX source files.
- Run the makefile in side the ./Docs/latex directory to get the PDF documentation.
This is the build steps that are used in QTCreator: 
![Alt text](http://i.imgur.com/2WEKehh.png)
