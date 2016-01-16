-module(mergesort).
-export([mergesort/1]).

swap_if_greater([A,B]) ->
    if 
        A > B ->
            [B, A];
        true ->
            [A, B]
    end.

mergesort([A]) ->
    [A];

mergesort([A,B]) ->
    swap_if_greater([A,B]);

mergesort([H|T]) ->
    L = [H|T],
    Middle = trunc(length(L)/2),
    Top = lists:sublist(L, Middle),
    Bottom = lists:sublist(L, Middle + 1, length(L) - Middle),
    lists:merge(mergesort(Top), mergesort(Bottom)).
