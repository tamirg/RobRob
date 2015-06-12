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
//// $Id: example.cpp,v 1.5 2009-03-20 08:31:51 bradleyk Exp $
//
//#include <iostream>
//#include <iomanip>
//#include <ctime>
//#include <cmath>
//#include <sys/time.h>
//
//#include "pathplan.h"
//
//static timeval start_time = {0,0};
//
//// tic and toc functions work together to measure elapsed time.
//// tic saves the current time that TOC uses later to measure
//// the elapsed time. The sequence of commands:
////
////           tic();
////           operations
////           toc();
////
//// measures the amount of time MATLAB takes to complete the one
//// or more operations specified here by "operations" and displays
//// the time in seconds.
//inline void
//tic()
//{
//  gettimeofday(&start_time, NULL);
//}
//
//inline double
//toc(bool restart = false)
//{
//  timeval now;
//  gettimeofday(&now, NULL);
//
//  double elapsed_time = now.tv_sec - start_time.tv_sec +
//                        (now.tv_usec - start_time.tv_usec)/1e6;
//
//  if (restart)
//    tic();
//
//  return elapsed_time;
//}
//
//int
//main()
//{
//  int width=10;
//  int height=10;
//
//  uint8_t maze[]={000,000,000,000,000,000,000,000,000,000,
//                  000,000,255,255,255,255,255,255,255,000,
//                  000,000,000,000,000,000,255,255,255,000,
//                  000,000,000,000,000,000,255,255,255,000,
//                  000,000,000,000,000,000,000,000,000,000,
//                  000,000,000,000,000,255,255,255,000,000,
//                  000,000,000,000,255,255,000,000,000,000,
//                  000,255,255,255,255,255,000,255,255,255,
//                  000,255,255,255,255,255,000,255,000,255,
//                  000,255,255,255,255,255,000,000,000,000
//                };
//
//  PathPlan plan(maze, width, height);
//
//  int cnt = 0;
//  double elapsed_time = 5;
//  tic();
//  while (toc() < elapsed_time)
//  {
//    int x1 = static_cast<uint>(floor(10.0*rand()/RAND_MAX));
//    int x2 = static_cast<uint>(floor(10.0*rand()/RAND_MAX));
//    int y1 = static_cast<uint>(floor(10.0*rand()/RAND_MAX));
//    int y2 = static_cast<uint>(floor(10.0*rand()/RAND_MAX));
//
//    if (255 != maze[x1+y1*width] && 255 != maze[x2+y2*width])
//    {
//      ++cnt;
//      plan.GenerateGraph(x1, y1, x2, y2);
//    }
//  }
//
//  std::cout << "completed " << cnt << " iterations in " << elapsed_time
//            << "[s] for " << cnt/elapsed_time << "[Hz]" << std::endl;
//
//  return 0;
//}
