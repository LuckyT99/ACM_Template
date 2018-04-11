class disjointSet
{
  private:
    unsigned int count, size, sizeofSet;
    int *set;

  public:
    disjointSet();
    disjointSet(int val, bool without0 = false);
    ~disjointSet();
    unsigned int getCount() const;
    unsigned int getCount(int val) const;
    unsigned int getSize() const;
    unsigned int constFind(int val) const;
    unsigned int find(int val);
    bool merge(int lhs, int rhs);
};

disjointSet::disjointSet()
{
    count = 0;
    size = 0;
    set = nullptr;
}
disjointSet::disjointSet(int val, bool without0)
{
    count = val;
    size = val;
    sizeofSet = val + (unsigned int)without0;
    set = new int[sizeofSet];
    for (int i = 0; i < sizeofSet; ++i)
    {
        set[i] = -1;
    }
}
disjointSet::~disjointSet()
{
    delete[] set;
}
unsigned int disjointSet::getCount() const
{
    return count;
}
unsigned int disjointSet::getCount(int val) const
{
    return -set[constFind(val)];
}
unsigned int disjointSet::getSize() const
{
    return size;
}
unsigned int disjointSet::constFind(int val) const
{
    while (set[val] >= 0)
    {
        val = set[val];
    }
    return val;
}
unsigned int disjointSet::find(int val)
{
    int res = val;
    while (set[res] >= 0)
    {
        res = set[res];
    }
    for (int tmp; val != res; val = tmp)
    {
        tmp = set[val];
        set[val] = res;
    }
    return res;
}
bool disjointSet::merge(int lhs, int rhs)
{
    lhs = find(lhs);
    rhs = find(rhs);
    if (lhs == rhs)
    {
        return false;
    }
    if (set[lhs] < set[rhs])
    {
        set[lhs] += set[rhs];
        set[rhs] = lhs;
    }
    else
    {
        set[rhs] += set[lhs];
        set[lhs] = rhs;
    }
    --count;
    return true;
}