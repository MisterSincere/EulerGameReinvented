# EulerGameReinvented
## How to setup the CppVersion
1. Download SFML https://www.sfml-dev.org/download/sfml/2.5.1/
2. Create an environmental variable named ECA_SFML and set it to the root directory of SFML\
2.5 If you don't have CMake download it https://cmake.org/download/
3. In the CppVersion folder (with the CMakeLists.txt) call cmake -G "Visual Studio 15 2017 Win64". The configuration of Visual Studio is of course modifable, but it is made for Visual Studio. To see other options type cmake --help
4. Open the now created EulerAdventure.sln
5. Be Happy!
