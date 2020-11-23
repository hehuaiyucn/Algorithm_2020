#include <stdio.h>
#include <string.h>

char Text[] = "failureeisathebmotherccfdsuccess";


char Pattern[] = "scucess";
                //1234567
                //654321
                //c 3 
                //u 4
                //e 2
                //s 1
// char Text[] = "for switch if while do static return";
// char Pattern[] = "static";

void caculateDisc(char Pattern[], int *disc)
{
    int patternLength = strlen(Pattern);
    for (int i = 0; i < 27; i++)
    {
        disc[i] = patternLength;
    }
    printf("\n");
    for (int i = 0; i < patternLength - 1; i++)
    {
        disc[Pattern[i] - 'a'] = patternLength - i - 1;
    }
}

int HorspoolMatching(char Text[], char Pattern[], int disc[])
{
    int i = 0;
    int count = 0;
    int textLength = strlen(Text);
    int patternLength = strlen(Pattern);

    while (textLength > 0 && patternLength > 0 && i < (textLength - patternLength))
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
                i = i + disc[26];
            }
            else
            {
                i = i + disc[Text[i + patternLength - 1] - 'a'];
            }
            count++;
        }
    }
    return -1;
}

int main()
{
    int disc[27];
    caculateDisc(Pattern, disc);
    for (int i = 0; i < 27; i++)
    {
        if (disc[i] != 7)
        {
            printf("disc[%d]:%d ", i,disc[i]);
        }
    }
    int weizhi = HorspoolMatching(Text,Pattern,disc);
    printf("%d",weizhi);
}