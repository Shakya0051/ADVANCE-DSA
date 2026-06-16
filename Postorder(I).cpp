#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }




    void postOrder(Node *root) {

      if(root == NULL)
        return;
        
        stack<Node*> s1, s2;
        s1.push(root);
        
        while (!s1.empty()) {
            Node* curr = s1.top();
            s1.pop();
            
            s2.push(curr);
            
            if(curr->left)
              s1.push(curr->left);
              
            if(curr->right)
               s1.push(curr->right);
        
        }
        while(!s2.empty()){
            cout << s2.top()->data << " ";
            s2.pop();
        }
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.postOrder(root);
    return 0;
}
