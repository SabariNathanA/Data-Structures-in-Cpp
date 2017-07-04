
    std::queue <node*> list_of_seen;
    list_of_seen.push(root);
    
    while(!list_of_seen.empty())
    {
        node *here = list_of_seen.front();
        list_of_seen.pop();
        std::cout<<here->data<<" ";
        if(here->left) list_of_seen.push(here->left);
        if(here->right) list_of_seen.push(here->right);
    }
