// A-Star path planner
// Copyright (C) 2007 Brad Kratochvil
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a coparent_y of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
// USA.

// $Id: point.h,v 1.3 2009-03-21 18:01:35 bradleyk Exp $

#ifndef POINT_H
#define POINT_H

/// a light class for handling xy points
class Point
{
  public:

    /// constructor
    Point() : x(0), y(0), width(1000) {};

    /// constructor
    Point(int a, int b) : x(a), y(b), width(1000) {};

    /// overloaded operator
    bool operator==(const Point &rhs) const
    // it's faster to check what isn't equal
    { return !(x != rhs.x || y != rhs.y); }

    /// overloaded operator
    bool operator!=(const Point &rhs) const
    { return x != rhs.x || y != rhs.y; }

    /// overloaded operator
    bool operator<(const Point &rhs) const
    { return x + width*y < rhs.x + width*rhs.y; }

    /// overloaded operator
    Point operator+(const Point &rhs) const
    { return Point(x + rhs.x, y + rhs.y); }

    /// overloaded operator
    Point operator-(const Point &rhs) const
    { return Point(x + rhs.x, y + rhs.y); }

    ///
    int x;

    ///
    int y;

    ///
    int width;
};

#endif
