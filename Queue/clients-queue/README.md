# Clients Queue
Define a queue to process together two types of clients: priority clients (known as "prime" clients) and traditional clients who come after the priority clients.


### Clients Data Structure
Clients, whether premium or classic, are defined by their surname, first name and binary status: they are premium or non-premium.

#### Client Operations
- clientnew(fn, ln, status): constructor of client
- isprime(client): check if client has premium access
- isclassic(client): check if client is non-premium

# Queue
We want to set up a queue to manage customer requests.
The behaviour is that of a normal queue with one change:
priority (premium) customers are always placed before regular customers in the queue.
A new priority client arriving in the queue is placed in last position of the
priority clients, but before all classic clients. Conversely a customer
classic arriving in the queue is placed after all priority customers and
after all the classic customers, in other words, at the back of the queue.


### Client Queue Data Structure
The customer queue will be based on a simple non-circular chained representation.
For quick access to the head of the queue (head), to the last priority client (queuep),
and to the last classic customer (queuec) you will create a data structure
containing directly these three pieces of information and which will be named File. No other
representation will not be taken into account in the correction.

An empty queue is a queue whose three quick accesses do not point to anything. An empty
is a queue for which only one queuing is required, and that is made up exclusively of priority customers. doesn't point at anything. A line made up exclusively of classic customers is a line for which only tailpins point to nothing. A line full of priority customers and classic has its three direct accesses (head, tail, tailp) which point to row elements


### Client Queue Operations
The basic builders are:
- filenouv: empty file.
- adjc: customer addition, which adds a new customer (priority or
classic) in line.
In FILE, define in relation to filenouv and adjc the operations :
- head: which returns the client to the head of the queue.
- queue: which returns the last client in the queue
- queuep: which returns the last priority client in the queue (the priority client served
last)
- queuec: which returns the last regular customer in the queue (the regular customer served).
last)
- empty: which tests if the queue is empty
- lg: which returns the length of the queue = the total number of customers in the queue
- lgp: which returns the number of priority clients in the queue
- lgc: which returns the number of classic clients in the queue
- sup: which removes the customer at the head of the queue


[//]:(Unfinished last four operations)
