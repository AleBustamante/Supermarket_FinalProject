#pragma once
#include <iostream>
#include <string>
#include <Windows.h>


using namespace std;



namespace print{

    struct Vector2 {
        short x;
        short y;
    };


    //Positions
    constexpr Vector2 ORIGIN_POS = { 0, 0 };
    constexpr Vector2 TITLE_POS = { 0, 0 };
    constexpr Vector2 INIT_POS = { 0, 2 };


    //Colors
    constexpr int BLUE = 1;
    constexpr int GREEN = 2;
    constexpr int CYAN = 3;
    constexpr int RED = 4;
    constexpr int PURPLE = 5;
    constexpr int YELLOW_DARK = 6;
    constexpr int WHITE = 7;
    constexpr int GREY = 8;
    constexpr int BLUE_BRIGHT = 9;
    constexpr int GREEN_BRIGHT = 10;
    constexpr int CYAN_BRIGHT = 11;
    constexpr int RED_BRIGHT = 12;
    constexpr int PINK = 13;
    constexpr int YELLOW = 14;
    constexpr int WHITE_BRIGHT = 15;


    //Console sizes
    constexpr int CONSOLE_HEIGHT = 800;
    constexpr int CONSOLE_WIDTH = 800;
    constexpr int SCREEN_HEIGHT = 1080;
    constexpr int SCREEN_WIDHT = 1980;
    constexpr int ORIGIN_X = 300;
    constexpr int ORIGIN_Y = 200;


    //Design
    constexpr int CURSOR_HEIGHT = 37; 
    constexpr int CURSOR_WIDTH = 168;
    constexpr int INPUT_POS_Y = 4;
    constexpr int OUTPUT_POS_Y = CURSOR_HEIGHT/2 ;
    constexpr int RESULTS_POS_X = CURSOR_WIDTH / 2;
    constexpr int RESULTS_POS_Y = INPUT_POS_Y;

    //Cursor position
    void goToXY(Vector2 coordenates);
    void setCursorToInputPos();
    void setCursorToOutputPos();
    void setCursorToResultsPos();


    void setColor(WORD color);


    void setDefaultWindowSize();

    //Print functions
    void printBorders(WORD color);
    void printTitle(const string& title);
    void printHints(const string& hint1, const string& hint2 = "", const string& hint3 = "");

}

