#include <stdio.h>
#include <string.h>

//horspool
int horspoolMatching(char *Text, char *Pattern)
{
    int textLength = strlen(Text);
    int patternLength = strlen(Pattern);
    int i = 0;
    // 移动次数
    int count = 0;
    while (textLength > 0 && patternLength > 0 && i <= (textLength - patternLength))
    {
        int k = 0;
        int j = patternLength - 1;
        while (j >= 0 && Pattern[j] == Text[i + j])
        {
            j--;
        }

        if (j == -1)
        {
            return i;
        }
        else
        {
            int flag = 0;
            for (k = j - 1; k >= 0; k--)
            {
                if (Pattern[k] == Text[i + patternLength - 1])
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                i = i + patternLength;
            }
            else
            {
                i = i + (patternLength - k - 1);
            }
            count++;
        }
    }
    return -1;
}

// horspool的改进算法
int horspoolMatching2(char *Text, char *Pattern)
{
    int i = 0;
    int Disc[] = {};
    int count = 0;
    int textLength = strlen(Text);
    int patternLength = strlen(Pattern);

    while (textLength > 0 && patternLength > 0 && i <= (textLength - patternLength))
    {
        int j = patternLength - 1;
        while (j >= 0 && Pattern[j] == Text[i + j])
        {
            j--;
        }
        if (j == -1)
        {
            return i;
        }
        else
        {
            if (Text[i + j] == ' ')
            {
                i = i + Disc[26];
            }
            else
            {
                i = i + Disc[Text[i + patternLength - 1] - 'a'];
            }
        }
        count++;
    }
    return -1;
}