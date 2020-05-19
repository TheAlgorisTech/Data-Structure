# Clients Queue
Define a queue to process together two types of clients: priority clients (known as "prime" clients) and traditional clients who come after the priority clients.


### Clients Data Structure
Clients, whether premium or classic, are defined by their surname, first name and binary status: they are premium or non-premium.

#### Client Operations
- clientnew(fn, ln, status): constructor of client
- isprime(client): check if client has premium access
- isclassic(client): check if client is non-premium
