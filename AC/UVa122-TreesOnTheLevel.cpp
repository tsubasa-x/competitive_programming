#include <bits/stdc++.h>
using namespace std;

struct Node{
    bool have_value = false;
    int v;
    Node* left = NULL;
    Node* right = NULL;
};
int cnt = -1;
Node node[256];
Node* newnode(){ Node* u = &node[cnt++]; u->left = u->right = NULL; u->have_value = false; return u; }
Node* root = newnode();

bool failed = false;
vector<int> ans;
bool bfs(){
    ans.clear();
    queue<Node*> que;
    Node* c;
    que.emplace(root);
    while(!que.empty()){
        c = que.front(); que.pop();
        if(!c->have_value) return true;
        ans.emplace_back(c->v);
        if(c->left != NULL) que.push(c->left);
        if(c->right!= NULL) que.push(c->right);
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char ch[9999];
    //bool t = false;
    while(cin >> ch){
        if(ch[1] == ')'){
            failed = bfs();
            //if(t) cout << '\n';
            if(failed) cout << "not complete";
            else{
                for(vector<int>::iterator it = ans.begin(); it < ans.end(); it++){
                    cout << *it;
                    if(it < ans.end()-1) cout << ' ';
                }
            }
            cout << '\n';
            //t = true;
            cnt = -1;
            root = newnode();
            failed = false;
        }else{
            if(!failed){
                int value;
                sscanf(&ch[1], "%d", &value);
                char *pos = strchr(ch, ',')+1;
                int n = strlen(pos);
                Node* current = root;
                for(int i = 0; i < n; i++){
                    if(pos[i] == 'L'){
                        if(current->left == NULL) current->left = newnode();
                        current = current->left;
                    }else if(pos[i] == 'R'){
                        if(current->right == NULL) current->right = newnode();
                        current = current->right;
                    }
                }
                if(current->have_value) failed = true;
                else{ current->have_value = true; current->v = value; }
            }
        }
    }
}
