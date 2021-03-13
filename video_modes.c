#include "raylib.h"
#include <GLFW/glfw3.h>

typedef struct Display_ratio {
    int width;
    int height;
} Display_ratio;

long gcd_l(long a, long b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;

    if (a < b)
        return gcd_l(a, b % a);
    else
        return gcd_l(b, a % b);
}

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
    InitWindow(1500, 720, "monitor videomodes");

    int count;
    GLFWvidmode* modes = glfwGetVideoModes(glfwGetPrimaryMonitor(), &count);

    Display_ratio ratio;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
            int x = 10;
            int y = 0;

            ClearBackground(RAYWHITE);
            for (int i = 0; i < count; i++) {
                ratio = Ratio_info((int)modes[i].width, (int)modes[i].height);
                
                DrawText(FormatText("%ix%i, %i%i%i rgb, %i fps, %i:%i ratio",
                (int)modes[i].width, (int)modes[i].height,
                (int)modes[i].redBits, (int)modes[i].greenBits, (int)modes[i].blueBits,
                (int)modes[i].refreshRate, 
                ratio.width, ratio.height),
                x, y, 20, DARKGRAY);
                
                y+=20; if (y>700) {x+=480; y=0; };
            };
        EndDrawing();
    };
