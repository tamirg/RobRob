//// A-Star path planner
//// Copyright (C) 2007 Brad Kratochvil
////
//// This program is free software; you can redistribute it and/or
//// modify it under the terms of the GNU General Public License
//// as published by the Free Software Foundation; either version 2
//// of the License, or (at your option) any later version.
////
//// This program is distributed in the hope that it will be useful,
//// but WITHOUT ANY WARRANTY; without even the implied warranty of
//// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//// GNU General Public License for more details.
////
//// You should have received a coparent_y of the GNU General Public License
//// along with this program; if not, write to the Free Software
//// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
//// USA.
//
//// $Id: node.h,v 1.8 2009-03-21 18:01:35 bradleyk Exp $
//
//#ifndef NODE_H
//#define NODE_H
//
//#include <iostream>
//#include <list>
//
//#include "point.h"
//
//class Node;
//class PathPlan;
//
///// A node in the search path
//class Node
//{
//   /// output stream operator
//   friend std::ostream &operator<<(std::ostream &, const Node &);
//
//   /// so that PathPlan can have access to protected members
//   friend class PathPlan;
//
//   public:
//
//      /// constructor
//      Node();
//
//      /// constructor
//      Node(int aX,
//           int aY,
//           uint32_t aG = 0,
//           uint32_t aH = 0);
//
//      Node(Point p,
//           uint32_t aG = 0,
//           uint32_t aH = 0);
//
//      /// destructor
//      ~Node(){};
//
//      /// x position of node
//      int x() const
//        { return xy.x; }
//
//      /// y position of node
//      int y() const
//        { return xy.y; }
//
//      /// store the Node's xy position
//      Point xy;
//
//      /// equality operator, we only care if the location is the same
//      bool operator==(const Node &rhs) const
//      { return xy == rhs.xy; }
//
//      /// inequality operator, we only care if the location is the same
//      bool operator!=(const Node &rhs) const
//      { return xy != rhs.xy; }
//
//      /// less than operator
//      bool operator<(const Node &rhs) const
//      { return F() < rhs.F(); }
//
//    protected:
//
//      /// The total length of a backpointer path from n to start
//      uint32_t G;
//
//      /// the estimated cost of the shortest path from n to the goal
//      uint32_t H;
//
//      /// a pointer to the previous best node in the path
//      std::list<Node>::iterator mBackPointer;
//
//      /// is this node valid?
//      bool valid;
//
//      /// the estimated cost of the shortest path from start to goal via n
//      uint32_t F() const
//      { return G + H; }
//
//};
//
//#endif
