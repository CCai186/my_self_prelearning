#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL] = {
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0,
};


int dfs(int row, int col)
{
    if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL)
        return 0;
    if (maze[row][col] != 0)
        return 0;

    maze[row][col] = 2;

    if (row == MAX_ROW - 1 && col == MAX_COL - 1) {
        printf("(%d, %d)\n", row, col);
        return 1;
    }

    if (dfs(row, col + 1)) {
        printf("(%d, %d)\n", row, col);
        return 1;
    }
    if (dfs(row + 1, col)) {
        printf("(%d, %d)\n", row, col);
        return 1;
    }
    if (dfs(row, col - 1)) {
        printf("(%d, %d)\n", row, col);
        return 1;
    }
    if (dfs(row - 1, col)) {
        printf("(%d, %d)\n", row, col);
        return 1;
    }

    return 0;
}

int main(void)
{
    printf("递归DFS路线（终点→起点）：\n");
    if (!dfs(0, 0)) {
        printf("No path!\n");
    }
    return 0;
}