package main

import (
	"container/heap"
	"container/list"
	"fmt"
	"time"
)

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

type ExpiryHeap []*Item

func (h ExpiryHeap) Len() int           { return len(h) }
func (h ExpiryHeap) Less(i, j int) bool { return h[i].expire.Before(h[j].expire) }
func (h ExpiryHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
	*h[i].expiryHeapIndex = i
	*h[j].expiryHeapIndex = j
}

func (h *ExpiryHeap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(*Item))
	arr := *h
	n := len(arr)
	last := arr[n-1]
	*last.expiryHeapIndex = n - 1
}

func (h *ExpiryHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func (h *ExpiryHeap) Top() interface{} {
	return (*h)[0]
}

type PriorityHeap []*Item

func (h PriorityHeap) Len() int           { return len(h) }
func (h PriorityHeap) Less(i, j int) bool { return h[i].priority < h[j].priority }
func (h PriorityHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
	*h[i].priorityIndex = i
	*h[j].priorityIndex = j
}

func (h *PriorityHeap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(*Item))
	arr := *h
	n := len(arr)
	last := arr[n-1]
	*last.priorityIndex = n - 1
}

func (h *PriorityHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func (h *PriorityHeap) Top() interface{} {
	return (*h)[0]
}

// Item should provide O(1) access to pointer in priorities and expiryTimes maps
type Item struct {
	key      string
	value    interface{}
	priority int
	expire   time.Time

	expiryHeapIndex *int
	priorityIndex   *int

	priorityListNode *list.Element
}

type PriorityExpiryCache struct {
	maxItems int

	// TODO(cadurham): implement pointer into items map
	items            map[string]*Item
	priorities       map[int]*list.List
	priorityIndexMap map[int]*int
	expiryIndexMap   map[time.Time]*int

	expiryValues   *ExpiryHeap
	priorityValues *PriorityHeap
}

func NewCache(maxItems int) *PriorityExpiryCache {
	return &PriorityExpiryCache{
		maxItems:         maxItems,
		items:            make(map[string]*Item),
		priorities:       make(map[int]*list.List),
		priorityIndexMap: make(map[int]*int),
		expiryIndexMap:   make(map[time.Time]*int),
		expiryValues:     &ExpiryHeap{},
		priorityValues:   &PriorityHeap{},
	}
}

func (c *PriorityExpiryCache) Get(key string) interface{} {
	// ... the interviewee does not need to implement this.

	if item, ok := c.items[key]; ok {

		// check if key is expired
		if time.Now().After(item.expire) {
			c.removeItem(item)
			return nil
		}

		// get key into the priorities map
		// move item to tail of list
		c.priorities[item.priority].MoveToFront(item.priorityListNode)

		return item
	} else {
		return nil
	}

}

func (c *PriorityExpiryCache) Set(key string, value interface{}, priority int, expire time.Time) {
	// ... the interviewee does not need to implement this.
	var priorityIndex *int
	var expiryHeapIndex *int

	if ptr, ok := c.priorityIndexMap[priority]; ok {
		priorityIndex = ptr
	} else {
		priorityIndex = new(int)
	}

	if ptr, ok := c.expiryIndexMap[expire]; ok {
		expiryHeapIndex = ptr
	} else {
		expiryHeapIndex = new(int)
	}

	item := &Item{
		key:             key,
		value:           value,
		priority:        priority,
		expire:          expire,
		priorityIndex:   priorityIndex,
		expiryHeapIndex: expiryHeapIndex,
	}

	if dll, ok := c.priorities[priority]; ok {
		node := dll.PushFront(key)
		item.priorityListNode = node
	} else {
		ll := list.New()
		node := ll.PushFront(key)
		c.priorities[priority] = ll
		item.priorityListNode = node
	}

	if _, ok := c.priorityIndexMap[priority]; !ok {
		c.priorityIndexMap[priority] = priorityIndex
		heap.Push(c.priorityValues, item)
	}

	if _, ok := c.expiryIndexMap[expire]; !ok {
		c.expiryIndexMap[expire] = expiryHeapIndex
		heap.Push(c.expiryValues, item)
	}

	c.items[item.key] = item

	c.evictItems()
}

func (c *PriorityExpiryCache) SetMaxItems(maxItems int) {
	c.maxItems = maxItems

	c.evictItems()
}

func (c *PriorityExpiryCache) Keys() []string {
	keys := make([]string, 0)
	for k, _ := range c.items {
		keys = append(keys, k)
	}
	return keys
}

// evictItems will evict items from the cache to make room for new ones.
func (c *PriorityExpiryCache) evictItems() {
	// TODO(interviewee): implement this within runtime requirement
	// log(p) + log(e); p=# distinct priorities, e=# distinct expiryTimes

	if c.maxItems < len(c.items) {
		// check if there are expired entries to evict
		for time.Now().After(c.expiryValues.Top().(*Item).expire) &&
			len(c.items) > c.maxItems {
			c.removeItem(c.expiryValues.Top().(*Item))
		}
		for len(c.items) > c.maxItems {
			lowestPriority := c.priorityValues.Top().(*Item).priority
			lru := c.priorities[lowestPriority].Back()
			c.removeItem(c.items[lru.Value.(string)])
		}
	}
}

func (c *PriorityExpiryCache) removeItem(item *Item) {
	// complexity of list.Len() is O(1)
	// https://golang.org/pkg/container/list/#List.Len

	// O(e)
	heap.Remove(c.expiryValues, *item.expiryHeapIndex)
	c.priorities[item.priority].Remove(item.priorityListNode)

	if c.priorities[item.priority].Len() == 0 {
		// O(p)
		heap.Remove(c.priorityValues, *item.priorityIndex)
		delete(c.priorities, item.priority)
	}

	delete(c.items, item.key)
}

func printArr(arr []string) {
	fmt.Print("[")
	for _, e := range arr {
		fmt.Printf(" \"%v\",", e)
	}
	fmt.Print(" ]\n")
}

// TODO(interviewee): writeup time/space complexity for each basic operation, describe and justify choices
func main() {

	c := NewCache(5)
	c.Set("A", 1, 5, time.Now().Add(time.Second*100))
	c.Set("B", 2, 15, time.Now().Add(time.Second*3))
	c.Set("C", 3, 5, time.Now().Add(time.Second*10))
	c.Set("D", 4, 1, time.Now().Add(time.Second*15))
	c.Set("E", 5, 5, time.Now().Add(time.Second*150))
	c.Get("C")

	// Current time = 0
	c.SetMaxItems(5)
	//c.Keys() = ["A", "B", "C", "D", "E"]
	// space for 5 keys, all 5 items are included
	printArr(c.Keys())

	time.Sleep(5)

	// Current time = 5
	c.SetMaxItems(4)
	//c.Keys() = ["A", "C", "D", "E"]
	// "B" is removed because it is expired.  e3 < e5
	printArr(c.Keys())

	c.SetMaxItems(3)
	//c.Keys() = ["A", "C", "E"]
	// "D" is removed because it the lowest priority
	// D's expire time is irrelevant.
	printArr(c.Keys())

	c.SetMaxItems(2)
	//c.Keys() = ["C", "E"]
	// "A" is removed because it is least recently used."
	// A's expire time is irrelevant.
	printArr(c.Keys())

	c.SetMaxItems(1)
	//c.Keys() = ["C"]
	// "E" is removed because C is more recently used (due to the Get("C") event).
	printArr(c.Keys())
}
