#include <stdio.h>
#include <string.h>
#define Num 7
struct HashType
{
    char str[80];
};

struct HashType HashData[Num] = {"for", "switch", "if", "case", "else", "static", "union"};
int HashAddress[Num];
struct HashType *HashTable[Num];

// 计算散列地址
void calculateHashAddress()
{
    for (int i = 0; i < Num; i++)
    {
        int HashSumTemp = 0;
        for (int j = 0; j < strlen(HashData[i].str); j++)
        {
            HashSumTemp += HashData[i].str[j] - 'a' + 1;
        }
        HashAddress[i] = HashSumTemp % Num;
    }
}

//将各记录的指针分布到散列表中
void calculateHashTable()
{
    for (int i = 0; i < Num; i++)
    {
        HashTable[HashAddress[i]] = HashData[i].str;
    }
}

//查找记录时 先计算散列地址
int calculateSearchRecordHashAddress(char *record)
{
    int hashSumTemp = 0;
    for (int j = 0; j < strlen(record); j++)
    {
        hashSumTemp += record[j] - 'a' + 1;
    }
    return hashSumTemp % Num;
}

//根据散列地址判断待查找记录的有无
int searchRecord()
{
    char record[80] = {};
    gets(record);
    int searchRecordHashAddress = calculateSearchRecordHashAddress(record);
    if (strcmp(HashTable[searchRecordHashAddress], record) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}