#include "lfu_cache.h"
#include <iostream>

using namespace std;

int main()
{
    LFUCache<int, int> lfuCache(2, -1);
    lfuCache.PutValue(1, 1);
    lfuCache.PutValue(2, 2);
    lfuCache.GetValue(1); // 返回 1
    lfuCache.PutValue(3, 3); // 去除 key 2
    lfuCache.GetValue(2); // 返回 -1 (未找到key 2)
    lfuCache.GetValue(3); // 返回 3
    lfuCache.PutValue(4, 4); // 去除 key 1
    lfuCache.GetValue(1); // 返回 -1 (未找到 key 1)
    lfuCache.GetValue(3); // 返回 3
    lfuCache.GetValue(4); // 返回 4

    return 0;
}