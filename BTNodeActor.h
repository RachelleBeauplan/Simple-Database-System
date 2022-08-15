//
// Created by Rachelle Beauplan on 12/10/20.
//

#ifndef OSCARSDATABASE_BTNODEACTOR_H
#define OSCARSDATABASE_BTNODEACTOR_H
#include "Actors.h"
#include <fstream>
#include <iomanip>
using namespace std;

class BTNode
{
private:
    //accesors
    BTNode* leftChildPtr;
    BTNode* rightChildPtr;
    BTNode* parent;

public:

    ActorBST actorNode;
    bool year=true;
    bool name=true;
    bool award=true;
    bool winner=true;
    bool film = true;


    BTNode(){ //default constructor
        actorNode= ActorBST();
        leftChildPtr= nullptr,
        rightChildPtr= nullptr,
        parent= nullptr;
    };


    BTNode(const ActorBST &_Actor) {
        actorNode = _Actor;
        leftChildPtr = nullptr;
        rightChildPtr = nullptr;
        parent = nullptr;
    };




    void setLeftChildPtr (BTNode* left)
    {
        leftChildPtr =left;
    }
    void setRightChildPtr (BTNode* right)
    {
        rightChildPtr =right;
    }
    void setParent (BTNode* _parent)
    {
        parent=_parent;
    }

    void setKey(string _Key)
    {
        actorNode.setKey(_Key);
    }



    BTNode* LeftChildPtr()
    {
        return leftChildPtr;
    }
    BTNode* RightChildPtr()
    {
        return rightChildPtr;
    }
    BTNode* Parent()
    {
        return parent;
    }

    ActorBST getBST()
    {
        return actorNode;
    }

    string Key() { return actorNode.getKey(); };


    void printActorNode ()
    {
        if (year)
        { cout << "| " << setw(10)<<leftChildPtr << actorNode.getYear();}
        if (award)
        { cout << "| " << setw(40)<<leftChildPtr << actorNode.getAward();}
        if (name)
        { cout << "| " << setw(40)<<leftChildPtr << actorNode.getName();}
        if (winner) {
            cout << "| " << setw(10) << leftChildPtr;
            if (actorNode.getWinner())
                cout << "Yes";
            else
                cout << "No";
        }

        if (film) {
            cout << "| " << setw(70) << std::left << actorNode.getFilm();
        }
        cout << "|" << endl;

    }

    void printActorFile ()
    {
        ofstream outfile;
        if (year)
        { outfile << "| " << setw(10)<<leftChildPtr << actorNode.getYear();}
        if (award)
        { outfile << "| " << setw(40)<<leftChildPtr << actorNode.getAward();}
        if (name)
        { outfile << "| " << setw(40)<<leftChildPtr << actorNode.getName();}
        if (winner)
        {
            outfile << "| " << setw(10) << leftChildPtr;
            if (actorNode.getWinner())
                cout << "Yes";
            else
                cout << "No";
        }
        if (film) {
            outfile << "| " << setw(68) << std::left << actorNode.getFilm();}
        outfile << "|" << endl;
    }


};
#endif //OSCARSDATABASE_BTNODEACTOR_H
