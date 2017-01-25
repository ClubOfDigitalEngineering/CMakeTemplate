# cmakeTemplate
This repository is a common template for c++ projects with cmake.

## folder structure

**applications**
- every folder generate a lib or an executable
- the main is placed here
- every folder contains a CMakeList.txt with applications details like links and includes

**cmake**
- cmake macros to handle the project

**src**
- contains source code

**examples**
- AllTest
- Boost
- Cuda
- GMock
- Lib
- LibTest
- Qt
- VTK


## platforms
- this project is used by:
  - visual studio 2013
  - visual studio 2015
  - unix makefile
  - Xcode
  - clion
