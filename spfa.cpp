/*
SPFA, 优先队列优化的 Bellman-Ford 算法, 优先队列优化且允许重入队的 Dijkstra 算法;
需要头文件 queue 用于优先队列, list 用于邻接表;
需要在调用函数前初始化 dis 数组;
*/

class dist //类 dist 存储节点号和距离
{
  public:
    int index;                                              //节点号
    long long distance;                                     //距离
    friend bool operator<(const dist &lhs, const dist &rhs) //重载 < 使优先队列中距离小的在前
    {
        return lhs.distance > rhs.distance;
    }
};

void spfa(int s, long long dis[], const list<dist> rel[]) //s 是源节点号, dis 数组存储结果, rel数组是邻接表
{
    priority_queue<dist> mindis; //存储节点到源节点的最小距离, 距离小的在前
    dis[s] = 0;                  //源节点与自身距离
    mindis.push(dist{s, 0});     //将源节点入队
    while (!mindis.empty())      //队列为空时结束
    {
        dist tmp = mindis.top(); //获取队头
        mindis.pop();
        if (tmp.distance != dis[tmp.index]) //如果队列中的数据已过期则直接进入下一次循环重新获取队头
        {
            continue;
        }
        for (list<dist>::const_iterator it = rel[tmp.index].cbegin(); it != rel[tmp.index].cend(); ++it) //遍历相邻的节点
        {
            if (tmp.distance + it->distance < dis[it->index]) //如果可以更新 dis 数组
            {
                dis[it->index] = tmp.distance + it->distance; //更新 dis 数组
                mindis.push(dist{it->index, dis[it->index]}); //将节点加入队列
            }
        }
    }
}