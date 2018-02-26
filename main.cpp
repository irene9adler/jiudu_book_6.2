//�����������BFS ��6.2�ǳ�����
#include <stdio.h>
#include <queue>
#define M 100
using namespace std;

typedef struct node
{
    int a,b,c;//�������ӵ�ǰ����
    int t;//��ǰ�㵹����
}node;
queue <node> Q;
bool mark[M][M][M];//ĳʱ��״̬(a,b,c) �Ƿ��Ѿ���չ

int dump(int sa,int sb,int &a,int &b)//�㵹����������a sa sb�����������ӵ��ݻ� a,b���������������еĿ��������㵹ǰ �㵹��
{
    if(a <= sb - b)//���a����ȫ������b
    {
        b = a + b;
        a = 0;
        //b = a + b;
    }
    else//����ȫ�� ��b������
    {
        a -= (sb - b);
        b = sb;
    }
}
int BFS(int s,int m,int n)//������a,b,c���ݻ� ������
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
    //�൱��6������ �����������
    //��a��b��
    //����Ĵ���
    if(mark[a][b][c] == false)
    {
        mark[a][b][c] = true;
        node tmp;
        tmp.a = a;
        tmp.b = b;
        tmp.c = c;
        tmp.t = t+1;//�㵹�����һ״̬
        if((a == s/2)&&(b == s/2)) return tmp.t;
        if((a == s/2)&&(c == s/2)) return tmp.t;
        if((b == s/2)&&(c == s/2)) return tmp.t;

        Q.push(tmp);
    }

    //��b��a��
    //������a,b,c ��Ϊ��BFSֻ�൱����һ��
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
        tmp.t = t+1;//�㵹�����һ״̬
        if((a == s/2)&&(b == s/2)) return tmp.t;
        if((a == s/2)&&(c == s/2)) return tmp.t;
        if((b == s/2)&&(c == s/2)) return tmp.t;

        Q.push(tmp);
    }
    //��a��c��
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
        tmp.t = t+1;//�㵹�����һ״̬
        if((a == s/2)&&(b == s/2)) return tmp.t;
        if((a == s/2)&&(c == s/2)) return tmp.t;
        if((b == s/2)&&(c == s/2)) return tmp.t;

        Q.push(tmp);
    }
    //��c��a��
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
        tmp.t = t+1;//�㵹�����һ״̬
        if((a == s/2)&&(b == s/2)) return tmp.t;
        if((a == s/2)&&(c == s/2)) return tmp.t;
        if((b == s/2)&&(c == s/2)) return tmp.t;

        Q.push(tmp);
    }
    //��b��c��
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
        tmp.t = t+1;//�㵹�����һ״̬
        if((a == s/2)&&(b == s/2)) return tmp.t;
        if((a == s/2)&&(c == s/2)) return tmp.t;
        if((b == s/2)&&(c == s/2)) return tmp.t;

        Q.push(tmp);
    }
    //��c��b��
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
        tmp.t = t+1;//�㵹�����һ״̬
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
            continue;//����ѭ���ȴ����ݵ�����
        }
        //��mark����ȫ����false
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
        node start;//���
        start.a = s;
        start.b = 0;
        start.c = 0;
        start.t = 0;
        while(Q.empty()==false)//���в��� �����
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
