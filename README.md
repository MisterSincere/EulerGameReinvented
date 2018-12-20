# EulerGameReinvented
## How to setup
1. Download the following third party libraries and set it to the specified environmental variable.
   1. ```ECA_SFML_PATH```: https://www.sfml-dev.org/download/sfml/2.5.1/
   2. ```EE_VULKAN_PATH```: https://vulkan.lunarg.com/sdk/home
   3. ```EE_GLM_PATH```: https://github.com/g-truc/glm/tags
   4. ```EE_GLFW_PATH```: https://www.glfw.org/
3. Clone the repository recursively: ```git clone --recursive <ThisRepoLink>```.\
   If you already have a cloned version without the submodules at all or they remain empty,\
   try ```git submodule update --init``` or ```git pull --recurse-submodule``` .
4. Start the GenerateSolution.bat file, which will lead you through some settings and creates the solution afterwards.\
   *You'll need cmake for the process to work (last tested version is 3.13.1) .*
5. A link to the EulerAdventureReinvented solution should be appear in your root folder after the batch opened Visual Studio.
6. Be Happy!
