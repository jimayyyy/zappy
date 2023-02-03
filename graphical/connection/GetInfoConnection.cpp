/*
** EPITECH PROJECT, 2021
** GRAPHICAL
** File description:
** GetInfoConnection.cpp
*/

#include "GetInfoConnection.hpp"

std::string GetInfoConnection::getPort(void)
{
    Rectangle textBox = {1920 / 2.0f - 100, 180, 225, 50};
    bool mouseOnText = false;
    int framesCounter = 0;

    if (CheckCollisionPointRec(GetMousePosition(), textBox))
        mouseOnText = true;
    else
        mouseOnText = false;
    if (mouseOnText)
    {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);

        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (letterCount < 9))
            {
                port[letterCount] = (char)key;
                port[letterCount + 1] = '\0';
                letterCount++;
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            letterCount--;
            if (letterCount < 0)
                letterCount = 0;
            port[letterCount] = '\0';
        }
    }

    DrawRectangleRec(textBox, LIGHTGRAY);
    DrawText(port, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);
    if (mouseOnText)
    {
        if (letterCount < 9)
        {
            if (((framesCounter / 20) % 2) == 0)
                DrawText("_", (int)textBox.x + 8 + MeasureText(port, 40), (int)textBox.y + 12, 40, MAROON);
        }
        else
            DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, LIGHTGRAY);
    }
    return port;
}

std::string GetInfoConnection::getMachine(void)
{
    Rectangle textBox2 = {1920 / 2.0f - 100, 300, 225, 50};
    bool mouseOnText2 = false;
    int framesCounter = 0;

    if (CheckCollisionPointRec(GetMousePosition(), textBox2))
        mouseOnText2 = true;
    else
        mouseOnText2 = false;

    if (mouseOnText2)
    {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (letterCount2 < 9))
            {
                machine[letterCount2] = (char)key;
                machine[letterCount2 + 1] = '\0';
                letterCount2++;
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            letterCount2--;
            if (letterCount2 < 0)
                letterCount2 = 0;
            machine[letterCount2] = '\0';
        }
    }
    DrawRectangleRec(textBox2, LIGHTGRAY);
    if (mouseOnText2)
        DrawRectangleLines((int)textBox2.x, (int)textBox2.y, (int)textBox2.width, (int)textBox2.height, RED);
    else
        DrawRectangleLines((int)textBox2.x, (int)textBox2.y, (int)textBox2.width, (int)textBox2.height, DARKGRAY);

    DrawText(machine, (int)textBox2.x + 5, (int)textBox2.y + 8, 40, MAROON);

    if (mouseOnText2)
    {
        if (letterCount2 < 9)
        {
            if (((framesCounter / 20) % 2) == 0)
                DrawText("_", (int)textBox2.x + 8 + MeasureText(machine, 40), (int)textBox2.y + 12, 40, MAROON);
        }
        else
            DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, LIGHTGRAY);
    }
    return machine;
}
