#include <stdio.h>
#include <string.h>
#define RECORDNUM 32
#define HASHTABLENUM 32

struct HashType
{
    char str[20];
    struct HashType *next;
};

struct HashType HashData[RECORDNUM] = {"auto", NULL, "break", NULL, "while", NULL, "if", NULL, "case", NULL, "default",NULL};

int hashAddress[HASHTABLENUM];
struct HashType *hashTable[HASHTABLENUM];
struct HashType *p, *q;

//-----------------------------构造-------------------------------------------------------------------
void CalculateHashAddress()
{
    for (int i = 0; i < RECORDNUM; i++)
    {
        int hashSumTemp = 0;
        //求和
        for (int j = 0; j < strlen(HashData[i].str); j++)
        {
            hashSumTemp += HashData[i].str[j] - 'a' + 1;
        }
        // 分配hash地址
        hashAddress[i] = hashSumTemp % HASHTABLENUM;
    }
}

void CalculateHashTable()
{
    //初始化hashtable
    for (int i = 0; i < HASHTABLENUM; i++)
    {
        hashTable[i] = NULL;
    }

    for (int i = 0; i < RECORDNUM; i++)
    {
        if (hashTable[hashAddress[i]] == NULL)
        {
            hashTable[hashAddress[i]] = &HashData[i];
        }
        else
        {
            p = q = hashTable[hashAddress[i]];
            while (p != NULL)
            {
                q = p;
                p = p->next;
            }
            q->next = &HashData[i];
        }
    }
}

//------------------------查找-----------------------------------------------------------------------------
int CalculateSearchRecordHashAddress(char record[])
{
    int HashSumTemp = 0;
    for (int i = 0; i < strlen(record); i++)
    {
        HashSumTemp += record[i] - 'a' + 1;
    }
    return HashSumTemp % HASHTABLENUM;
}

void SearchRecord()
{
    //查找次数
    int count = 0;
    char record[20];
    gets(record);
    int searchRecordHashAddress = CalculateSearchRecordHashAddress(record);
    p = hashTable[searchRecordHashAddress];
    while (p != NULL)
    {
        count++;
        if (strcmp(p->str, record) == 0)
        {
            printf("\n找到");
            break;
        }
        else
        {
            p = p->next;
        }
    }
    if (p == NULL)
    {
        printf("\n查无记录");
    }
    printf("查找次数：%d",count);
}

int main(){
    int i;
    CalculateHashAddress();
    CalculateHashTable();
    SearchRecord();
}