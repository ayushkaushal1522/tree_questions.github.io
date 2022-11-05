vector<int> noSibling(Node* node)
{
    // code here
    vector<int> v;
    if(node==NULL) return{-1};
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp->left && temp->right){
            q.push(temp->left);
            q.push(temp->right);
            
        }
        else if(temp->left && !temp->right){
            v.push_back(temp->left->data);
            q.push(temp->left);
        }
        else if(!temp->left && temp->right){
            v.push_back(temp->right->data);
            q.push(temp->right);
        }
    }
    if(v.size()==0) return {-1};
    else{
        sort(v.begin(),v.end());
        return v;
    }
}