#include <stdio.h>

// TODO 哈夫曼编码
struct HuffNode
{
    char c;
    unsigned int freq;
    HuffNode *left;
    HuffNode *right;
};

// 优先级队列
void heapify(int i)
{
    int l, r, smallest;
    struct HuffNode *tmp;
    l = 2 * i;
    r = 2 * i + 1;
    int size = 0;

    // if((l<size) &&(HuffNode[l].freq<HuffNode./))
}