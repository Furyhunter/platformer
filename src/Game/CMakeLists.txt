include_directories(${SDL_INCLUDE_DIR})
include_directories(${SDLIMAGE_INCLUDE_DIR})
include_directories(../Engine)

set(GAME_SOURCES
	main.cpp)

set(GAME_HEADERS )

add_executable(game WIN32 MACOSX_BUNDLE ${GAME_SOURCES} ${GAME_HEADERS})
add_dependencies(game engine)
target_link_libraries(game engine)
