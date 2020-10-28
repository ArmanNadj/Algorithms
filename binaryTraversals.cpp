#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>

    std::string root = "root";
    std::string left = "left";
    std::string right = "right";

//This program is to demonstrates pre-order, in-order, and post-order traversals.
//This program also demonstrates a basic implementation of a node and binary treee.


//this class represents a node
//this node contains a left and right node as well as a data value for the root of the node
class Node{
public:
Node * left;
Node * right;
Node(){left = right = NULL; data = 0;}
Node(int x){left = right = NULL; data = x;}
double getData(){return data;}
private:
double data;
};

//this class represents a binary tree
//this tree contains a simple root node to be implemented in the algorithm
class binaryTree {
public:
    Node * root;
    binaryTree(){root = NULL;}
    void destroyTree(Node * n){
        if(n == NULL)
            return;
        destroyTree(n->left);
        destroyTree(n->right);
        delete n;
    }
    ~binaryTree(){
        std::cout << "\nThe binary tree has been destroyed..." << std::endl;
        destroyTree(this->root);
    }
};

//this function implements a recursive pre-order traversal
//on first pass, spot contains the word "root"
void preOrder(Node * n, std::string spot){
    if(n == NULL)
        return;
    std::cout << "The " << spot << " node value is: " << n->getData() << "\n";
    if(n->left != NULL)
        preOrder(n->left, left);
    if(n->right != NULL)
        preOrder(n->right, right);
}


//this function implements a recursive in-order traversal
//on first pass, spot contains the word "root"
void inOrder(Node * n, std::string spot){
    if(n == NULL)
        return;
    if(n->left != NULL)
        preOrder(n->left, left);
    std::cout << "The " << spot << " node value is: " << n->getData() << "\n";
    if(n->right != NULL)
        preOrder(n->right, right);
}

//this function implements a recursive post-order traversal
//on first pass, spot contains the word "root"
void postOrder(Node * n, std::string spot){
    if(n == NULL)
        return;
    if(n->left != NULL)
        preOrder(n->left, "left");
    if(n->right != NULL)
        preOrder(n->right, "right");
    std::cout << "The " << spot << " node value is: " << n->getData() << "\n";
}


//this function does error checking to make sure that the proper
//data type is being inputted
double properInputting(){
    double x;
    while(1){
     if(std::cin >> x){
         return x;
     }
     else {
         std::cout << "Invalid entry. Please enter a numeric value: ";
         std::cin.clear();
         std::cin.get();
         std::cin.ignore();
         continue;
     }
    }
}

int main(int argc, char * argv[]){
    binaryTree * tree = new binaryTree(); //dynamically allocate a binary tree
    
    //taking in the data values for the three nodes then assigning them
    //to a variable
    double rootValue, leftValue, rightValue;
    std::cout << "Enter a numeric value for the root node: ";
    rootValue = properInputting();

    std::cout << "Enter a numeric value for the left node: ";
    leftValue = properInputting();

    std::cout << "Enter a numeric value for the right node: ";
    rightValue = properInputting();

    tree->root = new Node(rootValue);
    tree->root->left = new Node(leftValue);
    tree->root->right = new Node(rightValue);
 
    Node * n = tree->root;
    //printing the traversals
    printf("\n");   
    printf("Here we implement a Pre-Order Traversal: \n");
    preOrder(n, "root");
    printf("\n");
    printf("Here we implement an In-Order Traversal: \n");
    inOrder(n, "left");
    printf("\n");
    printf("Here we implement a Post-Order Traversal: \n");
    postOrder(n, "left");

    delete tree;
    std::cout << "Goodbye!" << std::endl;

}