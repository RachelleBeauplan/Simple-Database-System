//
// Created by Rachelle Beauplan on 12/10/20.
//

#ifndef OSCARSDATABASE_MENU_H
#define OSCARSDATABASE_MENU_H
#include <vector>
#include "ActorsBinaryTree.h"
#include "PicturesBinaryTree.h"
using namespace std;

class Menu {
public:
    BSTActors ActorBT;
    BSTActors *ActorsBSTPtr;
    BSTPictures PictureBT;
    BSTPictures * PictureBSTPtr;
    BTNode *ActorsNodePtr;
    PictureBTnode *PictureNodePtr;
    vector<ActorBST> sortActors;
    vector <PictureBST> sortPictures;


    Menu()
    {
        ActorsBSTPtr = &ActorBT;
        PictureBSTPtr= &PictureBT;
    };

    void menuSelection();
    void findActor();
    void findPicture();
    void printActorVector();
    void printPictureVector();
    void selectA();
    void selectP();
    void printDatabase();
    void sort();
    void printVector();
    void insertNode();
    void sortMenu();
    void printtoCSV();
    void modify();
    void searchNode();
    void printActor();
    void readFromFile();
    int BSTMenu();
    int answer();
    int userinput=0;



};
#endif //OSCARSDATABASE_MENU_H
