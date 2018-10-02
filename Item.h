#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using std::ostream;
using std::string;

// TODO: your code  goes here

class Item {

   // friend ostream& operator<<(ostream &o, const  Item& item);

private:
    double latitude;
    double longitude;
    string name;
    int time;

public:
    Item(double lat, double lon, string n, int t) {
        latitude = lat;
        longitude = lon;
        name = n;
        time = t;
    }



    double getLatitude() {
        return latitude;
    }

    double getLongitude() {
        return longitude;
    }

    string getName(){
        return '"' + name + '"';
    }

    int getTime(){
        return time;
    }


};


ostream & operator<< (ostream & o, Item & item)
{
    o << "{"
      << item.getLatitude()
      << ", "
      << item.getLongitude()
      << ", "
      << item.getName()
      << ", "
      << item.getTime()
      << "}";

    return o;
}

// don't write any code below this line

#endif

