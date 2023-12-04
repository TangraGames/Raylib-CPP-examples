#include "raylib.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    const int squareSize = 48;
    const int margin = 1;
    const int gridSize = 11;
    const int fontSize = 20;

    const Color backgroundColor = DARKGRAY;
    const Color squareColor = DARKBLUE;
    const Color textColor = WHITE;
    const Color highlightColor = MAROON;
    const Color gridLinesColor = RAYWHITE;

    bool grid[gridSize][gridSize] = { 0 };

    InitWindow(screenWidth, screenHeight, "Grid Example - Square Cells");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(DARKGRAY);

        int startX = (screenWidth - (gridSize * squareSize + (gridSize - 1) * margin)) / 2;
        int startY = (screenHeight - (gridSize * squareSize + (gridSize - 1) * margin)) / 2;
        DrawRectangle(startX-1, startY-1, gridSize * squareSize + (gridSize - 1) * margin + 2, gridSize * squareSize + (gridSize - 1) * margin + 2, gridLinesColor);

        for (int i = 0; i < gridSize; i++)
        {
            for (int j = 0; j < gridSize; j++)
            {
                int x = startX + j * (squareSize + margin);
                int y = startY + i * (squareSize + margin);

                Color color = grid[i][j] ? highlightColor : squareColor;

                DrawRectangle(x, y, squareSize, squareSize, color);

                // Draw cell number starting at 1 and incrementing by 1 to the right
                int number = i * gridSize + j + 1;
                int textWidth = MeasureText(TextFormat("%d", number), fontSize);
                int textHeight = fontSize;
                int textX = x + (squareSize - textWidth) / 2;
                int textY = y + (squareSize - textHeight) / 2;
                DrawText(TextFormat("%d", number), textX, textY, fontSize, WHITE);

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
					          Vector2 mousePos = GetMousePosition();
                    if (CheckCollisionPointRec(mousePos, Rectangle{ (float)x, (float)y, (float)squareSize, (float)squareSize }))
                    {
                        // Toggle the color of the selected cell
                        grid[i][j] = !grid[i][j];

                        // Toggle the color of the neighbors
                        if (i > 0)
                        {
                          grid[i - 1][j] = !grid[i - 1][j];
            						}

                        if (i < gridSize - 1)
                        {
							            grid[i + 1][j] = !grid[i + 1][j];
						            }
                        
                        if (j > 0)
                        {
							            grid[i][j - 1] = !grid[i][j - 1];
						            }

                        if (j < gridSize - 1)
                        {
							            grid[i][j + 1] = !grid[i][j + 1];
						            }
				          	}
				        }
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
