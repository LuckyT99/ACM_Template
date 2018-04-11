/*
判断是否存在负权回路;
需要头文件 cstring 用于初始化 dis 数组, list 用于邻接表;
需要定义常量 SIZEN ;
*/

bool vis[SIZEN];
int dis[SIZEN];

bool checkNegativeCycle(int sta, long long dis[], const list<dist> rel[])
{
    vis[sta] = true;
    for (list<dist>::const_iterator it = rel[sta].begin(); it != rel[sta].end(); ++it)
    {
        if (dis[sta] + it->distance < dis[it->index])
        {
            if (vis[it->index])
            {
                return true;
            }
            else
            {
                dis[it->index] = dis[sta] + it->distance;
                if (checkNegativeCycle(it->index, dis, rel))
                {
                    return true;
                }
            }
        }
    }
    vis[sta] = false;
}

bool hasNegativeCycle(const list<dist> rel[], int n)
{
    memset(dis, 0, sizeof dis);
    for (int i = 1; i <= n; ++i)
    {
        if (checkNegativeCycle(i, dis, rel))
        {
            return true;
        }
    }
}