# Check if a binary tree is balanced, where balanced means neither of the two subtrees has a height
# difference greater than 1. In the module the trees 1 and 3 are not balanced. 2 is balanced.
#
defmodule CheckBalanced do
  
    @tree1 {1, 
              {2,
                  {4,
                      {5, :nil, :nil},
                      {6, :nil, :nil},
                  },
                  :nil
              },
              {3, :nil, :nil}
          }

    @tree2 {1,
              {2, :nil, :nil},
              {3, :nil, :nil},
            }

    @tree3 {1, 
              {2,
                  {4,
                      {5, :nil, :nil},
                      {6, :nil, :nil},
                  },
                  :nil
              },
              {3,
                  {7, :nil, :nil},
                  {8, :nil, :nil},
              }
           }
    
    #recursively determine the height of a tree.
    def height(t, acc) do
      case t do
        :nil -> acc
        t -> 
          lh = height(elem(t,1), acc + 1)
          rh = height(elem(t,2), acc + 1)
          max(rh,lh)
      end
    end
    
    #compare the heights of the the 2 subtrees of any node. If the difference is greater than 1 then
    #the tree is not balanced.
    def is_node_balanced(t) do
      case t do
        :nil -> true
        t ->
          lh = height(elem(t,1), 0)
          rh = height(elem(t,2), 0)
          if abs(lh - rh) > 1 do
            n = elem(t, 0)
            IO.write("Node #{n} is not balanced\n")
          end
          abs(lh - rh) <= 1
      end
    end
  
    #recursively check all nodes in the tree and see if each node has a balanced subtree. In the
    #worst case this is O(n), but because the height function itself recurses this fucntion becomes
    #O(n^2)
    def is_tree_balanced(t, flag) do
      if flag do
        case t do
          :nil -> flag
          t -> 
            b = is_node_balanced(elem(t,1)) && is_node_balanced(elem(t,2))
            b = is_tree_balanced(elem(t,1), b)
            b = is_tree_balanced(elem(t,2), b)
        end
      else
        flag
      end
    end

    def inorder(t) do
      if t != :nil do
        inorder(elem(t,1))
        IO.write(elem(t,0))
        inorder(elem(t,2))
      end
    end

    def main do
      h = height(@tree1, 0)
      IO.write("height: #{h}\n")
      b = is_tree_balanced(@tree1, true)
      IO.write("balanced: #{b}\n")
      h = height(@tree2, 0)
      IO.write("height: #{h}\n")
      b = is_tree_balanced(@tree2, true)
      IO.write("balanced: #{b}\n")
      h = height(@tree3, 0)
      IO.write("height: #{h}\n")
      b = is_tree_balanced(@tree3, true)
      IO.write("balanced: #{b}\n")
    end
end
