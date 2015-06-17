/* 
 * File:   Location.h
 * Author: Ido
 *
 * Created on 16 יוני 2015, 19:53
 */

#ifndef LOCATION_H
#define	LOCATION_H

struct Location
{
    int x;
    int y;
    
    Location() : x(0), y(0) {        
    }
    
    Location(int x_location, int y_location) : x(x_location), y(y_location) {        
    }    
    
    bool operator==(const Location &o) const {
        return x == o.x && y == o.y;
    }
    
    bool operator!=(const Location &o) const {
        return !(*this == o);
    }

    bool operator<(const Location &o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
    
    bool operator>(const Location &o) const {
        return !(*this < o) && !(*this == o);
    }
    
    bool operator<=(const Location &o) const {
        return (*this < o || *this == o);
    }
    
    bool operator>=(const Location &o) const {
        return !(*this < o);
    }
};

#endif	/* LOCATION_H */

