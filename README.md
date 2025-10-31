# Basic Web Window made with Emscript!

## For this to work you will need:

- Cmake (latest version)
- Emscript - already setup with everything you need
- Make installed

- Open the terminal and type*:
````````````
     emcmake cmake -S . -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
````````````
*You may have to run the command twice

-- Then type these commands:

`````````````````
    emmake make -C build
    emrun build/Aaron.html