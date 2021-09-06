// Binary Search Tree is a node-based binary tree data structure which has the following properties
// 1.) The left subtree of a node contains only nodes with keys lesser than the node’s key.
// 2.) The right subtree of a node contains only nodes with keys greater than the node’s key.
// 3.) The left and right subtree each must also be a binary search tree. 
// 4.) There must be no duplicate nodes.
/*
class BST{
    value,right,left;
    BST* insert();         //O(log(h))
    BST* delete();
    int search(int key);  // O(log(h))
}
*/
// 1.)all basic operations(insert,delte,search);
// 2.)sorted array to binary search tree(more accurately this algorithm is for balanced BST constructio)
// 3.)Binary tree to Binary search tree while BT structure is maintaind
//      (do IOT and a store in an array---> sort array--->again do IOT and copy array elements to the tree)
// 4.)Check if a binary tree is BST;
// 5.Largest BST in a binary tree;
// 6.Lowest Common Ancestor in a Binary Search Tree.
// 6.)AVL Tree implementation(pending)
// 7.)Red Black Tree(pending)


#include<bits/stdc++.h>
using namespace std;

// There is no facilty of balancing so bst may be skewd;
// I did not find any array based implementation of BST as skewed tree will cause excess memeory wastage

class BST{
    int value;
    BST *left;
    BST *right;

    public:
    BST(){
        value=0;
        left=right=NULL;
    }
    BST(int);
    BST* insert(BST *,int);
    BST* deleteNode(BST*,int);
    BST* search(BST *,int );
    bool isBST(BST*,BST*,BST*);
    

};
BST::BST (int key){
        value=key;
        left=NULL;
        right=NULL;
    }
BST* BST:: search(BST *node,int key){
        if(node==NULL) return NULL;
        if(key==node->value) return node;
        if(key>node->value) return search(node->right,key);
        else return search(node->right,key);
    }
BST* BST:: insert(BST *node,int key){
        if(node==NULL) return new BST(key);

        if(key> node->value ){
            node->right=insert(node->right,key);
        }
        else{
            node->left=insert(node->left,key);
        }
    }
//In deletion there are three cases
//case 1: if node deleted is leaf node,it is simply deleted
//case 2: if node deleted has only one child: Copy the child to the node and delete the child 
//case 3: Node to be deleted has two children: Copy contents of the inorder successor/predecessor
//                                              to the node and delete the inorder successor


BST* BST::deleteNode(BST*node,int key){
    
    if(node==NULL) return NULL;

    if(key>node->value){
        node->right=deleteNode(node->right,key);
    }

    else if(key<node->value){
        node->left=deleteNode(node->left,key);
    }
    else{
        // if node does not have any children
        if(node->left==node->right==NULL){
            
            return NULL;
        }
        // if have only right chilld
        if(node->left==NULL){
            BST *temp=node->right;
            free(node);
            return temp;
        }
        //if have only right child
        if(node->right==NULL ){
           
            BST *temp=node->left;
            free(node);
            return temp;
            
        }
        //if have both children

        else{
            /*
             BST *temp=inorderSuccessor(node);
             //copy the inorder successor content in current node
             node->value=temp->value;
             //delete the inorder successor present in right subtree
             node->right= deleteNode(node->right,node->value);
             */
             BST *succParent=node;
             BST *succ=succ->right;
             while(succ && succ->left!=NULL){
                 succParent=succ;
                 succ=succ->left;
             }
             //since successor node is left child of its parent, also successor node does not have any left child,
             // we can safely make suuc->rightChild as succParent->leftChild, then make node data=succ-dta and deltee succecssor node;
             if(succParent!=node){
                 succParent->left=succ->right;
               
             }
             else succParent->right=succ->right;
              
              node->value=succ->value;
              delete succ;

        }
        return node;
    }
}
    bool BST::isBST(BST *root,BST *l,BST *r){
    if(root==NULL)                       return true;
    if(l!=NULL && root->value<=l->value) return false;
    if(r!=NULL && root->value>=r->value) return false;
    return ( isBST(root->left,l,root) && isBST(root->right,root,r) );     
}  //another method is inOrder Traversal of BST in increasing order



int main(){
    return 0;
}
