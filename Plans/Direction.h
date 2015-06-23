/*
 * Direction.h
 *
 *  Created on: Jun 23, 2015
 *      Author: colman
 */

#ifndef DIRECTION_H_
#define DIRECTION_H_


struct Direction {
	int x;
	int y;

	Direction(int xDir, int yDir) : x(xDir), y(yDir) {
	}

	bool operator==(const Direction &o) const {
		return x == o.x && y == o.y;
	}

    bool operator<(const Direction &o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};


#endif /* DIRECTION_H_ */
