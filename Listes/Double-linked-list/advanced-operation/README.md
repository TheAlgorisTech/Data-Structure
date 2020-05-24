# Lists: Advanced Operations


## Operations

```
liste* liste_range(S debut, S fin, S pas);
```
This function constructs a list of elements of the interval [start, f in[ spaced by steps. For example, it builds a list of elements in the interval [start, f in[ spaced by steps:

```
— liste_range(0, 10, 1) = [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ]
— liste_range(10, 0, -1) = [ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 ]
— liste_range(0, 20, 2) = [ 0, 2, 4, 6, 8, 10, 12, 14, 16, 18 ]
```

Here are some indications on these functions:
- list_reverse() reverses the order of items in the list.
- list_map() consists in applying the f function provided on each element. In other words :
map([x 1 , x 2 , , . . . . , x n ], f ) = [f (x 1 ), f (x 2 ), . . . . , f (x n )]].
- list_filter() keeps only those items for which f is true. That is to say :
f ilter([x 1 , x 2 , , . . . . , x n ]) = [x i | 1 lessorequal i lessorequal n and f (x i ) = true]
- list_reduce() corresponds to the reduction of a list :
reduce([x 1 , x 2 , . . . . , x n ], f ) = f (. . . f (x 1 , x 2 ) . . . . , x n )
- list_fold_left() matches :
f old_lef t([x 1 , x 2 , , . . . . , x n ], f, r) = f (. . . f (f (r, x 1 ), x 2 ) . . . , x n )
- list_fold_right() corresponds to :
f old_right([x 1 , x 2 , . . . . , x n ], f, r) = f (x1, f (x 2 , . . . f (x n-1 , f (x n, r)) . .))
Functions that return a list must return a list without modifying the input list.


### Operation applied to Lists
such as:
- list_sum() returns the sum of the elements in a list.
- list_product() returns the product of the elements of a list.
- list_minimum() returns the minimum of the elements of a list.
- list_maximum() returns the maximum of the elements of a list.
- list_squares() returns a list whose elements are the squares of the elements of the input list.
- liste_any() returns true if there is an element in the list for which f returns true .
- liste_all() returns true if for all the elements of the list f returns true .
