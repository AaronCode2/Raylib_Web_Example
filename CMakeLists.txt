cmake_minimum_required(VERSION 3.28)
project(Tutorial)

# --- Force Web platform if EMSCRIPTEN detected ---
if(EMSCRIPTEN)
message(STATUS "Building for Web (HTML5) using Emscripten")
    set(PLATFORM "Web")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    # Set any Emscripten-specific flags
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s INITIAL_MEMORY=67108864 -s ALLOW_MEMORY_GROWTH=1")
endif()

# --- Raylib dependency ---
include(FetchContent)
set(RAYLIB_VERSION 4.2.0)

FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
)

set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

# --- Source files ---
set(SOURCE_FILES
    src/main.cpp
)

# --- Create executable ---
add_executable(Tutorial ${SOURCE_FILES})

# --- Link Raylib ---
target_link_libraries(Tutorial raylib)

# Do this if you are using Assets!

# if(EMSCRIPTEN)
#     set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")
#     if(EXISTS ${ASSETS_DIR})
#         message(STATUS "Preloading assets from: ${ASSETS_DIR}")
#         set_target_properties(Aaron PROPERTIES
#             LINK_FLAGS "--preload-file ${ASSETS_DIR}@/assets"
#         )
#     else()
#         message(WARNING "Assets folder not found: ${ASSETS_DIR}")
#     endif()
# endif()

# --- Optional: Set C++ standard ---
set_target_properties(Aaron PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)