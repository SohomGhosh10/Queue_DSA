class Queue:
    def __init__(self , max_size):
        self.max_size = max_size
        self.items = []
        
    def is_empty(self):
        return len(self.items) == 0
    
    def is_Full(self):
        return len(self.items) == self.max_size
    
    def enqueue(self , item):
        if not self.is_Full():
            self.items.append(item)
            
        else:
            print("Queue overflow")
    
    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0)
        
        else:
            print("Queue underflow")
            return None
        
    def size(self):
        return len(self.items)
    
my_queue = Queue(3)

# Enqueue elements
my_queue.enqueue(1)
my_queue.enqueue(2)
my_queue.enqueue(3)

# Try to enqueue one more element, which will give "Queue Overflow" 
my_queue.enqueue(4)

# Dequeue elements
print(my_queue.dequeue()) # 1
print(my_queue.dequeue()) # 2

