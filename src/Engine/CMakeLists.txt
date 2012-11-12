include_directories(${SDL_INCLUDE_DIR})
include_directories(${SDLIMAGE_INCLUDE_DIR})

set(ENGINE_SOURCES
    AABB.cpp
    Color.cpp
    exmath.cpp
    Game.cpp
    Graphics.cpp
    Texture.cpp
    Vector2f.cpp)
	
set(ENGINE_HEADERS
	AABB.h
	Color.h
	Entity.h
	exmath.h
	Game.h
	Graphics.h
	Texture.h
	Vector2f.h)

add_library(engine STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})
target_link_libraries(engine ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY} ${OPENGL_LIBRARY})
