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
//// $Id: example.cpp,v 1.7 2009-03-21 18:01:35 bradleyk Exp $
//
//#include <iostream>
//#include <iomanip>
//#include <ctime>
//#include <cmath>
//#include <sys/time.h>
//
//#include "pathplan.h"
//
///// a simple function for outputting a map to the console
//void
//output_map(const uint8_t* map, int width, int height,
//           const std::vector<Node> &traj = std::vector<Node>())
//{
//  using namespace std;
//  cout << "-------------------------------------------" << endl;
//
//  cout << "    ";
//  for(int x=0; x<width; ++x)
//  {
//    cout << setw(3) << x << " ";
//  }
//  cout << endl;
//
//
//  for(int y=0;y<height; ++y)
//  {
//    cout << setw(3) << y << " ";
//    for(int x=0; x<width; ++x)
//    {
//      // check to see if we're at a point on the trajectory
//      bool at_point = false;
//      for (int i=0; i<traj.size(); ++i)
//      {
//        if (traj[i].x() == x && traj[i].y() == y)
//          at_point = true;
//      }
//
//      if (at_point)
//        cout << "*** ";
//      else
//        cout << setw(3) << static_cast<int>(map[x+y*width]) << " ";
//    }
//    cout << std::endl;
//  }
//
//  cout << "-------------------------------------------" << endl;
//}
//
///// a simple function for outputting the trajectory points to the console
//void
//output_traj(const std::vector<Node> &traj)
//{
//  for(int i=0; i<traj.size(); ++i)
//  {
//    std::cout << traj[i] << std::endl;
//  }
//  std::cout << std::endl;
//}
//
///// @mainpage A* Path Search
/////
///// @author Brad Kratochvil (brad@kratochvil.name)
/////
///// Here is a simple C++ implementation of A* I put together a few years ago for
///// doing path planning with our Magmite robots.
///// The code is fairly clean, and should be easy to use for other simple path
///// planning tasks.  It is composed primarily of two classes:
///// - Node: a node in the search path
///// - PathPlan: the class for generating the plan.
/////
///// If you are not familiar with A* searches, check out Wikipedia's entry on it.
/////
///// http://en.wikipedia.org/wiki/Graph_traversal
/////
///// To download the code, go to:
/////
///// http://brad.kratochvil.name/software/a-star/a-star.tgz
/////
/////
///// As a simple example of the path planning, the following code:
///// @code
//int
//main()
//{
//  int width=10;
//  int height=10;
//
//  uint8_t maze[]={000,000,000,000,000,000,000,000,000,000,
//                  000,000,255,255,255,255,255,255,255,000,
//                  000,000,000,000,000,000,255,000,255,000,
//                  000,000,000,000,000,000,255,255,255,000,
//                  000,000,000,000,000,000,000,000,000,000,
//                  000,000,000,000,000,255,255,255,000,000,
//                  000,000,000,000,255,255,000,000,000,000,
//                  000,255,255,255,255,255,000,255,255,255,
//                  000,255,255,255,255,255,000,255,000,255,
//                  000,255,255,255,255,255,000,000,000,000
//                };
//
//  output_map(maze, width, height);
//
//  PathPlan plan(maze, width, height);
//
//  std::vector<Node> trajectory = plan.GenerateGraph(0,0,9,9);
//
//  output_map(maze, width, height, trajectory);
//  output_traj(trajectory);
//
//  return 0;
//}
///// @endcode
/////
///// will output the following, where the ***s represent the selected path.
///// @verbatim
///// -------------------------------------------
/////       0   1   2   3   4   5   6   7   8   9
/////   0   0   0   0   0   0   0   0   0   0   0
/////   1   0   0 255 255 255 255 255 255 255   0
/////   2   0   0   0   0   0   0 255   0 255   0
/////   3   0   0   0   0   0   0 255 255 255   0
/////   4   0   0   0   0   0   0   0   0   0   0
/////   5   0   0   0   0   0 255 255 255   0   0
/////   6   0   0   0   0 255 255   0   0   0   0
/////   7   0 255 255 255 255 255   0 255 255 255
/////   8   0 255 255 255 255 255   0 255   0 255
/////   9   0 255 255 255 255 255   0   0   0   0
///// -------------------------------------------
///// -------------------------------------------
/////       0   1   2   3   4   5   6   7   8   9
/////   0   0   0   0   0   0   0   0   0   0   0
/////   1   0 *** 255 255 255 255 255 255 255   0
/////   2   0   0 *** ***   0   0 255   0 255   0
/////   3   0   0   0   0 *** *** 255 255 255   0
/////   4   0   0   0   0   0   0 *** ***   0   0
/////   5   0   0   0   0   0 255 255 255 ***   0
/////   6   0   0   0   0 255 255   0 ***   0   0
/////   7   0 255 255 255 255 255 *** 255 255 255
/////   8   0 255 255 255 255 255 *** 255   0 255
/////   9   0 255 255 255 255 255   0 *** *** ***
///// -------------------------------------------
///// @endverbatim
