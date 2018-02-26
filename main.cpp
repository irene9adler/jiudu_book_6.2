//广度优先搜索BFS 例6.2非常可乐
#include <stdio.h>
#include <queue>
#define M 100
using namespace std;

typedef struct node
{
    int a,b,c;//三个杯子当前的量
    int t;//当前倾倒次数
}node;
queue <node> Q;
bool mark[M][M][M];//某时刻状态(a,b,c) 是否已经扩展

int dump(int sa,int sb,int &a,int &b)//倾倒函数方向是a sa sb是这两个杯子的容积 a,b引用是两个杯子中的可乐量（倾倒前 倾倒后）
{
    if(a <= sb - b)//如果a可以全部倒到b
    {
        b = a + b;
        a = 0;
        //b = a + b;
    }
    else//不能全倒 把b倒到满
    {
        a -= (sb - b);
        b = sb;
    }
}
int BFS(int s,int m,int n)//参数是a,b,c的容积 不是量
{
  while(Q.empty()==false){
    node now = Q.front();
    Q.pop();
    int a,b,c,t;
    a = now.a;
    b = now.b;
    c = now.c;
    t = now.t;
    dump(s,n,a,b);//?
    printf("a->b\n");
    //相当于6个方向 广度优先搜索
    //由a往b倒
    //倒完的处理
    if(mark[a][b][c] == false)
    {
        mark[a][b][c] = true;
        node tmp;
        tmp.a = a;
        tmp.b = b;
        tmp.c = c;
        tmp.t = t+1;//倾倒后的下一状态
        if((a == s/2)&&(b == s/2)) return tmp.t;
        if((a == s/2)&&(c == s/2)) return tmp.t;
        if((b == s/2)&&(c == s/2)) return tmp.t;

        Q.push(tmp);
    }

    //由b往a倒
    //先重置a,b,c 因为调BFS只相当于走一步
    a = now.a;
    b = now.b;
    c = now.c;
    dump(n,s,b,a);//?
    printf("b->a\n");
    if(mark[a][b][c] == false)
    {
        mark[a][b][c] = true;
        node tmp;
        tmp.a = a;
        tmp.b = b;
        tmp.c = c;
        tmp.t = t+1;//倾倒后的下一状态
        if((a == s/2)&&(b == s/2)) return tmp.t;
        if((a == s/2)&&(c == s/2)) return tmp.t;
        if((b == s/2)&&(c == s/2)) return tmp.t;

        Q.push(tmp);
    }
    //由a往c倒
    a = now.a;
    b = now.b;
    c = now.c;
    dump(s,m,a,c);//?
    printf("a->c\n");
    if(mark[a][b][c] == false)
    {
        mark[a][b][c] = true;
        node tmp;
        tmp.a = a;
        tmp.b = b;
        tmp.c = c;
        tmp.t = t+1;//倾倒后的下一状态
        if((a == s/2)&&(b == s/2)) return tmp.t;
        if((a == s/2)&&(c == s/2)) return tmp.t;
        if((b == s/2)&&(c == s/2)) return tmp.t;

        Q.push(tmp);
    }
    //由c往a倒
    a = now.a;
    b = now.b;
    c = now.c;
    dump(m,s,c,a);//?
    printf("c->a\n");
    if(mark[a][b][c] == false)
    {
        mark[a][b][c] = true;
        node tmp;
        tmp.a = a;
        tmp.b = b;
        tmp.c = c;
        tmp.t = t+1;//倾倒后的下一状态
        if((a == s/2)&&(b == s/2)) return tmp.t;
        if((a == s/2)&&(c == s/2)) return tmp.t;
        if((b == s/2)&&(c == s/2)) return tmp.t;

        Q.push(tmp);
    }
    //由b往c倒
    a = now.a;
    b = now.b;
    c = now.c;
    dump(n,m,b,c);//?
    printf("b->c\n");
    if(mark[a][b][c] == false)
    {
        mark[a][b][c] = true;
        node tmp;
        tmp.a = a;
        tmp.b = b;
        tmp.c = c;
        tmp.t = t+1;//倾倒后的下一状态
        if((a == s/2)&&(b == s/2)) return tmp.t;
        if((a == s/2)&&(c == s/2)) return tmp.t;
        if((b == s/2)&&(c == s/2)) return tmp.t;

        Q.push(tmp);
    }
    //由c往b倒
    a = now.a;
    b = now.b;
    c = now.c;
    dump(m,n,c,b);//?
    printf("c->b\n");
    if(mark[a][b][c] == false)
    {
        mark[a][b][c] = true;
        node tmp;
        tmp.a = a;
        tmp.b = b;
        tmp.c = c;
        tmp.t = t+1;//倾倒后的下一状态
        if((a == s/2)&&(b == s/2)) return tmp.t;
        if((a == s/2)&&(c == s/2)) return tmp.t;
        if((b == s/2)&&(c == s/2)) return tmp.t;

        Q.push(tmp);
    }

  }
  return -1;
}

int main()
{
    int s,m,n;
    //a-s b-n c-m
    while(scanf("%d%d%d",&s,&m,&n)!=EOF)
    {
        if(s == 0) break;
        if(s%2 == 1)
        {
            printf("this is NO\n");
            continue;//继续循环等待数据的输入
        }
        //将mark数组全部置false
        int i,j,k;
        for(i = 0;i < M;i++)
        {
            for(j = 0;j < M;j++)
            {
                for(k = 0;k < M; k++)
                {
                    mark[i][j][k] = false;
                }
            }
        }
        node start;//起点
        start.a = s;
        start.b = 0;
        start.c = 0;
        start.t = 0;
        while(Q.empty()==false)//队列不空 清队列
        {
            Q.pop();
        }
        Q.push(start);
        mark[s][0][0] = true;
        int res = BFS(s,n,m);
        if(res == -1) printf("NO\n");
        else printf("%d\n",res);
    }
    return 0;
}
