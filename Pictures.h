//
// Created by Rachelle Beauplan on 12/10/20.
//

#ifndef OSCARSDATABASE_PICTURES_H
#define OSCARSDATABASE_PICTURES_H

#include <iostream>
#include <string>
using namespace std;


class PictureBTnode;
class PictureBST {
private:
    int year;
    string name;
    int nominations;
    int rating;
    int duration;
    string genre1;
    string genre2;
    string release;
    int metacritic;
    string synopsis;
    PictureBTnode *loc;
    string key;
public:

    PictureBST() {
        year = 0;
        nominations = 0;
        rating = 0;
        duration = 0;
        name = "";
        genre1 = "";
        genre2 = "";
        release = "";
        metacritic = 0;
        synopsis="";
        key = "";
        loc = nullptr;
    };

    PictureBST(string _name, int _year, int _nominations, int _rating, int _duration, string _genre1, string _genre2,string _release, int _metacritic, string _synopsis) // constructor
    {
        year = _year;
        nominations = _nominations;
        rating = _rating;
        duration = _duration;
        name = _name;
        genre1 = _genre1;
        genre2 = _genre2;
        release = _release;
        metacritic = _metacritic;
        synopsis=_synopsis;
        loc = nullptr;
        key = _name;
        loc = nullptr;
    };

    PictureBST(const PictureBST &_Picture) {
        year = _Picture.getYear();
        nominations = _Picture.getNominations();
        rating = _Picture.getRating();
        name = _Picture.getName();
        duration = _Picture.getDuration();
        genre1 = _Picture.getGenre1();
        genre2 = _Picture.getGenre2();
        release = _Picture.getRelease();
        metacritic = _Picture.getMetacritic();
        synopsis = _Picture.getSynopsis();
        key = _Picture.getKey();
        loc = _Picture.getLoc();


    }

    //Setters

    void setName(string _Name) { name = _Name; }                                    // Modifiers
    void setYear(int _Year) { year = _Year; }
    void setNominations(int _Nominations) { nominations = _Nominations; }
    void setRating(int _Rating) { rating = _Rating; }
    void setDuration(int _Duration) { duration = _Duration; }
    void setGenre1(string _Genre) { genre1 = _Genre; }
    void setGenre2(string _Genre) { genre2 = _Genre; }
    void setRelease(string _Release) { release = _Release; }
    void setMetacritic(int _Metacritic) { metacritic = _Metacritic; }
    void setSynopsis(string _Synopsis) { synopsis = _Synopsis; }
    void setKey(string _Key) { key = _Key; };
    void setLoc(PictureBTnode *_loc) { loc = _loc; };

    //getters

    string getName() const { return name; }                                                // Accessors
    int getYear() const { return year; }
    int getNominations() const {return nominations; }
    int getRating() const { return rating; }
    int getDuration() const { return duration; }
    string getGenre1() const { return genre1; }
    string getGenre2() const { return genre2; }
    string getRelease() const { return release; }
    int getMetacritic() const { return metacritic; }
    string getSynopsis() const { return synopsis; }
    string getKey() const { return key; }
    PictureBTnode *getLoc() const { return loc; };


//name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis
void printPicturefile()
{
        cout << " Name:  " << this->getName() << "Year: " << this->getYear() << " Nominations: "
             << this->getNominations();
        cout << " Rating: " << this->getRating() << "Genre 1: " << this->getGenre1() << "Genre 2: "
             << this->getGenre2();
        cout << "Release: " << this->getRelease() << "Metametric: " << this->getMetacritic() << "Synopsis: "
             << this->getSynopsis();
        return;


}


bool operator<(PictureBST other) const {
        if (key < other.getKey()) {
            return true;
        } else
            return false;
}


};




#endif //OSCARSDATABASE_PICTURES_H
