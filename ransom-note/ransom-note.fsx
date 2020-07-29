open System.Collections.Generic

let letters = new Dictionary<char,int>()
[ ('a', 2); ('b', 1); ('c', 1); ('e', 1) ] |> Seq.iter letters.Add

let can_spell (word : string) =
    let mutable result = true
    for x in word do
        if letters.ContainsKey x && letters.[x] > 0 then
            let old = letters.[x]
            letters.[x] <- old - 1
        else
            result <- false
    done
    result

let letters2 = dict [ ('a', 2); ('b', 1); ('c', 1); ('e', 1) ]

let contains (word:string)(letters:IDictionary<char,int>) = 
    let w = word
            |>Seq.countBy id
            |>dict

    let mapped = Seq.map(fun k-> letters.ContainsKey k && letters.[k] >= w.[k]) w.Keys
    printfn "%A" mapped
    let reduced = Seq.reduce(&&) mapped
    printfn "%A" reduced
    reduced

(* let helper (letters : IDictionary<char,int>) (c : char) =
    if letters.ContainsKey c && letters.[c] > 1 then
        Seq.pick (fun (kvp : KeyValuePair<char,int>) -> kvp.Key = c) letters
    else
        letters
let can_spell3 (word : string) =
//    Seq.fold (fun letters x ->  *)