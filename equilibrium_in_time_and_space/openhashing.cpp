#include <stdio.h>
#include <string.h>
#define RecordNum 7
#define HashTableNum 32
struct HashType
{
    char str[80];
    struct HashType *next;
};

//散列表
// struct HashType HashData[RecordNum] = {"for", "switch", "if", "case", "else", "static", "union"};
struct HashType HashData[RecordNum] = {};

int HashAddress[HashTableNum];
struct HashType *HashTable[HashTableNum];
struct HashType *p, *q;

void calculateHashAddress()
{
    for (int i = 0; i < RecordNum; i++)
    {
        int HashSumTemp = 0;
        for (int j = 0; j < strlen(HashData[i].str); j++)
        {
            HashSumTemp += HashData[i].str[j] - 'a' + 1;
        }
        HashAddress[i] = HashSumTemp % HashTableNum;
    }
}

//将各记录的指针分布到散列表中
void calculateHashTable()
{
    for (int i = 0; i < HashTableNum; i++)
    {
        HashTable[i] = NULL;
    }

    for (int i = 0; i < RecordNum; i++)
    {
        if (HashTable[HashAddress[i]] == NULL)
        {
            HashTable[HashAddress[i]] = &HashData[i];
        }
        else
        {
            p = q = HashTable[HashAddress[i]];
            while (p != NULL)
            {
                q = p;
                p = p->next;
            }
            q->next = &HashData[i];
        }
    }
}

//查找记录时 先计算散列地址
int calculateSearchRecordHashAddress(char *record)
{
    int HashSumTemp = 0;
    for (int j = 0; j < strlen(record); j++)
    {
        HashSumTemp += record[j] - 'a' + 1;
    }
    return HashSumTemp % HashTableNum;
}

//根据散列地址判断待查找记录的有无
int searchRecord()
{
    int count = 0;
    char record[20];
    gets(record);
    int searchRecordHashAddress = calculateSearchRecordHashAddress(record);
    p = HashTable[searchRecordHashAddress];
    while (p != NULL)
    {
        count++;
        if (strcmp(p->str, record) == 0)
        {
            return 1;
            break;
        }
        else
        {
            p = p->next;
        }
    }
    if (p == NULL)
    {
        return 0;
    }
}