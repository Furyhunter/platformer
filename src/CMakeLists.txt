include_directories(${SDL_INCLUDE_DIR})
include_directories(${SDLIMAGE_INCLUDE_DIR})

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

set(ENGINE_HEADERS
	AABB.h
	Color.h
	Entity.h
	exmath.h
	Game.h
	Graphics.h
	IInputListener.h
	LinkedList.h
	List.h
	Texture.h
	Vector2f.h)

add_executable(platformer WIN32 MACOSX_BUNDLE ${ENGINE_SOURCES} ${ENGINE_HEADERS})
target_link_libraries(platformer ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY} ${OPENGL_LIBRARY})
