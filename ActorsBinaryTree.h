//
// Created by Rachelle Beauplan on 12/10/20.
//

#ifndef OSCARSDATABASE_ACTORSBINARYTREE_H
#define OSCARSDATABASE_ACTORSBINARYTREE_H
#include "BTNodeActor.h"
using namespace std;

class BSTActors{

private:


    BTNode* root;

    void readFile();
    void insertNode(ActorBST _Actor, BTNode* leaf);
    BTNode * findNodeExact(string key, BTNode* node);
    void findNodeExactAll(string key, BTNode* node, vector<ActorBST>& data);
    void findNodeContainsAll(string key, BTNode* node,vector<ActorBST>& data);
    void findNodeExact2(string key, BTNode* node,vector<ActorBST>& data);



    void exportFile(BTNode *node, ofstream &outfile);



    void toVector(BTNode*, vector<ActorBST>& data);									// Converst the entire BST into a vector.
    int size(BTNode* node);

    void printInorder(BTNode* node, bool, bool, bool, bool, bool);
    void printInorderFile(BTNode* node, ofstream&, bool, bool, bool, bool, bool);
    void printPreorder(BTNode* node);
    void printPostorder(BTNode* node);
    BTNode* freeNode(BTNode* node, string key);



public:
    BSTActors();
    ~BSTActors();


    void insertNode(ActorBST _Actor);
    void deleteNode(BTNode* leaf);
    void findNodeExactAll(string key, vector<ActorBST>& data);
    BTNode * findNodeExact(string key);
    void findNodeContainsAll(string key,vector<ActorBST>& data);
    void findNodeExact2(string key,vector<ActorBST>& data);


    void switchAll(int& userinput, BTNode* node);
    void readFromFile(string, BSTActors* );
    void exportFile(ofstream&);
    void modifyNode(BTNode * node);
    BTNode* Root() { return root;}
    void setRoot(BTNode * _root) { root = _root; }

    void printInorder(bool, bool, bool, bool, bool);
    void printInorderFile(ofstream&, bool, bool, bool, bool, bool);
    void printPreorder();
    void printPostorder();
    void deleteTargetNode(BTNode*);							// Deletes a node based on node's address
    BTNode* min(BTNode* node);
    BTNode* max(BTNode* node);
    void toVector(vector<ActorBST>& data);




};

#endif //OSCARSDATABASE_ACTORSBINARYTREE_H
