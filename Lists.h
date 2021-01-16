#include "Letter.cpp"
#include "Toys.cpp"
#include "GPS.cpp"
#ifndef PROIECTLABORATORPOO_LISTS_H
#define PROIECTLABORATORPOO_LISTS_H

#endif //PROIECTLABORATORPOO_LISTS_H

/**fisierul header contine toate listele si iteratorii declarati pe parcursul codului
   pentru o usoara urmarire a acestora
*/
list<Letter*> letters;
list<Letter*>::iterator it;
list<NaughtyCheck*> listCheck;
list<NaughtyCheck*>::iterator itr;
list<Toys*> myToys;
list<Toys*>::iterator toyIt;
list<string> wishes;
list<string>::iterator wishesIt;
list<string> toysForGood;
list<string> toysForBad;;
list<City*> cities;
list<City*>::iterator citiesIt;
list<GPS*> gps;
list<GPS*>::iterator gpsIt;
list<GPS*> gpsByDist;
list<GPS*> gpsByChildNr;


