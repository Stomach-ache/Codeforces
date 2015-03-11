main = interact $ show. f. map read. words
f (n:d:xs) 
  	| sum xs  + (n-1)*10 > d = -1
	| otherwise 			 = div (d - sum xs) 5
