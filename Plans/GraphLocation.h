/* 
 * File:   GraphLocation.h
 * Author: Ido
 *
 * Created on 16 יוני 2015, 19:53
 */

#ifndef GRAPHLOCATION_H
#define	GRAPHLOCATION_H

struct GraphLocation
{
    int x;
    int y;
    
    GraphLocation() : x(0), y(0) {
    }
    
    GraphLocation(int x_location, int y_location) : x(x_location), y(y_location) {
    }    
    
    bool operator==(const GraphLocation &o) const {
        return x == o.x && y == o.y;
    }
    
    bool operator!=(const GraphLocation &o) const {
        return !(*this == o);
    }

    bool operator<(const GraphLocation &o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
    
    bool operator>(const GraphLocation &o) const {
        return !(*this < o) && !(*this == o);
    }
    
    bool operator<=(const GraphLocation &o) const {
        return (*this < o || *this == o);
    }
    
    bool operator>=(const GraphLocation &o) const {
        return !(*this < o);
    }
};

#endif	/* GRAPHLOCATION_H */

