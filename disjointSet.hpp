class disjointSet
{
  private:
    unsigned int count, size;
    int *set;

  public:
    disjointSet();
    disjointSet(int val);
    ~disjointSet();
    unsigned int getCount() const;
    unsigned int getCount(int val) const;
    unsigned int getSize() const;
    unsigned int find(int val);
    bool merge(int lhs, int rhs);
};

disjointSet::disjointSet()
{
    count = 0;
    size = 0;
    set = nullptr;
}
disjointSet::disjointSet(int val)
{
    count = val;
    size = val;
    set = new int[size];
    for (int i = 0; i < size; ++i)
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
    while (set[val] >= 0)
    {
        val = set[val];
    }
    return -set[val];
}
unsigned int disjointSet::getSize() const
{
    return size;
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