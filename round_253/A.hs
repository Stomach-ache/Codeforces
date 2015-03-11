import Data.List (nub)
import Data.Char (isAlpha)
main = 
	interact $ show. length. nub. filter isAlpha 
