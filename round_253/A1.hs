main = interact $ show. length. filter (any $ map $ elem ['a'..'z'])
