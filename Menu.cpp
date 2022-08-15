
#include "Menu.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;


void Menu::menuSelection()
{
    while (userinput!=-1)
    {

        cout << " Welcome to the 'Here comes the Academy Awards! Database'\n";
        cout << " At anypoint, enter '7' and you will exit the database \n";
        cout <<"\n";
        cout << " Please select from the following menu option (Enter 1-7): \n";
        cout << " 1. Print the CSV file to Binary Tree\n";
        cout << " 2. Add a record to the database\n";
        cout << " 3. Search for a record\n";
        cout << " 4. Modify a record \n";
        cout << " 5. Sort a single field\n";
        cout << " 6. Print out to database\n";
        cout << " 7. Exit\n";
        cin >> userinput;

        switch(userinput)
        {
            case 1:
                readFromFile();
                break;
            case 2:
                insertNode();
                break;
            case 3:
                searchNode();
                break;
            case 4:
                modify();
                break;
            case 5:
                sortMenu();
                break;
            case 6:
                printtoCSV();
                break;
            case 7:
                exit(0);

            default: userinput=0;

        }

    }
}
int Menu::BSTMenu()  //Allows userinput how which database to step into
{
    int userinput;
    cout << "Which database would you like to use" << endl;
    cout << "1. Actor/Actress" << endl;
    cout << "2. Pictures" << endl;
    cin >> userinput;
    while (cin.fail()) {
        cout << "Not valid. Try again." << endl;
        cin.clear();
        cin.ignore();
        cin >> userinput;
    }
    cin.ignore();
    if (userinput == -1)
        return -1;
    while (userinput != 1 && userinput != 2)
    {
        cout << "Not valid. Try again." << endl;
        cin.clear();
        cin.ignore();
        cin >> userinput;
    }
    return userinput;
}

void Menu::findActor()		// Search vector to find actor
{
    int userInput = 0;
    int searchType;
    string searchTerm;
    vector<ActorBST> v;
    while (userInput != 1 && userInput != 2 && userInput !=3) {
        cout << "What field would you like to search by?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Award" << endl;
        cout << "3. Film" << endl;
        cin >> userInput;
        cin.ignore();
        while (cin.fail()) {
            cout << "Not valid. Try again" << endl;
            cin.clear();
            cin.ignore();
            cin >> userInput;
        }
        cout << "How would you like to search" << endl;
        cout << "1. Exact" << endl;
        cout << "2. Contains" << endl;
        cin >> searchType;
        while (cin.fail()) {
            cout << "Not valid. Try again" << endl;
            cin.clear();
            cin.ignore();
            cin >> searchType;
        }
        cin.ignore();
        cout << "Enter the keyword to search" << endl;
        getline(cin, searchTerm);
        if (userInput == 1)
        {

            //check vector for the keyword
            for (int i = 0; i < sortActors.size(); i++)
            {
                sortActors[i].setKey(sortActors[i].getName());
            }
           // keyword found. sort the vector and push the into v
            ::sort(sortActors.begin(), sortActors.end());
            if (searchType == 1) {
                for (int i = 0; i < sortActors.size(); i++)
                {
                    if (sortActors[i].getKey() == searchTerm)
                    {
                        v.push_back(sortActors[i]);
                    }
                }
                sortActors = v;
                return;
            }
            if (searchType == 2) {
                // contains search
                for (int i = 0; i < sortActors.size(); i++)
                {
                    if (sortActors[i].getKey().find(searchTerm) != string::npos)
                    {
                        v.push_back(sortActors[i]);
                    }
                }
                sortActors = v;
                return;
            }
        }
        if (userInput == 2)
        {
            for (int i = 0; i < sortActors.size(); i++)
            {
                sortActors[i].setKey(sortActors[i].getAward());
            }
            ::sort(sortActors.begin(), sortActors.end());
            if (searchType == 1) {
                for (int i = 0; i < sortActors.size(); i++)
                {
                    if (sortActors[i].getKey() == searchTerm)
                    {
                        v.push_back(sortActors[i]);
                    }
                }
                sortActors = v;
                return;
            }
            if (searchType == 2) {
                for (int i = 0; i < sortActors.size(); i++)
                {
                    if (sortActors[i].getKey().find(searchTerm) != string::npos)
                    {
                        v.push_back(sortActors[i]);
                    }
                }
                sortActors = v;
                return;
            }
        }
        if (userInput == 3)
        {
            for (int i = 0; i < sortActors.size(); i++)
            {
                sortActors[i].setKey(sortActors[i].getFilm());
            }
            ::sort(sortActors.begin(), sortActors.end());
            if (searchType == 1) {
                for (int i = 0; i < sortActors.size(); i++)
                {
                    if (sortActors[i].getKey() == searchTerm)
                    {
                        v.push_back(sortActors[i]);
                    }
                }
                sortActors = v;
                return;
            }
            if (searchType == 2) {
                for (int i = 0; i < sortActors.size(); i++)
                {
                    if (sortActors[i].getKey().find(searchTerm) != string::npos)
                    {
                        v.push_back(sortActors[i]);
                    }
                }
                sortActors = v;
                return;
            }
        }
    }
}

void Menu::findPicture()
{
    int userInput = 0;
    int searchType;
    string searchTerm;
    vector<PictureBST> v;
    while (userInput != -1 && userInput != 1 && userInput != 2 && userInput !=3 && userInput !=4 && userInput !=5) {
        cout << "What field would you like to search by?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Genre1" << endl;
        cout << "3. Genre2" << endl;
        cout << "4. Release" << endl;
        cout << "5. Synopsis" << endl;
        cin >> userInput;
        while (cin.fail()) {
            cout << "Please make a valid selection" << endl;
            cin.clear();
            cin.ignore();
            cin >> userInput;
        }
        cout << "How would you like to search" << endl;
        cout << "1. Exact" << endl;
        cout << "2. Contains" << endl;
        cin >> searchType;
        while (cin.fail()) {
            cout << "Please make a valid selection" << endl;
            cin.clear();
            cin.ignore();
            cin >> searchType;
        }
        cin.ignore();
        cout << "Please enter search word" << endl;
        getline(cin, searchTerm);
        if (userInput == 1)
        {
            for (int i = 0; i < sortPictures.size(); i++)
            {
                sortPictures[i].setKey(sortPictures[i].getName());
            }
            ::sort(sortPictures.begin(), sortPictures.end());
            if (searchType == 1) {
                for (int i = 0; i < sortPictures.size(); i++)
                {
                    if (sortPictures[i].getKey() == searchTerm)
                    {
                        v.push_back(sortPictures[i]);
                    }
                }
                sortPictures = v;
                return;
            }
            if (searchType == 2) {
                for (int i = 0; i < sortPictures.size(); i++)
                {
                    if (sortPictures[i].getKey().find(searchTerm) != string::npos)
                    {
                        v.push_back(sortPictures[i]);
                    }
                }
                sortPictures = v;
                return;
            }
        }
        if (userInput == 2)
        {
            for (int i = 0; i < sortPictures.size(); i++)
            {
                sortPictures[i].setKey(sortPictures[i].getGenre1());
            }
            ::sort(sortPictures.begin(), sortPictures.end());
            if (searchType == 1) {
                for (int i = 0; i < sortPictures.size(); i++)
                {
                    if (sortPictures[i].getKey() == searchTerm)
                    {
                        v.push_back(sortPictures[i]);
                    }
                }
                sortPictures = v;
                return;
            }
            if (searchType == 2) {
                for (int i = 0; i < sortPictures.size(); i++)
                {
                    if (sortPictures[i].getKey().find(searchTerm) != string::npos)
                    {
                        v.push_back(sortPictures[i]);
                    }
                }
                sortPictures = v;
                return;
            }
        }
        if (userInput == 3)
        {
            for (int i = 0; i < sortPictures.size(); i++)
            {
                sortPictures[i].setKey(sortPictures[i].getGenre2());
            }
            ::sort(sortPictures.begin(), sortPictures.end());
            if (searchType == 1) {
                for (int i = 0; i < sortPictures.size(); i++)
                {
                    if (sortPictures[i].getKey() == searchTerm)
                    {
                        v.push_back(sortPictures[i]);
                    }
                }
                sortPictures = v;
                return;
            }
            if (searchType == 2) {
                for (int i = 0; i < sortPictures.size(); i++)
                {
                    if (sortPictures[i].getKey().find(searchTerm) != string::npos)
                    {
                        v.push_back(sortPictures[i]);
                    }
                }
                sortPictures = v;
                return;
            }
        }
        if (userInput == 4)
        {
            for (int i = 0; i < sortPictures.size(); i++)
            {
                sortPictures[i].setKey(sortPictures[i].getRelease());
            }
            ::sort(sortPictures.begin(), sortPictures.end());
            if (searchType == 1) {
                for (int i = 0; i < sortPictures.size(); i++)
                {
                    if (sortPictures[i].getKey() == searchTerm)
                    {
                        v.push_back(sortPictures[i]);
                    }
                }
                sortPictures = v;
                return;
            }
            if (searchType == 2) {
                for (int i = 0; i < sortPictures.size(); i++)
                {
                    if (sortPictures[i].getKey().find(searchTerm) != string::npos)
                    {
                        v.push_back(sortPictures[i]);
                    }
                }
                sortPictures = v;
                return;
            }
        }
        if (userInput == 5)
        {
            for (int i = 0; i < sortPictures.size(); i++)
            {
                sortPictures[i].setKey(sortPictures[i].getSynopsis());
            }
            ::sort(sortPictures.begin(), sortPictures.end());
            if (searchType == 1) {
                for (int i = 0; i < sortPictures.size(); i++)
                {
                    if (sortPictures[i].getKey() == searchTerm)
                    {
                        v.push_back(sortPictures[i]);
                    }
                }
                sortPictures = v;
                return;
            }
            if (searchType == 2) {
                for (int i = 0; i < sortPictures.size(); i++)
                {
                    if (sortPictures[i].getKey().find(searchTerm) != string::npos)
                    {
                        v.push_back(sortPictures[i]);
                    }
                }
                sortPictures = v;
                return;
            }
        }
    }
}

void Menu::printActorVector()
{
    if (sortActors.empty())
        cout << "No matching values found!!" << endl;
    else
        cout << setw(40) << left << "| Name";
    cout << setw(8) << left << "| Year";
    cout << setw(40) << left << "| Award";
    cout << setw(10) << left << "| Winner";
    cout << setw(70) << left << "| Film";
    cout << "|" << endl;
    for (int i = 0; i < sortActors.size(); i++)
    {
        cout << "| " << setw(38) << left << sortActors[i].getName();
        cout << "| " << setw(6) << left << sortActors[i].getYear();
        cout << "| " << setw(38) << left << sortActors[i].getAward();
        cout << "| " << setw(8) << left;
        if (sortActors[i].getWinner())
            cout << "Yes";
        else
            cout << "No";

        cout << "| " << setw(68) << left << sortActors[i].getFilm();
        cout << "|" << endl;
    }
}


void Menu::printPictureVector()
{
    if (sortPictures.empty())
        cout << "No matching values found!!" << endl;
    else
        cout << setw(60) << left << "| Name";
    cout << setw(8) << left << "| Year";
    cout << setw(15) << left << "| Nominations";
    cout << setw(10) << left << "| Rating";
    cout << setw(12) << left << "| Duration";
    cout << setw(12) << left << "| Genre 1";
    cout << setw(12) << left << "| Genre 2";
    cout << setw(12) << left << "| Release";
    cout << setw(15) << left << "| Metacritic";
    cout << "|" << endl;
    for (int i = 0; i < sortPictures.size(); i++)
    {
        cout << "| " << setw(58) << left << sortPictures[i].getName();
        cout << "| " << setw(6) << left << sortPictures[i].getYear();
        cout << "| " << setw(13) << left << sortPictures[i].getNominations();
        cout << "| " << setw(8) << left << sortPictures[i].getRating();
        cout << "| " << setw(10) << left << sortPictures[i].getDuration();
        cout << "| " << setw(10) << left << sortPictures[i].getGenre1();
        cout << "| " << setw(10) << left << sortPictures[i].getGenre2();
        cout << "| " << setw(10) << left << sortPictures[i].getRelease();
        cout << "| " << setw(13) << left << sortPictures[i].getMetacritic();
        cout << endl;
        cout << "| Synopsis: " << setw(148) << left << sortPictures[i].getSynopsis();
        cout << "|" << endl << endl;
    }
}

void Menu::insertNode()
{
    int addNodeInput;
    ActorBST newActor;
    PictureBST newPicture;
    int year;
    string award;
    int winner;
    string name;
    string film;
    int nominations;
    int rating;
    int duration;
    string genre1;
    string genre2;
    string release;
    int metacritic;
    string synopsis;

    addNodeInput = BSTMenu();
    if (addNodeInput == 1)
    {
        stringstream numConvert;
        string numString;
        cout << "Please enter the Actor/Actress' name" << endl;
        getline(cin, name);
        newActor.setName(name);
        cout << "Please enter the year" << endl;
        cin >> year;
        while (cin.fail()) {
            cout << "Please make a valid selection" << endl;
            cin.clear();
            cin.ignore();
            cin >> userinput;
        }
        cin.ignore();
        newActor.setYear(year);
        cout << "Please enter the award" << endl;
        getline(cin, award);
        newActor.setAward(award);
        cout << "Did the actor win? Enter 1 for YES and 0 for NO " << endl;
        cin >> winner;
        while (cin.fail()) {
            cout << "Not valid. Try again" << endl;
            cin.clear();
            cin.ignore();
            cin >> userinput;
        }
        cin.ignore();
        newActor.setWinner(winner);
        cout << "Please enter the film" << endl;
        getline(cin, film);
        newActor.setFilm(film);
        newActor.setKey(name);
        ActorBT.insertNode(newActor);

    }
    if (addNodeInput == 2)
    {

        cout << "Please enter the picture's name" << endl;
        getline(cin, name);
        newPicture.setName(name);
        cout << "Please enter the picture's year" << endl;
        cin >> year;
        while (cin.fail()) {
            cout << "Not valid. Try again" << endl;
            cin.clear();
            cin.ignore();
            cin >> userinput;
        }
        cin.ignore();
        newPicture.setYear(year);
        cout << "Please how many nominations the picture had" << endl;
        cin >> nominations;
        while (cin.fail()) {
            cout << "Not valid. Try again" << endl;
            cin.clear();
            cin.ignore();
            cin >> userinput;
        }
        cin.ignore();
        newPicture.setNominations(nominations);
        cout << "Please the picture's rating" << endl;
        cin >> rating;
        while (cin.fail()) {
            cout << "Not valid. Try again" << endl;
            cin.clear();
            cin.ignore();
            cin >> userinput;
        }
        cin.ignore();
        newPicture.setRating(rating);
        cout << "Please enter the duration of the picture" << endl;
        cin >> duration;
        while (cin.fail()) {
            cout << "Not valid. Try again" << endl;
            cin.clear();
            cin.ignore();
            cin >> userinput;
        }
        cin.ignore();
        newPicture.setRating(duration);
        cout << "Please enter Genre1 for the picture" << endl;
        getline(cin, genre1);
        newPicture.setGenre1(genre1);
        cout << "Please enter Genre2 for the picture" << endl;
        getline(cin, genre2);
        newPicture.setGenre2(genre2);
        cout << "Please enter the release month of the picture" << endl;
        getline(cin, release);
        newPicture.setRelease(release);
        cout << "Please  metacritic for the picture" << endl;
        cin >> metacritic;
        while (cin.fail()) {
            cout << "Not valid. Try again" << endl;
            cin.clear();
            cin.ignore();
            cin >> userinput;
        }
        cin.ignore();
        newPicture.setMetacritic(metacritic);
        cout << "Please synopsis of the picture" << endl;
        getline(cin, synopsis);
        newPicture.setSynopsis(synopsis);
        if (PictureBT.Root() == nullptr) {
            newPicture.setKey(name);
        }
        else {
            newPicture.setKey(PictureBT.Root()->getPicture().getKey());
        }
        PictureBT.insertNode(newPicture);
    }

}

void Menu::searchNode() {


    int userSelect = 0;
    int typeSelect = 0;
    int fieldSearch = 0;
    int moreInput = 0;
    int defaultkey = 1;
    string userString;
    while (userSelect != 1 && userSelect != 2) {
        cout << "You are about to search either the Actor-Actress database or the picture database" << endl;
        userSelect = BSTMenu();
        if (userSelect == -1) {
            return;
        }
    }
    while (typeSelect != 1 && typeSelect != 2) {
        cout << "How would you like to perform the search" << endl;
        cout << "1. Exact" << endl;
        cout << "2. Contains" << endl;
        cin >> typeSelect;
        while (cin.fail()) {
            cout << "Not valid. Try again" << endl;
            cin.clear();
            cin.ignore();
            cin >> typeSelect;
        }
        cin.ignore();
    }

    if (userSelect == 1) {
        sortActors.clear();
        ActorsBSTPtr->switchAll(defaultkey, ActorsBSTPtr->Root());
        cout << "Please select the field you want to search?" << endl;
        cout << "1. Actor-Actress Name" << endl;
        cout << "2. Award" << endl;
        cout << "3. Film" << endl;
        cout << "To exit, enter 0" << endl;
        cin >> fieldSearch;
        while (cin.fail()) {
            cout << "Please make a valid selection" << endl;
            cin.clear();
            cin.ignore();
            cin >> fieldSearch;
        }
        cin.ignore();
    } else if (userSelect == 2) {
        sortPictures.clear();
        PictureBSTPtr->switchAll(defaultkey, PictureBSTPtr->Root());
        cout << "Please select the field you want to search" << endl;
        cout << "Please be aware that any search other than by name will be less efficient" << endl;
        cout << "1. Name" << endl;
        cout << "2. Genre 1" << endl;
        cout << "3. Genre 2" << endl;
        cout << "4. Release" << endl;
        cout << "5. Synopsis" << endl;
        cout << " To exit, enter 0" << endl;
        cin >> fieldSearch;
        while (cin.fail()) {
            cout << "Please make a valid selection" << endl;
            cin.clear();
            cin.ignore();
            cin >> fieldSearch;
        }
        cin.ignore();
    }
    cout << "Please enter search word" << endl;
    getline(cin, userString);
    if (userSelect == 1 && typeSelect == 1 && fieldSearch == 1) {
        ActorsBSTPtr->findNodeExactAll(userString, sortActors);
    } else if (userSelect == 1 && typeSelect == 1 && fieldSearch != 1) {
        ActorsBSTPtr->switchAll(fieldSearch, ActorsBSTPtr->Root());
        ActorsBSTPtr->findNodeExact2(userString, sortActors);
    } else if (userSelect == 1 && typeSelect == 2 && fieldSearch == 1) {
        ActorsBSTPtr->findNodeContainsAll(userString, sortActors);
    } else if (userSelect == 1 && typeSelect == 2 && fieldSearch != 1) {
        ActorsBSTPtr->switchAll(fieldSearch, ActorsBSTPtr->Root());
        ActorsBSTPtr->findNodeContainsAll(userString, sortActors);
    } else if (userSelect == 2 && typeSelect == 1 && fieldSearch == 1) {
        PictureBSTPtr->findNodeExactAll(userString, sortPictures);
    } else if (userSelect == 2 && typeSelect == 1 && fieldSearch != 1) {
        PictureBSTPtr->switchAll(fieldSearch, PictureBSTPtr->Root());
        PictureBSTPtr->findNodeExactAll(userString, sortPictures);
    } else if (userSelect == 2 && typeSelect == 2 && fieldSearch == 1) {
        PictureBSTPtr->findNodeContainsAll(userString, sortPictures);
    } else if (userSelect == 2 && typeSelect == 2 && fieldSearch != 1) {
        PictureBSTPtr->switchAll(fieldSearch, PictureBSTPtr->Root());
        PictureBSTPtr->findNodeContainsAll(userString, sortPictures);
    }

    if (userSelect == 1) {
        while (moreInput != -1) {
            cout << "We've found " << sortActors.size()
                 << " file that matches your search. Would you like to see the result" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cin >> moreInput;
            while (cin.fail()) {
                cout << "Not valid. Try again" << endl;
                cin.clear();
                cin.ignore();
                cin >> moreInput;
                while (moreInput != 1 && moreInput != 2) {
                    cout << "Not valid. Try again" << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> moreInput;
                }
            }
            if (moreInput == 1) {
                printActorVector();
                break;
            } else
                break;

        }

        if (userSelect == 2) {
            while (moreInput != -1) {
                cout << "We've found " << sortPictures.size()
                     << " files that matches your search. Would you like to see the file(s)" << endl;
                moreInput = answer();
                if (moreInput == 1) {
                    printPictureVector();
                    break;
                } else
                    break;
            }
        }
    }
}


void Menu::sortMenu() {

    int userinput;
    int searchKey;
    stringstream cos;
    string st;

    cout << "Which database would you like to sort?" << endl;
    cout << "1: Actor-Actress Database" << endl;
    cout << "2: Pictures Database " << endl;
    cin >> userinput;

    if (userinput == 1) {
        cout << "Which field would you like to sort" << endl;
        cout << "1. Actor/Actress Name" << endl;
        cout << "2. Year" << endl;
        cout << "3. Award" << endl;
        cout << "4. Film" << endl;
        cout << "5. Winner" << endl;
        cin >> searchKey;
        while (cin.fail()) {
            cout << "Invalid selection" << endl;
            cin.clear();
            cin >> searchKey;
        }
        cin.ignore();
        while (searchKey != 1 && searchKey != 2 && searchKey != 3 && searchKey != 4 &&
               searchKey != 5)
        {
            cout << "Not valid. Try again" << endl;
            cin.clear();
            cin.ignore();
            cin >> searchKey;
        }
        if (searchKey == 1) {
            for (int i = 0; i < sortActors.size(); i++) {
                sortActors[i].setKey(sortActors[i].getName());
            }
            ::sort(sortActors.begin(),
                   sortActors.end());
        }

        if (searchKey == 2) {
            for (int i = 0; i < sortActors.size(); i++) {
                cos
                        << sortActors[i].getYear();
                st = cos.str();
                sortActors[i].setKey(
                        st);
                cos.str(std::string());
                cos.clear();
            }
            ::sort(sortActors.begin(), sortActors.end());
        }
        if (searchKey == 3) {
            for (int i = 0; i < sortActors.size(); i++) {
                sortActors[i].setKey(sortActors[i].getAward());
            }
            ::sort(sortActors.begin(), sortActors.end());
        }
        if (searchKey == 4) {
            for (int i = 0; i < sortActors.size(); i++) {
                sortActors[i].setKey(sortActors[i].getFilm());
            }
            ::sort(sortActors.begin(), sortActors.end());
        }
        if (searchKey == 5) {
            for (int i = 0; i < sortActors.size(); i++) {
                cos << sortActors[i].getWinner();
                st = cos.str();
                sortActors[i].setKey(st);
                cos.str(std::string());
                cos.clear();
            }
            ::sort(sortActors.begin(), sortActors.end());
        }

        if (userinput == 2) {
            cout << "Which field do you want to sort by" << endl;
            cout << "1. Name" << endl;
            cout << "2. Year" << endl;
            cout << "3. Nominations" << endl;
            cout << "4. Rating" << endl;
            cout << "5. Duration" << endl;
            cout << "6. Genre1" << endl;
            cout << "7. Genre2" << endl;
            cout << "8. Release" << endl;
            cout << "9. Metacritic" << endl;
            cout << "10. Synopsis" << endl;
            cin >> searchKey;
            cin.ignore();
            while (searchKey != 1 && searchKey != 2 && searchKey != 3 && searchKey != 4 && searchKey != 5) {
                cout << "Invalid selection. Please make another selection (1-10)" << endl;
                cin.clear();
                cin.ignore();
                cin >> searchKey;
            }
            if (searchKey == 1) {
                for (int i = 0; i < sortPictures.size(); i++) {
                    sortPictures[i].setKey(sortPictures[i].getName());
                }
                ::sort(sortPictures.begin(), sortPictures.end());
            }
            if (searchKey == 2) {
                for (int i = 0; i < sortPictures.size(); i++) {
                    cos << sortPictures[i].getYear();
                    st = cos.str();
                    sortPictures[i].setKey(st);
                    cos.str(std::string());
                    cos.clear();
                }
                ::sort(sortPictures.begin(), sortPictures.end());
            }
            if (searchKey == 3) {
                for (int i = 0; i < sortPictures.size(); i++) {
                    cos << sortPictures[i].getNominations();
                    st = cos.str();
                    sortPictures[i].setKey(st);
                    cos.str(std::string());
                    cos.clear();
                }
                ::sort(sortPictures.begin(), sortPictures.end());
            }
            if (searchKey == 4) {
                for (int i = 0; i < sortPictures.size(); i++) {
                    cos << sortPictures[i].getRating();
                    st = cos.str();
                    sortPictures[i].setKey(st);
                    cos.str(std::string());
                    cos.clear();
                }
                ::sort(sortPictures.begin(), sortPictures.end());
            }
            if (searchKey == 5) {
                for (int i = 0; i < sortPictures.size(); i++) {
                    cos << sortPictures[i].getDuration();
                    st = cos.str();
                    sortPictures[i].setKey(st);
                    cos.str(std::string());
                    cos.clear();
                }
                ::sort(sortPictures.begin(), sortPictures.end());
            }
            if (searchKey == 6) {
                for (int i = 0; i < sortPictures.size(); i++) {
                    sortPictures[i].setKey(sortPictures[i].getGenre1());
                }
                ::sort(sortPictures.begin(), sortPictures.end());
            }
            if (searchKey == 7) {
                for (int i = 0; i < sortPictures.size(); i++) {
                    sortPictures[i].setKey(sortPictures[i].getGenre2());
                }
                ::sort(sortPictures.begin(), sortPictures.end());
            }
            if (searchKey == 8) {
                for (int i = 0; i < sortPictures.size(); i++) {
                    sortPictures[i].setKey(sortPictures[i].getRelease());
                }
                ::sort(sortPictures.begin(), sortPictures.end());
            }
            if (searchKey == 9) {
                for (int i = 0; i < sortPictures.size(); i++) {
                    cos << sortPictures[i].getMetacritic();
                    st = cos.str();
                    sortPictures[i].setKey(st);
                    cos.str(std::string());
                    cos.clear();
                }
                ::sort(sortPictures.begin(), sortPictures.end());
            }
            if (searchKey == 10) {
                for (int i = 0; i < sortPictures.size(); i++) {
                    sortPictures[i].setKey(sortPictures[i].getSynopsis());
                }
                ::sort(sortPictures.begin(), sortPictures.end());
            }
        }
    }
}
void Menu::selectA()
{
    if (sortActors.empty())
    {
        cout << "Not valid. Try again" << endl;
        return;
    }
    int userinput=0;
    cout << "Enter 0 to start modifying" << endl;
    for (int i = 0; i < sortActors.size(); i++)
    {
        cout << i << ". ";
        sortActors[i].printActorfile();
        cout << endl;
    }
    cin >> userinput;
    while (cin.fail()) {
        cout << "Not valid. Try again" << endl;
        cin.clear();
        cin.ignore();
        cin >> userinput;
    }
    cin.ignore();
    while (userinput >= sortActors.size()) {
        cout << "Not found!" << endl;
        cin >> userinput;
        while (cin.fail()) {
            cout << "Please try again" << endl;
            cin.clear();
            cin.ignore();
            cin >> userinput;
        }
        cin.ignore();
    }
    ActorsNodePtr = sortActors[userinput].getLoc();
}

void Menu::selectP()
{
    if (sortPictures.empty())
    {
        cout << "Not valid! Try again" << endl;

        return;
    }
    int userInput = 0;
    cout << "Enter 0 to start modifying" << endl;
    for (int i = 0; i < sortPictures.size(); i++)
    {
        cout << i << ". ";
        sortPictures[i].printPicturefile();
        cout << endl;
    }
    cin >> userInput;
    while (cin.fail()) {
        cout << "Not valid. Try again" << endl;
        cin.clear();
        cin.ignore();
        cin >> userInput;
    }
    while (userInput >= sortPictures.size()) {
        cout << "Not found!" << endl;
        cin >> userInput;
        while (cin.fail()) {
            cout << "Please try again" << endl;
            cin.clear();
            cin.ignore();
            cin >> userInput;
        }
    }
    PictureNodePtr =sortPictures[userInput].getLoc();
}

void Menu::modify()							//Allows the user to select which record to modify based on search results
{
    int userch;
    int userinput;
    while (userch != -1)
    {
        cout << "Modifying record..." << endl;
        userch = BSTMenu();
        if (userch == -1) {
            return;
        }
        if (userch == 1)
        {
            selectA();
        }
        if (userch == 2)
        {
            selectP();
        }

        if (userch == 1) {
            while (ActorsNodePtr != nullptr && userinput != -1) {
                cout << "Result from your search. Do you want to modify it?" << endl;

                ActorsNodePtr->getBST().printActorfile();
                cout << endl;
                userinput = answer();
                while (userinput != 1 && userinput != 2)
                    cout << "Not valid. Please try again" << endl;
                if (userinput == 1)
                {
                    ActorBT.modifyNode(ActorsNodePtr);
                    userinput = -1;
                }
                else
                    break;
            }
        }
        if (userch == 2)
        {
            while (PictureNodePtr != nullptr && userinput != -1) {
                cout << "Proceed with caution! Do you want to modify these records?" << endl;
                PictureNodePtr->getPicture().printPicturefile();
                cout << endl;
                userinput = answer();
                while (userinput != 1 && userinput != 2)
                    cout << "Not valid. Please try again" << endl;
                if (userinput == 1)
                {
                    PictureBT.modifyNode(PictureNodePtr);
                    userinput = -1;
                }
                else
                    break;
            }
        }
        else
            userch = -1;
    }
}

void Menu::printtoCSV()
{
    ofstream outfile;
    int userinput;
    string file;
    cout << "Which database would you like to print to CSV?" << endl;
    cout << "1: Actor-Actress Database" << endl;
    cout << "2: Pictures Database" << endl;
    cin>>userinput;

    if (userinput == 1) {
        outfile.open("actor-actressout.csv");
        outfile << "Year,Award,Winner,Name,Film" << endl;
        ActorBT.exportFile(outfile);
    }
    if (userinput == 2) {
        outfile.open("picturesout.csv");
        outfile << "name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis" << endl;
        ActorBT.exportFile(outfile);
    }
    outfile.close();
    cout << "Database has been printed to CSV" << endl;

}

int Menu::answer()
{
    int userinput = 0;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cin >> userinput;
    while (cin.fail()) {
        cout << "Not valid. Try again" << endl;
        cin.clear();
        cin.ignore();
        cin >> userinput;
        while (userinput != 1 && userinput != 2)
        {
            cout << "Not valid. Try again" << endl;
            cin.clear();
            cin.ignore();
            cin >> userinput;
        }
    }
    return userinput;

}
void Menu::readFromFile()
{
    int userch;
    string selection;
    cout << "Are you ready to load the files into the Binary Search Tree" << endl;
    userch = BSTMenu();
    if (userch == -1) {
        return;
    }
    cout << "Enter 1 to read file into BST or enter filename" << endl;
    cin >> selection;
    if (userch == 1)
    {
        if (selection == "1")
            ActorsBSTPtr->readFromFile("actor-actress.csv", ActorsBSTPtr);
        else
            ActorsBSTPtr->readFromFile(selection, ActorsBSTPtr);
    }

    if (userch == 2)
    {
        if (selection == "1")
            PictureBSTPtr->readFromFile("pictures.csv", PictureBSTPtr);
        else
            PictureBSTPtr->readFromFile(selection, PictureBSTPtr);
    }

}



void Menu::printVector()
{
    int userch = 0;
    while (userch != -1) {
        cout << "What search data do you want to see:" << endl;
        userch = BSTMenu();
        if (userch == -1) {
            return;
        }
        if (userch == 1) {
            printActorVector();
            userch = -1;
        }
        if (userch == 2) {
            printPictureVector();
            userch = -1;
        } else
            cout << "Not valid. Please try again" << endl;
    }
}
