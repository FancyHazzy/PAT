#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 110;

struct node{
    int lchild, rchild;
}Node[maxn];

bool notRoot[maxn] = {false};
int n, num = 0;

void postOrder(int root){
    if (root == -1) return ;
    postOrder(Node[root].lchild);
    postOrder(Node[root].rchild);
    swap (Node[root].lchild, Node[root].rchild);
}

void print(int root){
    printf("%d", root);
    num ++;
    if (num < n)
        printf(" ");
    else printf("\n");
}

void inOrder(int root){
    if (root == -1) return;
    inOrder(Node[root].lchild);
    print(root);
    inOrder(Node[root].rchild);
}

void BFS(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        print(now);
        if (Node[now].lchild != -1) q.push(Node[now].lchild);
        if (Node[now].rchild != -1) q.push(Node[now].rchild);
    }
}

int strToNum(char c){
    if (c == '-') return -1;
    else{
        notRoot[c - '0'] = true;
        return c - '0';
    }
}

int findRoot(){
    for (int i = 0;i < n;i++){
        if (notRoot[i] == false)
            return i;
    }
}

int main (void){
    char lchild, rchild;
    scanf("%d", &n);
    for (int i = 0;i < n;i++){
        scanf("%*c%c %c", &lchild, &rchild);
        Node[i].lchild = strToNum (lchild);
        Node[i].rchild = strToNum (rchild);
    }

 //   for (int i = 0;i < n;i++){
 //      printf("%d %d\n", Node[i].lchild, Node[i].rchild);
 //   }


    int root = findRoot();

    postOrder(root);

    BFS(root);//level-order

    num = 0;
    inOrder(root);


    return 0;
}



