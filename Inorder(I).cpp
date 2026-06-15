#include<iostream>
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

    void inOrder(Node *root) {
        stack<Node*> st;
        Node* curr = root;
        while (curr !=NULL || ! st.empty()) {
            while (curr !=NULL) 
            {
                st.push(curr);
                curr = curr->left;
            
            }
            curr = st.top();
            st.pop();
            
            cout<<curr->data << " ";
            curr = curr-> right;
        
        } 

    }

};