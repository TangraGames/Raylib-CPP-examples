// Conway's game of life example

#include "raylib.h"

typedef struct Cell {
    int screenX, screenY;
    int gridX, gridY;
    int state, prevState;
    int lifeScore;
    int neighbours[8];
} Cell;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int cols = 192;
    const int rows = 108;
    const int cellSize = 10;
    int startAlivePercent = 25;
    const Color cellColor[] = { BLACK, RAYWHITE };
    Cell grid[cols * rows];

    int screenWidth = cols * cellSize;
    int screenHeight = rows * cellSize;

    InitWindow(screenWidth, screenHeight, "Game Of Life");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    unsigned int frame = 0;
    //--------------------------------------------------------------------------------------

    // Set-up
    for (int i = 0; i < cols * rows; i++) {
        Cell c;
        c.gridX = i % cols;
        c.gridY = i / cols;
        c.screenX = c.gridX * cellSize;
        c.screenY = c.gridY * cellSize;
        c.prevState = 0;
        int rand = GetRandomValue(0, 100);
        (rand <= startAlivePercent) ? (c.state = 1) : (c.state = 0);
        c.lifeScore = 0;
        // Populate array with neighbouring cells. Position 0 is top left, 1 is top, 2 is top right etc...Add -1 if no such neighbour.
        if (c.gridX == 0 || c.gridY == 0) { c.neighbours[0] = -1; }
        else { c.neighbours[0] = i - cols - 1; } //top-left
        if (c.gridY == 0) { c.neighbours[1] = -1; }
        else { c.neighbours[1] = i - cols; } //top
        if (c.gridX == rows - 1 || c.gridY == 0) { c.neighbours[2] = -1; }
        else { c.neighbours[2] = i - cols + 1; } //top-right
        if (c.gridX == 0) { c.neighbours[3] = -1; }
        else { c.neighbours[3] = i - 1; } //left
        if (c.gridX == cols - 1) { c.neighbours[4] = -1; }
        else { c.neighbours[4] = i + 1; } //right
        if (c.gridX == 0 || c.gridY == rows - 1) { c.neighbours[5] = -1; }
        else { c.neighbours[5] = i + cols - 1; } //bottom-left
        if (c.gridY == rows - 1) { c.neighbours[6] = -1; }
        else { c.neighbours[6] = i + cols; } //bottom
        if (c.gridX == cols - 1 || c.gridY == rows - 1) { c.neighbours[7] = -1; }
        else { c.neighbours[7] = i + cols + 1; } //bottom-right
        grid[i] = c;
    }

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        if (frame % 20 == 0) { // slow down the update cycle
            for (int i = 0; i < cols * rows; i++) {
                int sum = 0;
                for (int n = 0; n < 8; n++) {
                    int neighbour = grid[i].neighbours[n];
                    if (neighbour != -1) {
                        sum += grid[neighbour].state;
                    }
                    grid[i].lifeScore = sum;
                }
            }

            for (int i = 0; i < cols * rows; i++) {
                // Any dead cell with three live neighbours becomes a live cell.
                if (grid[i].state == 0 && grid[i].lifeScore == 3) {
                    grid[i].prevState = grid[i].state;
                    grid[i].state = 1;
                }
                // Any live cell with less than two or more than three live neighbours dies.
                else if ((grid[i].state == 1) && (grid[i].lifeScore < 2 || grid[i].lifeScore > 3)) {
                    grid[i].prevState = grid[i].state;
                    grid[i].state = 0;
                }
            }
        }
        frame += 1;

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
 
        for (int i = 0; i < cols * rows; i++) {
            DrawRectangle(grid[i].screenX, grid[i].screenY, cellSize, cellSize, cellColor[grid[i].state]);
            DrawRectangleLines(grid[i].screenX, grid[i].screenY, cellSize, cellSize, DARKGRAY);
        }

        DrawFPS(10, 10);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}
