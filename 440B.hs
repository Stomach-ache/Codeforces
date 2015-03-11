main = 
	interact $ show.  map (read :: String -> Int). tail. words
