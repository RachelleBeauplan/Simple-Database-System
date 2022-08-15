//
// Created by Rachelle Beauplan on 12/10/20.
//

#include "ActorsBinaryTree.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

BSTActors::BSTActors()
{
    root= nullptr;
}
BSTActors::~BSTActors()
{
    deleteNode(root);
}

void BSTActors::deleteNode(BTNode* leaf)
{

    if (this->Root()==leaf) {
        delete leaf;
    }
    else if (leaf != nullptr)
    {
        deleteNode(leaf->LeftChildPtr());
        deleteNode(leaf->RightChildPtr());
        delete leaf;
    }
}


void BSTActors::insertNode(ActorBST _Actor) {
    BTNode* newNode = new BTNode (_Actor);
    newNode -> setKey(_Actor.getKey());
    if (this ->Root()== nullptr)
    {
        this->setRoot(newNode);
    }
    else
        insertNode(_Actor, this->Root());

}
void BSTActors::insertNode(ActorBST _Actor, BTNode* leaf)
{

    BTNode * newNode = new BTNode(_Actor);
    newNode->setKey(_Actor.getKey());
    newNode->setLeftChildPtr(nullptr);
    newNode->setRightChildPtr(nullptr);
    if ((_Actor.getKey() < leaf->Key()))
    {
        if (leaf->LeftChildPtr() == nullptr)
        {
            newNode->setParent(leaf);
            leaf->setLeftChildPtr(newNode);
        }
        else
            insertNode(_Actor, leaf->LeftChildPtr());

    }
    else
    {
        if (leaf->RightChildPtr() == nullptr)
        {
            newNode->setParent(leaf);
            leaf->setRightChildPtr(newNode);
        }
        else
            insertNode(_Actor, leaf->RightChildPtr());
    }
}



void BSTActors::readFromFile(string file, BSTActors* tree)
{
    ActorBST newBST;
    ifstream infile(file);
    int year;
    string award;
    int winner;
    string name;
    string film;
    string first;
    string temp;

    while (!infile.is_open() && file != "-1" ) {
        cout << "File not found!  Please reenter" << endl;
        getline(cin, file);
        infile.open(file);
    }
    if (infile.is_open())
    {
        getline(infile, first);
        while (infile.good()) {
            getline(infile, temp, ',');
            stringstream(temp) >> year;
            getline(infile, award, ',');
            getline(infile, temp, ',');
            stringstream(temp) >> winner;
            getline(infile, name, ',');
            getline(infile, film);
            tree->insertNode(ActorBST(year, award, winner, name, film));
        }
        infile.close();
    }
    else
    {
        while (file != "-1") {
            cout << "File not found." << endl;
            getline(cin, file);
            readFromFile(file, tree);
        }
    }


}
void BSTActors::modifyNode(BTNode * node)			// functions will modify the tree
{
    int userInput = 0;
    int userChoice;
    bool nameChange = false;
    string switchString="";
    string userString;
    while (switchString != "-1") {
        cout << "Select field to modify" << endl;
        cout << "1. Name" << endl << "2. Award" << endl << "3. Winner" << endl << "4. Year" << endl << "5. Film" << endl;
        cin >> userInput;
        cin.ignore();
        switch (userInput)
        {
            case 1:
                nameChange = true;
                cout << "What is the new name" << endl;
                getline(cin, userString);
                if (node->actorNode.getName() == node->actorNode.getKey()) {
                    node->actorNode.setKey(userString);
                };
                node->actorNode.setName(userString);
                break;
            case 2:
                cout << "What is the new name" << endl;
                getline(cin, userString);
                if (node->actorNode.getAward() == node->actorNode.getKey()) {
                    node->actorNode.setKey(userString);
                };
                node->actorNode.setAward(userString);
                break;
            case 3:
                cout << "Did the actor win their award? Enter 1 for Yes and 0 for No" << endl;
                cin >> userChoice;
                cin.ignore();
                node->actorNode.setWinner(userChoice);
                break;
            case 4:
                cout << "What is the new year" << endl;
                cin >> userChoice;
                cin.ignore();
                node->actorNode.setYear(userChoice);
                break;
            case 5:
                cout << "What is the new Film" << endl;
                getline(cin, userString);
                if (node->actorNode.getFilm() == node->actorNode.getKey()) {
                    node->actorNode.setKey(userString);
                };
                node->actorNode.setFilm(userString);
                break;
        }
        cout << "Here's the new information you've entered" << endl;
        node->actorNode.printActorfile();
        cout << endl;
        cout << "Do you want to modify another record? Press 1 to exit" << endl;
        getline(cin, switchString);
    }
    if (nameChange == true) {
        insertNode(node->actorNode);
        deleteNode(node);
    }
}
void BSTActors::exportFile(ofstream &outfile)
{
    exportFile(root, outfile);
}

void BSTActors::exportFile(BTNode *node, ofstream &outfile)
{
    if (node != nullptr)
    {
        outfile << node->actorNode.getYear() << "," << node->actorNode.getAward() << "," << node->actorNode.getWinner() << "," << node->actorNode.getName() << "," << node->actorNode.getFilm() << endl;
        exportFile(node->LeftChildPtr(), outfile);
        exportFile(node->RightChildPtr(), outfile);
    }
}
void BSTActors::switchAll(int& userinput, BTNode* node)
{
    if (userinput == 1) {
        if (node != nullptr)
        {
            switchAll(userinput, node->LeftChildPtr());
            node->setKey(node->getBST().getName());
            switchAll(userinput, node->RightChildPtr());
        }
    }
    else if (userinput == 2) {
        if (node != nullptr)
        {
            switchAll(userinput, node->LeftChildPtr());
            node->setKey(node->getBST().getAward());
            switchAll(userinput, node->RightChildPtr());
        }
    }
    else if (userinput == 3) {
        if (node != nullptr)
        {
            switchAll(userinput, node->LeftChildPtr());
            node->setKey(node->getBST().getFilm());
            switchAll(userinput, node->RightChildPtr());
        }
    }
}

//https://stackoverflow.com/questions/49970499/push-back-binary-tree-into-vector

BTNode * BSTActors::findNodeExact(string key)
{
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    return findNodeExact(key,root);
}

BTNode * BSTActors::findNodeExact(string key, BTNode* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    string nodeKey = node->Key();
    transform(nodeKey.begin(), nodeKey.end(), nodeKey.begin(), ::tolower);
    if ( key == nodeKey)							//return the node based on the key
    {
        return node;
    }
    if ((key < node->Key()))
    {
        return findNodeExact(key, node->LeftChildPtr());		// based on key, step to the left
    }
    else
    {
        return findNodeExact(key, node->RightChildPtr());		// based on key, step to the right
    }
}

//traverse the tree and see if the node exists-complete search
void BSTActors::findNodeExactAll(string key, vector<ActorBST>& data)
{
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    return findNodeExactAll(key, root, data);
}

void BSTActors::findNodeExactAll(string key, BTNode* node, vector<ActorBST>& data)
{
    BTNode* temp = new BTNode;				// create a new node
    if (node == nullptr)							// if node is empty, continue
    {
        return;
    }
    string nodeKey = node->Key();
    transform(nodeKey.begin(), nodeKey.end(), nodeKey.begin(), ::tolower);

    if ( key == nodeKey)						// If  key matches
    {
        temp = node;								// Point temp at the node
        temp->actorNode.setLoc(node);			// Set the location to the actor node
        data.push_back(temp->getBST());			// Push into the vector
    }
    if (key < node->Key())
    {
        return findNodeExactAll(key, node->LeftChildPtr(),data);  //check the left substree
    }
    else
    {
        return findNodeExactAll(key, node->RightChildPtr(),data);//check the right subtree
    }
    delete temp;
}

//traverse the tree and see if the node exists-complete search
void BSTActors::findNodeContainsAll(string key, vector<ActorBST>& data)
{
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    return findNodeContainsAll(key, root, data);
}

void BSTActors::findNodeContainsAll(string key, BTNode* node, vector<ActorBST>& data)
{
    BTNode* temp = new BTNode;
    if (node != nullptr) {
        findNodeContainsAll(key, node->LeftChildPtr(), data);

        string nodeKey = node->Key();
        transform(nodeKey.begin(), nodeKey.end(), nodeKey.begin(), ::tolower);
        if (nodeKey.find(key) != string::npos) {
            temp = node;
            temp->actorNode.setLoc(node);
            data.push_back(temp->getBST());
        }
        findNodeContainsAll(key, node->RightChildPtr(), data);
    }
    return;

}

void BSTActors::findNodeExact2(string key, vector<ActorBST>& data)
{
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    return findNodeExact2(key, root, data);
}

void BSTActors::findNodeExact2(string key, BTNode * node, vector<ActorBST>& data)
{
    BTNode* temp = new BTNode;
    if (node != nullptr) {
        findNodeExact2(key, node->LeftChildPtr(), data);
        string nodeKey = node->Key();
        transform(nodeKey.begin(), nodeKey.end(), nodeKey.begin(), ::tolower);
        if (nodeKey== key) {
            temp = node;
            temp->actorNode.setLoc(node);
            data.push_back(temp->getBST());
        }
        findNodeExact2(key, node->RightChildPtr(), data);
    }
    return;

}




void BSTActors::printPreorder()
{
    printPreorder(root);
    cout << endl;
}

void BSTActors::printPreorder(BTNode* node)
{
    if (node != nullptr)
    {
        cout << node->Key() << ", ";
        printPreorder(node->LeftChildPtr());
        printPreorder(node->RightChildPtr());
    }
}

void BSTActors::printPostorder()
{
    printPostorder(root);
    cout << endl;
}

void BSTActors::printPostorder(BTNode* node)
{
    if (node != nullptr)
    {
        printPostorder(node->LeftChildPtr());
        printPostorder(node->RightChildPtr());
        cout << node->Key() << ", ";
    }
}

void BSTActors::toVector(vector<ActorBST>& data)
{
    toVector(root, data);
}

void BSTActors::toVector(BTNode * node, vector<ActorBST>& data)
{
    if (node != nullptr)
    {
        toVector(node->LeftChildPtr(), data);
        toVector(node->RightChildPtr(), data);
        data.push_back(node->actorNode);
    }
}
BTNode* BSTActors::freeNode(BTNode* root, string key)
{

    if (root == nullptr) return root;
    else if (key < root->Key())
        root->setLeftChildPtr(freeNode(root->LeftChildPtr(), key));
    else if (key > root->Key())
        root->setRightChildPtr(freeNode(root->RightChildPtr(), key));
    else {

        if (root->LeftChildPtr() == nullptr && root->RightChildPtr() == nullptr) {
            delete root;
            root = nullptr;

        }
        else if (root->LeftChildPtr() == nullptr) {

            BTNode *temp = root->RightChildPtr();
            root->setKey(temp->Key());
            root->setLeftChildPtr(temp->LeftChildPtr());
            root->setRightChildPtr(temp->RightChildPtr());
            delete temp;
        }
        else if (root->RightChildPtr() == nullptr) {

            BTNode *temp = root->LeftChildPtr();
            root->setKey(temp->Key());
            root->setLeftChildPtr(temp->LeftChildPtr());
            root->setRightChildPtr(temp->RightChildPtr());
            delete temp;
        }
        else {
            BTNode *temp = min(root->RightChildPtr());
            root->setKey(temp->Key());
            root->setRightChildPtr(freeNode(root->RightChildPtr(), temp->Key()));
        }
    }
    return root;
}
void BSTActors::deleteTargetNode(BTNode * target)
{
    if (target == nullptr)
        return;
    else {
        if (target->LeftChildPtr() == nullptr && target->RightChildPtr() == nullptr) {
            delete target;
            target = nullptr;
        }
        else if (target->LeftChildPtr() == nullptr) {
            BTNode *temp = target->RightChildPtr();
            target->setKey(temp->Key());
            target->actorNode = (temp->actorNode);		//added this
            target->setLeftChildPtr(temp->LeftChildPtr());
            target->setRightChildPtr(temp->RightChildPtr());
            delete temp;
        }
        else if (target->RightChildPtr() == nullptr) {
            BTNode *temp = root->LeftChildPtr();
            target->setKey(temp->Key());
            target->actorNode = (temp->actorNode);		//added this
            target->setRightChildPtr(temp->LeftChildPtr());
            target->setRightChildPtr(temp->RightChildPtr());
            delete temp;
        }
        else {
            BTNode *temp = min(target->RightChildPtr());
            target->setKey(temp->Key());
            target->actorNode = (temp->actorNode);		//added this
            target->setRightChildPtr(freeNode(root->RightChildPtr(), temp->Key()));
        }
        return;
    }
}
void BSTActors::printInorderFile(ofstream& myfile, bool name, bool year, bool award, bool winner, bool film)
{
    printInorderFile(root, myfile, name, year, award, winner, film);
}

void BSTActors::printInorderFile(BTNode* node, ofstream& outfile, bool name, bool year, bool award, bool winner, bool film) {
    if (node != nullptr) {
        printInorderFile(node->LeftChildPtr(), outfile, name, year, award, winner, film);
        node->printActorFile();
        printInorderFile(node->RightChildPtr(), outfile, name, year, award, winner, film);
    }
}


//function to help keep track of the min level of the tree
BTNode* BSTActors::min(BTNode* node)
{
    BTNode* tempNode = node;
    if (node == nullptr) //check is tree is empty
        tempNode = nullptr;
    else if (node->LeftChildPtr()) //tree not empty, keep going down and the lef subtree
    {
        tempNode = min(node->LeftChildPtr());
    }
    else
        tempNode = node;

    return tempNode;
}

//function to keep track of the max level of the tree
BTNode* BSTActors::max(BTNode* node) {
    BTNode *tempNode = node;  //create new node
    if (node == nullptr)
        tempNode = nullptr;   //check if tree empty
    else if (node->RightChildPtr()) //tree not empty, go down and check the right subtree
        tempNode = max(node->RightChildPtr());
    else
        tempNode = node;

    return tempNode;
}
