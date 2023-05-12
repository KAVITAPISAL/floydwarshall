#include<stdio.h>
#include<stdlib.h>
void creatematrix(int m[10][10],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for (j  = 0; j < n; j++)
        {
            m[i][j]=0;
            if(i!=j)
            {
                printf("\n is there any vertices between %d and %d (1/0) : ",i+1,j+1);
                scanf("%d",&m[i][j]);
            }
        }
        
    }
}

void displaymatrix(int m[10][10],int n)
{
    int i,j;
    printf("\n adjacancy matrix is : \n");
    for(i=0;i<n;i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}

void indegree(int m[10][10],int n)
{
    int i,j,count;
    for(i=0;i<n;i++)
    {
        count=0;
        for(j=0;j<n;j++)
        {
            if(m[j][i] == 1)
            {
                count++;
              
            }
        }
        printf("\n indegree (v %d ) = %d \n  ",i+1,count);
    }
}
void outdegree(int m[10][10],int n)
{
    int i,j,count;
    for(i=0;i<n;i++)
    {
        count=0;
        for(j=0;j<n;j++)
        {
            if(m[i][j] == 1)
            {
                count++;

            }
        }
        printf("\n outdegree (v %d ) = %d \n  ",i+1,count);
    }
}


typedef struct node
{
    int vertex;
    struct node *next;
}node;

node *list[10];

void createlist(int m[10][10],int n)
{
    int i,j;
    struct  node *temp,*newnode;
    for(i=0;i<n;i++)
    {
        list[i]=NULL;
        for(j=0;j<n;j++)
        {
            if(m[i][j] == 1)
            {
                newnode=(node*)malloc(sizeof(node));
                newnode->vertex=j+1;
                newnode->next=NULL;
                if(list[i] == NULL)
                {

                    list[i]=temp=newnode;
                }
                else
                {
                    temp->next=newnode;
                    temp=newnode;
                }
            }
        }
    }
}

void displaylist(int n)
{
    struct node *temp;
    int i;
    printf("adjacency list is \n");
    for(i=0;i<n;i++)
    {
        printf("v%d -->",i+1);
        temp=list[i];
        while(temp)
        {
            printf("v%d-->",temp->vertex);
            temp=temp->next;
        }
        printf("NULL \n");
    }
}

int main()
{
    int m[10][10],n;
    printf("how many edges are there : ");
    scanf("%d",&n);
    creatematrix(m,n);
    displaymatrix(m,n);
    outdegree(m,n);
    indegree(m,n);
    createlist(m,n);
    displaylist(n);
}
