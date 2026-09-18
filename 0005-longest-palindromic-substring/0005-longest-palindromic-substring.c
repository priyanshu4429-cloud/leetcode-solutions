#include <string.h>
#include <stdlib.h>

char* longestPalindrome(char* s)
{
    int n = strlen(s);

    if(n == 1)
    {
        char* answer = malloc(2 * sizeof(char));
        answer[0] = s[0];
        answer[1] = '\0';
        return answer;
    }

    int start = 0;
    int maxLength = 1;

    for(int i = 0; i < n; i++)
    {
        // Odd length palindrome
        int left = i;
        int right = i;

        while(left >= 0 && right < n &&
              s[left] == s[right])
        {
            int length = right - left + 1;

            if(length > maxLength)
            {
                start = left;
                maxLength = length;
            }

            left--;
            right++;
        }

        // Even length palindrome
        left = i;
        right = i + 1;

        while(left >= 0 && right < n &&
              s[left] == s[right])
        {
            int length = right - left + 1;

            if(length > maxLength)
            {
                start = left;
                maxLength = length;
            }

            left--;
            right++;
        }
    }

    char* answer = malloc((maxLength + 1) * sizeof(char));

    for(int i = 0; i < maxLength; i++)
    {
        answer[i] = s[start + i];
    }

    answer[maxLength] = '\0';

    return answer;
}