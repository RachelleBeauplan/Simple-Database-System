//
// Created by Rachelle Beauplan on 12/10/20.
//

#ifndef OSCARSDATABASE_BTNODEPICTURE_H
#define OSCARSDATABASE_BTNODEPICTURE_H
#include <iomanip>
#include "Pictures.h"

#include <fstream>
using namespace std;


class PictureBTnode
{
private:
    PictureBTnode* leftChildPtr;
    PictureBTnode* rightChildPtr;
    PictureBTnode* parent;

public:
    PictureBST pictureNode;
    bool year=true;
    bool name=true;
    bool nominations = true;
    bool rating = true;
    bool duration = true;
    bool genre1 = true;
    bool genre2 = true;
    bool release = true;
    bool metacritic = true;
    bool synopsys=true;


    PictureBTnode(){pictureNode= PictureBST(); leftChildPtr= nullptr, rightChildPtr= nullptr, parent= nullptr;}


    PictureBTnode(const PictureBST &_Picture) {		// Constructor for ActorNode with an Actor object
        pictureNode = _Picture;
        leftChildPtr = nullptr;
        rightChildPtr = nullptr;
        parent = nullptr;
    };


    void setLeftChildPtr (PictureBTnode* left)
    {
        leftChildPtr =left;
    }
    void setRightChildPtr (PictureBTnode* right)
    {
        rightChildPtr =right;
    }
    void setParent (PictureBTnode* _parent)
    {
        parent=_parent;
    }

    void setKey(string _Key)
    {
        pictureNode.setKey(_Key);
    }





    PictureBTnode* LeftChildPtr()
    {
        return leftChildPtr;
    }
    PictureBTnode* RightChildPtr()
    {
        return rightChildPtr;
    }
    PictureBTnode* Parent()
    {
        return parent;
    }

    PictureBST getPicture()
    {
        return pictureNode;
    }

    string Key() { return pictureNode.getKey(); };


    void printPictureNode (bool name, bool year, bool nominations, bool rating, bool duration, bool genre1, bool genre2, bool release, bool metacritic, bool synopsis)
    {
        if (name)
        {   cout << "| " << setw(58)<<leftChildPtr << pictureNode.getName();}
        if (year)
        {   cout << "| " << setw(6)<<leftChildPtr << pictureNode.getYear();}
        if (nominations)
        {   cout << "| " << setw(13)<<leftChildPtr << pictureNode.getNominations();}
        if (rating) {
            cout << "| " << setw(8) << leftChildPtr<<pictureNode.getRating();}
        if (duration)
        {   cout << "| " << setw(10)<<leftChildPtr << pictureNode.getDuration();}
        if (genre1)
        {   cout << "| " << setw(10)<<leftChildPtr << pictureNode.getGenre1();}
        if (genre2)
        {   cout << "| " << setw(10)<<leftChildPtr << pictureNode.getGenre2();}
        if (release) {
            cout << "| " << setw(10) << leftChildPtr<<pictureNode.getRelease();}
        if (metacritic)
        {   cout << "| " << setw(10)<<leftChildPtr << pictureNode.getMetacritic();}
        if (synopsys) {
            cout << "| " << setw(226) << leftChildPtr<<pictureNode.getSynopsis();}
        cout << "|" << endl;

    }

    void printPictureFile (ostream& myfile, bool name, bool year, bool nominations, bool rating, bool duration, bool genre1, bool genre2, bool release, bool metacritic, bool synopsis)
    {
        ofstream outfile;
        if (name)
        {   cout << "| " << setw(58)<<leftChildPtr << pictureNode.getName();}
        if (year)
        {   cout << "| " << setw(6)<<leftChildPtr << pictureNode.getYear();}
        if (nominations)
        {   cout << "| " << setw(13)<<leftChildPtr << pictureNode.getNominations();}
        if (rating) {
            cout << "| " << setw(8) << leftChildPtr<<pictureNode.getRating();}
        if (duration)
        {   cout << "| " << setw(10)<<leftChildPtr << pictureNode.getDuration();}
        if (genre1)
        {   cout << "| " << setw(10)<<leftChildPtr << pictureNode.getGenre1();}
        if (genre2)
        {   cout << "| " << setw(10)<<leftChildPtr << pictureNode.getGenre2();}
        if (release) {
            cout << "| " << setw(10) << leftChildPtr<<pictureNode.getRelease();}
        if (metacritic)
        {   cout << "| " << setw(10)<<leftChildPtr << pictureNode.getMetacritic();}
        if (synopsys) {
            cout << "| " << setw(226) << leftChildPtr<<pictureNode.getSynopsis();}


    }


};
#endif //OSCARSDATABASE_BTNODEPICTURE_H
