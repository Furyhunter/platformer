#include <SDL.h>

#include "Game.h"

int main(int argc, char** argv) {
    Game game = Game();

    game.setCaption("engine-cpp game");
    game.init();
    game.run();
    exit(0);
    return 0;
}
