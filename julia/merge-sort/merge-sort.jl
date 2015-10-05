function mergesort(x)
    function combine(lhs, rhs)
        j = 1
        k = 1
        result = Int64[]
        while true
            if lhs[j] > rhs[k]
                append!(result, [rhs[k]])
                k += 1
            else
                append!(result, [lhs[j]])
                j += 1
            end
            if j == length(lhs) + 1
                append!(result, rhs[k:end])
                break
            end
            if k == length(rhs) + 1
                append!(result, lhs[j:end])
                break
            end
        end
        return result
    end

    l = length(x)
    if l > 2
        left = x[1 : div(l, 2)]
        right = x[div(l, 2) + 1 : end]
        left_result = mergesort(left)
        right_result = mergesort(right)
        return combine(left_result, right_result)
    elseif l < 2
        return x
    else
        if x[1] > x[2]
            temp = x[1]
            x[1] = x[2]
            x[2] = temp
        end
        return x
    end
end

question = [3,1,4,2]
result = mergesort(question)
println("question = $question, result = $result")
question = [5,1,3,9,0]
result = mergesort(question)
println("question = $question, result = $result")
