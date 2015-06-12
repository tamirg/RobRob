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
//// $Id: node.cpp,v 1.6 2009-03-21 18:01:35 bradleyk Exp $
//
//#include "node.h"
//
//#include <iomanip>
//
//Node::Node() :
// xy(),
// G(0),
// H(0),
// mBackPointer(NULL)
//{
//}
//
//Node::Node(int aX,
//           int aY,
//           uint32_t aG,
//           uint32_t aH) :
// xy(aX, aY),
// G(aG),
// H(aH),
// mBackPointer(NULL)
//{
//}
//
//Node::Node(Point p,
//           uint32_t aG,
//           uint32_t aH) :
// xy(p),
// G(aG),
// H(aH),
// mBackPointer(NULL)
//{
//}
//
//std::ostream&
//operator << (std::ostream &output, const Node &n)
//{
//  return output << std::setprecision(3)
//                << " x:" << n.x()
//                << " y:" << n.y()
//                << " G:" << n.G
//                << " H:" << n.H
//                << " F:" << n.F();
//}
