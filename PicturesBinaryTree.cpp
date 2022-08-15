//
// Created by Rachelle Beauplan on 12/10/20.
//

#include "PicturesBinaryTree.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;


BSTPictures::BSTPictures()
{
    root= nullptr;
}
BSTPictures::~BSTPictures()
{
    deleteNode(root);
}

void BSTPictures::deleteNode(PictureBTnode* leaf)
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


void BSTPictures::insertNode(PictureBST _Picture) {
    PictureBTnode* newNode = new PictureBTnode(_Picture);
    newNode -> setKey(_Picture.getKey());
    if (this ->Root()== nullptr)
    {
        this->setRoot(newNode);
    }
    else
        insertNode(_Picture, this->Root());

}
void BSTPictures::insertNode(PictureBST _Picture, PictureBTnode* leaf)
{

    PictureBTnode * newNode = new PictureBTnode(_Picture);
    newNode->setKey(_Picture.getKey());
    newNode->setLeftChildPtr(nullptr);
    newNode->setRightChildPtr(nullptr);
    if ((_Picture.getKey() < leaf->Key()))
    {
        if (leaf->LeftChildPtr() == nullptr)
        {
            newNode->setParent(leaf);
            leaf->setLeftChildPtr(newNode);
        }
        else
            insertNode(_Picture, leaf->LeftChildPtr());

    }
    else
    {
        if (leaf->RightChildPtr() == nullptr)
        {
            newNode->setParent(leaf);
            leaf->setRightChildPtr(newNode);
        }
        else
            insertNode(_Picture, leaf->RightChildPtr());
    }
}



void BSTPictures::readFromFile (string file, BSTPictures* tree)		// Function to read from a csv file into a BST
{

        PictureBST newpicBST;
        ifstream infile(file);
        string name;
        int year;
        int nominations;
        float rating;
        int duration;
        string genre1;
        string genre2;
        string release;
        int metacritic;
        string synopsis;
        PictureBTnode *Loc;
        string first;
        string temp;
        while (!infile.is_open() && file != "-1") {
            cout << "File not found! Reenter file name" << endl;
            getline(cin, file);
            infile.open(file);
        }
        if (infile.is_open()) {
            getline(infile, first);
            while (infile.is_open()) {
                getline(infile, name, ',');
                getline(infile, temp, ',');
                stringstream(temp) >> year;
                getline(infile, temp, ',');
                stringstream(temp) >> nominations;
                getline(infile, temp, ',');
                stringstream(temp) >> rating;
                getline(infile, temp, ',');
                stringstream(temp) >> duration;
                getline(infile, genre1, ',');
                getline(infile, genre2, ',');
                getline(infile, release, ',');
                getline(infile, temp, ',');
                stringstream(temp) >> metacritic;
                getline(infile, synopsis);
                tree->insertNode(PictureBST(name, year, nominations, rating, duration, genre1, genre2, release, metacritic,
                                   synopsis));
            }
            infile.close();
        }
}


void BSTPictures::freeNode(string key)
{
    {
        if (freeNode(Root(), key) == nullptr)
            setRoot(nullptr);
    }
}


PictureBTnode* BSTPictures::freeNode(PictureBTnode* root, string key)
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
            PictureBTnode *temp = root->RightChildPtr();
            root->setKey(temp->Key());
            root->setLeftChildPtr(temp->LeftChildPtr());
            root->setRightChildPtr(temp->RightChildPtr());
            delete temp;
        }
        else if (root->RightChildPtr() == nullptr) {
            PictureBTnode *temp = root->LeftChildPtr();
            root->setKey(temp->Key());
            root->setLeftChildPtr(temp->LeftChildPtr());
            root->setRightChildPtr(temp->RightChildPtr());
            delete temp;
        }
        else {
            PictureBTnode *temp = min(root->RightChildPtr());
            root->setKey(temp->Key());
            root->setRightChildPtr(freeNode(root->RightChildPtr(), temp->Key()));
        }
    }
    return root;
}

void BSTPictures::modifyNode(PictureBTnode * node)			//modify specific node
{
    int userinput = 0;
    int choice;
    bool change = false;
    string switchString="";
    string userString;
    while (switchString != "-1") {
        cout << "Which field like to modify" << endl;
        cout << "1. Name" << endl << "2. Award" << endl << "3. Winner" << endl << "4. Year" << endl << "5. Film" << endl;
        cin >> userinput;
        cin.ignore();
        switch (userinput)
        {
            case 1:
                change = true;
                cout << "What is the new name" << endl;
                getline(cin, userString);
                if (node->pictureNode.getName() == node->pictureNode.getKey()) {
                    node->pictureNode.setKey(userString);
                };
                node->pictureNode.setName(userString);
                break;
            case 2:
                cout << "What is the new year" << endl;
                cin >> choice;
                cin.ignore();
                node->pictureNode.setYear(choice);
                break;
            case 3:
                cout << "What is the number nominations" << endl;
                cin >> choice;
                cin.ignore();
                node->pictureNode.setNominations(choice);
                break;
            case 4:
                cout << "What is the new rating" << endl;
                cin >> choice;
                cin.ignore();
                node->pictureNode.setRating(choice);
                break;
            case 5:
                cout << "What is the new Duration" << endl;
                cin >> choice;
                cin.ignore();
                node->pictureNode.setRating(choice);
                break;
            case 6:
                cout << "What is the new Genre1" << endl;
                getline(cin, userString);
                if (node->pictureNode.getGenre1() == node->pictureNode.getKey()) {
                    node->pictureNode.setKey(userString);
                };
                node->pictureNode.setGenre1(userString);
                break;
            case 7:
                cout << "What is the new Genre2" << endl;
                getline(cin, userString);
                if (node->pictureNode.getGenre2() == node->pictureNode.getKey()) {
                    node->pictureNode.setKey(userString);
                };
                node->pictureNode.setGenre2(userString);
                break;
            case 8:
                cout << "What is the new release month" << endl;
                getline(cin, userString);
                if (node->pictureNode.getRelease() == node->pictureNode.getKey()) {
                    node->pictureNode.setKey(userString);
                };
                node->pictureNode.setRelease(userString);
                break;
            case 9:
                cout << "What is the  new metacritic rating" << endl;
                cin >> choice;
                cin.ignore();
                node->pictureNode.setMetacritic(choice);
                break;
            case 10:
                cout << "What is the new synopsis" << endl;
                getline(cin, userString);
                if (node->pictureNode.getSynopsis() == node->pictureNode.getKey()) {
                    node->pictureNode.setKey(userString);
                };
                node->pictureNode.setSynopsis(userString);
                break;
            default:
                break;

        }
        cout << "New Record information" << endl;
        node->pictureNode.printPicturefile();
        cout << endl;
        cout << "To exit, enter -1. Otherwise press enter to continue" << endl;
        getline(cin, switchString);
    }
    if (change == true) {
        insertNode(node->pictureNode);
        deleteNode(node);
    }
}

void BSTPictures::exportFile(ofstream &outfile)
{
    exportFile(root, outfile);
}

void BSTPictures::exportFile(PictureBTnode *node, ofstream &outfile)
{
    if (node != nullptr)
    {
        outfile << node->pictureNode.getName() << "," << node->pictureNode.getYear() << "," << node->pictureNode.getNominations() << "," << node->pictureNode.getRating() << ",";
        outfile << node->pictureNode.getDuration() << "," << node->pictureNode.getGenre1() << "," << node->pictureNode.getGenre2() << "," << node->pictureNode.getRelease() << ",";
        outfile << node->pictureNode.getMetacritic() << "," << node->pictureNode.getSynopsis() << endl;
        exportFile(node->LeftChildPtr(), outfile);
        exportFile(node->RightChildPtr(), outfile);
    }
}
void BSTPictures::switchAll(int& userinput, PictureBTnode* node)
{
    if (userinput == 1) {
        if (node != nullptr)
        {
            switchAll(userinput, node->LeftChildPtr());
            node->setKey(node->getPicture().getName());
            switchAll(userinput, node->RightChildPtr());
        }
    }
    else if (userinput == 2) {
        if (node != nullptr)
        {
            switchAll(userinput, node->LeftChildPtr());
            node->setKey(node->getPicture().getGenre1());
            switchAll(userinput, node->RightChildPtr());
        }
    }
    else if (userinput == 3) {
        if (node != nullptr)
        {
            switchAll(userinput, node->LeftChildPtr());
            node->setKey(node->getPicture().getGenre2());
            switchAll(userinput, node->RightChildPtr());
        }
        else if (userinput == 4) {
            if (node != nullptr)
            {
                switchAll(userinput, node->LeftChildPtr());
                node->setKey(node->getPicture().getRelease());
                switchAll(userinput, node->RightChildPtr());
            }
        }
        else if (userinput == 5) {
            if (node != nullptr) {
                switchAll(userinput, node->LeftChildPtr());
                node->setKey(node->getPicture().getSynopsis());
                switchAll(userinput, node->RightChildPtr());
            }
        }
    }
}



PictureBTnode * BSTPictures::findExactNode(string key)			// Find first node based on key
{
    transform(key.begin(), key.end(), key.begin(), ::tolower); //make case insensitive
    return findExactNode(key,root);
}

PictureBTnode * BSTPictures::findExactNode(string key, PictureBTnode* node)	// Private function to find node
{
    if (node == nullptr)
    {
        return nullptr;
    }

    string nodeKey = node->Key();
    transform(nodeKey.begin(), nodeKey.end(), nodeKey.begin(), ::tolower);
    if ( key == nodeKey)							// search key matches the node's key
    {
        return node;									// Return the node
    }
    if ((key < node->Key()))
    {
        return findExactNode(key, node->LeftChildPtr());		// If key is smaller go left
    }
    else
    {
        return findExactNode(key, node->RightChildPtr());		// otherwise go right
    }
}

void BSTPictures::findNodeExactAll(string key, vector<PictureBST>& data)			// Find all exact nodes if the key is based on the BST
{
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    return findNodeExactAll(key, root, data);
}

void BSTPictures::findNodeExactAll(string key, PictureBTnode* node, vector<PictureBST>& data)
{
    PictureBTnode* temp = new PictureBTnode;
    if (node == nullptr)
    {
        return;
    }
    string nodeKey = node->Key();
    transform(nodeKey.begin(), nodeKey.end(), nodeKey.begin(), ::tolower);

    if ( key == nodeKey)
    {
        temp = node;
        temp->pictureNode.setLoc(node);
        data.push_back(temp->getPicture());
    }
    if ((key < node->Key()))
    {
        return findNodeExactAll(key, node->LeftChildPtr(),data);
    }
    else
    {
        return findNodeExactAll(key, node->RightChildPtr(),data);
    }
    delete temp;
}

void BSTPictures::findNodeContainsAll(string key, vector<PictureBST>& data)
{
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    return findNodeContainsAll(key, root, data);
}


void BSTPictures::findNodeContainsAll(string key, PictureBTnode* node, vector<PictureBST>& data)		// Adds all actors from nodes that contain a key to a vector using tree traversal
{
    PictureBTnode* temp = new PictureBTnode;
    if (node != nullptr) {
        findNodeContainsAll(key, node->LeftChildPtr(), data);
        string nodeKey = node->Key();
        transform(nodeKey.begin(), nodeKey.end(), nodeKey.begin(), ::tolower);
        if (nodeKey.find(key) != string::npos) {
            temp = node;
            temp->pictureNode.setLoc(node);
            data.push_back(temp->getPicture());
        }
        findNodeContainsAll(key, node->RightChildPtr(), data);
    }
    return;

}
//traverse unsorted node
void BSTPictures::findNodeExact2(string key, vector<PictureBST>& data)
{
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    return findNodeExact2(key, root, data);
}

void BSTPictures::findNodeExact2(string key, PictureBTnode * node, vector<PictureBST>& data)
{
    PictureBTnode* temp = new PictureBTnode;
    if (node != nullptr) {
        findNodeExact2(key, node->LeftChildPtr(), data);
        string nodeKey = node->Key();
        transform(nodeKey.begin(), nodeKey.end(), nodeKey.begin(), ::tolower);
        if (nodeKey== key) {
            temp = node;
            temp->pictureNode.setLoc(node);
            data.push_back(temp->getPicture());
        }
        findNodeExact2(key, node->RightChildPtr(), data);
    }
    return;

}



void BSTPictures::printPreorder()
{
    printPreorder(root);
    cout << endl;
}

void BSTPictures::printPreorder(PictureBTnode* node)
{
    if (node != nullptr)
    {
        cout << node->Key() << ", ";
        printPreorder(node->LeftChildPtr());
        printPreorder(node->RightChildPtr());
    }
}

void BSTPictures::printPostorder()
{
    printPostorder(root);
    cout << endl;
}

void BSTPictures::printPostorder(PictureBTnode* node)
{
    if (node != nullptr)
    {
        printPostorder(node->LeftChildPtr());
        printPostorder(node->RightChildPtr());
        cout << node->Key() << ", ";
    }
}

void BSTPictures::toVector(vector<PictureBST>& data)
{
    toVector(root, data);
}

void BSTPictures::toVector(PictureBTnode * node, vector<PictureBST>& data)		// create vector for easy sorting
{
    if (node != nullptr)
    {
        toVector(node->LeftChildPtr(), data);
        toVector(node->RightChildPtr(), data);
        data.push_back(node->pictureNode);
    }
}

void BSTPictures::deleteTargetNode(PictureBTnode * target)			// Allow the user to delete the node directly
{
    if (target == nullptr)
        return;
    else {
        // Case 1: No Child
        if (target->LeftChildPtr() == nullptr && target->RightChildPtr() == nullptr) {
            delete target;
            target = nullptr;
            // Case 2: one child
        }
        else if (target->LeftChildPtr() == nullptr) {
            PictureBTnode *temp = target->RightChildPtr();
            target->setKey(temp->Key());
            target->pictureNode = (temp->pictureNode);		//added this
            target->setLeftChildPtr(temp->LeftChildPtr());
            target->setRightChildPtr(temp->RightChildPtr());
            delete temp;
        }
        else if (target->RightChildPtr() == nullptr) {
            PictureBTnode *temp = root->LeftChildPtr();
            target->setKey(temp->Key());
            target->pictureNode = (temp->pictureNode);		//added this
            target->setRightChildPtr(temp->LeftChildPtr());
            target->setRightChildPtr(temp->RightChildPtr());
            delete temp;
        }
        else {
            PictureBTnode *temp = min(target->RightChildPtr());
            target->setKey(temp->Key());
            target->pictureNode = (temp->pictureNode);		//added this
            target->setRightChildPtr(freeNode(root->RightChildPtr(), temp->Key()));
        }
        return;
    }
}
void BSTPictures::printInorder()				// Prints the trees inorder
{
    printInorder(root, true, true, true, true, true, true, true, true, true, true);
}

void BSTPictures::printInorder(bool name, bool year, bool nominations, bool rating, bool duration, bool genre1, bool genre2, bool release, bool metacritic, bool synopsis)
{
    printInorder(root, name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis);
}

void BSTPictures::printInorder(PictureBTnode* node, bool name, bool year, bool nominations, bool rating, bool duration, bool genre1, bool genre2, bool release, bool metacritic, bool synopsis)
{
    if (node != nullptr)
    {
        printInorder(node->LeftChildPtr(), name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis);
        node->printPictureNode(name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis);

        printInorder(node->RightChildPtr(), name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis);
    }
}

PictureBTnode* BSTPictures::min(PictureBTnode* node)
{
    PictureBTnode* tempNode = node;
    if (node == nullptr)
        tempNode = nullptr;
    else if (node->LeftChildPtr())
    {
        tempNode = min(node->LeftChildPtr());
    }
    else
        tempNode = node;

    return tempNode;
}

PictureBTnode* BSTPictures::max(PictureBTnode* node)
{
    PictureBTnode * tempNode = node;
    if (node == nullptr)
        tempNode = nullptr;
    else if (node->RightChildPtr())
        tempNode = max(node->RightChildPtr());
    else
        tempNode = node;

    return tempNode;
}

//https://stackoverflow.com/questions/42951748/c-bst-tree-insert-a-string