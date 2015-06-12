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
//// $Id: pathplan.cpp,v 1.8 2009-03-21 18:01:35 bradleyk Exp $
//
//#include "pathplan.h"
//#include "point.h"
//
//#include <cmath>
//#include <list>
//#include <map>
//#include <iostream>
//#include <string.h>
//#include <algorithm>
//
//PathPlan::PathPlan(uint8_t* aMap, int aWidth, int aHeight) :
//  mMap(aMap),
//  mWidth(aWidth),
//  mHeight(aHeight)
//{
//}
//
//PathPlan::~PathPlan()
//{
//}
//
//std::list<Node>::iterator
//PathPlan::InsertNode(std::list<Node> &l,
//                     std::map<int, std::list<Node>::iterator> &m,
//                     Node &n)
//{
//  std::list<Node>::iterator
//    it = l.insert(std::lower_bound(l.begin(), l.end(), n), n);
//  m[NodeId(n)] = it;
//  return it;
//}
//std::list<Node>::iterator
//PathPlan::FindNode(std::list<Node> &l,
//                   std::map<int, std::list<Node>::iterator> &m,
//                   Node &n)
//{
//  std::map<int, std::list<Node>::iterator>::iterator it = m.find(NodeId(n));
//
//  if (m.end() != it)
//    return it->second;
//  else
//    return l.end();
//}
//
//std::vector<Node>
//PathPlan::GenerateGraph(Point aStart, Point aTarget)
//{
//  mTarget = aTarget;
//  mStart = aStart;
//
//  std::vector<Node> graph;
//  if (NULL == mMap)
//  {
//    std::cerr << "[PathPlan] Invalid map!" << std::endl;
//    return graph;
//  }
//  if (!Free(aTarget) || !ValidPoint(aTarget))
//  {
//    std::cerr << "[PathPlan] Invalid goal!" << std::endl;
//    return graph;
//  }
//  if (!ValidPoint(aStart))
//  {
//    std::cerr << "[PathPlan] Invalid Start!" << std::endl;
//  }
//  if (!Free(aStart))
//  {
//    std::cerr << "[PathPlan] Start in an obstacle, undefined response!" << std::endl;
//  }
//
//  Node best(mStart, 0, ManhattanCost(mStart, mTarget));
//
//  // we keep these sorted by default
//  std::list<Node> open;
//  std::list<Node> closed;
//  // We keep these two maps so that we don't have to run find on the list of
//  // nodes which is expensive when the list gets to be large.
//  std::map<int, std::list<Node>::iterator> open_map;
//  std::map<int, std::list<Node>::iterator> closed_map;
//
//  best.mBackPointer =  closed.end();
//  InsertNode(open, open_map, best);
//
//  bool found = false;
//  bool failed = false;
//
//  while (!found && !open.empty() && !failed)
//  {
//    best = open.front();
//
//    if (best.xy == mTarget)
//      found = true;
//    else
//    {
//      open.remove(best);
//      open_map[NodeId(best)] = open.end();
//      std::list<Node>::iterator last = InsertNode(closed, closed_map, best);
//      // 9-way connectivity
//      for (int i = -1; i<=1; ++i)
//      {
//        for (int j = -1; j<=1; ++j)
//        {
//          Node n = Expand(best.xy, best.xy + Point(i,j), best.G);
//
//          // don't re-add the same node
//          if (!(0==i && 0==j) && ValidPoint(n.xy) && Free(n.xy))
//          {
//            n.mBackPointer = last;
//
//            std::list<Node>::iterator found = FindNode(closed, closed_map, n);
//            if (closed.end() != found)
//            {
//              if (n.G < found->G)
//              {
//                closed.erase(found);
//                closed_map[NodeId(n)] = closed.end();
//                InsertNode(open, open_map, n);
//              }
//              else
//              {
//                // it's not better, so do nothing
//              }
//            }
//            else
//            {
//              std::list<Node>::iterator found = FindNode(open, open_map, n);
//              if (open.end() != found)
//              {
//                if (n.G < found->G)
//                {
//                  open.erase(found);
//                  InsertNode(open, open_map, n);
//                }
//                else
//                {
//                  // it's not better, so do nothing
//                }
//              }
//              else
//              {
//                InsertNode(open, open_map, n);
//              }
//            }
//          }
//        }
//      }
//    }
//    // this often happens if we start in an obstacle and can't go anywhere
//    if (open.empty())
//    {
//      failed = true;
//    }
//  }
//
//  if (!found)
//    std::cerr << "[PathPlan] no solution for ("
//              << mStart.x << ", " << mStart.y << ") => "
//              << mTarget.x << ", " << mTarget.y << ")" << std::endl;
//  else
//  {
//    graph.push_back(best);
//
//    if (!closed.empty())
//    {
//      // follow the back pointers to recreate the path
//      for (std::list<Node>::iterator node = best.mBackPointer;
//           node != closed.end();
//           node = node->mBackPointer)
//      {
//        graph.push_back(*node);
//      }
//
//      std::reverse(graph.begin(), graph.end());
//    }
//  }
//
//  return graph;
//}
//
