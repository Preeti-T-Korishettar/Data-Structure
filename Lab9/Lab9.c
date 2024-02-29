#include<stdio.h>

int queue[100];
int front=0,rear=0;
//int n=6;

int a[10][10];
void enqueue(int var)
{
    queue[rear] = var;
    rear++;
}
void dequeue()
{
    front++;
}

void bfs(int n)
{
    int visited[10] = {0};
    enqueue(0);
    visited[0] = 1;
    while(front != rear)
    {
        int current = queue[front];
        printf("%d ", current);
        dequeue();
        for(int i=0;i<n;i++)
        {
            if((a[current][i] == 1) && (visited[i] == 0))
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}


void dfs(int a[][10], int n, int start , int visited2[10]) {

   visited2[start] = 1;
   printf("%d ", start);

   for(int i=0; i<n; i++) {
      if(a[start][i] && !visited2[i]) {
         dfs(a,n,i,visited2);
      }
   }
}
void main()
{
    int n;
    int start=0;
    int visited2[10];
    printf("Enter no of vertices:");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    bfs(n);
   for(int i = 0; i < 10; ++i) {
      visited2[i] = 0;
   }

   printf("\nDFS Traversal: ");
   dfs(a, n, start,visited2);

    //dfs(a,n,start);
}
