#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cmath>
using std::ostream;
using std::string;

// TODO: your code  goes here

class Item {


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

    double distanceTo(Item item1){

        int R = 6373000; // The radius of the Earth

        /*
         * dlon = lon2 - lon1
           dlat = lat2 - lat1
           a = pow((sin(dlat/2)), 2) + cos(lat1) * cos(lat2) * pow((sin(dlon/2)), 2)
           c = 2 * atan2( sqrt(a), sqrt(1-a) )
           distance = R * c (where R is the radius of the Earth)
         */


        double dlon = degreesToRadians(item1.getLongitude()) - degreesToRadians(getLongitude());
        double dlat = degreesToRadians(item1.getLatitude()) - degreesToRadians(getLatitude());
        double a = pow((sin(dlat/2)), 2) + cos(getLatitude()) * cos(item1.getLatitude()) * pow((sin(dlon/2)), 2);
        double c = 2 * atan2( sqrt(a), sqrt(1-a) );
        double distance = R * c;
        return distance;


    }

    double degreesToRadians(double valueToConvert){
        double result = valueToConvert * ( M_PI / 180 );
        return result;
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

