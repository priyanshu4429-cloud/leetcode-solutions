int lengthOfLongestSubstring(char* s) {

    int visited[256] = {0};

    int left = 0;
    int maxLength = 0;

    for(int right = 0; s[right] != '\0'; right++)
    {
        while(visited[(unsigned char)s[right]] == 1)
        {
            visited[(unsigned char)s[left]] = 0;
            left++;
        }

        visited[(unsigned char)s[right]] = 1;

        int length = right - left + 1;

        if(length > maxLength)
        {
            maxLength = length;
        }
    }

    return maxLength;
}