//已知后序和中序，输出层序遍历
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;
const int maxn = 50;
struct node{
    int data;
    node * lchild;
    node * rchild;
};

int pre[maxn], in[maxn], post[maxn];
int n;
int num = 0;

node* create(int postL, int postR, int inL, int inR){
    if (postL > postR){
        return NULL;
    }
    node* root = new node;
    root->data = post[postR];
    int k;
    for (k = inL; k <= inR; k++){
        if (in[k] == post[postR]){
            break;
        }
    }
    int numLeft = k - inL;
    root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    return root;

}

void BFS(node * root){
    queue<node* > q;
    q.push(root);
    while (!q.empty()){
        node* now = q.front();
        q.pop();
        printf("%d", now->data);
        num ++;
        if (num < n) printf(" ");
        if (now->lchild != NULL) q.push(now->lchild);
        if (now->rchild != NULL) q.push(now->rchild);
    }

    return ;
}




int main (void){
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n;i++){
        scanf("%d", &in[i]);
    }
    node * root = create(0, n - 1, 0, n - 1);
    BFS(root);



    return 0;
}
