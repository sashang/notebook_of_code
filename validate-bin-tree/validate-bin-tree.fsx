type Tree =
    | Leaf
    | Node of Tree * int * Tree

//      5 
//    3   7
//   1 4 2
let rec is_valid t min max : bool =
    match t with
    | Leaf -> true
    | Node (left, value, right) ->
        if value < max && value > min
           && is_valid left min value
           && is_valid right value max then true else false

let t1 =
    Node(Leaf, 1, Leaf)

let t2 =
    Node(
        Node(
            Node(Leaf, 1, Leaf), 3, Node(Leaf, 4, Leaf)
        ),
        5,
        Node(
            Node(Leaf, 6, Leaf), 7, Leaf))

