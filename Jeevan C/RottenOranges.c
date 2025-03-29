#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int time;
} QueueElement;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    if (m == 0) return 0;
    int n = gridColSize[0];
    int fresh = 0;
    int front = 0, rear = 0;
    QueueElement* queue = (QueueElement*)malloc(m * n * sizeof(QueueElement));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                fresh++;
            } else if (grid[i][j] == 2) {
                queue[rear].row = i;
                queue[rear].col = j;
                queue[rear].time = 0;
                rear++;
            }
        }
    }
    
    if (fresh == 0) {
        free(queue);
        return 0;
    }
    
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int max_time = 0;
    
    while (front < rear) {
        QueueElement current = queue[front];
        front++;
        
        for (int d = 0; d < 4; d++) {
            int newRow = current.row + directions[d][0];
            int newCol = current.col + directions[d][1];
            
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1) {
                grid[newRow][newCol] = 2; 
                fresh--;
                
                queue[rear].row = newRow;
                queue[rear].col = newCol;
                queue[rear].time = current.time + 1;
                rear++;
                max_time = current.time + 1; 
                
                if (fresh == 0) {
                    free(queue);
                    return max_time;
                }
            }
        }
    }
    
    free(queue);
    return (fresh == 0) ? max_time : -1;
}
