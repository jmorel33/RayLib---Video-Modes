#include "raylib.h"
#include <GLFW/glfw3.h>

int main()
{
    InitWindow(1024, 600, "monitor videomodes");

    int count;
    GLFWvidmode* modes = glfwGetVideoModes(glfwGetPrimaryMonitor(), &count);

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
            int x = 10;
            int y = 10;

            ClearBackground(RAYWHITE);
            for (int i = 0; i < count; i++) {
                 DrawText(FormatText("%i x %i rez, %ix%ix%i col, %i rate", (int)modes[i].width, (int)modes[i].height, (int)modes[i].redBits, (int)modes[i].greenBits, (int)modes[i].blueBits, (int)modes[i].refreshRate), x, y, 10, DARKGRAY);
                 y+=10; if (y>550) {x+=200; y=10; };
            }
        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}