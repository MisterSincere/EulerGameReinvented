# EulerGameReinvented

## How to setup (Linux)
1. Vulkan: `https://vulkan.lunarg.com/` provides information about how to setup vulkan
2. GLFW:
  - `git clone git@github.com:glfw/glfw.git`
  - `mkdir build`, `cd build`
  - `cmake ..`
  - for building: `make` or `cmake --build`
3. FreeType:
  - Check out this link!!!! `http://www.linuxfromscratch.org/blfs/view/svn/general/freetype2.html`

## How to setup (Windows)
1. Download the following third party libraries and set it to the specified environmental variable.
   1. ```EE_VULKAN_PATH```: https://vulkan.lunarg.com/sdk/home
   2. ```EE_GLFW_PATH```: https://www.glfw.org/
3. Clone the repository recursively: ```git clone --recursive <ThisRepoLink>```.\
   If you already have a cloned version without the submodules at all or they remain empty,\
   try ```git submodule update --init``` or ```git pull --recurse-submodule``` .
4. Start the GenerateSolution.bat file, which will lead you through some settings and creates the solution afterwards.\
   *You'll need cmake for the process to work (last tested version is 3.13.1) .*
5. A link to the EulerAdventureReinvented solution should be appear in your root folder after the batch opened Visual Studio.
6. Be Happy!
