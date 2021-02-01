package main

import "time"
import "container/heap"

/*
You can use any language.

Your task is to implement a PriorityExpiryCache cache with a max capacity.  Specifically please fill out the data structures on the PriorityExpiryCache object and implement the entry eviction method.

You do NOT need to implement the get or set methods.

It should support these operations:
  Get: Get the value of the key if the key exists in the cache and is not expired.
  Set: Update or insert the value of the key with a priority value and expiretime.
    Set should never ever allow more items than maxItems to be in the cache.
    When evicting we need to evict the lowest priority item(s) which are least recently used.

Example:
p5 => priority 5
e10 => expires at 10 seconds since epoch

c = NewCache(5)
c.Set("A", value=1, priority=5,  expireTime=100)
c.Set("B", value=2, priority=15, expireTime=3)
c.Set("C", value=3, priority=5,  expireTime=10)
c.Set("D", value=4, priority=1,  expireTime=15)
c.Set("E", value=5, priority=5,  expireTime=150)
c.Get("C")


// Current time = 0
c.SetMaxItems(5)
c.Keys() = ["A", "B", "C", "D", "E"]
// space for 5 keys, all 5 items are included

time.Sleep(5)

// Current time = 5
c.SetMaxItems(4)
c.Keys() = ["A", "C", "D", "E"]
// "B" is removed because it is expired.  e3 < e5

c.SetMaxItems(3)
c.Keys() = ["A", "C", "E"]
// "D" is removed because it the lowest priority
// D's expire time is irrelevant.

c.SetMaxItems(2)
c.Keys() = ["C", "E"]
// "A" is removed because it is least recently used."
// A's expire time is irrelevant.

c.SetMaxItems(1)
c.Keys() = ["C"]
// "E" is removed because C is more recently used (due to the Get("C") event).

*/

// Begin TimeHeap
// An TimeHeap is a min-heap of timestamps.
type TimeHeap []time.Time

func (h TimeHeap) Len() int           { return len(h) }
func (h TimeHeap) Less(i, j int) bool { return h[i].Before(h[j]) }
func (h TimeHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *TimeHeap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(time.Time))
}

func (h *TimeHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// End TimeHeap

// Begin IntHeap

// An IntHeap is a min-heap of ints.
type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// End IntHeap

type Item struct {
	key      string
	value    interface{}
	priority int
	expire   time.Time

	prev *Item
	next *Item
}

type LinkedList struct {
	head *Item
	tail *Item
}

type PriorityExpiryCache struct {
	maxItems int
	// TODO(interviewee): implement this
	items       map[string]*Item
	expireTimes map[time.Time]*Item
	priorities  map[int]*LinkedList

	expireValues   TimeHeap
	priorityValues IntHeap
}

func NewCache(maxItems int) *PriorityExpiryCache {
	return &PriorityExpiryCache{
		maxItems: maxItems,
	}
}

func (c *PriorityExpiryCache) Get(key string) interface{} {
	// ... the interviewee does not need to implement this.

	// check if key is in items

	// retrieve itme from priorities
	item := c.items[key]

	// (LRU) HEAD -> N1 -> TAIL (Recently Used)
	// item.expire

	return nil
}

func (c *PriorityExpiryCache) Set(key string, value interface{}, priority int, expire time.Time) {
	// ... the interviewee does not need to implement this.

	c.evictItems()
}

func (c *PriorityExpiryCache) SetMaxItems(maxItems int) {
	c.maxItems = maxItems

	c.evictItems()
}

// evictItems will evict items from the cache to make room for new ones.
func (c *PriorityExpiryCache) evictItems() {
	// TODO(interviewee): implement this
	// log(p) + log(e); p=# distinct priorities, e=# distinct expiries
}

// TODO(interviewee): writeup time/space complexity for each basic operation, describe and justify choices
