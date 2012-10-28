include_directories(${SDL_INCLUDE_DIR})
include_directories(${SDLIMAGE_INCLUDE_DIR})

set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

set(ENGINE_SOURCES
    main.cpp
    AABB.cpp
    Color.cpp
    Entity.cpp
    exmath.cpp
    Game.cpp
    Graphics.cpp
    LinkedList.cpp
    Texture.cpp
    Vector2f.cpp)

add_executable(engine-cpp WIN32 MACOSX_BUNDLE ${ENGINE_SOURCES})
target_link_libraries(engine-cpp ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY}
${OPENGL_LIBRARY})
