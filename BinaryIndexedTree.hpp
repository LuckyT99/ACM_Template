typedef long long ELEM;

class BinaryIndexedTree
{
  private:
    unsigned int _size;
    ELEM *_bit;
    inline int _lowbit(int val)
    {
        return val & (-val);
    }

  public:
    BinaryIndexedTree();
    BinaryIndexedTree(int val);
    ~BinaryIndexedTree();
    ELEM getSum(int pos);
    unsigned int size() const
    {
        return _size;
    }
    bool update(int pos, ELEM val);
};

BinaryIndexedTree::BinaryIndexedTree()
{
    _size = 0;
    _bit = nullptr;
}
BinaryIndexedTree::BinaryIndexedTree(int val)
{
    _size = val;
    _bit = new ELEM[val + 1];
}
BinaryIndexedTree::~BinaryIndexedTree()
{
    delete[] _bit;
}
ELEM BinaryIndexedTree::getSum(int pos)
{
    ELEM res = 0;
    for (; pos; pos -= _lowbit(pos))
    {
        res += _bit[pos];
    }
    return res;
}
bool BinaryIndexedTree::update(int pos, ELEM val)
{
    if (pos < 1 || pos > _size)
    {
        return false;
    }
    for (; pos <= _size; pos += _lowbit(pos))
    {
        _bit[pos] += val;
    }
}