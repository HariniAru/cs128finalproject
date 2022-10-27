#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif

#include "catch.hpp"

#include "../application.hpp"
#include "../application.cpp"
#include "../player.hpp"
#include "../player.cpp"
#include "../location.hpp"
#include "../location.cpp"

#include "../maze_game.cpp"
#include "../game_options.cpp"
#include "../navigatable_maze.cpp"
#include "../mazegenerator.cpp"


TEST_CASE( "test shoot", "[shoot test]" ) {
    player p;
    p.setArrows(3);
    p.shoot();
    REQUIRE(p.getArrows() == 2);
}

TEST_CASE( "test escape", "[escape test]" ) {
    application a;
    static location* loc1 = a.getBossLoc();
    location* loc2 = loc1->escape();
    REQUIRE(loc2 != loc1);
}

TEST_CASE( "test checklost", "[checklost test]" ) {
    player p;
    application a;
    p.setLocation(a.getBossLoc());
    REQUIRE(a.getStatus() == 2);
}

TEST_CASE( "draws correct game", "[hidden maze test]" ) {
    GameType game = GameType::GAME1;
    draw_game(game);
    REQUIRE(check_status == GameType::GAME1);
}

TEST_CASE( "draws correct game", "[maze runner test]" ) {
    GameType game = GameType::GAME2;
    draw_game(game);
    REQUIRE(check_status == GameType::GAME2);
}

TEST_CASE( "game ends on quit", "[quitting game test]") {
    run_game();
    if (to_check == 'q')
        REQUIRE(game_over == true);
}

TEST_CASE( "keyboard events detected correctly - maze runner game", "[keyboard event test]") {
    run_game();
    if (to_check == KEY_LEFT)
        REQUIRE(kl == true);
    if (to_check == KEY_RIGHT)
        REQUIRE(kr == true);
    if (to_check == KEY_UP)
        REQUIRE(ku == true);
    if (to_check == KEY_DOWN)
        REQUIRE(kd == true);
}

TEST_CASE( "maze generated properly", "[maze generation test]") {
    std::vector<std::vector<char>> maze = generatemaze(50, 50);
    PrintMaze(maze);
    REQUIRE(check_h == maze.size());
    REQUIRE(check_w == maze[0].size());
}
