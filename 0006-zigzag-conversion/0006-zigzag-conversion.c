char* convert(char* s, int numRows)
{
    int n = strlen(s);

    // Special case
    if(numRows == 1 || numRows >= n)
    {
        char* answer = malloc((n + 1) * sizeof(char));
        strcpy(answer, s);
        return answer;
    }

    // Each row gets a string
    char** rows = malloc(numRows * sizeof(char*));

    for(int i = 0; i < numRows; i++)
    {
        rows[i] = malloc((n + 1) * sizeof(char));
        rows[i][0] = '\0';
    }

    int currentRow = 0;
    int direction = 1;   // 1 = down, -1 = up

    for(int i = 0; i < n; i++)
    {
        int len = strlen(rows[currentRow]);

        rows[currentRow][len] = s[i];
        rows[currentRow][len + 1] = '\0';

        // Last row → go up
        if(currentRow == numRows - 1)
        {
            direction = -1;
        }

        // First row → go down
        if(currentRow == 0)
        {
            direction = 1;
        }

        currentRow = currentRow + direction;
    }

    // Combine all rows
    char* answer = malloc((n + 1) * sizeof(char));

    int position = 0;

    for(int i = 0; i < numRows; i++)
    {
        int len = strlen(rows[i]);

        for(int j = 0; j < len; j++)
        {
            answer[position] = rows[i][j];
            position++;
        }

        free(rows[i]);
    }

    free(rows);

    answer[position] = '\0';

    return answer;
}