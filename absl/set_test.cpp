#include <iostream>
#include <benchmark/benchmark.h>
#include <absl/container/btree_set.h>
#include <stdio.h>
#include <vector>
#include <set>

const int len = 10000;


void init(std::vector<int>& insert, int len)
{
    insert.reserve(len);
    for(int i=0;i<len;++i)
    {
        insert[i]=i;
    }
}


static void btree_set_insert(benchmark::State& state)
{
    absl::btree_set<int> set;
    state.SetComplexityN(len);
    int i=0;
    while(state.KeepRunningBatch(len))
    {
        set.insert(i++);
    }
}

static void rbtree_set_insert(benchmark::State& state)
{
    std::set<int> set;
    state.SetComplexityN(len);
    int i=0;
    while(state.KeepRunningBatch(len))
    {
        set.insert(i++);
    }
}


BENCHMARK(btree_set_insert);
BENCHMARK(rbtree_set_insert);
BENCHMARK_MAIN();
