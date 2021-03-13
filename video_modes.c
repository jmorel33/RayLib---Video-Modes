#include "raylib.h"
#include <GLFW/glfw3.h>

typedef struct Display_ratio {
    int width;
    int height;
} Display_ratio;

int gcd_i(int a, int b) {
    int res = a%b;
    while (res > 0) {
        a = b;
        b = res;
        res = a % b;
    }
    return b;
}

Display_ratio Ratio_info(int x, int y) {
    Display_ratio p;

    int gcd_res = gcd_i(x,y);
    p.width = x / gcd_res;
    p.height = y / gcd_res;
    return p;
};

int main()
{
    InitWindow(1024, 600, "monitor videomodes");

    int count;
    GLFWvidmode* modes = glfwGetVideoModes(glfwGetPrimaryMonitor(), &count);

    Display_ratio ratio;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
            int x = 10;
            int y = 10;

            ClearBackground(RAYWHITE);
            for (int i = 0; i < count; i++) {
                ratio = Ratio_info((int)modes[i].width, (int)modes[i].height);
                
                DrawText(FormatText("%i x %i rez, %ix%ix%i col, %i rate, ratio = %i:%i",
                (int)modes[i].width, (int)modes[i].height,
                (int)modes[i].redBits, (int)modes[i].greenBits, (int)modes[i].blueBits,
                (int)modes[i].refreshRate, 
                ratio.width, ratio.height),
                x, y, 10, DARKGRAY);
                
                y+=10; if (y>550) {x+=300; y=10; };
            };
        EndDrawing();
    };

    CloseWindow();        // Close window and OpenGL context

    return 0;
};
