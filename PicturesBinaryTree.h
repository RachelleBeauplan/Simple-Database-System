//
// Created by Rachelle Beauplan on 12/10/20.
//

#ifndef OSCARSDATABASE_PICTURESBINARYTREE_H
#define OSCARSDATABASE_PICTURESBINARYTREE_H
#include <vector>

#include "BTNodePicture.h"
using namespace std;

class BSTPictures {

private:

    void readFile();

    void insertNode(PictureBST _Picture, PictureBTnode *leaf);
    void printPreorder(PictureBTnode *node);
    void printPostorder(PictureBTnode *node);
    PictureBTnode *findExactNode(string key,PictureBTnode *parent);
    void findNodeExactAll(string key, PictureBTnode *parent,vector<PictureBST> &data);
    void findNodeContainsAll(string, PictureBTnode *parent,vector<PictureBST> &data);
    void findNodeExact2(string, PictureBTnode *, vector<PictureBST> &data);
    void exportFile(PictureBTnode *node, ofstream &outfile);
    void printInorder(PictureBTnode *node);
    void printInorder(PictureBTnode *, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool);
    void printInorderFile(PictureBTnode *, ofstream &, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool);
    int size(PictureBST *node);

    void toVector(PictureBTnode *, vector<PictureBST> &data);

    PictureBTnode *freeNode(PictureBTnode *node, string key);

    void deleteNode(PictureBTnode *leaf);

    void freeNode(string key);

    PictureBTnode *root;


public:
    BSTPictures();
    ~BSTPictures();


    void insertNode(PictureBST _Actor);
    void findNodeExactAll(string key, vector<PictureBST> &data);
    PictureBTnode *findExactNode(string key);
    void findNodeContainsAll(string key, vector<PictureBST> &data);
    void findNodeExact2(string key, vector<PictureBST> &data);
    void switchAll(int &userinput, PictureBTnode *node);
    void readFromFile(string, BSTPictures *);
    void exportFile(ofstream &);
    void modifyNode(PictureBTnode *node);
    PictureBTnode *Root() { return root; }
    void setRoot(PictureBTnode *_root) { root = _root; }
    void printInorder();
    void printInorder(bool, bool, bool, bool, bool, bool, bool, bool, bool, bool);
    void printInorderFile(ofstream &, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool);
    void printPreorder();
    void printPostorder();
    void deleteTargetNode(PictureBTnode *);
    PictureBTnode *min(PictureBTnode *node);
    PictureBTnode *max(PictureBTnode *node);

    void toVector(vector<PictureBST> &data);
};




#endif //OSCARSDATABASE_PICTURESBINARYTREE_H
