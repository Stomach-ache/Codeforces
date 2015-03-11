import Data.List (sort, group)

main :: IO ()
main = do
  		interact (show. length. group. sort. tail. lines)
