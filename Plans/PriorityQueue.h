/* 
 * File:   PriorityQueue.h
 * Author: Ido
 *
 * Created on 16 יוני 2015, 20:26
 */

#ifndef PRIORITYQUEUE_H
#define	PRIORITYQUEUE_H

#include <queue>

template<typename T, typename Number=int>
struct PriorityQueue {
    typedef pair<Number, T> PQElement;
    
    std::priority_queue<Number, std::vector<PQElement>, std::greater<PQElement> > elements;
    
    inline bool empty() { return elements.empty(); }

    inline void put(T item, Number priority) {        
        elements.push(PQElement(priority, item));
    }

    inline T get() {
        T best_item = elements.top().second;
        elements.pop();
        return best_item;
    }
};

#endif	/* PRIORITYQUEUE_H */

