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
//// $Id: pathplan.h,v 1.9 2009-03-21 18:01:35 bradleyk Exp $
//
//#ifndef PATH_PLAN_H
//#define PATH_PLAN_H
//
//#include <vector>
//#include <map>
//#include <cmath>
//#include <stdint.h>
//
//#include "node.h"
//
///// Our path planner class
//class PathPlan
//{
//  public:
//
//    /// constructor with a pointer to the row-major occupancy map
//    /// @arg aMap: a pointer to the map to be used: 0=no obstacle, >0=obstacle
//    /// @arg aWidth: the width of the map
//    /// @arg aHeight: the height of the map
//    PathPlan(uint8_t* aMap, int aWidth, int aHeight);
//
//    /// destructor
//    ~PathPlan();
//
//    /// returns the a-star path to the goal
//    /// @arg start - xy location of start
//    /// @arg target - xy location of target
//    std::vector<Node> GenerateGraph(int sx, int sy,
//                                    int tx, int ty)
//      { return GenerateGraph(Point(sx, sy), Point(tx, ty)); }
//
//    /// returns the a-star path to the goal
//    /// @arg sx - x location of start
//    /// @arg sy - y location of start
//    /// @arg tx - x location of target
//    /// @arg ty - y location of target
//    std::vector<Node> GenerateGraph(Point start,
//                                    Point target);
//
//  protected:
//
//    // we're inlining these to make them faster
//
//    /// is the point in the map?
//    bool ValidPoint(const Point &p)
//    { return p.x >= 0 && p.x < mWidth && p.y >=0 && p.y < mHeight; }
//    /// is the point currently free?
//    bool Free(const Point &p)
//    { return 0 == Value(p); }
//
//    /// what is the value of the point?
//    int Value(const Point &p)
//    { return mMap[p.x + p.y*mWidth]; }
//
//    /// return's the node ID that we store as a unique ID in the map
//    int NodeId(const Node& n)
//    { return n.xy.x + n.xy.y*mWidth; }
//
//    /// we calculate the cost of moving to a neighbor differently than the
//    /// cost to the final goal.
//    uint32_t NeighborCost(const Point &p1, const Point &p2)
//    {
//      // these are multiplied by 10 so that we can use integer math
//      int est = abs(p2.x-p1.x) + abs(p2.y-p1.y);
//      // the only options here are 0,1,2
//      if (2 == est)
//        return 14;
//      else
//        return 10*est;
//    }
//
//    /// the Manhattan (city-block) distance is sufficient for calculating
//    /// the distance to the goal.
//    uint32_t ManhattanCost(const Point &p1, const Point &p2)
//    {
//      // these are multiplied by 10 so that we can use integer math
//      return 10*abs((p2.x-p1.x) + (p2.y-p1.y));
//    }
//
//    /// Expand the point for all connected nodes
//    Node Expand(const Point &p1, const Point &p2, uint32_t cost)
//    {
//      return Node(p2.x,
//                  p2.y,
//                  cost + NeighborCost(p1, p2),
//                  ManhattanCost(p2, mTarget));
//    }
//
//    /// Insert a node into the sorted list (open or closed)
//    std::list<Node>::iterator InsertNode(std::list<Node> &l,
//                     std::map<int, std::list<Node>::iterator> &m, Node &n);
//
//    /// Find a stored node using the map
//    std::list<Node>::iterator FindNode(std::list<Node> &l,
//                                       std::map<int, std::list<Node>::iterator> &m,
//                                       Node &n);
//
//    /// @brief a pointer to the map (managed elsewhere)
//    ///
//    /// - 0 => free space
//    /// - >0 => occupied
//    uint8_t* mMap;
//
//    /// the width of the map
//    int mWidth;
//
//    /// the height of the map
//    int mHeight;
//
//    /// start location
//    Point mStart;
//
//    /// target location
//    Point mTarget;
//
//};
//
//#endif
