//
// Created by Rachelle Beauplan on 12/10/20.
//

#ifndef OSCARSDATABASE_ACTORS_H
#define OSCARSDATABASE_ACTORS_H
#include <iostream>
#include <string>
using namespace std;


class BTNode;
class ActorBST{
private:
    int year;
    string award;
    int winner;
    string name;
    string film;
    string key;
    BTNode* loc;
public:


    ActorBST() //default constructor
    {
        year = 0;
        award="";
        winner=0;
        name="";
        film="";
        key="";
        loc= nullptr;
    };

    ActorBST(int _year, string _award, int _winner, string _name, string _film) // constructor
    {
        year= _year;
        award=_award;
        winner=_winner;
        name=_name;
        film=_film;
        key=_name;
        loc= nullptr;
    };

    //copy constructor
    ActorBST(const ActorBST &_Actor)
    {
        year = _Actor.getYear();
        award =_Actor.getAward();
        winner = _Actor.getWinner();
        name = _Actor.getName();
        film = _Actor.getFilm();
        key = _Actor.getKey();
        loc= _Actor.getLoc();


    }

    //Setters

    void setYear(int _year) {year=_year;}
    void setAward(string _award) {award=_award;}
    void setWinner(int _winner) {winner=_winner;}
    void setName(string _name) {name=_name;}
    void setFilm(string _film) {film=_film;}
    void setKey(string _key) {key=_key;}
    void setLoc (BTNode* _loc){loc=_loc;};

    //getters

    int getYear() const {return year;}
    string getAward() const{return award;}
    int getWinner() const {return winner;}
    string getName() const {return name;}
    string getFilm() const{return film;}
    string getKey() const {return key;}
    BTNode * getLoc() const {return loc;};



    void printActorfile()
    {
        cout  << " Year:    "  << this->getYear() << " Name:  "   << this->getName()<< "  Award:  " << this->getAward() << "  Winner:  ";
        if (this->getWinner() == 1)
            cout << "Yes";
        else
            cout << "No";
        cout << " Film:  " << this->getFilm() << endl;
        return;

    }


    bool operator <(ActorBST other) const {		// Overloaded < operator for sort
        if (key < other.getKey())
        {
            return true;
        }
        else
            return false;
    }





};

#endif //OSCARSDATABASE_ACTORS_H
