## Description

x 3

I bet you won't ever catch a Lift (a.k.a. elevator) again without thinking of this Kata !

## Synopsis

A multi-floor building has a Lift in it.

People are queued on different floors waiting for the Lift.

Some people want to go up. Some people want to go down.

The floor they want to go to is represented by a number (i.e. when they enter the Lift this is the button they will press)

```
BEFORE (people waiting in queues)               AFTER (people at their destinations)
                   +--+                                          +--+ 
  /----------------|  |----------------\        /----------------|  |----------------\
10|                |  | 1,4,3,2        |      10|             10 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 9|                |  | 1,10,2         |       9|                |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 8|                |  |                |       8|                |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 7|                |  | 3,6,4,5,6      |       7|                |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 6|                |  |                |       6|          6,6,6 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 5|                |  |                |       5|            5,5 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 4|                |  | 0,0,0          |       4|          4,4,4 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 3|                |  |                |       3|            3,3 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 2|                |  | 4              |       2|          2,2,2 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 1|                |  | 6,5,2          |       1|            1,1 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 G|                |  |                |       G|          0,0,0 |  |                |
  |====================================|        |====================================|
```
## Rules
### Lift Rules

* The Lift only goes up or down!
* Each floor has both UP and DOWN Lift-call buttons (except top and ground floors which have only DOWN and UP respectively)
* The Lift never changes direction until there are no more people wanting to get on/off in the direction it is already travelling
* When empty the Lift tries to be smart. For example,
* If it was going up then it may continue up to collect the highest floor person wanting to go down
* If it was going down then it may continue down to collect the lowest floor person wanting to go up
* The Lift has a maximum capacity of people
* When called, the Lift will stop at a floor even if it is full, although unless somebody gets off nobody else can get on!
* If the lift is empty, and no people are waiting, then it will return to the ground floor

### People Rules

* People are in "queues" that represent their order of arrival to wait for the Lift
* All people can press the UP/DOWN Lift-call buttons
* Only people going the same direction as the Lift may enter it
* Entry is according to the "queue" order, but those unable to enter do not block those behind them that can
* If a person is unable to enter a full Lift, they will press the UP/DOWN Lift-call button again after it has departed without them

### Kata Task

* Get all the people to the floors they want to go to while obeying the Lift rules and the People rules
* Return a list of all floors that the Lift stopped at (in the order visited!)

NOTE: The Lift always starts on the ground floor (and people waiting on the ground floor may enter immediately)

## I/O
### Input

* queues a list of queues of people for all floors of the building.
* The height of the building varies
* 0 = the ground floor
* Not all floors have queues
* Queue index [0] is the "head" of the queue
* Numbers indicate which floor the person wants go to
* capacity maximum number of people allowed in the lift

Parameter validation - All input parameters can be assumed OK. No need to check for things like:

* People wanting to go to floors that do not exist
* People wanting to take the Lift to the floor they are already on
* Buildings with < 2 floors
* Basements

## Output

* A list of all floors that the Lift stopped at (in the order visited!)


**Kata's link:** [The Lift](https://www.codewars.com/kata/58905bfa1decb981da00009e/cpp)

## Best Practices

**First:**
```cpp
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Checks if the Lift is empty (goes through each floor queue and checks to see that it is empty)
bool isEmpty(const vector<vector<int>>& queues)
{
    for (auto ix : queues)
    {
        if (ix.empty() == false)
        {
            return false;
        }
    }
    return true;
}

vector<int> the_lift(vector<vector<int>> queues, int capacity)
{
    // No matter the case, the lift always starts at the ground level
    vector<int> floorsVisited{ 0 };
  
    // Bool variable to keep track of the direction of the lift
    bool goUp = false;
    // Multiset to keep track of who is currently on the lift
    unordered_multiset<int> onLift;
  
    // Start at floor 0
    int floor = 0;
  
    // Keep visiting floors while there are still people in the floor queue or on the elevator
    while (!(isEmpty(queues) == true && onLift.empty() == true))
    {
        // Variable that keeps track if the lift actually stopped at that floor (either to pick someone up or drop someone off)
        bool didStop = false;
      
        // Once you hit the first or top floors, change the lift's direction
        if (floor == 0 || floor == queues.size() - 1)
        {
            goUp = !goUp;
        }
      
        // If there are people on the lift who want to get out at the current floor, let them get out
        while (onLift.find(floor) != onLift.end())
        {
            didStop = true;
            onLift.erase(floor);
        }
        
      
        // Traverse the current queue to see if there is someone who can get on if there is space in the lift
        vector<int> newQueue;
        for (auto ix : queues[floor])
        {
          
            // If the lift is going up, only stop for people who want to go up
            if (goUp == true)
            {
                if (ix > floor)
                {
                    didStop = true;
                  
                    // If there is no space, but there are people on the floor who want to go up, you still stopped at the floor, you just can't take them on the lift
                    if (onLift.size() < capacity)
                    {
                        onLift.insert(ix);
                    }
                  
                    // So, they remain in the queue
                    else
                    {
                        newQueue.push_back(ix);
                    }
                }
              
                // If they aren't going in the same direction as the lift, leave them in the queue
                else
                {
                    newQueue.push_back(ix);
                }
            }
          
            // If the lift is going down, only stop for people who want to go down
            else
            {
                if (ix < floor)
                {
                    didStop = true;
                  
                    // If there is no space, but there are people on the floor who want to go up, you still stopped at the floor, you just can't take them on the lift
                    if (onLift.size() < capacity)
                    {
                        onLift.insert(ix);
                    }
                  
                    // So, they remain in the queue
                    else
                    {
                        newQueue.push_back(ix);
                    }
                }
              
                // If they aren't going in the same direction as the lift, leave them in queue
                else
                {
                    newQueue.push_back(ix);
                }
            } 
        }
      
        // If you stopped at the floor, change the queue accordingly (if no one was allowed to get on, the queue will be the same as originally; if people were
        // allowed to get on, then the newQueue vector will only contain people who weren't allowed to get on in their relative position in the original queue for that floor)
        if (didStop == true)
        {
            queues[floor] = newQueue;
          
            // If the current floor is the last floor you visited, (i.e. you are now travelling in the opposite direction) then don't add the floor to the previously visited floors
            if (floorsVisited.back() != floor)
            {
                floorsVisited.push_back(floor);
            }  
        }
        (goUp) ? floor++ : floor--;
    }
  
    // If the last floor visited was the bottom (and there are no more floors to visit), then don't add 0 to the queue. If the last visited floor wasn't 0 (and there are no more floors
    // to visit), then add 0 to the queue since the lift will return to the ground floor once it is finished
    if (floorsVisited.back() != 0)
    {
        floorsVisited.push_back(0);
    }
    return floorsVisited;
}
```

**Second:**
```cpp
#include <vector>
#include <list>

class Lift{
    const size_t capacity;
    const size_t top_floor;
    std::list<size_t> passengers{};
    int travel_direction = 1;
    bool muzak_playing = false;
  public:
    int people_waiting = 0;
    size_t floor = 0;
    std::vector<std::vector<size_t>> *up_qs, *down_qs;
    
    Lift(int c, size_t t): capacity(c), top_floor(t) {};
    bool travel();
    bool exit_passengers();
    bool enter_passengers();
    bool muzak();
    bool occupied();
    bool empty();
};

std::vector<int> the_lift(const std::vector<std::vector<int>> &queues, int capacity) {
  std::vector<int> floors_visited{0};
  size_t  t_floor = queues.size() - 1;
  Lift    lift(capacity, t_floor);
  std::vector<std::vector<size_t>> up_qs, down_qs;
  lift.up_qs = &up_qs;
  lift.down_qs = &down_qs; 
  
  // std::cout << "cap: " << capacity << "\n";
  for(size_t f = 0; f <= t_floor; ++f){         // form separate queues for people going up or going down
    // std::cout << f << ": ";
    up_qs.push_back(std::vector<size_t> {});    // going up
    down_qs.push_back(std::vector<size_t> {});  // going down
    for(size_t p = queues[f].size(); p > 0;){
      --p;
      if(queues[f][p] > (int)f) 
             up_qs[f].push_back((size_t)queues[f][p]);
      else down_qs[f].push_back((size_t)queues[f][p]);
      ++lift.people_waiting;
      // std::cout << queues[f][p] << " ";
    }
    // std::cout << "\n";
  }
  // std::cout << "\n";
  lift.muzak();              // switch on annoying elevator music
  lift.enter_passengers();   // people waiting at ground floor enter
  while(lift.people_waiting  // still people waiting
        || lift.floor        // lift not returned to ground floor
        || lift.occupied()){ // still passengers in lift
    if(lift.travel())        // travel to the next floor. Return false if no travel has occurred
      floors_visited.push_back(lift.floor);
    lift.exit_passengers();  // passengers leave the lift
    lift.enter_passengers(); // new passengers enter the lift
  }
  lift.muzak();              // don't forget to switch of the elevator music in the evening
  
  // std::cout << "run\n";
  return floors_visited;
}

bool Lift::travel(){
      if(!people_waiting && empty()){ // if nobody is waiting and lift empty return to ground floor
        if(floor == 0) return false;  // already at ground floor, no travel
        floor = 0;     return true;
      }
  size_t start_floor = floor;
      for(bool stop = false; !stop;){
        floor += travel_direction;
        if(floor == 0 || floor == top_floor) travel_direction *= -1;    // switch directions at ground an top floor
        if(travel_direction ==  1) stop = (*up_qs)[floor].size() > 0;   // stop if people wait to go up
        if(travel_direction == -1) stop = (*down_qs)[floor].size() > 0; // stop if people wait to go down
        if(occupied() && passengers.back() == floor) stop = true;       // stop if passengers want to exit
      }
      return floor != start_floor; // if the lift has not travelled, return false
    }

bool Lift::exit_passengers(){
  bool exited = false;
  while(!passengers.empty() && passengers.back() == floor){
      passengers.pop_back(); // passengers are ordered according to direction of travel
      exited = true;}
  return exited;
}

bool Lift::enter_passengers(){
  bool entered = false;
  std::vector<size_t> *queue = travel_direction == 1 ? &((*up_qs)[floor])  // pick queue according to 
                             : travel_direction == -1? &((*down_qs)[floor])// direction of travel
                             : nullptr;
  // std::cout << floor << ": ";
  while(!(queue->empty() || passengers.size() == capacity)){ // let passengers enter while space in lift
    // std::cout << queue->back() << " ";
    passengers.push_back(queue->back());
    queue->pop_back();
    --people_waiting;
    entered = true;
  }
  if(travel_direction == 1) passengers.sort(std::greater<size_t>()); // sort descending if going up
  if(travel_direction == -1) passengers.sort();                      // sort ascending if going ddown
  // std::cout << " : " << passengers.size() << "\n";
  return entered;
}

bool Lift::occupied(){
  return passengers.size() > 0;
}
    
bool Lift::empty(){
  return passengers.empty();
}

bool Lift::muzak(){
  muzak_playing ^= true; // toggle muzak on off
  if(muzak_playing)/*
    ba ba dee ba ba dee dee
    ba dee ba dee dee deee
    baaa dee dee dee doooo
    ba dee ba dee dee deee
    baaa dee dee dee dooooooo....
    */;
  return muzak_playing;
}
```

## My Solutions
```cpp
#include <vector>

std::vector<int> the_lift(std::vector<std::vector<int>> queues, int capacity)
{
  std::vector<int> lift{0};
  bool direction = true;
  std::vector<int> p;
  int count = 0;

  for (int i = 0; i < queues.size() && i >= 0; i = direction ? i + 1 : i - 1)
  {
    for (auto it = p.begin(); it != p.end();) {
      if (*it == i) {
        it = p.erase(it);
        if (*lift.rbegin() != i)
          lift.push_back(i);
      } else
        ++it;
    }
    if (i == 0 && count != 0 || i == queues.size() - 1)
    {
      count = 0;
      direction = !direction;
    }
    if (i == 0 && !queues[i].empty())
      direction = true;
    if (queues[i].empty())
      continue;
    for (auto it = queues[i].begin(); it != queues[i].end();)
    {
      ++count;
      if (direction == *it > i)
      {
        if (*lift.rbegin() != i)
          lift.push_back(i);
      }
      if (p.size() < capacity && (direction == *it > i))
      {
        p.push_back(*it);
        it = queues[i].erase(it);
        --count;
      } else
        ++it;
    }
  }
  if (*lift.rbegin() != 0)
    lift.push_back(0);

  return lift;
}
```
