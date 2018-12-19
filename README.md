# EulerGameReinvented
## How to setup
1. Download SFML https://www.sfml-dev.org/download/sfml/2.5.1/ and set an environmental variable named ```ECA_SFML_PATH``` to
   the root    directory of SFML
3. Clone the repository recursively: ```git clone --recursive <ThisRepoLink>```.\
   If you already have a cloned version without the submodules at all or they remain empty,\
   try ```git submodule update --init``` or ```git pull --recurse-submodule``` .
4. Start the GenerateSolution.bat file, which will lead you through some settings and creates the solution afterwards.\
   *You'll need cmake for the process to work (last tested version is 3.13.1) .*
5. A link to the EulerAdventureReinvented solution should be appear in your root folder after the batch opened Visual Studio.
6. Be Happy!
